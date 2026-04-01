#pragma once

#include <functional>

#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

#include "ElaMessageBar.h"

#include "../src/util/ring_buffer.hpp"
#include "../src/util/shm_manager.hpp"
#include "../src/util/user_role.h"

/**
 * 主机参数页面（挂在“手动控制”下）
 *
 * 背景：
 * 你原本把很多“参数/调试/设置”内容都放在了电机主页 `HomePage` 里。
 * 现在为了让主页更聚焦，只保留：
 * - 操作权限（切换游客/操作员）
 * - 计米清零
 * - 主状态机按钮：错误复位/停止/运行/急停/急停清除（由主页保留）
 *
 * 其余内容迁移到本页面，包括：
 * - 设定速度（主轴速度设定）
 * - 模式状态机（自动/手动）
 * - PID 参数（撑杆退/撑杆进/中穿进/边穿进/通用PID）
 * - 大小头设置（上限位/下限位显示 + 修改）
 *
 * ⚠️ 重要说明（方便你后续和后端沟通）：
 * 当前实现延续你现有 `HomePage` 的做法：直接读写共享内存结构体：
 * - 速度设定：`data->config.motor_config[MAIN_SPINDLE].running_speed`
 * - PID 参数：`data->pid = ...`
 * - 上/下限位：`data->feedback.wheel_fdb.start_length_ref / finish_length_ref`
 * - 模式/状态机命令：与参数调试页一致，`buffer_P` + `buffer_M` 双写下发
 *
 * 如果后端希望改为“命令接口/协议”方式：
 * - UI 不需要改，只需要把下面这些写入点替换成后端接口即可。
 */
class HostParamsPage : public QWidget {
public:
    explicit HostParamsPage(QWidget* parent = nullptr)
        : QWidget(parent), buffer_p_(nullptr), buffer_m_(nullptr) {
        init_ui();
        init_refresh();

        connect(&ShmManager::get_instance(), &ShmManager::loaded, [this](bool success) {
            if (success) {
                sync_ring_buffers_from_shm();
                refresh_timer_->start(200);
            } else {
                refresh_timer_->stop();
            }
        });
        // 共享内存若在页面创建前已加载完成，会错过 `loaded` 信号，需补绑环形缓冲
        sync_ring_buffers_from_shm();
        if (ShmManager::get_instance().get_data()) {
            refresh_timer_->start(200);
        }

        // 初始化一次权限状态（当前手动控制页只在操作员显示，但这里也做保险）
        update_enabled_state();
    }

private:
    void sync_ring_buffers_from_shm() {
        auto* d = ShmManager::get_instance().get_data();
        if (!d) {
            return;
        }
        buffer_p_.set_buffer(&d->buffer_P);
        buffer_m_.set_buffer(&d->buffer_M);
    }

    /** 与 data_monitor_page 一致：模式命令写入 P/M 双缓冲 */
    bool push_mode_cmd(MODE_FSM_EVENT_TYPE mode_event) {
        if (!ShmManager::get_instance().get_data()) {
            QMessageBox::warning(this, tr("未连接"), tr("未连接到共享内存，请先加载共享内存"));
            return false;
        }
        COMMOND_GROUPS cmd;
        cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MODE_CMD;
        cmd.mode_fsm_event_type = mode_event;
        buffer_p_.push(cmd);
        buffer_m_.push(cmd);
        return true;
    }

    RingBuffer<RINGBUFFER> buffer_p_;
    RingBuffer<RINGBUFFER> buffer_m_;

    // ===== 顶部状态显示（复用主页逻辑） =====
    QLabel* actual_speed_value_{nullptr};  // 实际速度
    QLabel* upper_limit_value_{nullptr};   // 上限位显示
    QLabel* lower_limit_value_{nullptr};   // 下限位显示

    // ===== 设定速度 =====
    QLineEdit* set_speed_input_{nullptr};
    QPushButton* set_speed_confirm_{nullptr};

    // ===== 模式状态机 =====
    QPushButton* mode_auto_btn_{nullptr};
    QPushButton* mode_manual_btn_{nullptr};

    // ===== PID 参数 =====
    QLineEdit* rod_ret_kp_{nullptr};
    QLineEdit* rod_ret_ki_{nullptr};
    QLineEdit* rod_ret_kd_{nullptr};
    QPushButton* rod_ret_confirm_{nullptr};

    QLineEdit* rod_adv_kp_{nullptr};
    QLineEdit* rod_adv_ki_{nullptr};
    QLineEdit* rod_adv_kd_{nullptr};
    QPushButton* rod_adv_confirm_{nullptr};

    QLineEdit* center_adv_kp_{nullptr};
    QLineEdit* center_adv_ki_{nullptr};
    QLineEdit* center_adv_kd_{nullptr};
    QPushButton* center_adv_confirm_{nullptr};

