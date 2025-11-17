#pragma once

#include <qjsonarray.h>
#include <qlogging.h>
#include <qwidget.h>
#ifdef max
#undef max
#endif
#ifdef min
#undef min
#endif

#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStackedWidget>
#include <QTextStream>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include <QWindow>
#include <QDebug>

#include "../src/util/db_writer.hpp"
#include "../src/util/ring_buffer.hpp"
#include "../src/util/shm_manager.hpp"
#include "ElaComboBox.h"
#include "ElaLineEdit.h"
#include "ElaMessageBar.h"
#include "ElaPivot.h"
#include "ElaPushButton.h"
#include "ElaText.h"
#include "ElaToggleButton.h"
#include "webview/webview.h"

inline constexpr int sampling_time = 50;

REGISTER_AUTO_KEY(MotorData, data_id)
YLT_REFL(MotorData, data_id, motor_id, running_speed, acceleration, position, follow_ratio, encoder_resolution_counter,
         create_at)

//注册自增主键
REGISTER_AUTO_KEY(ATM_LOG_DATA, data_id)
YLT_REFL(ATM_LOG_DATA, data_id, spindle_speed, torsion_speed, ATM_sensor, filter_data, required_speed, bias, winding_length, dead_zone, goat, tension, create_at)

class ChartPage : public QWidget {
    Q_OBJECT

public:
    ChartPage(QWidget *parent = nullptr);
    ~ChartPage();

private:
    void _init_content();

    QStackedWidget *stack_;
    ElaPivot *pivot_;

    QWidget *container_smmp_widget_{};
    std::unique_ptr<webview::webview> smmp_webview_;
    QWidget *chart_smmp_widget_{};
    QJsonArray smmp_datas_;

    QWidget *container_mmsp_widget_{};
    std::unique_ptr<webview::webview> mmsp_webview_;
    QWidget *chart_mmsp_widget_{};
    QJsonArray mmsp_datas_;

    QWidget *container_other_widget_{};
    std::unique_ptr<webview::webview> other_webview_;
    QWidget *chart_other_widget_{};
    QJsonArray other_datas_;
    
    QWidget *container_test_widget_{};
    std::unique_ptr<webview::webview> test_webview_;
    QWidget *chart_test_widget_{};
    QJsonArray test_datas_;

    // atm
    QWidget *container_atm_widget_{};
    std::unique_ptr<webview::webview> atm_webview_;
    QWidget *chart_atm_widget_{};
    QJsonArray atm_datas_;

    std::optional<DBWriter<MotorData>> db_writer_;
    std::optional<DBWriter<ATM_LOG_DATA>> db_atm_writer_;

    RingBuffer<Datas> datas_{nullptr};
    //ATM_Datas
    RingBuffer<ATM_Datas> atm_buff_datas_{nullptr};

};

inline ChartPage::ChartPage(QWidget *parent)
    : QWidget(parent),
      stack_(new QStackedWidget(this)),
      pivot_(new ElaPivot(this)),

      container_smmp_widget_(new QWidget()),
      smmp_webview_(std::make_unique<webview::webview>(true, reinterpret_cast<HWND>(container_smmp_widget_->winId()))),
      chart_smmp_widget_{QWidget::createWindowContainer(
          QWindow::fromWinId(reinterpret_cast<WId>(reinterpret_cast<HWND>(smmp_webview_->widget().value()))),
          container_smmp_widget_)},

      container_mmsp_widget_(new QWidget()),
      mmsp_webview_(std::make_unique<webview::webview>(true, reinterpret_cast<HWND>(container_mmsp_widget_->winId()))),
      chart_mmsp_widget_{QWidget::createWindowContainer(
          QWindow::fromWinId(reinterpret_cast<WId>(reinterpret_cast<HWND>(mmsp_webview_->widget().value()))),
          container_mmsp_widget_)},

      container_other_widget_(new QWidget()),
      other_webview_(
          std::make_unique<webview::webview>(true, reinterpret_cast<HWND>(container_other_widget_->winId()))),
      chart_other_widget_{QWidget::createWindowContainer(
          QWindow::fromWinId(reinterpret_cast<WId>(reinterpret_cast<HWND>(other_webview_->widget().value()))),
          container_other_widget_)},
          container_atm_widget_(new QWidget()),
    atm_webview_(std::make_unique<webview::webview>(true, reinterpret_cast<HWND>(container_atm_widget_->winId()))),
    chart_atm_widget_{QWidget::createWindowContainer(
    QWindow::fromWinId(reinterpret_cast<WId>(reinterpret_cast<HWND>(atm_webview_->widget().value()))),
    container_atm_widget_)}
    // ,
    //           container_test_widget_(new QWidget()),
    //   test_webview_(
    //       std::make_unique<webview::webview>(true, reinterpret_cast<HWND>(container_test_widget_->winId()))),
    //   chart_test_widget_{QWidget::createWindowContainer(
    //       QWindow::fromWinId(reinterpret_cast<WId>(reinterpret_cast<HWND>(test_webview_->widget().value()))),
    //       container_test_widget_)}
          {
    this->_init_content();


    connect(&ShmManager::get_instance(), &ShmManager::loaded, [this](bool success) {
        if (success) {
            datas_.set_buffer(&ShmManager::get_instance().get_data()->datas);
            atm_buff_datas_.set_buffer(&ShmManager::get_instance().get_data()->atm_datas); 
        }
    });
}

