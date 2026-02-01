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
#include <limits> 
#include <algorithm> 

#include "../src/util/db_writer.hpp"
#include "../src/util/ring_buffer.hpp"
#include "../src/util/shm_manager.hpp"
#include "../src/util/ring_buffer.hpp"
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

    RingBuffer<RINGBUFFER> buffer_p_;  
    RingBuffer<RINGBUFFER> buffer_m_;  


    // 平均值显示控件（双行：文字+大号数字）
    ElaText* main_axis_avg_label_{nullptr};   // 主轴平均值文字标签
    ElaText* main_axis_avg_value_{nullptr};   // 主轴平均值数字
    ElaText* traction_avg_label_{nullptr};    // 牵引平均值文字标签
    ElaText* traction_avg_value_{nullptr};    // 牵引平均值数字


    int sampling_time_{10};
};

inline ChartPage::ChartPage(QWidget *parent)
    : QWidget(parent),
      stack_(new QStackedWidget(this)),
      pivot_(new ElaPivot(this)),
       buffer_p_(nullptr), 
      buffer_m_(nullptr),

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
            buffer_p_.set_buffer(&ShmManager::get_instance().get_data()->buffer_P);
            buffer_m_.set_buffer(&ShmManager::get_instance().get_data()->buffer_M);
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
    // pivot_->appendPivot("多电机单参数");
    pivot_->appendPivot("捻距检测");
    pivot_->appendPivot("ATM检测");
    pivot_->appendPivot("震动温度检测");
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

    // {
    //     auto *center_widget = new QWidget(this);
    //     auto *center_layout = new QVBoxLayout(center_widget);
    //     {
    //         auto *motor_type_layout = new QHBoxLayout();
    //         auto *param_type_combo = new ElaComboBox(this);
    //         param_type_combo->addItems({"速度", "位置", "加速度", "跟随比率", "编码器分辨率计数器"});
    //         connect(param_type_combo, &ElaComboBox::currentIndexChanged, [this](int) {
    //             mmsp_webview_->eval("clearChartData()");
    //             mmsp_datas_ = QJsonArray();
    //         });
    //         motor_type_layout->addStretch();
    //         motor_type_layout->addWidget(new ElaText("多电机单参数监控：", 16));
    //         motor_type_layout->addWidget(param_type_combo);
    //         motor_type_layout->addStretch();
    //         mmsp_webview_->set_virtual_hostname("charts", "./res");
    //         mmsp_webview_->navigate("http://charts/multi-motor-single-param.html");
    //         auto *update_chart_timer = new QTimer(this);
    //         connect(update_chart_timer, &QTimer::timeout, [this, param_type_combo]() {
    //             const static auto &data = ShmManager::get_instance().get_data()->feedback.motor_fdb;
    //             QJsonObject data_json;
    //             QJsonArray motor_data;
    //             for (const auto &i : data) {
    //                 auto roundToTwoDecimals = [](double value) { return QString::number(value, 'f', 2).toDouble(); };
    //                 switch (param_type_combo->currentIndex()) {
    //                     case 0:
    //                         motor_data.append(roundToTwoDecimals(i.running_speed));
    //                         break;
    //                     case 1:
    //                         motor_data.append(roundToTwoDecimals(i.position));
    //                         break;
    //                     case 2:
    //                         motor_data.append(roundToTwoDecimals(i.acceleration));
    //                         break;
    //                     case 3:
    //                         motor_data.append(roundToTwoDecimals(i.follow_ratio));
    //                         break;
    //                     case 4:
    //                         motor_data.append(roundToTwoDecimals(i.encoder_resolution_counter));
    //                         break;
    //                     default:
    //                         break;
    //                 }
    //             }
    //             data_json["motorData"] = motor_data;
    //             mmsp_datas_.append(data_json);
    //             if (mmsp_datas_.size() > 1000 / sampling_time) {
    //                 QString data_str{QJsonDocument(mmsp_datas_).toJson(QJsonDocument::Compact)};
    //                 mmsp_webview_->eval("updateChartData(" + data_str.toStdString() + ");");
    //                 mmsp_datas_ = QJsonArray();
    //             }
    //         });
    //         connect(&ShmManager::get_instance(), &ShmManager::loaded, [update_chart_timer, this](bool success) {
    //             if (success) {
    //                 update_chart_timer->start(sampling_time);
    //             } else {
    //                 update_chart_timer->stop();
    //             }
    //         });
    //         center_layout->addLayout(motor_type_layout);
    //         center_layout->addWidget(chart_mmsp_widget_);
    //     }
    //     stack_->addWidget(center_widget);
    // }


