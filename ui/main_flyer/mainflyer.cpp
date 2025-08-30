#include "mainflyer.h"
#include "ui_mainflyer.h"
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <qdeadlinetimer.h>
#include <qdebug.h>
#include <qlogging.h>
#include <qobject.h>

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


            // 电机-显示
            ui->lineEdit_2->setText(QString::number(getMotorNum(MAIN_SPINDLE, "speed"), 'f'));
            ui->lineEdit_3->setText(QString::number(getMotorNum(MAIN_SPINDLE, "acceleration"), 'f'));
            ui->lineEdit_6->setText(QString::number(getMotorNum(MAIN_SPINDLE, "position"), 'f'));

            //虚捻-显示
            ui->lineEdit_14->setText(QString::number(getMotorNum(MAIN_TORSION,"speed"), 'f'));
            ui->lineEdit_15->setText(QString::number(getMotorNum(MAIN_TORSION,"acceleration"), 'f'));
            ui->lineEdit_16->setText(QString::number(getMotorNum(MAIN_TORSION,"position"), 'f'));

            // 牵引-显示
            ui->lineEdit_20->setText(QString::number(getMotorNum(MAIN_DRAWING, "speed"), 'f'));
            ui->lineEdit_21->setText(QString::number(getMotorNum(MAIN_DRAWING, "acceleration"), 'f'));
            ui->lineEdit_22->setText(QString::number(getMotorNum(MAIN_DRAWING, "position"), 'f'));

            // 收线-显示
            ui->lineEdit_26->setText(QString::number(getMotorNum(MAIN_WINDING, "speed"), 'f'));
            ui->lineEdit_33->setText(QString::number(getMotorNum(MAIN_WINDING, "acceleration"), 'f'));
            ui->lineEdit_34->setText(QString::number(getMotorNum(MAIN_WINDING, "position"), 'f'));

            // 排线-显示
            ui->lineEdit_38->setText(QString::number(getMotorNum(MAIN_LAYING, "speed"), 'f'));
            ui->lineEdit_39->setText(QString::number(getMotorNum(MAIN_LAYING, "acceleration"), 'f'));
            ui->lineEdit_40->setText(QString::number(getMotorNum(MAIN_LAYING, "position"), 'f'));
          });

  connect(
      &ShmManager::get_instance(), &ShmManager::loaded, [this, timer](bool success) {

        if (success) {
          buffer.set_buffer(&ShmManager::get_instance().get_data()->buffer_P);
          timer->start(200);
        }
      });
}




// 获取电机的速度，加速度，位置
double MainFlyer::getMotorNum(int motorType, QString model) const
{

        double num = 0.0;
    // 检查共享内存是否已加载
    if (!ShmManager::get_instance().get_data()) {
        qDebug() << "Shared memory not loaded";
        return 0.0;
    }

    
    qDebug() << "getMotorSpeed called with motorType:" << motorType;
 
    if (model == "speed") {    
        num =  ShmManager::get_instance()
                    .get_data()
                    ->feedback.motor_fdb[motorType]
                    .running_speed;
    } else if (model == "acceleration") {   
        num =  ShmManager::get_instance()
                    .get_data()
                    ->feedback.motor_fdb[motorType]
                    .acceleration;
    } else if (model == "position") {
        num =  ShmManager::get_instance()
                    .get_data()
                    ->feedback.motor_fdb[motorType]
                    .acceleration;
    }

    qDebug() << "MotorType:" << motorType << "num:" << num;

    return  num;
}


MainFlyer::~MainFlyer()
{
    delete ui;
}


