// #pragma once

// #include <Def.h>
// #include <QHeaderView>
// #include <QLabel>
// #include <QPixmap>
// #include <QVBoxLayout>

// #include "ElaStatusBar.h"
// #include "ElaWindow.h"
// #include "beside_pass/besidepass.h"
// #include "blanking/blanking.h"
// #include "chart_page.hpp"
// #include "config_page.hpp"
// #include "data_monitor_page.hpp"
// #include "main_flyer/mainflyer.h"
// #include "middle_circuit_breaker/middelcircuitbreaker.h"
// #include "param_page.hpp"
// // #include "form/form.h"
// #include "home_page/homepage.h"

// class MainWindow : public ElaWindow {
//     Q_OBJECT

// public:
//     MainWindow(QWidget *parent = nullptr);

//     ~MainWindow() = default;

// private:
//     void _setup_ui();
//     void _init_content();

//     DataMonitorPage *data_monitor_page_;
//     ChartPage *chart_page_;
//     ConfigPage *config_page_;
//     ParamPage *param_page_;

//     QString config_key_;
//     QString manual_key_;

//     ElaText *fsm_feb_text_;

//     std::mutex lock_;
// };

// inline MainWindow::MainWindow(QWidget *parent)
//     : ElaWindow(parent),
//       data_monitor_page_(new DataMonitorPage(this)),
//       chart_page_(new ChartPage(this)),
//       config_page_(new ConfigPage(this)),
//       param_page_(new ParamPage(this)),
//       config_key_("config"),
//       fsm_feb_text_(new ElaText("", 14)) {
//     this->_setup_ui();
//     this->_init_content();
//     this->showFullScreen();
// }

// inline void MainWindow::_setup_ui() {
//     this->setWindowTitle("Shm-Viewer");
//     this->setWindowIcon(QIcon(":/favicon.svg"));
//     this->setFixedSize(1200, 900);
//     this->setUserInfoCardVisible(false);
//     this->setNavigationBarWidth(0);
//     this->moveToCenter();
// }

// inline void MainWindow::_init_content() {
//     auto *status_bar = new ElaStatusBar(this);
//     {        
//         status_bar->addWidget(fsm_feb_text_, 99);
//         this->setStatusBar(status_bar);

//         auto *refresh = new QTimer(this);
//         connect(refresh, &QTimer::timeout, [this]() {
//             static FDB_DATA feb{};
//             {
//                 std::lock_guard<std::mutex> guard(lock_);
//                 feb = ShmManager::get_instance().get_data()->feedback;
//             }
//             auto &fsm = feb.fsm_fdb;
//             fsm_feb_text_->setText(QString("模式状态机：%1; 主状态机：%2;")
//                                        .arg(Enum2Str::to_string(fsm.mode), Enum2Str::to_string(fsm.main)));
//         });
//         connect(&ShmManager::get_instance(), &ShmManager::loaded, [refresh](bool success) {
//             if (success) {
//                 refresh->start(500);
//             } else {
//                 refresh->stop();
//             }
//         });
//     }

//     // this->addPageNode("test主页", new Form(this), ElaIconType::None);
//     this->addPageNode("电机主页", new HomePage(this), ElaIconType::House);
//     this->addExpanderNode("手动控制", manual_key_, ElaIconType::BookOpenCover);
//     {
//         this->addPageNode("主飞轮/虚捻/牵引手动", new MainFlyer(this), manual_key_, ElaIconType::None);
//         // this->addPageNode("上料站手动", new QWidget(this), manual_key_, ElaIconType::None);
//         this->addPageNode("中穿熔丝手动", new MiddelCircuitBreaker(this), manual_key_, ElaIconType::None);
//         this->addPageNode("边穿手动", new BesidePass(this), manual_key_, ElaIconType::None);
//         this->addPageNode("下料工字轮手动", new Blanking(this), manual_key_, ElaIconType::None);
//     }

//     this->addPageNode("参数调试", data_monitor_page_, 0, ElaIconType::ScrewdriverWrench);
//     this->addPageNode("数据监控", chart_page_, 0, ElaIconType::ChartMixed);
//     this->addPageNode("计米参数设置", param_page_, 0, ElaIconType::Ruler);

//     this->addFooterNode("配置管理", config_page_, config_key_, 0, ElaIconType::Gear);

//     this->navigation(config_key_);

//     ElaMessageBar::success(ElaMessageBarType::Top, "欢迎！", "请先加载共享内存", 3000, this);
// }



// main_window.hpp
#pragma once