// ========== 捻距检测页面（参照单电机多参数修改，横坐标连续） ==========
// ========== 捻距检测页面（修复后：横坐标连续） ==========
{
    auto *center_widget = new QWidget(this);
    auto *center_layout = new QVBoxLayout(center_widget);
    center_layout->setContentsMargins(10, 10, 10, 10);
    center_layout->setSpacing(10);
    
    {
        auto *motor_type_layout = new QHBoxLayout();
        auto *param_type_combo = new ElaComboBox(this);
        param_type_combo->addItems({"速度", "位置", "加速度", "跟随比率", "编码器分辨率计数器"});
       
        // 下拉框切换：清空图表+重置平均值（和单电机逻辑一致）
        connect(param_type_combo, &ElaComboBox::currentIndexChanged, [this](int) {
            mmsp_webview_->eval("clearChartData()");
            mmsp_datas_ = QJsonArray(); // 清空数据缓存
            if (main_axis_avg_value_) main_axis_avg_value_->setText("--");
            if (traction_avg_value_) traction_avg_value_->setText("--");
        });

        motor_type_layout->addStretch();
        motor_type_layout->addWidget(new ElaText("捻距检测：", 16));
        motor_type_layout->addWidget(param_type_combo);
        motor_type_layout->addStretch();

        // 加载图表页面（和单电机逻辑一致）
        mmsp_webview_->set_virtual_hostname("charts", "./res");
        mmsp_webview_->navigate("http://charts/multi-motor-single-param.html");

        // 定时器：更新数据（修复核心逻辑，保证横坐标连续）
        auto *update_chart_timer = new QTimer(this);
        connect(update_chart_timer, &QTimer::timeout, [this, param_type_combo]() {
            const static auto &data = ShmManager::get_instance().get_data()->feedback.motor_fdb;
            QJsonObject data_json; // 单数据点对象
            QJsonArray motor_data;

            // ========== 核心修复1：索引越界不中断，改为默认值兜底 ==========
            // 原逻辑：越界直接return，丢失当前周期数据 → 新逻辑：兜底默认值，保证数据连续
            const int main_spindle_idx = MAIN_SPINDLE;          // 主轴索引：1
            const int main_drawing_idx = MAIN_DRAWING;          // 牵引索引：2
            
            double main_spindle_value = 0.0;
            double main_drawing_value = 0.0;

            // 防越界检查：不return，而是给默认值
            if (main_spindle_idx < MAX_MOTOR_TYPE_NUM && main_drawing_idx < MAX_MOTOR_TYPE_NUM) {
                // 工具函数：保留2位小数（和单电机逻辑一致）
                auto roundToTwoDecimals = [](double value) { 
                    return std::round(value * 100.0) / 100.0; 
                };

                // 1. 提取主轴（索引1）数据
                switch (param_type_combo->currentIndex()) {
                    case 0: main_spindle_value = roundToTwoDecimals(data[main_spindle_idx].running_speed); break;
                    case 1: main_spindle_value = roundToTwoDecimals(data[main_spindle_idx].position); break;
                    case 2: main_spindle_value = roundToTwoDecimals(data[main_spindle_idx].acceleration); break;
                    case 3: main_spindle_value = roundToTwoDecimals(data[main_spindle_idx].follow_ratio); break;
                    case 4: main_spindle_value = roundToTwoDecimals(data[main_spindle_idx].encoder_resolution_counter); break;
                    default: main_spindle_value = 0.0;
                }

                // 2. 提取牵引（索引2）数据
                switch (param_type_combo->currentIndex()) {
                    case 0: main_drawing_value = roundToTwoDecimals(data[main_drawing_idx].running_speed); break;
                    case 1: main_drawing_value = roundToTwoDecimals(data[main_drawing_idx].position); break;
                    case 2: main_drawing_value = roundToTwoDecimals(data[main_drawing_idx].acceleration); break;
                    case 3: main_drawing_value = roundToTwoDecimals(data[main_drawing_idx].follow_ratio); break;
                    case 4: main_drawing_value = roundToTwoDecimals(data[main_drawing_idx].encoder_resolution_counter); break;
                    default: main_drawing_value = 0.0;
                }
            } else {
                qWarning() << "电机索引越界！主轴索引：" << main_spindle_idx << " 牵引索引：" << main_drawing_idx;
                main_spindle_value = 0.0;
                main_drawing_value = 0.0; // 兜底默认值，不中断数据生成
            }
            
            motor_data.append(main_spindle_value);
            motor_data.append(main_drawing_value);
            
            // ========== 核心修复2：添加毫秒级时间戳，支撑前端连续时间轴 ==========
            // 前端可基于该时间戳渲染连续横坐标，而非仅靠数据点索引
            data_json["timestamp"] = QDateTime::currentMSecsSinceEpoch();
            data_json["motorData"] = motor_data;
            mmsp_datas_.append(data_json);

            // ========== 核心修复3：平均值计算移除continue，补全默认值 ==========
            // 原逻辑：continue过滤数据 → 新逻辑：补0兜底，保证计数完整
            double main_axis_sum = 0.0, traction_sum = 0.0;
            int count = 0;
            const int target_count = 20;
            int start_idx = qMax(0, mmsp_datas_.size() - target_count);

            for (int i = start_idx; i < mmsp_datas_.size(); ++i) {
                QJsonObject item = mmsp_datas_[i].toObject();
                QJsonArray motor_arr = item.contains("motorData") ? item["motorData"].toArray() : QJsonArray();
                
                // 补全默认值，不跳过任何数据项
                double main_val = (motor_arr.size() >= 1) ? motor_arr[0].toDouble() : 0.0;
                double traction_val = (motor_arr.size() >= 2) ? motor_arr[1].toDouble() : 0.0;
                
                main_axis_sum += main_val;
                traction_sum += traction_val;
                count++; // 每个数据项都计数，保证平均值计算连续
            }

            // 计算平均值（保留2位小数）
            double main_axis_avg = 0.0, traction_avg = 0.0;
            if (count > 0) {
                main_axis_avg = QString::number(main_axis_sum / count, 'f', 2).toDouble();
                traction_avg = QString::number(traction_sum / count, 'f', 2).toDouble();
            }

            // 更新双行显示（增加空指针判断，避免崩溃）
            if (main_axis_avg_value_) {
                main_axis_avg_value_->setText(QString::number(main_axis_avg, 'f', 2));
            }
            if (traction_avg_value_) {
                traction_avg_value_->setText(QString::number(traction_avg, 'f', 2));
            }

            // ========== 核心修复4：优化批量发送条件，增加超时兜底 ==========
            // 原逻辑：仅靠整数除法判断 → 新逻辑：固定缓存大小+超时兜底，保证发送时机稳定
            const int CACHE_MAX_SIZE = 20; // 固定缓存20条（对应sampling_time=50ms，1秒发送一次）
            static int cache_timeout_count = 0;
            cache_timeout_count++;

            if (mmsp_datas_.size() >= CACHE_MAX_SIZE || cache_timeout_count >= (1000 / sampling_time)) { 
                QString data_str = QJsonDocument(mmsp_datas_).toJson(QJsonDocument::Compact);
                mmsp_webview_->eval("updateChartData(" + data_str.toStdString() + ");");
                mmsp_datas_ = QJsonArray(); // 清空缓存
                cache_timeout_count = 0; // 重置超时计数器
            }
        });

        // ========== 核心修复5：增加定时器重启逻辑，避免偶发中断 ==========
        // 监听共享内存加载状态
        connect(&ShmManager::get_instance(), &ShmManager::loaded, [this, update_chart_timer](bool success) {
            if (success) {
                update_chart_timer->start(sampling_time); // 统一用全局sampling_time（50ms）
            } else {
                update_chart_timer->stop();
                // 重置显示为--（增加空指针判断）
                if (main_axis_avg_value_) main_axis_avg_value_->setText("--");
                if (traction_avg_value_) traction_avg_value_->setText("--");
            }
        });

        // // 额外保障：定时检查共享内存状态，自动重启定时器（防止信号丢失）
        // auto *watchdog_timer = new QTimer(this);
        // connect(watchdog_timer, &QTimer::timeout, [this, update_chart_timer]() {
        //     if (ShmManager::get_instance().is_loaded() && !update_chart_timer->isActive()) {
        //         update_chart_timer->start(sampling_time);
        //     }
        // });
        // watchdog_timer->start(1000); // 1秒检查一次

        // ========== 图表+统计栏布局（双行显示样式不变） ==========
        auto *chart_stats_layout = new QHBoxLayout();
        
        // 图表区域（左侧85%）
        chart_mmsp_widget_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        chart_stats_layout->addWidget(chart_mmsp_widget_, 85);
        
        // 统计栏（右侧15%：双行显示平均值）
        {
            auto *stats_widget = new QWidget();
            auto *stats_layout = new QVBoxLayout(stats_widget);
            stats_layout->setContentsMargins(10, 10, 10, 10);
            stats_layout->setSpacing(15);
            stats_widget->setStyleSheet(R"(
                background-color: #f5f5f5; 
                border: 1px solid #ddd; 
                border-radius: 4px;
            )");
            stats_widget->setMinimumWidth(140);

            // 主轴平均值区域（双行）
            auto *main_axis_widget = new QWidget();
            auto *main_axis_layout = new QVBoxLayout(main_axis_widget);
            main_axis_layout->setContentsMargins(0, 0, 0, 0);
            main_axis_layout->setSpacing(2);

            main_axis_avg_label_ = new ElaText("主轴平均值", 10);
            main_axis_avg_label_->setAlignment(Qt::AlignCenter);
            main_axis_layout->addWidget(main_axis_avg_label_);

            main_axis_avg_value_ = new ElaText("--", 16);
            main_axis_avg_value_->setAlignment(Qt::AlignCenter);
            main_axis_avg_value_->setStyleSheet("color: #2196F3; font-weight: bold;");
            main_axis_layout->addWidget(main_axis_avg_value_);

            stats_layout->addWidget(main_axis_widget);

            // 牵引平均值区域（双行）
            auto *traction_widget = new QWidget();
            auto *traction_layout = new QVBoxLayout(traction_widget);
            traction_layout->setContentsMargins(0, 0, 0, 0);
            traction_layout->setSpacing(2);

            traction_avg_label_ = new ElaText("牵引平均值", 10);
            traction_avg_label_->setAlignment(Qt::AlignCenter);
            traction_layout->addWidget(traction_avg_label_);

            traction_avg_value_ = new ElaText("--", 16);
            traction_avg_value_->setAlignment(Qt::AlignCenter);
            traction_avg_value_->setStyleSheet("color: #4CAF50; font-weight: bold;");
            traction_layout->addWidget(traction_avg_value_);

            stats_layout->addWidget(traction_widget);

            chart_stats_layout->addWidget(stats_widget, 15);
        }

        center_layout->addLayout(motor_type_layout);
        center_layout->addLayout(chart_stats_layout);
    }

    stack_->addWidget(center_widget);
}


