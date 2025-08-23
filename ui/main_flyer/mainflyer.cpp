#include "mainflyer.h"
#include "ui_mainflyer.h"
#include <QTimer>
#include <QDebug>
#include <QMessageBox>


#include "../../src/util/shm_manager.hpp"



MainFlyer::MainFlyer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainFlyer)
    ,buffer(nullptr) 
{
    ui->setupUi(this);

    //     connect(&ShmManager::get_instance(), &ShmManager::loaded, [this](bool success) {
    //     if (success) {
    //         // buffer.set_buffer(&ShmManager::get_instance().get_data()->buffer_M);
    //         buffer.set_buffer(&ShmManager::get_instance().get_data()->buffer_P);
    //     }
    // });



       // 主轴速度读取
          auto timer = new QTimer(this);
          connect(timer, &QTimer::timeout, this, [this]() {
            // // 模拟数据更新
            // auto data = rand() % 100;

            auto speed = 
            ShmManager::get_instance()
                            .get_data()
                            ->feedback.motor_fdb[MAIN_SPINDLE]
                            .running_speed;
            
            auto accelerate = 
            ShmManager::get_instance()
                            .get_data()
                            ->feedback.motor_fdb[MAIN_SPINDLE]
                            .acceleration;

            auto position = 
            ShmManager::get_instance()
                            .get_data()
                            ->feedback.motor_fdb[MAIN_SPINDLE]
                            .position;

            ui->lineEdit_2->setText(QString::number(speed));
            ui->lineEdit_3->setText(QString::number(accelerate));
            ui->lineEdit_6->setText(QString::number(position));
          });

  connect(
      &ShmManager::get_instance(), &ShmManager::loaded, [this, timer](bool success) {

        if (success) {
          buffer.set_buffer(&ShmManager::get_instance().get_data()->buffer_P);
          timer->start(200);
        }
      });
}

MainFlyer::~MainFlyer()
{
    delete ui;
}

// 主轴  ---  正点动
void MainFlyer::on_pushButton_clicked()
{
    qDebug() << "主轴正点动" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();


        // //检查空值并弹出提示框
    // if(ui->lineEdit_9->text().isEmpty() ||
    //     ui->lineEdit_8->text().isEmpty() ||
    //     ui->lineEdit_7->text().isEmpty()) {
    //     QMessageBox::warning(this, "输入错误", "主轴电动的速度、加速度或位置不能为空！！！");
    //     return;
    // }

    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD,
        .motor_manual_control = {
            .manual_control_cmd = MOTOR_MANUAL_CONTROL::FORWARD_JOGING,  //电机控制类型
            .motor_type = MAIN_SPINDLE,  // 飞轮对应的电机类型
            .speed = ui->lineEdit_9->text().toDouble(),  // 从输入框获取速度
            .manual_acceleration = ui -> lineEdit_8->text().toDouble(),  
            .manual_pos = ui -> lineEdit_7->text().toDouble()      
        }
    });
}


// 主轴  --- 反点动
void MainFlyer::on_pushButton_4_clicked()
{
    qDebug() << "主轴反电动" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();


    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD,
        .motor_manual_control = {
            .manual_control_cmd = MOTOR_MANUAL_CONTROL::REVERSE_JOGING,  //电机控制类型
            .motor_type = MAIN_SPINDLE,  // 飞轮对应的电机类型
            .speed = ui->lineEdit_9->text().toDouble(),  
            .manual_acceleration = ui -> lineEdit_8->text().toDouble(),  
            .manual_pos = ui -> lineEdit_7->text().toDouble()            
        }
    });
}


// 主轴  --- 回零
void MainFlyer::on_pushButton_2_clicked()
{
    qDebug() << "主轴回零" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();



    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD,
        .motor_manual_control = {
            .manual_control_cmd = MOTOR_MANUAL_CONTROL::RETURN_TO_ZERO,  //电机控制类型
            .motor_type = MAIN_SPINDLE, 
            .speed = ui->lineEdit_9->text().toDouble(),
            .manual_acceleration = ui -> lineEdit_8->text().toDouble(),
            .manual_pos = ui -> lineEdit_7->text().toDouble()
        }
    });
}


