#pragma once

#include <QHeaderView>
#include <QStackedWidget>
#include <QTableWidget>
#include <QTimer>
#include <QVBoxLayout>
#include <mutex>

#include "../src/delegate/light_delegate.hpp"
#include "../src/model/io_model.hpp"
#include "../src/model/motor_feb_model.hpp"
#include "../src/util/config_manager.hpp"
#include "../src/util/ring_buffer.hpp"
#include "../src/util/shm_manager.hpp"
#include "ElaCheckBox.h"
#include "ElaComboBox.h"
#include "ElaLineEdit.h"
#include "ElaMessageBar.h"
#include "ElaPivot.h"
#include "ElaPushButton.h"
#include "ElaScrollArea.h"
#include "ElaTableView.h"
#include "ElaText.h"


class MotorCard : public QWidget {
    Q_OBJECT

public:
    MotorCard(QWidget *parent = nullptr);
    ~MotorCard() = default;

    Q_SIGNAL void send_cmd(const COMMOND_GROUPS &cmd);
};

inline MotorCard::MotorCard(QWidget *parent) : QWidget(parent) {
    auto *main_layout = new QVBoxLayout(this);
    {
        auto *motor_type_layout = new QHBoxLayout();

        auto *motor_type_combo = new ElaComboBox();
        motor_type_combo->addItems(motortype2name.values());

        motor_type_layout->addStretch();
        motor_type_layout->addWidget(new ElaText("电机类型：", 16));
        motor_type_layout->addWidget(motor_type_combo);
        motor_type_layout->addStretch();

        auto *input_layout = new QHBoxLayout();

        auto *speed_input = new ElaLineEdit(this);
        speed_input->setFixedHeight(32);
        speed_input->setPlaceholderText("速度");

        auto *manual_acceleration_input = new ElaLineEdit(this);
        manual_acceleration_input->setFixedHeight(32);
        manual_acceleration_input->setPlaceholderText("加速度");

        auto *manual_pos_input = new ElaLineEdit(this);
        manual_pos_input->setFixedHeight(32);
        manual_pos_input->setPlaceholderText("位置");

        input_layout->addWidget(speed_input);
        input_layout->addWidget(manual_acceleration_input);
        input_layout->addWidget(manual_pos_input);

        auto *btn_layout = new QGridLayout();
#define CREATE_BUTTON(var, text, row, col) \
    auto *(var) = new ElaPushButton(text); \
    btn_layout->addWidget(var, row, col)

        CREATE_BUTTON(jog_forward, "正点动", 0, 0);
        CREATE_BUTTON(jog_reverse, "反点动", 0, 1);
        CREATE_BUTTON(home, "回零", 0, 2);
        CREATE_BUTTON(brake_release, "松闸", 1, 0);
        CREATE_BUTTON(brake_apply, "抱闸", 1, 1);
        CREATE_BUTTON(stop, "停止", 1, 2);
        CREATE_BUTTON(enable, "上使能", 2, 0);
        CREATE_BUTTON(disable, "去使能", 2, 1);
        CREATE_BUTTON(abs_move, "绝对移动", 2, 2);

#undef CREATE_BUTTON

#define CONNECT_MOTOR_CMD(button, command)                                                                             \
    connect(button, &ElaPushButton::clicked,                                                                           \
            [this, speed_input, manual_acceleration_input, manual_pos_input, motor_type_combo]() {                     \
                Q_EMIT send_cmd(                                                                                       \
                    {.cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD,                                   \
                     .motor_manual_control = {.manual_control_cmd = MOTOR_MANUAL_CONTROL::command,                     \
                                              .motor_type = static_cast<MOTOR_TYPE>(motor_type_combo->currentIndex()), \
                                              .speed = speed_input->text().toDouble(),                                 \
                                              .manual_acceleration = manual_acceleration_input->text().toDouble(),     \
                                              .manual_pos = manual_pos_input->text().toDouble()}});                    \
            })

        CONNECT_MOTOR_CMD(jog_forward, FORWARD_JOGING);
        CONNECT_MOTOR_CMD(jog_reverse, REVERSE_JOGING);
        CONNECT_MOTOR_CMD(brake_release, RELEASE_BRAKE);
        CONNECT_MOTOR_CMD(brake_apply, ENGAGE_BRAKE);
        CONNECT_MOTOR_CMD(home, RETURN_TO_ZERO);
        CONNECT_MOTOR_CMD(abs_move, ABSOLUTE_POSITION_MOTION);
        CONNECT_MOTOR_CMD(stop, STOP);
        CONNECT_MOTOR_CMD(enable, MANUAL_MOTOR_ON);
        CONNECT_MOTOR_CMD(disable, MANUAL_MOTOR_OFF);

#undef CONNECT_MOTOR_CMD

        main_layout->addLayout(motor_type_layout);
        main_layout->addLayout(btn_layout);
        main_layout->addLayout(input_layout);
    }
}