// // ========== 以下是界面逻辑代码 ==========
// {
//     {
//     auto *center_widget = new QWidget(this);
//     auto *center_layout = new QVBoxLayout(center_widget);
//     center_layout->setContentsMargins(10, 10, 10, 10);
//     center_layout->setSpacing(10);
    
//     {
//         auto *motor_type_layout = new QHBoxLayout();
//         auto *param_type_combo = new ElaComboBox(this);
//         param_type_combo->addItems({"速度", "位置", "加速度", "跟随比率", "编码器分辨率计数器"});
       
//         // 下拉框切换：清空图表+重置平均值
//         connect(param_type_combo, &ElaComboBox::currentIndexChanged, [this](int) {
//             mmsp_webview_->eval("clearChartData()");
//             mmsp_datas_ = QJsonArray();
//             main_axis_avg_value_->setText("--");
//             traction_avg_value_->setText("--");
//         });

//         motor_type_layout->addStretch();
//         motor_type_layout->addWidget(new ElaText("捻距检测：", 16));
//         motor_type_layout->addWidget(param_type_combo);
//         motor_type_layout->addStretch();

//         // 加载图表页面
//         mmsp_webview_->set_virtual_hostname("charts", "./res");
//         mmsp_webview_->navigate("http://charts/multi-motor-single-param.html");