void MainFlyer::executeOperation(int motorType, SpindleOperation operation, double speed, double acceleration, double position) {
    
 // 确保变量声明正确
    MOTOR_MANUAL_CONTROL::MANUAL_CONTROL_CMD cmdType;    
    switch (operation) {
    case SpindleOperation::FORWARD_JOGING:
        cmdType = MOTOR_MANUAL_CONTROL::FORWARD_JOGING;
        break;
    case SpindleOperation::REVERSE_JOGING:
        cmdType = MOTOR_MANUAL_CONTROL::REVERSE_JOGING;
        break;
    case SpindleOperation::RETURN_TO_ZERO:
        cmdType = MOTOR_MANUAL_CONTROL::RETURN_TO_ZERO;
        break;
    case SpindleOperation::RELEASE_BRAKE:
        cmdType = MOTOR_MANUAL_CONTROL::RELEASE_BRAKE;
        break;
    case SpindleOperation::ENGAGE_BRAKE:
        cmdType = MOTOR_MANUAL_CONTROL::ENGAGE_BRAKE;
        break;
    case SpindleOperation::STOP:
        cmdType = MOTOR_MANUAL_CONTROL::STOP;
        break;
    case SpindleOperation::MANUAL_MOTOR_ON:
        cmdType = MOTOR_MANUAL_CONTROL::MANUAL_MOTOR_ON;
        break;
    case SpindleOperation::MANUAL_MOTOR_OFF:
        cmdType = MOTOR_MANUAL_CONTROL::MANUAL_MOTOR_OFF;
        break;
    case SpindleOperation::ABSOLUTE_POSITION_MOTION:
        cmdType = MOTOR_MANUAL_CONTROL::ABSOLUTE_POSITION_MOTION;
        break;
    default:
        // 可以选择抛出异常、记录日志或设置默认值
        throw std::invalid_argument("Unknown SpindleOperation");
}

    buffer.push({
        .cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD,
        .motor_manual_control = {
            .manual_control_cmd = cmdType,
            .motor_type = static_cast<MOTOR_TYPE>(motorType),  
            .speed = speed,
            .manual_acceleration = acceleration,
            .manual_pos = position
        }
    });
}