#include <Def.h>
#include <QHeaderView>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QMessageBox>  // 添加此行以使用 QMessageBox
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include <mutex>


#include "ElaStatusBar.h"
#include "ElaWindow.h"
#include "ElaNavigationBar.h"
#include "beside_pass/besidepass.h"
#include "blanking/blanking.h"
#include "chart_page.hpp"
#include "config_page.hpp"
#include "warning_page.hpp"
#include "data_monitor_page.hpp"
#include "main_flyer/mainflyer.h"
#include "middle_circuit_breaker/middelcircuitbreaker.h"
#include "home_page/homepage.h"
#include "host_params_page.hpp"
#include "../src/util/user_role.h"

class MainWindow : public ElaWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow() = default;

private:
    void _setup_ui();
    void _init_content();
    void _sync_manual_controls_visibility();
    void _ensure_manual_nodes_added();
    void _remove_manual_nodes();

    DataMonitorPage *data_monitor_page_;
    ChartPage *chart_page_;
    ConfigPage *config_page_;
    WarningPage *warning_page_;
    HomePage *home_page_;

    // “手动控制”分组下的页面（便于动态显示/隐藏时复用）
    MainFlyer *main_flyer_{nullptr};
    MiddelCircuitBreaker *middle_cb_{nullptr};
    BesidePass *beside_pass_{nullptr};
    Blanking *blanking_{nullptr};
    HostParamsPage *host_params_{nullptr};
    bool manual_nodes_added_{false};


    QString config_key_;
    QString manual_key_;

    ElaText *fsm_feb_text_;

    // 添加急停按钮相关成员
    QPushButton *emergencyStopButton_;
    ElaNavigationBar* nav_bar_{nullptr};
    std::mutex lock_;

private slots:
    void onEmergencyStopClicked(); // 急停按钮点击槽函数

protected:
    void resizeEvent(QResizeEvent* event) override;
};

inline MainWindow::MainWindow(QWidget *parent)
    : ElaWindow(parent),
      data_monitor_page_(new DataMonitorPage(this)),
      chart_page_(new ChartPage(this)),
      config_page_(new ConfigPage(this)),
      warning_page_(new WarningPage(this)),
      home_page_(new HomePage(this)),
      config_key_("config"),
      manual_key_("manual"),
      fsm_feb_text_(new ElaText("", 14)) {
    this->_setup_ui();
    this->_init_content();
    this->showFullScreen();
}

inline void MainWindow::_setup_ui() {
    this->setWindowTitle("Shm-Viewer");
    this->setWindowIcon(QIcon(":/favicon.svg"));
    this->setFixedSize(1200, 900);
    this->setUserInfoCardVisible(false);
    this->setNavigationBarWidth(0);
    this->moveToCenter();
}

// 修改 _init_content() 方法中的相关代码
inline void MainWindow::_init_content() {
    auto *status_bar = new ElaStatusBar(this);
    {        
        status_bar->addWidget(fsm_feb_text_, 99);
        this->setStatusBar(status_bar);

        auto *refresh = new QTimer(this);
        connect(refresh, &QTimer::timeout, [this]() {
            static FDB_DATA feb{};
            {
                std::lock_guard<std::mutex> guard(lock_);
                feb = ShmManager::get_instance().get_data()->feedback;
            }
            auto &fsm = feb.fsm_fdb;
            fsm_feb_text_->setText(QString("模式状态机：%1; 主状态机：%2;")
                                       .arg(Enum2Str::to_string(fsm.mode), Enum2Str::to_string(fsm.main)));
        });
        connect(&ShmManager::get_instance(), &ShmManager::loaded, [refresh](bool success) {
            if (success) {
                refresh->start(500);
            } else {
                refresh->stop();
            }
        });
    }

    // 添加急停按钮
    emergencyStopButton_ = new QPushButton("急停", this);
    
    // 设置样式：红色背景、白色粗体文字、居中显示
    emergencyStopButton_->setStyleSheet(
        "background-color: red; "
        "color: white; "
        "font-size: 24px; "
        "font-weight: bold; "
        "border-radius: 8px; "
        "border: none;"
    );
    
    // 连接信号槽
    connect(emergencyStopButton_, &QPushButton::clicked, this, &MainWindow::onEmergencyStopClicked);

    // 添加其他页面节点
    this->addPageNode("电机主页", home_page_, ElaIconType::House);
    connect(home_page_, &HomePage::operatorModeChanged, this, [this](bool) {
        this->_sync_manual_controls_visibility();
    });
    connect(home_page_, &HomePage::mainRunStateForDbCollection, chart_page_,
            &ChartPage::setMainFsmDbCollection);
    this->_sync_manual_controls_visibility();

    this->addPageNode("参数调试", data_monitor_page_, 0, ElaIconType::ScrewdriverWrench);
    this->addPageNode("数据监控", chart_page_, 0, ElaIconType::ChartMixed);
    this->addPageNode("报警信息",warning_page_, 0, ElaIconType::Bell );

    // 添加配置管理节点
    this->addFooterNode("配置管理", config_page_, config_key_, 0, ElaIconType::Gear);

    this->navigation(config_key_);

    ElaMessageBar::success(ElaMessageBarType::Top, "欢迎！", "请先加载共享内存", 3000, this);

    // 把急停按钮放进侧边栏（不是节点），并定位到“配置管理”上方
    nav_bar_ = this->findChild<ElaNavigationBar*>();
    if (nav_bar_) {
        emergencyStopButton_->setParent(nav_bar_);
        emergencyStopButton_->raise();
        emergencyStopButton_->show();
        QTimer::singleShot(0, this, [this]() { this->resizeEvent(nullptr); });
    }
}