inline ChartPage::~ChartPage() {
    delete container_smmp_widget_;
    delete container_mmsp_widget_;
    delete container_other_widget_;
    delete container_test_widget_;
}

inline void ChartPage::_init_content() {
    pivot_->appendPivot("单电机多参数");
    pivot_->appendPivot("多电机单参数");
    pivot_->appendPivot("性能监控");
    pivot_->appendPivot("ATM检测");
    pivot_->setPivotSpacing(8);
    pivot_->setCurrentIndex(0);
    connect(pivot_, &ElaPivot::pivotClicked, stack_, &QStackedWidget::setCurrentIndex);

    {
        auto *center_widget = new QWidget(this);
        auto *center_layout = new QVBoxLayout(center_widget);
        {
            auto *motor_type_layout = new QHBoxLayout();

            auto *motor_type_combo = new ElaComboBox(this);
            motor_type_combo->addItems(motortype2name.values());
            connect(motor_type_combo, &ElaComboBox::currentIndexChanged, [this](int) {
                smmp_webview_->eval("clearChartData()");
                smmp_datas_ = QJsonArray();
            });

            motor_type_layout->addStretch();
            motor_type_layout->addWidget(new ElaText("单电机多参数监控：", 16));
            motor_type_layout->addWidget(motor_type_combo);
            motor_type_layout->addStretch();

            smmp_webview_->set_virtual_hostname("charts", "./res");
            smmp_webview_->navigate("http://charts/single-motor-multi-param.html");

            auto *update_chart_timer = new QTimer(this);
            connect(update_chart_timer, &QTimer::timeout, [this, motor_type_combo]() {
                const static auto &data = ShmManager::get_instance().get_data()->feedback.motor_fdb;
                QJsonObject data_json;
                auto roundToTwoDecimals = [](double value) { return std::round(value * 100.0) / 100.0; };
                int motor_type = motor_type_combo->currentIndex();
                data_json["speed"] = roundToTwoDecimals(data[motor_type].running_speed);
                data_json["position"] = roundToTwoDecimals(data[motor_type].position);
                data_json["accel"] = roundToTwoDecimals(data[motor_type].acceleration);
                data_json["followRatio"] = roundToTwoDecimals(data[motor_type].follow_ratio);
                data_json["encoder"] = roundToTwoDecimals(data[motor_type].encoder_resolution_counter);

                smmp_datas_.append(data_json);

                if (smmp_datas_.size() > 1000 / sampling_time) {
                    QString data_str{QJsonDocument(smmp_datas_).toJson(QJsonDocument::Compact)};
                    smmp_webview_->eval("updateChartData(" + data_str.toStdString() + ");");
                    smmp_datas_ = QJsonArray();
                }
            });

            connect(&ShmManager::get_instance(), &ShmManager::loaded, [update_chart_timer, this](bool success) {
                if (success) {
                    update_chart_timer->start(sampling_time);
                } else {
                    update_chart_timer->stop();
                }
            });

            center_layout->addLayout(motor_type_layout);
            center_layout->addWidget(chart_smmp_widget_);
        }

        stack_->addWidget(center_widget);
    }

    {
        auto *center_widget = new QWidget(this);
        auto *center_layout = new QVBoxLayout(center_widget);
        {
            auto *motor_type_layout = new QHBoxLayout();

            auto *param_type_combo = new ElaComboBox(this);
            param_type_combo->addItems({"速度", "位置", "加速度", "跟随比率", "编码器分辨率计数器"});
            connect(param_type_combo, &ElaComboBox::currentIndexChanged, [this](int) {
                mmsp_webview_->eval("clearChartData()");
                mmsp_datas_ = QJsonArray();
            });

            motor_type_layout->addStretch();
            motor_type_layout->addWidget(new ElaText("多电机单参数监控：", 16));
            motor_type_layout->addWidget(param_type_combo);
            motor_type_layout->addStretch();

            mmsp_webview_->set_virtual_hostname("charts", "./res");
            mmsp_webview_->navigate("http://charts/multi-motor-single-param.html");

            auto *update_chart_timer = new QTimer(this);
            connect(update_chart_timer, &QTimer::timeout, [this, param_type_combo]() {
                const static auto &data = ShmManager::get_instance().get_data()->feedback.motor_fdb;
                QJsonObject data_json;
                QJsonArray motor_data;
                for (const auto &i : data) {
                    auto roundToTwoDecimals = [](double value) { return QString::number(value, 'f', 2).toDouble(); };
                    switch (param_type_combo->currentIndex()) {
                        case 0:
                            motor_data.append(roundToTwoDecimals(i.running_speed));
                            break;
                        case 1:
                            motor_data.append(roundToTwoDecimals(i.position));
                            break;
                        case 2:
                            motor_data.append(roundToTwoDecimals(i.acceleration));
                            break;
                        case 3:
                            motor_data.append(roundToTwoDecimals(i.follow_ratio));
                            break;
                        case 4:
                            motor_data.append(roundToTwoDecimals(i.encoder_resolution_counter));
                            break;
                        default:
                            break;
                    }
                }
                data_json["motorData"] = motor_data;
                mmsp_datas_.append(data_json);

                if (mmsp_datas_.size() > 1000 / sampling_time) {
                    QString data_str{QJsonDocument(mmsp_datas_).toJson(QJsonDocument::Compact)};
                    mmsp_webview_->eval("updateChartData(" + data_str.toStdString() + ");");
                    mmsp_datas_ = QJsonArray();
                }
            });
            connect(&ShmManager::get_instance(), &ShmManager::loaded, [update_chart_timer, this](bool success) {
                if (success) {
                    update_chart_timer->start(sampling_time);
                } else {
                    update_chart_timer->stop();
                }
            });

            center_layout->addLayout(motor_type_layout);
            center_layout->addWidget(chart_mmsp_widget_);
        }

        stack_->addWidget(center_widget);
    }

    {
        other_webview_->set_virtual_hostname("charts", "./res");
        other_webview_->navigate("http://charts/other-data.html");

        auto *update_chart_timer = new QTimer(this);
        connect(update_chart_timer, &QTimer::timeout, [this]() {
            const static auto &data = ShmManager::get_instance().get_data()->feedback;
            QJsonObject data_json;
            data_json["vibrationData"] = QJsonArray{data.tremors[0], data.tremors[1]};
            data_json["temperatureData"] =
                QJsonArray{data.temperature[0], data.temperature[1], data.temperature[2], data.temperature[3]};

            other_datas_.append(data_json);

            if (other_datas_.size() > 1000 / sampling_time) {
                QString data_str{QJsonDocument(other_datas_).toJson(QJsonDocument::Compact)};
                other_webview_->eval("updateChartData(" + data_str.toStdString() + ");");
                other_datas_ = QJsonArray();
            }
        });

        connect(&ShmManager::get_instance(), &ShmManager::loaded, [update_chart_timer, this](bool success) {
            if (success) {
                update_chart_timer->start(sampling_time);
            } else {
                update_chart_timer->stop();
            }
        });

        stack_->addWidget(chart_other_widget_);
    }

    {

         atm_webview_->set_virtual_hostname("charts", "./res");
        
         atm_webview_->navigate("http://charts/atm-data.html");

         auto *update_chart_timer = new QTimer(this);
        connect(update_chart_timer, &QTimer::timeout, [this]() {
            const static auto &atm_datas = ShmManager::get_instance().get_data()->atm_datas;
            QJsonObject data_json;


            data_json["atmData"] = QJsonArray{atm_datas.data[atm_datas.read_index].ATM_sensor,
                                            atm_datas.data[atm_datas.read_index].filter_data,
                                            atm_datas.data[atm_datas.read_index].goat,
                                            atm_datas.data[atm_datas.read_index].goat + atm_datas.data[atm_datas.read_index].dead_zone,
                                            atm_datas.data[atm_datas.read_index].goat - atm_datas.data[atm_datas.read_index].dead_zone
            };

            data_json["speedControlData"] = QJsonArray{
                atm_datas.data[atm_datas.read_index].torsion_speed,
                atm_datas.data[atm_datas.read_index].required_speed,
            };

            // qDebug() << "[实际ATM, ATM滤波值， 目标值， 死区上限， 死区下限]" << data_json;


            atm_datas_.append(data_json);

            if (atm_datas_.size() > 1000 / sampling_time) {
                QString data_str{QJsonDocument(atm_datas_).toJson(QJsonDocument::Compact)};
                atm_webview_->eval("updateChartData(" + data_str.toStdString() + ");");
                atm_datas_ = QJsonArray();
            }
        });

        connect(&ShmManager::get_instance(), &ShmManager::loaded, [update_chart_timer, this](bool success) {
            if (success) {
                update_chart_timer->start(sampling_time);
            } else {
                update_chart_timer->stop();
            }
        });

        stack_->addWidget(chart_atm_widget_);
    }

    
    auto *collect_btn = new ElaToggleButton("连接数据库", this);
    {
        collect_btn->setFixedWidth(128);
        collect_btn->move(1040, 12);

        auto *collect_timer = new QTimer(this);

        connect(collect_btn, &ElaToggleButton::toggled, [this, collect_btn, collect_timer](bool checked) {
            if (!db_writer_.has_value() && !db_atm_writer_.has_value()) {
                // 第一次点击：连接数据库

                // 创建文件夹
                QDir db_dir("db");
                if (!db_dir.exists()) {
                    db_dir.mkpath(".");
                }

                auto db_file_name = QString("db/twister_%1 .db").arg(QDateTime::currentDateTime().toString("yyyyMMdd"));

                // 电机数据库
                db_writer_.emplace(db_file_name.toStdString());

                // atm数据库
                 db_atm_writer_.emplace(db_file_name.toStdString());

                collect_btn->setText("采集数据");
                collect_btn->setIsToggled(false);  // 重置按钮状态


                // 设置定时器回调
                connect(collect_timer, &QTimer::timeout, [this]() {

                    // qDebug() << "采集数据 1";
                    auto datas = datas_.pop_all();
                    // qDebug() << "datas 数据长度" << datas.size();
                    auto atm_datas = atm_buff_datas_.pop_all();
                    // qDebug() << "atm_datas 数据长度" << atm_datas.size();
                    for (const auto &item : datas) {
                        // qDebug() << "进入datas循环";
                        db_writer_->push({
                            0,
                            item.motor_id,
                            item.running_speed,
                            item.acceleration,
                            item.position,
                            item.follow_ratio,
                            item.encoder_resolution_counter,
                            static_cast<size_t>(item.create_at)
                        });
                    }

                    for (const auto &item : atm_datas) {
                        // qDebug() << "进入atm_datas循环";

                        db_atm_writer_->push({
                            0,
                            item.spindle_speed,
                            item.torsion_speed,
                            item.ATM_sensor,
                            item.filter_data,
                            item.required_speed,
                            item.bias,
                            item.winding_length,
                            item.dead_zone,
                            item.goat,
                            item.tension,
                            static_cast<size_t>(item.create_at)
                        });
                    }
                });
            }  else {
                // 后续点击：控制数据采集
                if (checked) {
                    collect_btn->setText("数据采集中...");
                    // 时间间隔50ms
                    collect_timer->start(50);
                } else {
                    collect_btn->setText("采集数据");
                    collect_timer->stop();
                }
            }
        });
    }
 
    auto *pid_widget = new QWidget(this);
    auto *pid_layout = new QHBoxLayout(pid_widget);
    {
        auto *Kp_input = new ElaLineEdit(this);
        {
            Kp_input->setPlaceholderText("Kp");
            Kp_input->setFixedSize(100, 32);
        }

        auto *Ki_input = new ElaLineEdit(this);
        {
            Ki_input->setPlaceholderText("Ki");
            Ki_input->setFixedSize(100, 32);
        }

        auto *Kd_input = new ElaLineEdit(this);
        {
            Kd_input->setPlaceholderText("Kd");
            Kd_input->setFixedSize(100, 32);
        }

        auto *apply_btn = new ElaPushButton("应用PID", this);
        apply_btn->setFixedSize(80, 32);
        connect(apply_btn, &ElaPushButton::clicked, [this, Kp_input, Ki_input, Kd_input]() {
            double Kp = Kp_input->text().toDouble();
            double Ki = Ki_input->text().toDouble();
            double Kd = Kd_input->text().toDouble();

            static std::mutex lock;
            {
                std::lock_guard<std::mutex> guard(lock);
                ShmManager::get_instance().get_data()->pid = {Kp, Ki, Kd};
            }

            ElaMessageBar::success(ElaMessageBarType::Top, "提示", "PID参数修改成功！", 3000, this);
        });

        pid_layout->addWidget(Kp_input);
        pid_layout->addWidget(Ki_input);
        pid_layout->addWidget(Kd_input);
        pid_layout->addWidget(apply_btn);

        pid_widget->setFixedSize(420, 40);
        pid_widget->move(600, 4);
    }

    auto *main_layout = new QVBoxLayout();
    main_layout->addWidget(pivot_, 0);
    main_layout->addWidget(stack_);

    this->setLayout(main_layout);
}
