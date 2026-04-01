#pragma once

#include <QGridLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

#include "../src/util/shm_manager.hpp"
#include "ElaLineEdit.h"
#include "ElaPushButton.h"
#include "ElaText.h"

/**
 * 计米参数组件（可复用）
 *
 * 设计目标：
 * - 同时用于：
 *   - “参数调试”中的“计米参数”Tab
 *   - “电机主页”中的“计米显示”区域
 *
 * 数据来源/写入方式（后端对接说明）：
 * - 当前版本为了先跑通 UI，延续你原 `ParamPage` 的做法：直接读写共享内存结构体：
 *   - 读：`ShmManager::get_instance().get_data()->feedback.wheel_fdb`
 *   - 写：直接修改 wheel_fdb 的 ref 字段（start/feed/finish）与 master_meters_fdb 清零
 *
 * 后续如果后端希望改成“命令接口/协议”：
 * - UI 不用改，只需要把 `on_commit` 和清零按钮点击处的写入点替换为后端接口即可。
 */
class MetersSettingsWidget : public QWidget {
public:
    explicit MetersSettingsWidget(QWidget* parent = nullptr);

private:
    ElaLineEdit* total_meters_{nullptr};
    ElaLineEdit* master_meters_{nullptr};
    ElaLineEdit* slave_meters_{nullptr};
    ElaLineEdit* start_meters_{nullptr};
    ElaLineEdit* feed_meters_{nullptr};
    ElaLineEdit* finish_meters_{nullptr};

    QWidget* editing_widget_{nullptr};  // 跟踪正在编辑的控件，避免定时刷新覆盖输入

    void init_ui();
    void init_refresh_timer();
    void refresh_from_shm();
};

inline MetersSettingsWidget::MetersSettingsWidget(QWidget* parent) : QWidget(parent) {
    init_ui();
    init_refresh_timer();
}

inline void MetersSettingsWidget::init_ui() {
    auto* root = new QVBoxLayout(this);
    root->setContentsMargins(16, 16, 16, 16);
    root->setSpacing(12);

    auto* title = new ElaText("计米参数设置", 18);
    title->setStyleSheet("font-weight: 700;");
    root->addWidget(title, 0, Qt::AlignLeft);

    auto* grid = new QGridLayout();
    grid->setHorizontalSpacing(12);
    grid->setVerticalSpacing(10);

    auto make_editor = [this]() {
        auto* e = new ElaLineEdit(this);
        e->setFixedHeight(32);
        return e;
    };

    total_meters_ = make_editor();
    master_meters_ = make_editor();
    slave_meters_ = make_editor();
    start_meters_ = make_editor();
    feed_meters_ = make_editor();
    finish_meters_ = make_editor();

    total_meters_->setEnabled(false);
    master_meters_->setEnabled(false);
    slave_meters_->setEnabled(false);

    for (auto* e : {start_meters_, feed_meters_, finish_meters_}) {
        e->setEnabled(true);
        e->setFocusPolicy(Qt::StrongFocus);
        connect(e, &ElaLineEdit::focusIn, this, [this, e]() { editing_widget_ = e; });
        connect(e, &ElaLineEdit::editingFinished, this, [this, e]() {
            if (editing_widget_ == e) editing_widget_ = nullptr;
        });
    }

    auto add_row = [&](int row, const QString& label_text, ElaLineEdit* editor,
                       bool editable, bool resettable, std::function<void()> on_commit) {
        auto* label = new ElaText(label_text, 16);
        label->setFixedWidth(160);

        grid->addWidget(label, row, 0);
        grid->addWidget(editor, row, 1);

        auto* btn_area = new QWidget(this);
        auto* btn_layout = new QHBoxLayout(btn_area);
        btn_layout->setContentsMargins(0, 0, 0, 0);
        btn_layout->setSpacing(8);
        btn_layout->addStretch();

        if (editable) {
            auto* confirm = new ElaPushButton("修改", this);
            confirm->setFixedHeight(32);
            confirm->setFixedWidth(96);
            connect(confirm, &ElaPushButton::clicked, this, [on_commit]() { on_commit(); });
            btn_layout->addWidget(confirm);
        }

        if (resettable) {
            auto* reset = new ElaPushButton("清零", this);
            reset->setFixedHeight(32);
            reset->setFixedWidth(96);
            connect(reset, &ElaPushButton::clicked, this, [this]() {
                if (auto* d = ShmManager::get_instance().get_data()) {
                    d->feedback.wheel_fdb.master_meters_fdb = 0.0;
                }
            });
            btn_layout->addWidget(reset);
        }

        grid->addWidget(btn_area, row, 2);
    };

    add_row(0, "总计米:", total_meters_, false, false, [] {});
    add_row(1, "主计米:", master_meters_, false, true, [] {});
    add_row(2, "从计米:", slave_meters_, false, false, [] {});
    add_row(3, "起始上料长度:", start_meters_, true, false, [this]() {
        if (auto* d = ShmManager::get_instance().get_data()) {
            d->feedback.wheel_fdb.start_length_ref = start_meters_->text().toDouble();
        }
    });
    add_row(4, "单丝剩余长度:", feed_meters_, true, false, [this]() {
        if (auto* d = ShmManager::get_instance().get_data()) {
            d->feedback.wheel_fdb.feeding_length_ref = feed_meters_->text().toDouble();
        }
    });
    add_row(5, "成品丝长度:", finish_meters_, true, false, [this]() {
        if (auto* d = ShmManager::get_instance().get_data()) {
            d->feedback.wheel_fdb.finish_length_ref = finish_meters_->text().toDouble();
        }
    });

    grid->setColumnStretch(1, 1);
    root->addLayout(grid);
    root->addStretch();
}

inline void MetersSettingsWidget::init_refresh_timer() {
    auto* refresh = new QTimer(this);
    connect(refresh, &QTimer::timeout, this, [this]() { refresh_from_shm(); });

    connect(&ShmManager::get_instance(), &ShmManager::loaded, [refresh](bool success) {
        if (success) {
            refresh->start(500);
        } else {
            refresh->stop();
        }
    });
}

inline void MetersSettingsWidget::refresh_from_shm() {
    auto* d = ShmManager::get_instance().get_data();
    if (!d) return;

    const auto meters_fdb = d->feedback.wheel_fdb;

    total_meters_->setText(QString::number(meters_fdb.total_meters_fdb, 'f', 4));
    master_meters_->setText(QString::number(meters_fdb.master_meters_fdb, 'f', 4));
    slave_meters_->setText(QString::number(meters_fdb.slave_meters_fdb, 'f', 4));

    if (editing_widget_ != start_meters_) {
        start_meters_->setText(QString::number(meters_fdb.start_length_ref, 'f', 4));
    }
    if (editing_widget_ != feed_meters_) {
        feed_meters_->setText(QString::number(meters_fdb.feeding_length_ref, 'f', 4));
    }
    if (editing_widget_ != finish_meters_) {
        finish_meters_->setText(QString::number(meters_fdb.finish_length_ref, 'f', 4));
    }
}

