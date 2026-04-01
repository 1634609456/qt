#pragma once

#include <QGridLayout>
#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

#include "../src/util/shm_manager.hpp"

/**
 * 计米参数纯显示组件（无按钮，用于电机主页）
 * 只展示：总计米、主计米、从计米、起始上料长度、单丝剩余长度、成品丝长度
 */
class MetersDisplayWidget : public QWidget {
public:
    explicit MetersDisplayWidget(QWidget* parent = nullptr);

private:
    QLabel* total_meters_{nullptr};
    QLabel* master_meters_{nullptr};
    QLabel* slave_meters_{nullptr};
    QLabel* start_meters_{nullptr};
    QLabel* feed_meters_{nullptr};
    QLabel* finish_meters_{nullptr};

    void init_ui();
    void init_refresh_timer();
    void refresh_from_shm();
};

inline MetersDisplayWidget::MetersDisplayWidget(QWidget* parent) : QWidget(parent) {
    init_ui();
    init_refresh_timer();
}

inline void MetersDisplayWidget::init_ui() {
    auto* root = new QVBoxLayout(this);
    root->setContentsMargins(8, 8, 8, 8);
    root->setSpacing(4);

    auto* title = new QLabel("计米显示", this);
    title->setStyleSheet("font-weight: bold; font-size: 13pt;");
    root->addWidget(title);

    auto* grid = new QGridLayout();
    grid->setHorizontalSpacing(10);
    grid->setVerticalSpacing(4);

    auto make_label = [this]() {
        auto* l = new QLabel("--", this);
        l->setMinimumWidth(90);
        l->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        l->setStyleSheet("font-size: 11pt;");
        return l;
    };

    total_meters_ = make_label();
    master_meters_ = make_label();
    slave_meters_ = make_label();
    start_meters_ = make_label();
    feed_meters_ = make_label();
    finish_meters_ = make_label();

    auto add_row = [&](int row, const QString& label_text, QLabel* value) {
        auto* lbl = new QLabel(label_text + ":", this);
        lbl->setMinimumWidth(110);
        lbl->setStyleSheet("font-size: 11pt;");
        grid->addWidget(lbl, row, 0);
        grid->addWidget(value, row, 1);
    };

    add_row(0, "总计米", total_meters_);
    add_row(1, "主计米", master_meters_);
    add_row(2, "从计米", slave_meters_);
    add_row(3, "起始上料长度", start_meters_);
    add_row(4, "单丝剩余长度", feed_meters_);
    add_row(5, "成品丝长度", finish_meters_);

    grid->setColumnStretch(1, 1);
    root->addLayout(grid);
    root->addStretch();
}

inline void MetersDisplayWidget::init_refresh_timer() {
    auto* refresh = new QTimer(this);
    connect(refresh, &QTimer::timeout, this, [this]() { refresh_from_shm(); });
    connect(&ShmManager::get_instance(), &ShmManager::loaded, [refresh](bool success) {
        if (success) refresh->start(500);
        else refresh->stop();
    });
}

inline void MetersDisplayWidget::refresh_from_shm() {
    auto* d = ShmManager::get_instance().get_data();
    if (!d) return;
    const auto& m = d->feedback.wheel_fdb;
    total_meters_->setText(QString::number(m.total_meters_fdb, 'f', 4));
    master_meters_->setText(QString::number(m.master_meters_fdb, 'f', 4));
    slave_meters_->setText(QString::number(m.slave_meters_fdb, 'f', 4));
    start_meters_->setText(QString::number(m.start_length_ref, 'f', 4));
    feed_meters_->setText(QString::number(m.feeding_length_ref, 'f', 4));
    finish_meters_->setText(QString::number(m.finish_length_ref, 'f', 4));
}