// 主轴  ---  正点动
// void MainFlyer::on_pushButton_clicked()
// {
//         // //检查空值并弹出提示框
//     // if(ui->lineEdit_9->text().isEmpty() ||
//     //     ui->lineEdit_8->text().isEmpty() ||
//     //     ui->lineEdit_7->text().isEmpty()) {
//     //     QMessageBox::warning(this, "输入错误", "主轴电动的速度、加速度或位置不能为空！！！");
//     //     return;
//     // }
// }
void MainFlyer::on_pushButton_pressed()
{
        qDebug() << "主轴正点动" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();

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


// 主轴  --- 正点动释放
void MainFlyer::on_pushButton_released()
{
    qDebug() << "主轴正点动释放";
    executeOperation(MAIN_SPINDLE, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}


// 主轴  --- 反点动
void MainFlyer::on_pushButton_4_pressed()
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
void MainFlyer::on_pushButton_4_released()
{
    qDebug() << "主轴反点动释放";
    executeOperation(MAIN_SPINDLE, SpindleOperation::STOP, 0.0, 0.0, 0.0);
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




// 虚捻  --- 正点动
void MainFlyer::on_pushButton_19_pressed()
{
     qDebug() << "虚捻正点动" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(MAIN_TORSION, SpindleOperation::FORWARD_JOGING, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());

}

//虚捻 --- 正点动释放
void MainFlyer::on_pushButton_19_released()
{
    qDebug() << "虚捻正点动释放";
    executeOperation(MAIN_TORSION, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}

// 虚捻  --- 反点动

void MainFlyer::on_pushButton_20_pressed()
{
    qDebug() << "虚捻正点动" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(MAIN_TORSION, SpindleOperation::REVERSE_JOGING, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());

}
// 虚捻  --- 反点动释放
void MainFlyer::on_pushButton_20_released()
{
    qDebug() << "虚捻反点动释放";
    executeOperation(MAIN_TORSION, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}


// 虚捻  --- 回零
void MainFlyer::on_pushButton_21_clicked()
{
    qDebug() << "虚捻回零" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(MAIN_TORSION, SpindleOperation::RETURN_TO_ZERO, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}

// 虚捻  --- 松闸
void MainFlyer::on_pushButton_22_clicked()
{
    qDebug() << "虚捻松闸" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(MAIN_TORSION, SpindleOperation::RELEASE_BRAKE, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}

// 虚捻  --- 抱闸
void MainFlyer::on_pushButton_23_clicked()
{
    qDebug() << "虚捻抱闸" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(MAIN_TORSION, SpindleOperation::ENGAGE_BRAKE, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}


// 虚捻  --- 停止
void MainFlyer::on_pushButton_24_clicked()
{
    qDebug() << "虚捻停止" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(MAIN_TORSION, SpindleOperation::STOP, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}

// 虚捻  --- 上使能
void MainFlyer::on_pushButton_25_clicked()
{
    qDebug() << "虚捻上使能" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(MAIN_TORSION, SpindleOperation::MANUAL_MOTOR_ON, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}

// 虚捻  --- 去使能
void MainFlyer::on_pushButton_26_clicked()
{
    qDebug() << "虚捻去使能" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(MAIN_TORSION, SpindleOperation::MANUAL_MOTOR_OFF, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}

// 虚捻  --- 绝对移动
void MainFlyer::on_pushButton_27_clicked()
{
    qDebug() << "虚捻绝对移动" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(MAIN_TORSION, SpindleOperation::ABSOLUTE_POSITION_MOTION, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}


//牵引  --- 正点动
// void MainFlyer::on_pushButton_28_clicked()
// {
//    }


void MainFlyer::on_pushButton_28_pressed()
{
    qDebug() << "牵引正点动" << ui->lineEdit_23->text() << ui->lineEdit_24->text() << ui->lineEdit_25->text();
    executeOperation(MAIN_DRAWING, SpindleOperation::FORWARD_JOGING, ui->lineEdit_23->text().toDouble(), ui->lineEdit_24->text().toDouble(), ui->lineEdit_25->text().toDouble());
}

//牵引 --- 正点动释放
void MainFlyer::on_pushButton_28_released()
{
    qDebug() << "牵引正点动释放";
    executeOperation(MAIN_DRAWING, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}

//牵引  --- 反点动
void MainFlyer::on_pushButton_29_pressed()
{
     qDebug() << "牵引反点动" << ui->lineEdit_23->text() << ui->lineEdit_24->text() << ui->lineEdit_25->text();
    executeOperation(MAIN_DRAWING, SpindleOperation::REVERSE_JOGING, ui->lineEdit_23->text().toDouble(), ui->lineEdit_24->text().toDouble(), ui->lineEdit_25->text().toDouble());
}

//牵引 --- 反点动释放
void MainFlyer::on_pushButton_29_released()
{
    qDebug() << "牵引反点动释放";
    executeOperation(MAIN_DRAWING, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}

//牵引  --- 回零
void MainFlyer::on_pushButton_30_clicked()
{
    qDebug() << "牵引回零" << ui->lineEdit_23->text() << ui->lineEdit_24->text() << ui->lineEdit_25->text();
    executeOperation(MAIN_DRAWING, SpindleOperation::RETURN_TO_ZERO, ui->lineEdit_23->text().toDouble(), ui->lineEdit_24->text().toDouble(), ui->lineEdit_25->text().toDouble());
}

//牵引  --- 松闸
void MainFlyer::on_pushButton_31_clicked()
{
    qDebug() << "牵引松闸" << ui->lineEdit_23->text() << ui->lineEdit_24->text() << ui->lineEdit_25->text();
    executeOperation(MAIN_DRAWING, SpindleOperation::RELEASE_BRAKE, ui->lineEdit_23->text().toDouble(), ui->lineEdit_24->text().toDouble(), ui->lineEdit_25->text().toDouble());
}

//牵引  --- 抱闸
void MainFlyer::on_pushButton_32_clicked()
{
    qDebug() << "牵引抱闸" << ui->lineEdit_23->text() << ui->lineEdit_24->text() << ui->lineEdit_25->text();
    executeOperation(MAIN_DRAWING, SpindleOperation::ENGAGE_BRAKE, ui->lineEdit_23->text().toDouble(), ui->lineEdit_24->text().toDouble(), ui->lineEdit_25->text().toDouble());
}

//牵引  --- 停止
void MainFlyer::on_pushButton_33_clicked()
{
    qDebug() << "牵引停止" << ui->lineEdit_23->text() << ui->lineEdit_24->text() << ui->lineEdit_25->text();
    executeOperation(MAIN_DRAWING, SpindleOperation::STOP, ui->lineEdit_23->text().toDouble(), ui->lineEdit_24->text().toDouble(), ui->lineEdit_25->text().toDouble());
}

//牵引  --- 上使能
void MainFlyer::on_pushButton_34_clicked()
{
    qDebug() << "牵引上使能" << ui->lineEdit_23->text() << ui->lineEdit_24->text() << ui->lineEdit_25->text();
    executeOperation(MAIN_DRAWING, SpindleOperation::MANUAL_MOTOR_ON, ui->lineEdit_23->text().toDouble(), ui->lineEdit_24->text().toDouble(), ui->lineEdit_25->text().toDouble());
}

//牵引  --- 去使能
void MainFlyer::on_pushButton_35_clicked()
{
    qDebug() << "牵引去使能" << ui->lineEdit_23->text() << ui->lineEdit_24->text() << ui->lineEdit_25->text();
    executeOperation(MAIN_DRAWING, SpindleOperation::MANUAL_MOTOR_OFF, ui->lineEdit_23->text().toDouble(), ui->lineEdit_24->text().toDouble(), ui->lineEdit_25->text().toDouble());
}

//牵引  --- 绝对移动
void MainFlyer::on_pushButton_36_clicked()
{
    qDebug() << "牵引绝对移动" << ui->lineEdit_23->text() << ui->lineEdit_24->text() << ui->lineEdit_25->text();
    executeOperation(MAIN_DRAWING, SpindleOperation::ABSOLUTE_POSITION_MOTION, ui->lineEdit_23->text().toDouble(), ui->lineEdit_24->text().toDouble(), ui->lineEdit_25->text().toDouble());
}


// 收线  --- 正点动
// void MainFlyer::on_pushButton_46_clicked()
// {
// }

void MainFlyer::on_pushButton_46_pressed()
{
    qDebug() << "收线正点动" << ui->lineEdit_35->text() << ui->lineEdit_36->text() << ui->lineEdit_37->text();
    executeOperation(MAIN_WINDING, SpindleOperation::FORWARD_JOGING, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}


//收线 --- 正点动释放
void MainFlyer::on_pushButton_46_released()
{
    qDebug() << "收线正点动释放";
    executeOperation(MAIN_WINDING, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}


//收线  --- 反点动
void MainFlyer::on_pushButton_47_pressed()
{
    qDebug() << "收线反点动" << ui->lineEdit_35->text() << ui->lineEdit_36->text() << ui->lineEdit_37->text();
    executeOperation(MAIN_WINDING, SpindleOperation::REVERSE_JOGING, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}

//收线  --- 反点动释放
void MainFlyer::on_pushButton_47_released()
{
    qDebug() << "收线反点动释放";
    executeOperation(MAIN_WINDING, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}

//收线  --- 回零
void MainFlyer::on_pushButton_48_clicked()
{
    qDebug() << "收线回零" << ui->lineEdit_35->text() << ui->lineEdit_36->text() << ui->lineEdit_37->text();
    executeOperation(MAIN_WINDING, SpindleOperation::RETURN_TO_ZERO, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}

//收线  --- 松闸
void MainFlyer::on_pushButton_49_clicked()
{
    qDebug() << "收线松闸" << ui->lineEdit_35->text() << ui->lineEdit_36->text() << ui->lineEdit_37->text();
    executeOperation(MAIN_WINDING, SpindleOperation::RELEASE_BRAKE, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}

//收线  --- 抱闸
void MainFlyer::on_pushButton_50_clicked()
{
    qDebug() << "收线抱闸" << ui->lineEdit_35->text() << ui->lineEdit_36->text() << ui->lineEdit_37->text();
    executeOperation(MAIN_WINDING, SpindleOperation::ENGAGE_BRAKE, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}

//收线  --- 停止
void MainFlyer::on_pushButton_51_clicked()
{
    qDebug() << "收线停止" << ui->lineEdit_35->text() << ui->lineEdit_36->text() << ui->lineEdit_37->text();
    executeOperation(MAIN_WINDING, SpindleOperation::STOP, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}

//收线  --- 上使能
void MainFlyer::on_pushButton_52_clicked()
{
    qDebug() << "收线上使能" << ui->lineEdit_35->text() << ui->lineEdit_36->text() << ui->lineEdit_37->text();
    executeOperation(MAIN_WINDING, SpindleOperation::MANUAL_MOTOR_ON, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}

//收线  --- 去使能
void MainFlyer::on_pushButton_53_clicked()
{
    qDebug() << "收线去使能" << ui->lineEdit_35->text() << ui->lineEdit_36->text() << ui->lineEdit_37->text();
    executeOperation(MAIN_WINDING, SpindleOperation::MANUAL_MOTOR_OFF, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}

//收线  --- 绝对移动
void MainFlyer::on_pushButton_54_clicked()
{
    qDebug() << "收线绝对移动" << ui->lineEdit_35->text() << ui->lineEdit_36->text() << ui->lineEdit_37->text();
    executeOperation(MAIN_WINDING, SpindleOperation::ABSOLUTE_POSITION_MOTION, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}


//排线  --- 正点动
void MainFlyer::on_pushButton_55_pressed()
{
    qDebug() << "排线正点动" << ui->lineEdit_41->text() << ui->lineEdit_42->text() << ui->lineEdit_43->text();
    executeOperation(MAIN_LAYING, SpindleOperation::FORWARD_JOGING, ui->lineEdit_41->text().toDouble(), ui->lineEdit_39->text().toDouble(), ui->lineEdit_40->text().toDouble());
}
//排线  --- 正点动释放
void MainFlyer::on_pushButton_55_released()
{
    qDebug() << "排线正点动释放";
    executeOperation(MAIN_LAYING, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}

//排线  --- 反点动
void MainFlyer::on_pushButton_56_pressed()
{
    qDebug() << "排线反点动" << ui->lineEdit_41->text() << ui->lineEdit_42->text() << ui->lineEdit_43->text();
    executeOperation(MAIN_LAYING, SpindleOperation::REVERSE_JOGING, ui->lineEdit_41->text().toDouble(), ui->lineEdit_42->text().toDouble(), ui->lineEdit_43->text().toDouble());
}
//排线  --- 反点动释放
void MainFlyer::on_pushButton_56_released()
{
    qDebug() << "排线反点动释放";
    executeOperation(MAIN_LAYING, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}

//排线  --- 回零
void MainFlyer::on_pushButton_57_clicked()
{
    qDebug() << "排线回零" << ui->lineEdit_41->text() << ui->lineEdit_42->text() << ui->lineEdit_43->text();
    executeOperation(MAIN_LAYING, SpindleOperation::RETURN_TO_ZERO, ui->lineEdit_41->text().toDouble(), ui->lineEdit_42->text().toDouble(), ui->lineEdit_43->text().toDouble());
}

//排线  --- 松闸
void MainFlyer::on_pushButton_58_clicked()
{
    qDebug() << "排线松闸" << ui->lineEdit_41->text() << ui->lineEdit_42->text() << ui->lineEdit_43->text();
    executeOperation(MAIN_LAYING, SpindleOperation::RELEASE_BRAKE, ui->lineEdit_41->text().toDouble(), ui->lineEdit_42->text().toDouble(), ui->lineEdit_43->text().toDouble());
}

//排线  --- 抱闸
void MainFlyer::on_pushButton_59_clicked()
{
    qDebug() << "排线抱闸" << ui->lineEdit_41->text() << ui->lineEdit_42->text() << ui->lineEdit_43->text();
    executeOperation(MAIN_LAYING, SpindleOperation::ENGAGE_BRAKE, ui->lineEdit_41->text().toDouble(), ui->lineEdit_42->text().toDouble(), ui->lineEdit_43->text().toDouble());}

//排线  --- 停止
void MainFlyer::on_pushButton_60_clicked()
{
    qDebug() << "排线停止" << ui->lineEdit_41->text() << ui->lineEdit_42->text() << ui->lineEdit_43->text();
    executeOperation(MAIN_LAYING, SpindleOperation::STOP, ui->lineEdit_41->text().toDouble(), ui->lineEdit_42->text().toDouble(), ui->lineEdit_43->text().toDouble());
}

//排线  --- 上使能
void MainFlyer::on_pushButton_61_clicked()
{
    qDebug() << "排线上使能" << ui->lineEdit_41->text() << ui->lineEdit_42->text() << ui->lineEdit_43->text();
    executeOperation(MAIN_LAYING, SpindleOperation::MANUAL_MOTOR_ON, ui->lineEdit_41->text().toDouble(), ui->lineEdit_42->text().toDouble(), ui->lineEdit_43->text().toDouble());
}

//排线  --- 去使能
void MainFlyer::on_pushButton_62_clicked()
{
    qDebug() << "排线去使能" << ui->lineEdit_41->text() << ui->lineEdit_42->text() << ui->lineEdit_43->text();
    executeOperation(MAIN_LAYING, SpindleOperation::MANUAL_MOTOR_OFF, ui->lineEdit_41->text().toDouble(), ui->lineEdit_42->text().toDouble(), ui->lineEdit_43->text().toDouble());
}

//排线  --- 绝对移动
void MainFlyer::on_pushButton_63_clicked()
{
    qDebug() << "排线绝对移动" << ui->lineEdit_41->text() << ui->lineEdit_42->text() << ui->lineEdit_43->text();
    executeOperation(MAIN_LAYING, SpindleOperation::ABSOLUTE_POSITION_MOTION, ui->lineEdit_38->text().toDouble(), ui->lineEdit_39->text().toDouble(), ui->lineEdit_40->text().toDouble());
}

