#pragma once

#include <QHeaderView>
#include <QTableWidget>
#include <QTimer>
#include <QVBoxLayout>
#include <mutex>

#include "../src/model/motor_config_model.hpp"
#include "../src/util/config_manager.hpp"
#include "../src/util/shm_manager.hpp"
#include "ElaMessageBar.h"
#include "ElaPushButton.h"
#include "ElaTableView.h"


class ConfigPage : public QWidget {
    Q_OBJECT

public:
    ConfigPage(QWidget *parent = nullptr);

    ~ConfigPage() = default;

private:
    void _init_content();

    ElaTableView *motor_view_{};
    MotorConfigModel *motor_model_{};

    std::mutex lock_;
};

inline ConfigPage::ConfigPage(QWidget *parent) : QWidget(parent), motor_view_(new ElaTableView()) {
    this->_init_content();
}

inline void ConfigPage::_init_content() {
    auto *main_layout = new QVBoxLayout();
    {
        {
            motor_view_->verticalHeader()->setVisible(false);
            motor_view_->setAlternatingRowColors(true);
            motor_view_->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
            // motor_view_->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
            motor_model_ = new MotorConfigModel(motor_view_);
            motor_view_->setModel(motor_model_);
        }

        auto *control_layout = new QHBoxLayout();
        {
            auto *write_conf_btn = new ElaPushButton("写入配置", this);
            {
                write_conf_btn->setEnabled(false);
                connect(write_conf_btn, &ElaPushButton::clicked, [this]() {
                    {
                        std::lock_guard<std::mutex> guard(lock_);
                        auto &config_data = ShmManager::get_instance().get_data()->config;
                        
                        // 使用表格中修改后的数据
                        const auto& motor_data = motor_model_->getDataStorage();
                        if (!motor_data.empty()) {
                            // 复制修改后的电机配置数据 (motor_config数组大小为20)
                            for (size_t i = 0; i < motor_data.size() && i < 20; ++i) {
                                config_data.motor_config[i] = motor_data[i];
                            }
                        }
                        
                        config_data.config_state = CONFIG_STATE::CONFIG_SUCCESS;
                    }

                    ElaMessageBar::success(ElaMessageBarType::Top, "提示", "配置写入成功！", 3000, this);
                });
            }

            auto *read_conf_btn = new ElaPushButton("刷新配置", this);
            {
                read_conf_btn->setEnabled(false);
                connect(read_conf_btn, &ElaPushButton::clicked, [this, write_conf_btn]() {
                    auto &config = ConfigManager::get_instance();
                    auto loaded = config.load();
                    if (loaded) {
                        motor_model_->setDataStorage(std::vector<MOTOR_DATA>(
                            std::begin(config.get_config().motor_config), std::end(config.get_config().motor_config)));
                        ElaMessageBar::success(ElaMessageBarType::Top, "提示", "配置加载成功！", 3000, this);
                    } else {
                        motor_model_->setDataStorage({});
                        ElaMessageBar::error(ElaMessageBarType::Top, "提示",
                                             QString("配置加载失败：%1").arg(ConfigManager::ERR_STR), 3000, this);
                    }
                    write_conf_btn->setEnabled(loaded);
                });
            }

            auto *read_shm_btn = new ElaPushButton("加载共享内存", this);
            {
                connect(read_shm_btn, &ElaPushButton::clicked, [this, read_conf_btn]() {
                    ShmManager::get_instance().load_shared_memory();
                    if (ShmManager::get_instance().get_data()) {
                        read_conf_btn->setEnabled(true);
                        ElaMessageBar::success(ElaMessageBarType::Top, "提示", "共享内存打开成功！", 3000, this);
                    } else {
                        read_conf_btn->setEnabled(false);
                        ElaMessageBar::error(ElaMessageBarType::Top, "错误", "共享内存打开失败！", 3000, this);
                    }
                });
            }

            control_layout->addStretch();
            control_layout->addWidget(read_shm_btn);
            control_layout->addWidget(read_conf_btn);
            control_layout->addWidget(write_conf_btn);
            control_layout->addStretch();
        }

        main_layout->addWidget(motor_view_);
        main_layout->addLayout(control_layout, 0);
    }

    this->setLayout(main_layout);
}