//         // 定时器：更新数据+计算正确的平均值
//         auto *update_chart_timer = new QTimer(this);
//         connect(update_chart_timer, &QTimer::timeout, [this, param_type_combo]() {
//             const static auto &data = ShmManager::get_instance().get_data()->feedback.motor_fdb;
//             QJsonObject data_json;
//             QJsonArray motor_data;

//             // ========== 核心修正：使用枚举值获取正确电机数据 ==========
//             // 定义正确的电机索引（从枚举来，避免硬编码）
//             const int main_spindle_idx = MAIN_SPINDLE;          // 主轴索引：1
//             const int main_drawing_idx = MAIN_DRAWING;          // 牵引索引：2
            
//             // 防越界检查：确保索引在有效范围内
//             if (main_spindle_idx >= MAX_MOTOR_TYPE_NUM || main_drawing_idx >= MAX_MOTOR_TYPE_NUM) {
//                 qWarning() << "电机索引越界！主轴索引：" << main_spindle_idx << " 牵引索引：" << main_drawing_idx;
//                 return;
//             }

//             // 工具函数：保留2位小数
//             auto roundToTwoDecimals = [](double value) { 
//                 return QString::number(value, 'f', 2).toDouble(); 
//             };

//             // 1. 提取主轴（索引1）数据
//             double main_spindle_value = 0.0;
//             switch (param_type_combo->currentIndex()) {
//                 case 0: main_spindle_value = roundToTwoDecimals(data[main_spindle_idx].running_speed); break;
//                 case 1: main_spindle_value = roundToTwoDecimals(data[main_spindle_idx].position); break;
//                 case 2: main_spindle_value = roundToTwoDecimals(data[main_spindle_idx].acceleration); break;
//                 case 3: main_spindle_value = roundToTwoDecimals(data[main_spindle_idx].follow_ratio); break;
//                 case 4: main_spindle_value = roundToTwoDecimals(data[main_spindle_idx].encoder_resolution_counter); break;
//                 default: main_spindle_value = 0.0;
//             }
//             motor_data.append(main_spindle_value);

//             // 2. 提取牵引（索引2）数据
//             double main_drawing_value = 0.0;
//             switch (param_type_combo->currentIndex()) {
//                 case 0: main_drawing_value = roundToTwoDecimals(data[main_drawing_idx].running_speed); break;
//                 case 1: main_drawing_value = roundToTwoDecimals(data[main_drawing_idx].position); break;
//                 case 2: main_drawing_value = roundToTwoDecimals(data[main_drawing_idx].acceleration); break;
//                 case 3: main_drawing_value = roundToTwoDecimals(data[main_drawing_idx].follow_ratio); break;
//                 case 4: main_drawing_value = roundToTwoDecimals(data[main_drawing_idx].encoder_resolution_counter); break;
//                 default: main_drawing_value = 0.0;
//             }
//             motor_data.append(main_drawing_value);
            
//             // 3. 缓存数据到mmsp_datas_
//             data_json["motorData"] = motor_data;
//             mmsp_datas_.append(data_json);

//             // ========== 计算最新10条数据的平均值（基于正确索引） ==========
//             double main_axis_sum = 0.0, traction_sum = 0.0;
//             int count = 0;
//             const int target_count = 10;
//             int start_idx = qMax(0, mmsp_datas_.size() - target_count);

//             for (int i = start_idx; i < mmsp_datas_.size(); ++i) {
//                 QJsonObject item = mmsp_datas_[i].toObject();
//                 if (!item.contains("motorData")) continue;
                
//                 QJsonArray motor_arr = item["motorData"].toArray();
//                 if (motor_arr.size() < 2) continue; // 确保包含主轴+牵引数据
                
//                 // 累加正确的数值：motor_arr[0]=主轴(索引1)、motor_arr[1]=牵引(索引2)
//                 main_axis_sum += motor_arr[0].toDouble();
//                 traction_sum += motor_arr[1].toDouble();
//                 count++;
//             }

//             // 计算平均值（保留2位小数）
//             double main_axis_avg = 0.0, traction_avg = 0.0;
//             if (count > 0) {
//                 main_axis_avg = QString::number(main_axis_sum / count, 'f', 2).toDouble();
//                 traction_avg = QString::number(traction_sum / count, 'f', 2).toDouble();
//             }

//             // ========== 更新双行显示（数字大号突出） ==========
//             main_axis_avg_value_->setText(QString::number(main_axis_avg, 'f', 2));
//             traction_avg_value_->setText(QString::number(traction_avg, 'f', 2));

