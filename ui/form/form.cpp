#include "form.h"
#include "ui_form.h"
#include <qdatetime.h>
#include <qdebug.h>
#include <qlogging.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <QTimer>
#include <winsock.h>

#include "../../src/util/shm_manager.hpp"


// 构造函数
Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
    // ,buffer(&ShmManager::get_instance().get_data()->buffer_P)
    , buffer(nullptr)
{
    ui->setupUi(this);

    connect(&ShmManager::get_instance(), &ShmManager::loaded, [this](bool success) {
        if (success) {
            buffer.set_buffer(&ShmManager::get_instance().get_data()->buffer_M);
            // buffer_p_.set_buffer(&ShmManager::get_instance().get_data()->buffer_P);
        }
    });

    // // 不点击按钮，在页面之直接显示
    // // 在构造函数中写
    // auto data = ShmManager::get_instance().get_data()-> feedback.temperature[0];
    // ui->lineEdit_2->setText(QString::number(data));

    // ui->lineEdit_3->setText(QString::number(666));

    // // 设置红绿告警灯
    // auto timer = new QTimer(this);
    // connect(timer, &QTimer::timeout, this, [this](){
    //     // test_data.feedback.temperature[0] = rand() % 100; // 模拟数据更新
    //     auto data = ShmManager::get_instance().get_data() -> feedback.temperature[0];
    //     if(data < 50) {
    //         ui->label->setStyleSheet("background-color: red;border-radius: 16px;");
    //         ui->label_2->setStyleSheet("background-color: green;border-radius: 16px;");
    //     }
    //     else {
    //         ui->label->setStyleSheet("background-color: green;border-radius: 16px;");
    //         ui->label_2->setStyleSheet("background-color: red;border-radius: 16px;");
    //     }
    // });
    // timer->start(500);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{

}

// void Form::on_pushButton_2_clicked()
// {
//     buffer.push({
//         .cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD,
//         .main_fsm_event_type = xxxx
//     });
// }


// 宏定义
#define FUN(btn, main_type) \
void Form::on_##btn##_clicked(){ \
    buffer.push({   \
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD, \
        .main_fsm_event_type = main_type \
    }); \
}

// 在form.h中的槽private slots，声明点击函数
FUN(pushButton_2, MAIN_EVENT_NONE)
FUN(pushButton_3, MAIN_EVENT_INIT)
FUN(pushButton_4, MAIN_EVENT_NONE)
FUN(pushButton_5, MAIN_EVENT_NONE)


// 文本框+按钮  写+虚拟内存
void Form::on_pushButton_11_clicked()
{
    auto test = ui->lineEdit->text().toInt();
    qDebug() << "text中的数据" << test;

    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MODE_CMD,
        .mode_fsm_event_type = (MODE_FSM_EVENT_TYPE)test
    });
    qDebug() << "发送text数据到共享内存中" <<  test;
}



// 文本框+按钮  读+虚拟内存
// 读数据都是从feedback中读取
void Form::on_pushButton_12_clicked()
{
    auto data = ShmManager::get_instance().get_data() -> feedback.temperature[0];
    qDebug() << "feedback中的数据" << data;
    //lineEdit_2是  文本栏的变量名称
    ui->lineEdit_2->setText(QString::number(data));
    qDebug() <<  "发送到text中" << data;
}




// 点击按钮变色

//存进数据库

//配置文件

// 联调常见问题
// 1 共享内存版本问题  -- 同步版本
// 2 写入配置问题 --  代码问题