#include "homepage.h"
#include "ui_homepage.h"

#include <QDebug>
#include <QTimer>
#include <cstdlib>
#include <qlogging.h>
#include <qtimer.h>
#include <winsock.h>

#include "../../src/util/shm_manager.hpp"

HomePage::HomePage(QWidget *parent)
    : QWidget(parent), ui(new Ui::HomePage), buffer(nullptr) // 初始化环形缓冲区
{
  ui->setupUi(this);


          // 主轴速度读取
          auto timer = new QTimer(this);
          connect(timer, &QTimer::timeout, this, [this]() {
            // // 模拟数据更新
            // auto data = rand() % 100;

            auto data = ShmManager::get_instance()
                            .get_data()
                            ->feedback.motor_fdb[MAIN_SPINDLE]
                            .running_speed;
            ui->label_5->setText(QString::number(data));
          });

  connect(
      &ShmManager::get_instance(), &ShmManager::loaded, [this, timer](bool success) {

        if (success) {
          buffer.set_buffer(&ShmManager::get_instance().get_data()->buffer_P);

          timer->start(200);
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


void HomePage::on_lineEdit_editingFinished()
{

    auto test = ui->lineEdit->text().toInt();
    qDebug() << "text中的数据" << test;
    
}


// 停止
void HomePage::on_pushButton_13_clicked()
{
    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD,
        .main_fsm_event_type =   MAIN_EVENT_CONTROL_OFF,        
    });

    qDebug() << "停止按钮";
}


// 急停
void HomePage::on_pushButton_15_clicked()
{
    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD,
        .main_fsm_event_type =   MAIN_EVENT_EME_STOP,        
    });

    qDebug() << "急停按钮";
}


// 急停清除
void HomePage::on_pushButton_16_clicked()
{
    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD,
        .main_fsm_event_type =   MAIN_EVENT_EME_STOP_CLEAR,        
    });

    qDebug() << "急停清除按钮";
}



// 错误
void HomePage::on_pushButton_9_clicked()
{
    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD,
        .main_fsm_event_type =   MAIN_EVENT_ERROR,        
    });

    qDebug() << "错误按钮";
}


// 错误复位
void HomePage::on_pushButton_10_clicked()
{
    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD,
        .main_fsm_event_type =   MAIN_EVENT_ERROR_RESET,        
    });

    qDebug() << "错误复位按钮";
}


// 上电
void HomePage::on_pushButton_11_clicked()
{
    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD,
        .main_fsm_event_type =   MAIN_EVENT_MOTOR_ON,        
    });

    qDebug() << "上电按钮";
}


// 下电
void HomePage::on_pushButton_12_clicked()
{
    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD,
        .main_fsm_event_type =   MAIN_EVENT_MOTOR_OFF,        
    });

    qDebug() << "下电按钮";
  }


// 自动
void HomePage::on_pushButton_17_clicked()
{
    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MODE_CMD,
        .mode_fsm_event_type = MODE_EVENT_AUTO,        
    });

    qDebug() << "自动按钮";
}

// 手动
void HomePage::on_pushButton_18_clicked()
{
    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MODE_CMD,
        .mode_fsm_event_type = MODE_EVENT_MANUAL,        
    });

    qDebug() << "手动按钮";
}


// 写入主轴的速度值
void HomePage::on_lineEdit_2_editingFinished()
{
  ui->lineEdit_2->text();
  buffer.push({
      .cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD,
      .motor_manual_control = {
          .manual_control_cmd = MOTOR_MANUAL_CONTROL::ABSOLUTE_POSITION_MOTION,
          .motor_type = MAIN_SPINDLE,
          .speed = ui->lineEdit_2->text().toDouble(),
      }
  });
  qDebug() << "速度值" << ui->lineEdit_2->text();
}