//             // 4. 批量更新图表
//             if (mmsp_datas_.size() > 1000 / sampling_time_) {
//                 QString data_str = QJsonDocument(mmsp_datas_).toJson(QJsonDocument::Compact);
//                 mmsp_webview_->eval("updateChartData(" + data_str.toStdString() + ");");
//                 mmsp_datas_ = QJsonArray();
//             }
//         });

//         // 共享内存状态监听
//         connect(&ShmManager::get_instance(), &ShmManager::loaded, [this, update_chart_timer](bool success) {
//             if (success) {
//                 update_chart_timer->start(sampling_time_);
//             } else {
//                 update_chart_timer->stop();
//                 // 重置显示为--
//                 main_axis_avg_value_->setText("--");
//                 traction_avg_value_->setText("--");
//             }
//         });

//         // ========== 图表+统计栏布局（双行显示样式不变） ==========
//         auto *chart_stats_layout = new QHBoxLayout();
        
//         // 图表区域（左侧85%）
//         chart_mmsp_widget_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//         chart_stats_layout->addWidget(chart_mmsp_widget_, 85);
        
//         // 统计栏（右侧15%：双行显示平均值）
//         {
//             auto *stats_widget = new QWidget();
//             auto *stats_layout = new QVBoxLayout(stats_widget);
//             stats_layout->setContentsMargins(10, 10, 10, 10);
//             stats_layout->setSpacing(15);
//             stats_widget->setStyleSheet(R"(
//                 background-color: #f5f5f5; 
//                 border: 1px solid #ddd; 
//                 border-radius: 4px;
//             )");
//             stats_widget->setMinimumWidth(140);

//             // 主轴平均值区域（双行）
//             auto *main_axis_widget = new QWidget();
//             auto *main_axis_layout = new QVBoxLayout(main_axis_widget);
//             main_axis_layout->setContentsMargins(0, 0, 0, 0);
//             main_axis_layout->setSpacing(2);

//             main_axis_avg_label_ = new ElaText("主轴平均值", 10);
//             main_axis_avg_label_->setAlignment(Qt::AlignCenter);
//             main_axis_layout->addWidget(main_axis_avg_label_);

//             main_axis_avg_value_ = new ElaText("--", 16);
//             main_axis_avg_value_->setAlignment(Qt::AlignCenter);
//             main_axis_avg_value_->setStyleSheet("color: #2196F3; font-weight: bold;");
//             main_axis_layout->addWidget(main_axis_avg_value_);

//             stats_layout->addWidget(main_axis_widget);

//             // 牵引平均值区域（双行）
//             auto *traction_widget = new QWidget();
//             auto *traction_layout = new QVBoxLayout(traction_widget);
//             traction_layout->setContentsMargins(0, 0, 0, 0);
//             traction_layout->setSpacing(2);

//             traction_avg_label_ = new ElaText("牵引平均值", 10);
//             traction_avg_label_->setAlignment(Qt::AlignCenter);
//             traction_layout->addWidget(traction_avg_label_);

//             traction_avg_value_ = new ElaText("--", 16);
//             traction_avg_value_->setAlignment(Qt::AlignCenter);
//             traction_avg_value_->setStyleSheet("color: #4CAF50; font-weight: bold;");
//             traction_layout->addWidget(traction_avg_value_);

//             stats_layout->addWidget(traction_widget);

//             chart_stats_layout->addWidget(stats_widget, 15);
//         }

//         center_layout->addLayout(motor_type_layout);
//         center_layout->addLayout(chart_stats_layout);
//     }

//     stack_->addWidget(center_widget);
// }
// }
// {
//     auto *center_widget = new QWidget(this);
//     auto *center_layout = new QVBoxLayout(center_widget);
    
//     {
//         auto *motor_type_layout = new QHBoxLayout();

//         auto *param_type_combo = new ElaComboBox(this);
//         param_type_combo->addItems({"速度", "位置", "加速度", "跟随比率", "编码器分辨率计数器"});
       
//         connect(param_type_combo, &ElaComboBox::currentIndexChanged, [this](int) {
//             mmsp_webview_->eval("clearChartData()");
//             mmsp_datas_ = QJsonArray();
//         });

//         motor_type_layout->addStretch();
//         motor_type_layout->addWidget(new ElaText("捻距检测：", 16));
//         motor_type_layout->addWidget(param_type_combo);
//         motor_type_layout->addStretch();

//         mmsp_webview_->set_virtual_hostname("charts", "./res");
//         mmsp_webview_->navigate("http://charts/multi-motor-single-param.html");

//         auto *update_chart_timer = new QTimer(this);
//         connect(update_chart_timer, &QTimer::timeout, [this, param_type_combo]() {
//             const static auto &data = ShmManager::get_instance().get_data()->feedback.motor_fdb;
//             QJsonObject data_json;
//             QJsonArray motor_data;

//             // 1. 采集主轴/牵引电机数据（原有逻辑）
//             for (int i = 1; i < 3; ++i) { // 只循环前两个电机
//                 auto roundToTwoDecimals = [](double value) { return QString::number(value, 'f', 2).toDouble(); };
//                 switch (param_type_combo->currentIndex()) {
//                     case 0:
//                         motor_data.append(roundToTwoDecimals(data[i].running_speed));
//                         break;
//                     case 1:
//                         motor_data.append(roundToTwoDecimals(data[i].position));
//                         break;
//                     case 2:
//                         motor_data.append(roundToTwoDecimals(data[i].acceleration));
//                         break;
//                     case 3:
//                         motor_data.append(roundToTwoDecimals(data[i].follow_ratio));
//                         break;
//                     case 4:
//                         motor_data.append(roundToTwoDecimals(data[i].encoder_resolution_counter));
//                         break;
//                     default:
//                         break;
//                 }
//             }
            
