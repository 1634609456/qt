#include "besidepass.h"
#include "ui_besidepass.h"
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <qobject.h>

#include "../../src/util/shm_manager.hpp"

BesidePass::BesidePass(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BesidePass)
,buffer(nullptr) 

{
    ui->setupUi(this);

        auto timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, [this]() {


        // 边穿丝机构进退-显示
        ui->lineEdit_2->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "speed"), 'f'));
        ui->lineEdit_3->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "acceleration"), 'f'));
        ui->lineEdit_6->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "position"), 'f'));


        //边穿丝气爪上下-显示
        ui->lineEdit_4->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "speed"), 'f'));
        ui->lineEdit_5->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "acceleration"), 'f'));
        ui->lineEdit_10->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "position"), 'f'));


        //边穿丝气爪旋转-显示
        ui->lineEdit_14->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "speed"), 'f'));
        ui->lineEdit_15->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "acceleration"), 'f'));
        ui->lineEdit_16->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "position"), 'f'));
        });

  connect(
      &ShmManager::get_instance(), &ShmManager::loaded, [this, timer](bool success) {

        if (success) {
          buffer.set_buffer(&ShmManager::get_instance().get_data()->buffer_P);
          timer->start(200);
        }
      });
}

void BesidePass::executeOperation(int motorType, SpindleOperation operation, double speed, double acceleration, double position) {
    
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

    // buffer.push({
    //     .cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD,
    //     .motor_manual_control = {
    //         .manual_control_cmd = cmdType,
    //         .motor_type = static_cast<MOTOR_TYPE>(motorType),  
    //         .speed = speed,
    //         .manual_acceleration = acceleration,
    //         .manual_pos = position
    //     }
    // });

        COMMOND_GROUPS cmd;
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD;
    cmd.motor_manual_control.manual_control_cmd = cmdType;
    cmd.motor_manual_control.motor_type = static_cast<MOTOR_TYPE>(motorType);
    cmd.motor_manual_control.speed = speed;
    cmd.motor_manual_control.manual_acceleration = acceleration;
    cmd.motor_manual_control.manual_pos = position;
    buffer.push(cmd);



// // 确保变量声明正确
//     MOTOR_MANUAL_CONTROL::MANUAL_CONTROL_CMD cmdType;    
//     switch (operation) {
//     case SpindleOperation::FORWARD_JOGING:
//         cmdType = MOTOR_MANUAL_CONTROL::FORWARD_JOGING;
//         break;
//     case SpindleOperation::REVERSE_JOGING:
//         cmdType = MOTOR_MANUAL_CONTROL::REVERSE_JOGING;
//         break;
//     case SpindleOperation::RETURN_TO_ZERO:
//         cmdType = MOTOR_MANUAL_CONTROL::RETURN_TO_ZERO;
//         break;
//     case SpindleOperation::RELEASE_BRAKE:
//         cmdType = MOTOR_MANUAL_CONTROL::RELEASE_BRAKE;
//         break;
//     case SpindleOperation::ENGAGE_BRAKE:
//         cmdType = MOTOR_MANUAL_CONTROL::ENGAGE_BRAKE;
//         break;
//     case SpindleOperation::STOP:
//         cmdType = MOTOR_MANUAL_CONTROL::STOP;
//         break;
//     case SpindleOperation::MANUAL_MOTOR_ON:
//         cmdType = MOTOR_MANUAL_CONTROL::MANUAL_MOTOR_ON;
//         break;
//     case SpindleOperation::MANUAL_MOTOR_OFF:
//         cmdType = MOTOR_MANUAL_CONTROL::MANUAL_MOTOR_OFF;
//         break;
//     case SpindleOperation::ABSOLUTE_POSITION_MOTION:
//         cmdType = MOTOR_MANUAL_CONTROL::ABSOLUTE_POSITION_MOTION;
//         break;
//     default:
//         throw std::invalid_argument("Unknown SpindleOperation");
// }

//     COMMOND_GROUPS cmd;
//     cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD;
//     cmd.motor_manual_control.manual_control_cmd = cmdType;
//     cmd.motor_manual_control.motor_type = static_cast<MOTOR_TYPE>(motorType);
//     cmd.motor_manual_control.speed = speed;
//     cmd.motor_manual_control.manual_acceleration = acceleration;
//     cmd.motor_manual_control.manual_pos = position;
//     buffer.push(cmd);
}