inline void MainWindow::_ensure_manual_nodes_added() {
    if (manual_nodes_added_) return;

    // 只有操作员才应该看到“手动控制”
    this->addExpanderNode("手动控制", manual_key_, ElaIconType::BookOpenCover);

    if (!host_params_) host_params_ = new HostParamsPage(this);
    if (!main_flyer_) main_flyer_ = new MainFlyer(this);
    if (!middle_cb_) middle_cb_ = new MiddelCircuitBreaker(this);
    if (!beside_pass_) beside_pass_ = new BesidePass(this);
    if (!blanking_) blanking_ = new Blanking(this);

    this->addPageNode("主机参数", host_params_, manual_key_, ElaIconType::None);
    this->addPageNode("主飞轮/虚捻/牵引手动", main_flyer_, manual_key_, ElaIconType::None);
    this->addPageNode("中穿熔丝手动", middle_cb_, manual_key_, ElaIconType::None);
    this->addPageNode("边穿手动", beside_pass_, manual_key_, ElaIconType::None);
    this->addPageNode("下料工字轮手动", blanking_, manual_key_, ElaIconType::None);

    manual_nodes_added_ = true;
}

inline void MainWindow::_remove_manual_nodes() {
    if (!manual_nodes_added_) return;
    this->removeNavigationNode(manual_key_);
    manual_nodes_added_ = false;
}

inline void MainWindow::_sync_manual_controls_visibility() {
    if (UserManager::getInstance().isOperator()) {
        _ensure_manual_nodes_added();
    } else {
        _remove_manual_nodes();
    }
}

inline void MainWindow::resizeEvent(QResizeEvent* event) {
    ElaWindow::resizeEvent(event);

    if (!nav_bar_ || !emergencyStopButton_) {
        return;
    }

    // 侧边栏内定位：底部留出“配置管理”一行的高度，再往上放急停按钮
    const int margin = 10;
    const int config_row_h = 56;  // 预留给“配置管理”那一行
    const int btn_h = 56;
    const int btn_w = qMax(120, nav_bar_->width() - margin * 2);
    const int x = margin;
    const int y = qMax(margin, nav_bar_->height() - config_row_h - btn_h - margin);

    emergencyStopButton_->setFixedSize(btn_w, btn_h);
    emergencyStopButton_->move(x, y);
}

// 实现急停按钮点击槽函数
inline void MainWindow::onEmergencyStopClicked()
{
    // 检查共享内存是否已加载
    if (ShmManager::get_instance().get_data() == nullptr) {
        QMessageBox::warning(this, "警告", "未连接到共享内存，请先加载共享内存");
        return;
    }
    
    // 发送急停命令
    COMMOND_GROUPS cmd;
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD;
    cmd.main_fsm_event_type = MAIN_EVENT_EME_STOP;
    
    try {
        // 使用共享内存中的 buffer_M 来发送命令
        RingBuffer<RINGBUFFER> command_buffer(&ShmManager::get_instance().get_data()->buffer_M);
        bool result = command_buffer.push(cmd);
        if (!result) {
            QMessageBox::warning(this, "警告", "命令缓冲区已满，无法发送急停命令");
            return;
        }
        qDebug() << "急停命令已发送";
        
        // 添加视觉反馈
        QMessageBox::information(this, "急停", "急停命令已发送");
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "错误", QString("无法发送急停命令: %1").arg(e.what()));
    }
}