    QLineEdit* edge_adv_kp_{nullptr};
    QLineEdit* edge_adv_ki_{nullptr};
    QLineEdit* edge_adv_kd_{nullptr};
    QPushButton* edge_adv_confirm_{nullptr};

    // ===== 大小头设置 =====
    QLineEdit* upper_limit_modify_{nullptr};
    QLineEdit* lower_limit_modify_{nullptr};
    QPushButton* upper_limit_confirm_{nullptr};
    QPushButton* lower_limit_confirm_{nullptr};

    QTimer* refresh_timer_{nullptr};

private:
    void init_ui() {
        auto* root = new QVBoxLayout(this);
        root->setContentsMargins(24, 16, 24, 16);
        root->setSpacing(12);

        // 顶部：速度/权限信息（这里不做权限切换按钮，权限按钮保留在主页）
        {
            auto* top = new QHBoxLayout();
            top->setSpacing(16);

            auto* set_speed_label = new QLabel(QStringLiteral("设定速度:"), this);
            set_speed_label->setStyleSheet("font-weight:600; font-size:16px;");
            set_speed_input_ = new QLineEdit(this);
            set_speed_input_->setFixedHeight(32);
            set_speed_input_->setPlaceholderText(QStringLiteral("r/min"));
            set_speed_confirm_ = new QPushButton(QStringLiteral("确定"), this);
            set_speed_confirm_->setFixedHeight(32);

            auto* actual_speed_label = new QLabel(QStringLiteral("实际速度:"), this);
            actual_speed_label->setStyleSheet("font-weight:600; font-size:16px;");
            actual_speed_value_ = new QLabel("--", this);
            actual_speed_value_->setMinimumWidth(100);
            actual_speed_value_->setAlignment(Qt::AlignCenter);
            auto* unit = new QLabel(QStringLiteral("r/min"), this);
            unit->setStyleSheet("font-weight:600; font-size:16px;");

            top->addWidget(set_speed_label);
            top->addWidget(set_speed_input_);
            top->addWidget(set_speed_confirm_);
            top->addSpacing(24);
            top->addWidget(actual_speed_label);
            top->addWidget(actual_speed_value_);
            top->addWidget(unit);
            top->addStretch();

            root->addLayout(top);

            connect(set_speed_confirm_, &QPushButton::clicked, this, [this]() {
                // 这段逻辑来自 HomePage::on_pushButton_clicked()
                if (!UserManager::getInstance().isOperator()) {
                    QMessageBox::warning(this, tr("权限不足"), tr("只有操作员可以修改参数！"));
                    return;
                }
                auto* d = ShmManager::get_instance().get_data();
                if (!d) {
                    QMessageBox::warning(this, tr("未连接"), tr("未连接到共享内存，请先加载共享内存"));
                    return;
                }
                d->config.motor_config[MAIN_SPINDLE].running_speed = set_speed_input_->text().toDouble() / 1.08;
            });
        }

        // 中部：模式状态机 + PID 参数（左右两栏，尽量接近主页的块状排版）
        auto* mid = new QHBoxLayout();
        mid->setSpacing(16);
        {
            // 左侧：模式状态机 + PID
            auto* left = new QVBoxLayout();
            left->setSpacing(12);

            // 模式状态机
            {
                auto* box = new QGroupBox(QStringLiteral("模式状态机"), this);
                box->setStyleSheet("QGroupBox{font-weight:700;}");
                auto* l = new QHBoxLayout(box);
                mode_auto_btn_ = new QPushButton(QStringLiteral("自动"), box);
                mode_manual_btn_ = new QPushButton(QStringLiteral("手动"), box);
                mode_auto_btn_->setFixedHeight(40);
                mode_manual_btn_->setFixedHeight(40);
                l->addWidget(mode_auto_btn_);
                l->addWidget(mode_manual_btn_);

                connect(mode_auto_btn_, &QPushButton::clicked, this, [this]() {
                    if (!UserManager::getInstance().isOperator()) {
                        QMessageBox::warning(this, tr("权限不足"), tr("只有操作员可以操作！"));
                        return;
                    }
                    if (!push_mode_cmd(MODE_EVENT_AUTO)) {
                        return;
                    }
                    ElaMessageBar::success(ElaMessageBarType::Top, QStringLiteral("提示"),
                                           QStringLiteral("自动模式命令下发成功！"), 3000, this);
                });
                connect(mode_manual_btn_, &QPushButton::clicked, this, [this]() {
                    if (!UserManager::getInstance().isOperator()) {
                        QMessageBox::warning(this, tr("权限不足"), tr("只有操作员可以操作！"));
                        return;
                    }
                    if (!push_mode_cmd(MODE_EVENT_MANUAL)) {
                        return;
                    }
                    ElaMessageBar::success(ElaMessageBarType::Top, QStringLiteral("提示"),
                                           QStringLiteral("手动模式命令下发成功！"), 3000, this);
                });

                left->addWidget(box);
            }

            // PID 参数区：用网格对齐
            auto add_pid_row = [&](QGridLayout* g, int row, const QString& title,
                                   QLineEdit*& kp, QLineEdit*& ki, QLineEdit*& kd, QPushButton*& btn,
                                   std::function<void()> on_commit) {
                auto* t = new QLabel(title, this);
                t->setStyleSheet("font-weight:600; font-size:16px;");
                kp = new QLineEdit(this);
                ki = new QLineEdit(this);
                kd = new QLineEdit(this);
                for (auto* e : {kp, ki, kd}) {
                    e->setFixedHeight(28);
                    e->setPlaceholderText("0");
                }
                btn = new QPushButton(QStringLiteral("确定"), this);
                btn->setFixedHeight(28);
                connect(btn, &QPushButton::clicked, this, [this, on_commit]() {
                    if (!UserManager::getInstance().isOperator()) {
                        QMessageBox::warning(this, tr("权限不足"), tr("只有操作员可以修改参数！"));
                        return;
                    }
                    if (!ShmManager::get_instance().get_data()) {
                        QMessageBox::warning(this, tr("未连接"), tr("未连接到共享内存，请先加载共享内存"));
                        return;
                    }
                    on_commit();
                });

                g->addWidget(t, row, 0);
                g->addWidget(kp, row, 1);
                g->addWidget(ki, row, 2);
                g->addWidget(kd, row, 3);
                g->addWidget(btn, row, 4);
            };

            {
                auto* box = new QGroupBox(QStringLiteral("PID 参数"), this);
                box->setStyleSheet("QGroupBox{font-weight:700;}");
                auto* g = new QGridLayout(box);
                g->setHorizontalSpacing(8);
                g->setVerticalSpacing(10);
                g->setColumnStretch(1, 1);
                g->setColumnStretch(2, 1);
                g->setColumnStretch(3, 1);

                add_pid_row(g, 0, QStringLiteral("撑杆退PID参数:"), rod_ret_kp_, rod_ret_ki_, rod_ret_kd_, rod_ret_confirm_, [this]() {
                    PID pid_data = ShmManager::get_instance().get_data()->pid;
                    pid_data.Kp_Rod_retreat = rod_ret_kp_->text().toDouble();
                    pid_data.Ki_Rod_retreat = rod_ret_ki_->text().toDouble();
                    pid_data.Kd_Rod_retreat = rod_ret_kd_->text().toDouble();
                    ShmManager::get_instance().get_data()->pid = pid_data;
                });

                add_pid_row(g, 1, QStringLiteral("撑杆进PID参数:"), rod_adv_kp_, rod_adv_ki_, rod_adv_kd_, rod_adv_confirm_, [this]() {
                    PID pid_data = ShmManager::get_instance().get_data()->pid;
                    pid_data.Kp_Rod_advance = rod_adv_kp_->text().toDouble();
                    pid_data.Ki_Rod_advance = rod_adv_ki_->text().toDouble();
                    pid_data.Kd_Rod_advance = rod_adv_kd_->text().toDouble();
                    ShmManager::get_instance().get_data()->pid = pid_data;
                });

                add_pid_row(g, 2, QStringLiteral("中穿进PID参数:"), center_adv_kp_, center_adv_ki_, center_adv_kd_, center_adv_confirm_, [this]() {
                    PID pid_data = ShmManager::get_instance().get_data()->pid;
                    pid_data.Kp_center_advance = center_adv_kp_->text().toDouble();
                    pid_data.Ki_center_advance = center_adv_ki_->text().toDouble();
                    pid_data.Kd_center_advance = center_adv_kd_->text().toDouble();
                    ShmManager::get_instance().get_data()->pid = pid_data;
                });

                add_pid_row(g, 3, QStringLiteral("边穿进PID参数:"), edge_adv_kp_, edge_adv_ki_, edge_adv_kd_, edge_adv_confirm_, [this]() {
                    // 复用主页的“PID参数”三个字段（Kp/Ki/Kd）作为边穿进的示例
                    // 如果后端后续给出更明确字段，请在这里替换为对应的 pid_data.xxx
                    PID pid_data = ShmManager::get_instance().get_data()->pid;
                    pid_data.Kp = edge_adv_kp_->text().toDouble();
                    pid_data.Ki = edge_adv_ki_->text().toDouble();
                    pid_data.Kd = edge_adv_kd_->text().toDouble();
                    ShmManager::get_instance().get_data()->pid = pid_data;
                });

                left->addWidget(box);
            }

            left->addStretch();
            mid->addLayout(left, 3);
        }

        {
            // 右侧：大小头设置
            auto* right = new QVBoxLayout();
            right->setSpacing(12);

            auto* box = new QGroupBox(QStringLiteral("大小头设置"), this);
            box->setStyleSheet("QGroupBox{font-weight:700;}");
            auto* g = new QGridLayout(box);
            g->setHorizontalSpacing(10);
            g->setVerticalSpacing(10);

            auto add_display_row = [&](int row, const QString& k, QLabel*& v) {
                auto* key = new QLabel(k, box);
                key->setStyleSheet("font-weight:600; font-size:16px;");
                v = new QLabel("--", box);
                v->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
                g->addWidget(key, row, 0);
                g->addWidget(v, row, 1);
            };

            add_display_row(0, QStringLiteral("上限位:"), upper_limit_value_);
            add_display_row(1, QStringLiteral("下限位:"), lower_limit_value_);

            auto add_modify_row = [&](int row, const QString& k, QLineEdit*& input, QPushButton*& btn, std::function<void()> on_commit) {
                auto* key = new QLabel(k, box);
                key->setStyleSheet("font-weight:600; font-size:16px;");
                input = new QLineEdit(box);
                input->setFixedHeight(28);
                btn = new QPushButton(QStringLiteral("确定"), box);
                btn->setFixedHeight(28);
                connect(btn, &QPushButton::clicked, this, [this, on_commit]() {
                    if (!UserManager::getInstance().isOperator()) {
                        QMessageBox::warning(this, tr("权限不足"), tr("只有操作员可以修改参数！"));
                        return;
                    }
                    if (!ShmManager::get_instance().get_data()) {
                        QMessageBox::warning(this, tr("未连接"), tr("未连接到共享内存，请先加载共享内存"));
                        return;
                    }
                    on_commit();
                });
                g->addWidget(key, row, 0);
                g->addWidget(input, row, 1);
                g->addWidget(btn, row, 2);
            };

            // 注意：这里完全复用主页逻辑（乘以 8388608 并叠加当前显示值）
            // 若后端后续明确单位/比例，请在此处统一修正。
            add_modify_row(2, QStringLiteral("上限位修改:"), upper_limit_modify_, upper_limit_confirm_, [this]() {
                auto* d = ShmManager::get_instance().get_data();
                d->feedback.wheel_fdb.start_length_ref =
                    upper_limit_modify_->text().toDouble() * 8388608 + upper_limit_value_->text().toDouble() * 8388608;
            });
            add_modify_row(3, QStringLiteral("下限位修改:"), lower_limit_modify_, lower_limit_confirm_, [this]() {
                auto* d = ShmManager::get_instance().get_data();
                d->feedback.wheel_fdb.finish_length_ref =
                    lower_limit_modify_->text().toDouble() * 8388608 + lower_limit_value_->text().toDouble() * 8388608;
            });

            right->addWidget(box);
            right->addStretch();
            mid->addLayout(right, 2);
        }

        root->addLayout(mid, 1);
    }

