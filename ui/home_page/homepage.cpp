#include "homepage.h"
#include "ui_homepage.h"

#include "../../src/util/shm_manager.hpp"


HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomePage)
    , buffer(nullptr) // 初始化环形缓冲区
{
    ui->setupUi(this);

    connect(&ShmManager::get_instance(), &ShmManager::loaded, [this](bool success) {
        if (success) {
            buffer.set_buffer(&ShmManager::get_instance().get_data()->buffer_P);
        }
    });
}

HomePage::~HomePage()
{
    delete ui;
}


// 运行
void HomePage::on_pushButton_14_clicked()
{
    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD,
        .main_fsm_event_type =   MAIN_EVENT_CONTROL_ON,        
    });

    qDebug() << "运行按钮";
}