//             // 2. 缓存数据到mmsp_datas_（原有逻辑）
//             data_json["motorData"] = motor_data;
//             mmsp_datas_.append(data_json);

//             // ========== 核心：计算最新10条数据的平均值 ==========
//             double main_axis_sum = 0.0;    // 主轴数值累加
//             double traction_sum = 0.0;    // 牵引数值累加
//             int count = 0;                // 实际参与计算的数据条数
//             const int target_count = 10;  // 取最新10条数据

//             // 确定起始索引（不足10条则取全部）
//             int start_idx = qMax(0, mmsp_datas_.size() - target_count);

//             // 遍历最新数据累加
//             for (int i = start_idx; i < mmsp_datas_.size(); ++i) {
//                 QJsonObject item = mmsp_datas_[i].toObject();
//                 if (!item.contains("motorData")) continue; // 跳过无效数据
                
//                 QJsonArray motor_arr = item["motorData"].toArray();
//                 if (motor_arr.size() < 2) continue; // 确保包含主轴+牵引数据
                
//                 main_axis_sum += motor_arr[0].toDouble();
//                 traction_sum += motor_arr[1].toDouble();
//                 count++;
//             }

//             // 计算平均值（避免除以0，保留2位小数）
//             double main_axis_avg = 0.0;
//             double traction_avg = 0.0;
//             if (count > 0) {
//                 main_axis_avg = QString::number(main_axis_sum / count, 'f', 2).toDouble();
//                 traction_avg = QString::number(traction_sum / count, 'f', 2).toDouble();
//             }

//             // ========== 关键：更新统计栏的平均值/最小值显示 ==========
//             // 更新主轴平均值
//             main_axis_avg_text_->setText(QString("主轴平均值: %1").arg(main_axis_avg, 0, 'f', 2));
//             // 主轴最小值暂显示为--（若有最小值计算逻辑可替换）
//             main_axis_min_text_->setText("主轴最小值: --");
//             // 更新牵引平均值
//             traction_axis_avg_text_->setText(QString("牵引平均值: %1").arg(traction_avg, 0, 'f', 2));
//             // 牵引最小值暂显示为--（若有最小值计算逻辑可替换）
//             traction_axis_min_text_->setText("牵引最小值: --");

//             // 3. 批量更新图表（原有逻辑）
//             if (mmsp_datas_.size() > 1000 / sampling_time) {
//                 QString data_str{QJsonDocument(mmsp_datas_).toJson(QJsonDocument::Compact)};
//                 mmsp_webview_->eval("updateChartData(" + data_str.toStdString() + ");");
//                 mmsp_datas_ = QJsonArray();
//             }
//         });

//         connect(&ShmManager::get_instance(), &ShmManager::loaded, [update_chart_timer, this](bool success) {
//             if (success) {
//                 update_chart_timer->start(sampling_time);
//             } else {
//                 update_chart_timer->stop();
//                 // 停止定时器后，重置统计栏显示
//                 main_axis_avg_text_->setText("主轴平均值: --");
//                 main_axis_min_text_->setText("主轴最小值: --");
//                 traction_axis_avg_text_->setText("牵引平均值: --");
//                 traction_axis_min_text_->setText("牵引最小值: --");
//             }
//         });

//         // ========== 图表+统计栏布局（修改为显示平均值） ==========
//         auto *chart_stats_layout = new QHBoxLayout();
        
//         // 图表组件（左侧85%）
//         chart_mmsp_widget_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//         chart_stats_layout->addWidget(chart_mmsp_widget_, 85);
        
//         // 统计栏（右侧15%）
//         {
//             auto *stats_widget = new QWidget();
//             auto *stats_layout = new QVBoxLayout(stats_widget);
//             stats_layout->setContentsMargins(5, 5, 5, 5); 
//             stats_layout->setSpacing(5); 
            
//             // 主轴统计区域（平均值+最小值）
//             auto *main_axis_stats = new QWidget();
//             auto *main_axis_layout = new QVBoxLayout(main_axis_stats);
//             main_axis_layout->setSpacing(2);
            
//             // 主轴平均值文本（保存指针到类成员）
//             main_axis_avg_text_ = new ElaText("主轴平均值: --", 10);
//             main_axis_layout->addWidget(main_axis_avg_text_);
//             // 主轴最小值文本（保存指针到类成员）
//             main_axis_min_text_ = new ElaText("主轴最小值: --", 10);
//             main_axis_layout->addWidget(main_axis_min_text_);
//             stats_layout->addWidget(main_axis_stats);
            
//             // 牵引统计区域（平均值+最小值）
//             auto *traction_stats = new QWidget();
//             auto *traction_layout = new QVBoxLayout(traction_stats);
//             traction_layout->setSpacing(2);
            
//             // 牵引平均值文本（保存指针到类成员）
//             traction_axis_avg_text_ = new ElaText("牵引平均值: --", 10);
//             traction_layout->addWidget(traction_axis_avg_text_);
//             // 牵引最小值文本（保存指针到类成员）
//             traction_axis_min_text_ = new ElaText("牵引最小值: --", 10);
//             traction_layout->addWidget(traction_axis_min_text_);
//             stats_layout->addWidget(traction_stats);
            