// 获取电机的速度，加速度，位置
double BesidePass::getMotorNum(int motorType, QString model) const
{

        double num = 0.0;
    // 检查共享内存是否已加载
    if (!ShmManager::get_instance().get_data()) {
        qDebug() << "Shared memory not loaded";
        return 0.0;
    }

    
 
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

    return  num;
}
BesidePass::~BesidePass()
{
    delete ui;
}


//边穿丝机构进退  --  正点动
void BesidePass::on_pushButton_pressed()
{
    qDebug() << "边穿丝机构进退  --  正点动" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(EDGE_ADVANCE_RETREAT_MOTOR, SpindleOperation::FORWARD_JOGING, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}


//边穿丝机构进退  --  正点动释放
void BesidePass::on_pushButton_released()
{
    qDebug() << "边穿丝机构进退  --  正点动释放";
    executeOperation(EDGE_ADVANCE_RETREAT_MOTOR, SpindleOperation::STOP, 0,0,0);
}


void BesidePass::on_pushButton_4_pressed()
{

    qDebug() << "边穿丝机构进退  --  反点动按下" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(EDGE_ADVANCE_RETREAT_MOTOR, SpindleOperation::REVERSE_JOGING, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}


void BesidePass::on_pushButton_4_released()
{
    qDebug() << "边穿丝机构进退  --  反点动松开";
    executeOperation(EDGE_ADVANCE_RETREAT_MOTOR, SpindleOperation::STOP, 0,0,0);
}



void BesidePass::on_pushButton_2_clicked()
{
    qDebug() << "边穿丝机构进退  --  回零" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(EDGE_ADVANCE_RETREAT_MOTOR, SpindleOperation::RETURN_TO_ZERO, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}




void BesidePass::on_pushButton_7_clicked()
{
    qDebug() << "边穿丝机构进退  --  松闸" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(EDGE_ADVANCE_RETREAT_MOTOR, SpindleOperation::RELEASE_BRAKE, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}



void BesidePass::on_pushButton_8_clicked()
{
    qDebug() << "边穿丝机构进退  --  抱闸" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(EDGE_ADVANCE_RETREAT_MOTOR, SpindleOperation::ENGAGE_BRAKE, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}


void BesidePass::on_pushButton_9_clicked()
{
    qDebug() << "边穿丝机构进退  --  停止" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(EDGE_ADVANCE_RETREAT_MOTOR, SpindleOperation::STOP, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}


void BesidePass::on_pushButton_3_clicked()
{
    qDebug() << "边穿丝机构进退  --  上使能" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(EDGE_ADVANCE_RETREAT_MOTOR, SpindleOperation::MANUAL_MOTOR_ON, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}


void BesidePass::on_pushButton_5_clicked()
{
    qDebug() << "边穿丝机构进退  --  下使能" << ui->lineEdit_10->text() << ui->lineEdit_11->text() << ui->lineEdit_12->text();
    executeOperation(EDGE_ADVANCE_RETREAT_MOTOR, SpindleOperation::MANUAL_MOTOR_OFF, ui->lineEdit_10->text().toDouble(), ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble());
}


void BesidePass::on_pushButton_6_clicked()
{
    qDebug() << "边穿丝机构进退  --  绝对移动" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(EDGE_ADVANCE_RETREAT_MOTOR, SpindleOperation::ABSOLUTE_POSITION_MOTION, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}



//边穿丝气爪升降  -- 正点动
void BesidePass::on_pushButton_10_pressed()
{
    qDebug() << "边穿丝气爪升降  -- 正点动按下" << ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(EDGE_LIFT_MOTOR, SpindleOperation::FORWARD_JOGING, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());
}


void BesidePass::on_pushButton_10_released()
{
    qDebug() << "边穿丝气爪升降  -- 正点动释放";
    executeOperation(EDGE_LIFT_MOTOR, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}




void BesidePass::on_pushButton_11_pressed()
{
    qDebug() << "边穿丝气爪升降  -- 负点动按下" << ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(EDGE_LIFT_MOTOR, SpindleOperation::REVERSE_JOGING, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());
}



void BesidePass::on_pushButton_11_released()
{
    qDebug() << "边穿丝气爪升降  -- 负点动释放";
    executeOperation(EDGE_LIFT_MOTOR, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}


void BesidePass::on_pushButton_12_clicked()
{
    qDebug() << "边穿丝气爪升降  --  回零" << ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(EDGE_LIFT_MOTOR, SpindleOperation::RETURN_TO_ZERO, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());
}


void BesidePass::on_pushButton_13_clicked()
{
    qDebug() << "边穿丝气爪升降  -- 松闸" << ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(EDGE_LIFT_MOTOR, SpindleOperation::RELEASE_BRAKE, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());
}


void BesidePass::on_pushButton_14_clicked()
{
    qDebug() << "边穿丝气爪升降  -- 抱闸" << ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(EDGE_LIFT_MOTOR, SpindleOperation::ENGAGE_BRAKE, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());
}


void BesidePass::on_pushButton_15_clicked()
{
    qDebug() << "边穿丝气爪升降  -- 停止" << ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(EDGE_LIFT_MOTOR, SpindleOperation::STOP, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());
}


void BesidePass::on_pushButton_16_clicked()
{
    qDebug() << "边穿丝气爪升降  -- 上使能" << ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(EDGE_LIFT_MOTOR, SpindleOperation::MANUAL_MOTOR_ON, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());
}


void BesidePass::on_pushButton_17_clicked()
{
    qDebug() << "边穿丝气爪升降  -- 下使能" << ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(EDGE_LIFT_MOTOR, SpindleOperation::MANUAL_MOTOR_OFF, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());  
}


void BesidePass::on_pushButton_18_clicked()
{
    qDebug() << "边穿丝气爪升降  -- 绝对移动" << ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(EDGE_LIFT_MOTOR, SpindleOperation::ABSOLUTE_POSITION_MOTION, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());
}



//边穿丝气爪旋转  -- 正点动按压
void BesidePass::on_pushButton_19_pressed()
{
    qDebug() << "边穿丝气爪旋转  -- 正点动按下" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(EDGE_ROTATING_MOTOR, SpindleOperation::FORWARD_JOGING, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}

void BesidePass::on_pushButton_19_released()
{
    qDebug() << "边穿丝气爪旋转  -- 正点动松开" ;
    executeOperation(EDGE_ROTATING_MOTOR, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}



void BesidePass::on_pushButton_20_pressed()
{
    qDebug() << "边穿丝气爪旋转  -- 反点动按下" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(EDGE_ROTATING_MOTOR, SpindleOperation::REVERSE_JOGING, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}

void BesidePass::on_pushButton_20_released()
{
    qDebug() << "边穿丝气爪旋转  -- 反点动松开" ;
    executeOperation(EDGE_ROTATING_MOTOR, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}



void BesidePass::on_pushButton_21_clicked()
{
    qDebug() << "边穿丝气爪旋转  -- 回零" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(EDGE_ROTATING_MOTOR, SpindleOperation::RETURN_TO_ZERO, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}


void BesidePass::on_pushButton_22_clicked()
{
    qDebug() << "边穿丝气爪旋转  -- 松闸" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(EDGE_ROTATING_MOTOR, SpindleOperation::RELEASE_BRAKE, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}


void BesidePass::on_pushButton_23_clicked()
{
    qDebug() << "边穿丝气爪旋转  -- 抱闸" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(EDGE_ROTATING_MOTOR, SpindleOperation::ENGAGE_BRAKE, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}


void BesidePass::on_pushButton_24_clicked()
{
    qDebug() << "边穿丝气爪旋转  -- 停止" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(EDGE_ROTATING_MOTOR, SpindleOperation::STOP, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}


void BesidePass::on_pushButton_25_clicked()
{
    qDebug() << "边穿丝气爪旋转  -- 上使能" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(EDGE_ROTATING_MOTOR, SpindleOperation::MANUAL_MOTOR_ON, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}


void BesidePass::on_pushButton_26_clicked()
{
    qDebug() << "边穿丝气爪旋转  -- 下使能" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(EDGE_ROTATING_MOTOR, SpindleOperation::MANUAL_MOTOR_OFF, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}


void BesidePass::on_pushButton_27_clicked()
{
    qDebug() << "边穿丝气爪旋转  -- 绝对移动" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(EDGE_ROTATING_MOTOR, SpindleOperation::ABSOLUTE_POSITION_MOTION, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}