// 主轴 --- 松闸
void MainFlyer::on_pushButton_7_clicked()
{
    qDebug() << "主轴松闸" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();



    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD,
        .motor_manual_control = {
            .manual_control_cmd = MOTOR_MANUAL_CONTROL::RELEASE_BRAKE,  //电机控制类型
            .motor_type = MAIN_SPINDLE, 
            .speed = ui->lineEdit_9->text().toDouble(),
            .manual_acceleration = ui -> lineEdit_8->text().toDouble(),
            .manual_pos = ui -> lineEdit_7->text().toDouble()
        }
    });
}


// 主轴 --- 抱闸

void MainFlyer::on_pushButton_8_clicked()
{
    qDebug() << "主轴抱闸" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();



    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD,
        .motor_manual_control = {
            .manual_control_cmd = MOTOR_MANUAL_CONTROL::ENGAGE_BRAKE,  //电机控制类型
            .motor_type = MAIN_SPINDLE, 
            .speed = ui->lineEdit_9->text().toDouble(),
            .manual_acceleration = ui -> lineEdit_8->text().toDouble(),
            .manual_pos = ui -> lineEdit_7->text().toDouble()
        }
    });
}

// 主轴 --- 停止
void MainFlyer::on_pushButton_9_clicked()
{
    qDebug() << "主轴停止" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();



    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD,
        .motor_manual_control = {
            .manual_control_cmd = MOTOR_MANUAL_CONTROL::STOP,  //电机控制类型
            .motor_type = MAIN_SPINDLE, 
            .speed = ui->lineEdit_9->text().toDouble(),
            .manual_acceleration = ui -> lineEdit_8->text().toDouble(),
            .manual_pos = ui -> lineEdit_7->text().toDouble()
        }
    });
}

// 主轴 --- 上使能
void MainFlyer::on_pushButton_3_clicked()
{

        qDebug() << "主轴上使能" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();


     buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD,
        .motor_manual_control = {
            .manual_control_cmd = MOTOR_MANUAL_CONTROL::MANUAL_MOTOR_ON,  //电机控制类型
            .motor_type = MAIN_SPINDLE, 
            .speed = ui->lineEdit_9->text().toDouble(),
            .manual_acceleration = ui -> lineEdit_8->text().toDouble(),
            .manual_pos = ui -> lineEdit_7->text().toDouble()
        }
    });
        qDebug() << "主轴上使能-输出" << ui->lineEdit_9->text().toDouble() << ui->lineEdit_8->text().toDouble() << ui->lineEdit_7->text().toDouble();

}


// 主轴 --- 去使能
void MainFlyer::on_pushButton_5_clicked()
{
        qDebug() << "主轴去使能" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();


    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD,
        .motor_manual_control = {
            .manual_control_cmd = MOTOR_MANUAL_CONTROL::MANUAL_MOTOR_OFF,  //电机控制类型
            .motor_type = MAIN_SPINDLE, 
            .speed = ui->lineEdit_9->text().toDouble(),
            .manual_acceleration = ui -> lineEdit_8->text().toDouble(),
            .manual_pos = ui -> lineEdit_7->text().toDouble()
        }
    });
}
// 主轴 --- 绝对移动
void MainFlyer::on_pushButton_6_clicked()
{
    qDebug() << "主轴绝对移动" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();


    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD,
        .motor_manual_control = {
            .manual_control_cmd = MOTOR_MANUAL_CONTROL::ABSOLUTE_POSITION_MOTION,  //电机控制类型
            .motor_type = MAIN_SPINDLE, 
            .speed = ui->lineEdit_9->text().toDouble(),
            .manual_acceleration = ui -> lineEdit_8->text().toDouble(),
            .manual_pos = ui -> lineEdit_7->text().toDouble()
        }
    });
}