//             // 统计栏样式
//             stats_widget->setStyleSheet("background-color: #f5f5f5; border: 1px solid #ddd; padding: 5px;");
//             stats_widget->setMinimumWidth(120); // 加宽适配平均值显示
//             chart_stats_layout->addWidget(stats_widget, 15);
//         }

//         // 组装布局
//         center_layout->addLayout(motor_type_layout);
//         center_layout->addLayout(chart_stats_layout);
//     }

//     stack_->addWidget(center_widget);
// }
// 修改后的捻距检测页面代码段
// {
//     auto *center_widget = new QWidget(this);
//     auto *center_layout = new QVBoxLayout(center_widget);
    
//     {
//         auto *motor_type_layout = new QHBoxLayout();

//         auto *param_type_combo = new ElaComboBox(this);
//         param_type_combo->addItems({"速度", "位置", "加速度", "跟随比率", "编码器分辨率计数器"});
       
//         connect(param_type_combo, &ElaComboBox::currentIndexChanged, [this](int) {
//             mmsp_webview_->eval("clearChartData()");
//             mmsp_datas_ = QJsonArray();
//         });

//         motor_type_layout->addStretch();
//         motor_type_layout->addWidget(new ElaText("捻距检测：", 16));
//         motor_type_layout->addWidget(param_type_combo);
//         motor_type_layout->addStretch();

//         mmsp_webview_->set_virtual_hostname("charts", "./res");
//         mmsp_webview_->navigate("http://charts/multi-motor-single-param.html");

//         auto *update_chart_timer = new QTimer(this);
//         connect(update_chart_timer, &QTimer::timeout, [this, param_type_combo]() {
//             const static auto &data = ShmManager::get_instance().get_data()->feedback.motor_fdb;
//             QJsonObject data_json;
//             QJsonArray motor_data;

//             // 只选择主轴和牵引电机的数据（索引0和1）
//             for (int i = 0; i < 2; ++i) { // 只循环前两个电机
//                 auto roundToTwoDecimals = [](double value) { return QString::number(value, 'f', 2).toDouble(); };
//                 switch (param_type_combo->currentIndex()) {
//                     case 0:
//                         motor_data.append(roundToTwoDecimals(data[i].running_speed));
//                         break;
//                     case 1:
//                         motor_data.append(roundToTwoDecimals(data[i].position));
//                         break;
//                     case 2:
//                         motor_data.append(roundToTwoDecimals(data[i].acceleration));
//                         break;
//                     case 3:
//                         motor_data.append(roundToTwoDecimals(data[i].follow_ratio));
//                         break;
//                     case 4:
//                         motor_data.append(roundToTwoDecimals(data[i].encoder_resolution_counter));
//                         break;
//                     default:
//                         break;
//                 }
//             }
            
//             data_json["motorData"] = motor_data;
//             mmsp_datas_.append(data_json);



//                         // ========== 新增：计算最新10个数据的平均数 ==========
//             // 1. 定义变量：累加值、计数、平均数
//             double main_axis_sum = 0.0;    // 主轴数值累加
//             double traction_sum = 0.0;    // 牵引数值累加
//             int count = 0;                // 实际参与计算的数据条数
//             const int target_count = 10;  // 目标取最新10条

//             // 2. 确定起始索引：取最后10条（不足10条则取全部）
//             int start_idx = qMax(0, mmsp_datas_.size() - target_count);

//             // 3. 遍历最新的10条数据，累加主轴/牵引数值
//             for (int i = start_idx; i < mmsp_datas_.size(); ++i) {
//                 QJsonObject item = mmsp_datas_[i].toObject();
//                 if (!item.contains("motorData")) continue; // 跳过无效数据
                
//                 QJsonArray motor_arr = item["motorData"].toArray();
//                 if (motor_arr.size() < 2) continue; // 确保包含主轴+牵引数据
                
//                 main_axis_sum += motor_arr[0].toDouble();
//                 traction_sum += motor_arr[1].toDouble();
//                 count++;
//             }

//             // 4. 计算平均数（避免除以0）
//             double main_axis_avg = 0.0;
//             double traction_avg = 0.0;
//             if (count > 0) {
//                 main_axis_avg = main_axis_sum / count;
//                 traction_avg = traction_sum / count;
//                 // 保留2位小数（和原始数据格式一致）
//                 main_axis_avg = QString::number(main_axis_avg, 'f', 2).toDouble();
//                 traction_avg = QString::number(traction_avg, 'f', 2).toDouble();
//             }

//             // 【可选】打印平均数（调试用），也可赋值给文本控件显示
//             qDebug() << "最新" << count << "条数据平均数：";
//             qDebug() << "主轴平均数：" << main_axis_avg;
//             qDebug() << "牵引平均数：" << traction_avg;


//             if (mmsp_datas_.size() > 1000 / sampling_time) {
//                 QString data_str{QJsonDocument(mmsp_datas_).toJson(QJsonDocument::Compact)};
//                 mmsp_webview_->eval("updateChartData(" + data_str.toStdString() + ");");
//                 mmsp_datas_ = QJsonArray();
//             }
//         });

//         connect(&ShmManager::get_instance(), &ShmManager::loaded, [update_chart_timer, this](bool success) {
//             if (success) {
//                 update_chart_timer->start(sampling_time);
//             } else {
//                 update_chart_timer->stop();
//             }
//         });

