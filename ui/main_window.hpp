#pragma once

#include <Def.h>
#include <QHeaderView>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>

#include "ElaStatusBar.h"
#include "ElaWindow.h"
#include "chart_page.hpp"
#include "config_page.hpp"
#include "data_monitor_page.hpp"
#include "param_page.hpp"
#include "form/form.h"
#include "home_page/homepage.h"

class MainWindow : public ElaWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow() = default;

private:
    void _setup_ui();
    void _init_content();

    DataMonitorPage *data_monitor_page_;
    ChartPage *chart_page_;
    ConfigPage *config_page_;
    ParamPage *param_page_;

    QString config_key_;

    ElaText *fsm_feb_text_;

    std::mutex lock_;
};

inline MainWindow::MainWindow(QWidget *parent)
    : ElaWindow(parent),
      data_monitor_page_(new DataMonitorPage(this)),
      chart_page_(new ChartPage(this)),
      config_page_(new ConfigPage(this)),
      param_page_(new ParamPage(this)),
      config_key_("config"),
      fsm_feb_text_(new ElaText("", 14)) {
    this->_setup_ui();
    this->_init_content();
}

inline void MainWindow::_setup_ui() {
    this->setWindowTitle("Shm-Viewer");
    this->setWindowIcon(QIcon(":/favicon.svg"));
    this->setFixedSize(1200, 900);
    this->setUserInfoCardVisible(false);
    this->setNavigationBarWidth(0);
    this->moveToCenter();
}

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

    this->addPageNode("test主页", new Form(this), ElaIconType::None);
    this->addPageNode("电机主页", new HomePage(this), ElaIconType::House);
    this->addPageNode("参数调试", data_monitor_page_, 0, ElaIconType::ScrewdriverWrench);
    this->addPageNode("数据监控", chart_page_, 0, ElaIconType::ChartMixed);
    this->addPageNode("参数设置", param_page_, 0, ElaIconType::Ruler);

    this->addFooterNode("配置管理", config_page_, config_key_, 0, ElaIconType::Gear);

    this->navigation(config_key_);

    ElaMessageBar::success(ElaMessageBarType::Top, "欢迎！", "请先加载共享内存", 3000, this);
}
