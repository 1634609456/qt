#pragma once

#include <QHBoxLayout>
#include <QTimer>

#include "../src/util/shm_manager.hpp"
#include "ElaLineEdit.h"
#include "ElaPushButton.h"
#include "ElaText.h"

class ParamPage : public QWidget {
    Q_OBJECT

public:
    ParamPage(QWidget* parent = nullptr);

    ~ParamPage() = default;

private:
    void _init_content();

    ElaLineEdit* total_meters_;
    ElaLineEdit* master_meters_;
    ElaLineEdit* slave_meters_;
    ElaLineEdit* start_meters_;
    ElaLineEdit* feed_meters_;
    ElaLineEdit* finish_meters_;
};

inline ParamPage::ParamPage(QWidget* parent)
    : QWidget(parent),
      total_meters_(new ElaLineEdit(this)),
      master_meters_(new ElaLineEdit(this)),
      slave_meters_(new ElaLineEdit(this)),
      start_meters_(new ElaLineEdit(this)),
      feed_meters_(new ElaLineEdit(this)),
      finish_meters_(new ElaLineEdit(this)) {
    this->_init_content();

    auto* refresh = new QTimer(this);
    connect(refresh, &QTimer::timeout, [this]() {
        auto meters_fdb = ShmManager::get_instance().get_data()->feedback.wheel_fdb;
        total_meters_->setText(QString::number(meters_fdb.total_meters_fdb, 'f', 4));
        master_meters_->setText(QString::number(meters_fdb.master_meters_fdb, 'f', 4));
        slave_meters_->setText(QString::number(meters_fdb.slave_meters_fdb, 'f', 4));
    });
    connect(&ShmManager::get_instance(), &ShmManager::loaded, [refresh](bool success) {
        if (success) {
            refresh->start(500);
        } else {
            refresh->stop();
        }
    });
}

inline void ParamPage::_init_content() {
    auto create_display_or_set = [this](const QString& text, ElaLineEdit* editor, bool editable) {
        auto* layout = new QHBoxLayout();
        {
            auto* title = new ElaText(text, 16);
            title->setFixedWidth(128);

            editor->setEnabled(editable);
            editor->setFixedHeight(32);

            layout->addWidget(title);
            layout->addWidget(editor);
            if (editable) {
                auto* confirm = new ElaPushButton("修改", editor);
                layout->addWidget(confirm);
                connect(confirm, &ElaPushButton::clicked, [this, editor]() {
                    if (editor == start_meters_) {
                        ShmManager::get_instance().get_data()->feedback.wheel_fdb.start_length_ref =
                            editor->text().toDouble();
                    } else if (editor == feed_meters_) {
                        ShmManager::get_instance().get_data()->feedback.wheel_fdb.feeding_length_ref =
                            editor->text().toDouble();
                    } else if (editor == finish_meters_) {
                        ShmManager::get_instance().get_data()->feedback.wheel_fdb.finish_length_ref =
                            editor->text().toDouble();
                    }
                });
            }
        }

        return layout;
    };

    auto* main_layout = new QHBoxLayout();
    {
        auto* content_layout = new QVBoxLayout();
        content_layout->setContentsMargins(32, 32, 32, 32);
        {
            content_layout->addLayout(create_display_or_set("总计米:", total_meters_, false));
            content_layout->addLayout(create_display_or_set("主计米:", master_meters_, false));
            content_layout->addLayout(create_display_or_set("从计米:", slave_meters_, false));
            content_layout->addLayout(create_display_or_set("起始上料长度:", start_meters_, true));
            content_layout->addLayout(create_display_or_set("上料丝长度:", feed_meters_, true));
            content_layout->addLayout(create_display_or_set("成品丝长度:", finish_meters_, true));
            content_layout->addStretch();
        }

        main_layout->addLayout(content_layout);
        main_layout->addStretch();
    }

    this->setLayout(main_layout);
}