//         // ========== 关键修改1：调整图表和统计栏的占比，突出图表 ==========
//         auto *chart_stats_layout = new QHBoxLayout();
        
//         // 图表组件（左侧，占85%宽度，原70%）
//         chart_mmsp_widget_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//         chart_stats_layout->addWidget(chart_mmsp_widget_, 85); // 提高图表占比到85%
        
//         // 添加统计信息显示区域（右侧，占15%宽度，原30%）
//         {
//             auto *stats_widget = new QWidget();
//             auto *stats_layout = new QVBoxLayout(stats_widget);
//             // 关键修改2：减小统计栏内边距，从10px改为5px，让整体更紧凑
//             stats_layout->setContentsMargins(5, 5, 5, 5); 
//             stats_layout->setSpacing(5); // 减小控件之间的间距
            
//             // 主轴统计信息
//             auto *main_axis_stats = new QWidget();
//             auto *main_axis_layout = new QVBoxLayout(main_axis_stats);
//             main_axis_layout->setSpacing(2); // 进一步缩小内部间距
//             // 关键修改3：缩小字体大小，从12px改为10px
//             main_axis_layout->addWidget(new ElaText("主轴最大值:", 10));
//             main_axis_layout->addWidget(new ElaText("主轴最小值:", 10));
//             stats_layout->addWidget(main_axis_stats);
            
//             // 牵引统计信息
//             auto *traction_stats = new QWidget();
//             auto *traction_layout = new QVBoxLayout(traction_stats);
//             traction_layout->setSpacing(2); // 进一步缩小内部间距
//             // 关键修改4：缩小字体大小，从12px改为10px
//             traction_layout->addWidget(new ElaText("牵引最大值:", 10));
//             traction_layout->addWidget(new ElaText("牵引最小值:", 10));
//             stats_layout->addWidget(traction_stats);
            
//             // 设置样式：减小内边距，保持基础样式
//             stats_widget->setStyleSheet("background-color: #f5f5f5; border: 1px solid #ddd; padding: 5px;");
//             // 关键修改5：设置统计栏最小宽度，避免过窄导致文字挤压
//             stats_widget->setMinimumWidth(100); 
            
//             // 统计组件放到水平布局右侧（占15%）
//             chart_stats_layout->addWidget(stats_widget, 15); // 降低统计栏占比到15%
//         }

//         // 垂直布局：先加参数选择栏，再加「图表+统计」水平布局
//         center_layout->addLayout(motor_type_layout);
//         center_layout->addLayout(chart_stats_layout); // 替换原来的addWidget(chart_mmsp_widget_)
//     }

//     stack_->addWidget(center_widget);
// }


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


  // ... existing code ...
    {
        auto *center_widget = new QWidget(this);
        auto *center_layout = new QVBoxLayout(center_widget);
        
        // 其他数据监控部分 (占70%)
        {
            other_webview_->set_virtual_hostname("charts", "./res");
            other_webview_->navigate("http://charts/other-data.html");

            auto *update_chart_timer_other = new QTimer(this);
            connect(update_chart_timer_other, &QTimer::timeout, [this]() {
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

            connect(&ShmManager::get_instance(), &ShmManager::loaded, [update_chart_timer_other, this](bool success) {
                if (success) {
                    update_chart_timer_other->start(sampling_time);
                } else {
                    update_chart_timer_other->stop();
                }
            });

            chart_other_widget_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            center_layout->addWidget(chart_other_widget_, 70); // 70%占比
        }

        stack_->addWidget(center_widget);
    }

    // 多电机单参数监控部分 (独立函数)
    auto createMultiMotorSingleParamSection = [this]() {
        auto *param_layout = new QHBoxLayout();

        auto *param_type_combo = new ElaComboBox(this);
        param_type_combo->addItems({"速度", "位置", "加速度", "跟随比率", "编码器分辨率计数器"});
       
        connect(param_type_combo, &ElaComboBox::currentIndexChanged, [this]() {
            mmsp_webview_->eval("clearChartData()");
            mmsp_datas_ = QJsonArray();
        });


        param_layout->addStretch();
        param_layout->addWidget(new ElaText("多电机单参数监控：", 16));
        param_layout->addWidget(param_type_combo);
        param_layout->addStretch();

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

        chart_mmsp_widget_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        
        auto *container_widget = new QWidget();
        auto *container_layout = new QVBoxLayout(container_widget);
        container_layout->addLayout(param_layout);
        container_layout->addWidget(chart_mmsp_widget_, 30); // 30%占比
        
        return container_widget;
    };

    
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


     // 添加停止电机按钮
    auto *stop_motor_btn = new ElaPushButton("停止电机", this);
    {
        stop_motor_btn->setFixedWidth(128);
        stop_motor_btn->move(1200, 12);
        
        connect(stop_motor_btn, &ElaPushButton::clicked, [this]() {
            COMMOND_GROUPS cmd;
            cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD;
            cmd.motor_manual_control = {
                MOTOR_MANUAL_CONTROL::STOP,
                static_cast<MOTOR_TYPE>(0),
                0.0,
                0.0,
                0.0
            };
            
            // 发送命令到两个缓冲区
        buffer_p_.push(cmd);
        buffer_m_.push(cmd);
            
            ElaMessageBar::success(ElaMessageBarType::Top, "提示", "停止命令已发送！", 3000, this);
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