    void init_refresh() {
        refresh_timer_ = new QTimer(this);
        connect(refresh_timer_, &QTimer::timeout, this, [this]() {
            auto* d = ShmManager::get_instance().get_data();
            if (!d) return;

            // 实际速度
            actual_speed_value_->setText(QString::number(d->feedback.motor_fdb[MAIN_SPINDLE].running_speed));

            // 上/下限位显示（和主页一致：除以 8388608）
            const double upper = d->feedback.wheel_fdb.start_length_ref / 8388608.0;
            const double lower = d->feedback.wheel_fdb.finish_length_ref / 8388608.0;
            upper_limit_value_->setText(QString::number(upper));
            lower_limit_value_->setText(QString::number(lower));

            update_enabled_state();
        });
    }

    void update_enabled_state() {
        const bool isOperator = UserManager::getInstance().isOperator();
        // MSVC 对 `{ ... }` 这种混合派生指针的自动推导比较挑剔，
        // 这里显式用 `QWidget*` 数组来做统一类型，避免推导失败。
        QWidget* widgets[] = {
            set_speed_input_,
            set_speed_confirm_,
            mode_auto_btn_,
            mode_manual_btn_,
            rod_ret_kp_,
            rod_ret_ki_,
            rod_ret_kd_,
            rod_ret_confirm_,
            rod_adv_kp_,
            rod_adv_ki_,
            rod_adv_kd_,
            rod_adv_confirm_,
            center_adv_kp_,
            center_adv_ki_,
            center_adv_kd_,
            center_adv_confirm_,
            edge_adv_kp_,
            edge_adv_ki_,
            edge_adv_kd_,
            edge_adv_confirm_,
            upper_limit_modify_,
            upper_limit_confirm_,
            lower_limit_modify_,
            lower_limit_confirm_,
        };

        for (QWidget* w : widgets) {
            if (w) w->setEnabled(isOperator);
        }
    }
};