class DataMonitorPage : public QWidget {
    Q_OBJECT

public:
    DataMonitorPage(QWidget *parent = nullptr);

    ~DataMonitorPage() = default;

private:
    void _init_content();

    RingBuffer<RINGBUFFER> buffer_p_;
    RingBuffer<RINGBUFFER> buffer_m_;

    QStackedWidget *stack_;
    ElaPivot *pivot_;

    std::mutex lock_;
};

inline DataMonitorPage::DataMonitorPage(QWidget *parent)
    : QWidget(parent),
      buffer_p_(nullptr),
      buffer_m_(nullptr),
      stack_(new QStackedWidget(this)),
      pivot_(new ElaPivot(this)) {
    this->_init_content();

    connect(&ShmManager::get_instance(), &ShmManager::loaded, [this](bool success) {
        if (success) {
            buffer_m_.set_buffer(&ShmManager::get_instance().get_data()->buffer_M);
            buffer_p_.set_buffer(&ShmManager::get_instance().get_data()->buffer_P);
        }
    });
}

inline void DataMonitorPage::_init_content() {
    auto *main_layout = new QHBoxLayout();
    {
        auto *view_layout = new QVBoxLayout();
        {
            auto *motor_view = new ElaTableView();
            {
                motor_view->verticalHeader()->setVisible(false);
                motor_view->setAlternatingRowColors(true);
                motor_view->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
                motor_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                motor_view->setModel(new MotorFebModel(motor_view));
                motor_view->setItemDelegateForColumn(1, new LightDelegate(motor_view));
                motor_view->setItemDelegateForColumn(2, new LightDelegate(motor_view));
                motor_view->setItemDelegateForColumn(3, new LightDelegate(motor_view));
                motor_view->setItemDelegateForColumn(4, new LightDelegate(motor_view));
            }

            auto *io_view = new ElaTableView();
            {
                io_view->verticalHeader()->setVisible(false);
                io_view->setAlternatingRowColors(true);
                io_view->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
                io_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                io_view->setModel(new IOModel(io_view));
                io_view->setItemDelegateForColumn(3, new LightDelegate(io_view));
            }

            pivot_->appendPivot("电机");
            pivot_->appendPivot("IO");
            pivot_->setPivotSpacing(8);
            pivot_->setCurrentIndex(0);

            stack_->addWidget(motor_view);
            stack_->addWidget(io_view);

            connect(pivot_, &ElaPivot::pivotClicked, stack_, &QStackedWidget::setCurrentIndex);

            view_layout->addWidget(pivot_, 0);
            view_layout->addWidget(stack_);
        }

        auto *control_layout = new QVBoxLayout();
        {
            auto *state_machine_layout = new QVBoxLayout();
            {
                auto *mode_layout = new QHBoxLayout();
                {
                    auto *auto_btn = new ElaPushButton("自动");
                    {
                        auto_btn->setLightTextColor({255, 255, 255});
                        auto_btn->setLightDefaultColor({14, 111, 14});
                        auto_btn->setLightHoverColor({60, 138, 60});
                        auto_btn->setLightPressColor({82, 150, 82});
                    }
                    auto *manual_btn = new ElaPushButton("手动");
                    {
                        manual_btn->setLightTextColor({255, 255, 255});
                        manual_btn->setLightDefaultColor({0, 102, 180});
                        manual_btn->setLightHoverColor({49, 131, 193});
                        manual_btn->setLightPressColor({72, 144, 198});
                    }
                    connect(auto_btn, &ElaPushButton::clicked, [this]() {
                        COMMOND_GROUPS cmd{.cmd_type = COMMOND_GROUPS::CMD_TYPE::MODE_CMD,
                                           .mode_fsm_event_type = MODE_EVENT_AUTO};
                        buffer_p_.push(cmd);
                        buffer_m_.push(cmd);
                        ElaMessageBar::success(ElaMessageBarType::Top, "提示", "自动模式命令下发成功！", 3000, this);
                    });

                    connect(manual_btn, &ElaPushButton::clicked, [this]() {
                        COMMOND_GROUPS cmd{.cmd_type = COMMOND_GROUPS::CMD_TYPE::MODE_CMD,
                                           .mode_fsm_event_type = MODE_EVENT_MANUAL};
                        buffer_p_.push(cmd);
                        buffer_m_.push(cmd);
                        ElaMessageBar::success(ElaMessageBarType::Top, "提示", "手动模式命令下发成功！", 3000, this);
                    });

                    mode_layout->addWidget(new ElaText("模式状态机：", 16));
                    mode_layout->addStretch();
                    mode_layout->addWidget(auto_btn);
                    mode_layout->addWidget(manual_btn);
                    mode_layout->addStretch();
                }

                auto *main__layout = new QGridLayout();
                {
                    auto *init_btn = new ElaPushButton("初始化");
                    auto *init_err_btn = new ElaPushButton("初始化");
                    auto *config_btn = new ElaPushButton("配置");
                    auto *config_err_btn = new ElaPushButton("配置错误");
                    auto *err_reset_btn = new ElaPushButton("错误复位");
                    auto *power_on_btn = new ElaPushButton("上电");
                    auto *power_off_btn = new ElaPushButton("下电");
                    auto *run_btn = new ElaPushButton("运行");
                    {
                        run_btn->setLightTextColor({255, 255, 255});
                        run_btn->setLightDefaultColor({14, 111, 14});
                        run_btn->setLightHoverColor({60, 138, 60});
                        run_btn->setLightPressColor({82, 150, 82});
                    }
                    auto *stop_btn = new ElaPushButton("停止");
                    {
                        stop_btn->setLightTextColor({255, 255, 255});
                        stop_btn->setLightDefaultColor({185, 13, 28});
                        stop_btn->setLightHoverColor({197, 59, 71});
                        stop_btn->setLightPressColor({202, 81, 92});
                    }
                    auto *error_btn = new ElaPushButton("错误");
                    auto *emg_btn = new ElaPushButton("急停");
                    {
                        emg_btn->setLightTextColor({255, 255, 255});
                        emg_btn->setLightDefaultColor({185, 13, 28});
                        emg_btn->setLightHoverColor({197, 59, 71});
                        emg_btn->setLightPressColor({202, 81, 92});
                    }
                    auto *emg_clear_btn = new ElaPushButton("急停清除");
                    {
                        emg_clear_btn->setLightTextColor({255, 255, 255});
                        emg_clear_btn->setLightDefaultColor({14, 111, 14});
                        emg_clear_btn->setLightHoverColor({60, 138, 60});
                        emg_clear_btn->setLightPressColor({82, 150, 82});
                    }

                    main__layout->addWidget(new ElaText("主状态机：", 16), 0, 0, 1, 4);
                    main__layout->addWidget(init_btn, 1, 0);
                    main__layout->addWidget(init_err_btn, 1, 1);
                    main__layout->addWidget(config_btn, 1, 2);
                    main__layout->addWidget(config_err_btn, 1, 3);
                    main__layout->addWidget(error_btn, 2, 0);
                    main__layout->addWidget(err_reset_btn, 2, 1);
                    main__layout->addWidget(power_on_btn, 2, 2);
                    main__layout->addWidget(power_off_btn, 2, 3);
                    main__layout->addWidget(stop_btn, 3, 0);
                    main__layout->addWidget(run_btn, 3, 1);
                    main__layout->addWidget(emg_btn, 3, 2);
                    main__layout->addWidget(emg_clear_btn, 3, 3);

                    for (auto *btn : {init_btn, init_err_btn, config_btn, config_err_btn, err_reset_btn, power_on_btn,
                                      power_off_btn, run_btn, stop_btn, error_btn, emg_btn, emg_clear_btn}) {
                        connect(btn, &ElaPushButton::clicked, [this, btn]() {
                            MAIN_FSM_EVENT_TYPE eventType;
                            QString eventName = btn->text();

                            if (eventName == "初始化")
                                eventType = MAIN_EVENT_INIT;
                            else if (eventName == "初始化错误")
                                eventType = MAIN_EVENT_INIT_ERROR;
                            else if (eventName == "配置")
                                eventType = MAIN_EVENT_CONFIG;
                            else if (eventName == "配置错误")
                                eventType = MAIN_EVENT_CONFIG_ERROR;
                            else if (eventName == "错误复位")
                                eventType = MAIN_EVENT_ERROR_RESET;
                            else if (eventName == "上电")
                                eventType = MAIN_EVENT_MOTOR_ON;
                            else if (eventName == "下电")
                                eventType = MAIN_EVENT_MOTOR_OFF;
                            else if (eventName == "运行")
                                eventType = MAIN_EVENT_CONTROL_ON;
                            else if (eventName == "停止")
                                eventType = MAIN_EVENT_CONTROL_OFF;
                            else if (eventName == "错误")
                                eventType = MAIN_EVENT_ERROR;
                            else if (eventName == "急停")
                                eventType = MAIN_EVENT_EME_STOP;
                            else if (eventName == "急停清除")
                                eventType = MAIN_EVENT_EME_STOP_CLEAR;

                            COMMOND_GROUPS cmd{.cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD,
                                               .main_fsm_event_type = eventType};
                            buffer_p_.push(cmd);
                            buffer_m_.push(cmd);

                            ElaMessageBar::success(ElaMessageBarType::Top, "提示",
                                                   QString("%1命令下发成功！").arg(eventName), 3000, this);
                        });
                    }
                }

                state_machine_layout->addLayout(mode_layout);
                state_machine_layout->addLayout(main__layout);
            }

            auto *io_layout = new QHBoxLayout();
            {
                auto *io_title = new ElaText("IO控制：", 16);

                auto *option_layout = new QVBoxLayout();
                {
                    auto *io_combo = new ElaComboBox();
                    io_combo->addItems(output2name.values());
                    io_combo->addItems(valve2name.values());

                    auto *bit_check_ = new ElaCheckBox("使能");
                    auto *modify_btn = new ElaPushButton("修改");
                    {
                        modify_btn->setFixedWidth(128);
                        modify_btn->setLightTextColor({255, 255, 255});
                        modify_btn->setLightDefaultColor({0, 102, 180});
                        modify_btn->setLightHoverColor({49, 131, 193});
                        modify_btn->setLightPressColor({72, 144, 198});
                    }

                    connect(modify_btn, &ElaPushButton::clicked, [this, io_combo, bit_check_]() {
                        int output_io = find_key_by_name(output2name, io_combo->currentText());
                        if (output_io == OUT_MAX) {
                            output_io = find_key_by_name(valve2name, io_combo->currentText());
                        }

                        COMMOND_GROUPS cmd{
                            .cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD,
                            .io_manual_control = {.output_signal_name = output_io,
                                                  .value = bit_check_->isChecked() ? YKE_TRUE : YKE_FALSE}};
                        buffer_p_.push(cmd);
                        buffer_m_.push(cmd);
                        ElaMessageBar::success(ElaMessageBarType::Top, "提示", "IO使能命令下发成功！", 3000, this);
                    });

                    option_layout->addWidget(io_combo);
                    option_layout->addWidget(bit_check_, 0, Qt::AlignCenter);
                    option_layout->addWidget(modify_btn, 0, Qt::AlignHCenter);
                }

                io_layout->addWidget(io_title);
                io_layout->addLayout(option_layout);
            }

            auto *motor_card = new MotorCard();
            {
                static CONST QSet<MOTOR_TYPE> p_set{MAIN_SPINDLE, MAIN_DRAWING, MAIN_TORSION, MAIN_WINDING,
                                                    MAIN_LAYING};
                connect(motor_card, &MotorCard::send_cmd, [this](const COMMOND_GROUPS &cmd) {
                    auto *buffer = p_set.contains(cmd.motor_manual_control.motor_type) ? &buffer_p_ : &buffer_m_;
                    if (buffer->push(cmd)) {
                        std::this_thread::sleep_for(std::chrono::milliseconds(50));
                        ElaMessageBar::success(
                            ElaMessageBarType::Top, "提示",
                            QString("命令下发成功！当前未处理命令数量为%1").arg(buffer->readable_length()), 3000, this);
                    }
                });
            }

            auto *automation_layout = new QGridLayout();
            {
                #define CREATE_AUTOMATION_BUTTON(var, text, cmd_type)                              \
                    auto *(var) = new ElaPushButton(text);                                        \
                    connect(var, &ElaPushButton::clicked, [this]() {                              \
                        ShmManager::get_instance().get_data()->machine_fsm_cmd.machine_fsm_cmd_view = cmd_type; \
                        ElaMessageBar::success(ElaMessageBarType::Top, "提示", QString("%1命令下发成功！").arg(text), 3000, this); \
                    })

                CREATE_AUTOMATION_BUTTON(edge_location_btn, "穿边线定位", MACHINE_FSM_CMD_TYPE::EDGE_PIERCE_LOCATION);
                CREATE_AUTOMATION_BUTTON(edge_btn, "穿边线", MACHINE_FSM_CMD_TYPE::EDGE_PIERCE);
                CREATE_AUTOMATION_BUTTON(center_location_btn, "穿中线定位", MACHINE_FSM_CMD_TYPE::CENTER_PIERCE_LOCATION);
                CREATE_AUTOMATION_BUTTON(center_btn, "穿中线", MACHINE_FSM_CMD_TYPE::CENTER_PIERCE);
                CREATE_AUTOMATION_BUTTON(oneclick_load, "一键上料", MACHINE_FSM_CMD_TYPE::ONE_CLICK_FEEDING);
                CREATE_AUTOMATION_BUTTON(oneclick_unload, "一键下料", MACHINE_FSM_CMD_TYPE::ONE_CLICK_UNLOADING);
                CREATE_AUTOMATION_BUTTON(unload_btn, "卸满轮上空轮", MACHINE_FSM_CMD_TYPE::LOAD_UNLOAD_WHEEL);

                #undef CREATE_AUTOMATION_BUTTON

                automation_layout->addWidget(new ElaText("自动化控制：", 16), 0, 0, 1, 2);
                automation_layout->addWidget(edge_location_btn, 1, 0);
                automation_layout->addWidget(edge_btn, 1, 1);
                automation_layout->addWidget(center_location_btn, 2, 0);
                automation_layout->addWidget(center_btn, 2, 1);
                automation_layout->addWidget(oneclick_load, 3, 0);
                automation_layout->addWidget(oneclick_unload, 3, 1);
                automation_layout->addWidget(unload_btn, 4, 0, 1, 2);
            }

            control_layout->addLayout(state_machine_layout);
            control_layout->addStretch();
            control_layout->addLayout(io_layout);
            control_layout->addStretch();
            control_layout->addWidget(motor_card);
            control_layout->addStretch();
            control_layout->addLayout(automation_layout);
        }

        main_layout->addLayout(view_layout, 4);
        main_layout->addLayout(control_layout, 1);
    }

    this->setLayout(main_layout);
}
