#include "homepage.h"
#include "ui_homepage.h"

#include <QDebug>
#include <QTimer>
#include <cstdlib>
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

