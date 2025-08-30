#include "middelcircuitbreaker.h"
#include "ui_middelcircuitbreaker.h"
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <qdebug.h>
#include <qobject.h>

#include "../../src/util/shm_manager.hpp"

MiddelCircuitBreaker::MiddelCircuitBreaker(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MiddelCircuitBreaker)
    ,buffer(nullptr) 

{
    ui->setupUi(this);

        auto timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, [this]() {


        // 中穿丝机构进退-显示
        ui->lineEdit_2->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "speed"), 'f'));
        ui->lineEdit_3->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "acceleration"), 'f'));
        ui->lineEdit_6->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "position"), 'f'));

        // 中穿丝机构上下-显示
        ui->lineEdit_26->setText(QString::number(getMotorNum(CENTER_LIFT_MOTOR, "speed"), 'f'));
        ui->lineEdit_27->setText(QString::number(getMotorNum(CENTER_LIFT_MOTOR, "acceleration"), 'f'));
        ui->lineEdit_28->setText(QString::number(getMotorNum(CENTER_LIFT_MOTOR, "position"), 'f'));

        //撑线机构进退-显示
        ui->lineEdit_32->setText(QString::number(getMotorNum(EXTENDABLE_ROD_MOTOR, "position"), 'f'));
        ui->lineEdit_33->setText(QString::number(getMotorNum(EXTENDABLE_ROD_MOTOR, "position"), 'f'));
        ui->lineEdit_34->setText(QString::number(getMotorNum(EXTENDABLE_ROD_MOTOR, "position"), 'f'));

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
double MiddelCircuitBreaker::getMotorNum(int motorType, QString model) const
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

//电机操作执行函数
void MiddelCircuitBreaker::executeOperation(int motorType, SpindleOperation operation, double speed, double acceleration, double position) {
    
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

MiddelCircuitBreaker::~MiddelCircuitBreaker()
{
    delete ui;
}

//中穿丝机构进退  --  正点动
void MiddelCircuitBreaker::on_pushButton_pressed()
{
    qDebug() << "中穿丝机构进退正点动" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(CENTER_ADVANCE_RETREAT_MOTOR, SpindleOperation::FORWARD_JOGING, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}

//中穿丝机构进退  --  正点动释放
void MiddelCircuitBreaker::on_pushButton_released()
{
    qDebug() << "中穿丝机构进退正点动释放";
    executeOperation(CENTER_ADVANCE_RETREAT_MOTOR, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}


//中穿丝机构进退  --  反点动
void MiddelCircuitBreaker::on_pushButton_4_pressed()
{
        qDebug() << "中穿丝机构进退反点动" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
        executeOperation(CENTER_ADVANCE_RETREAT_MOTOR, SpindleOperation::REVERSE_JOGING, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}

//中穿丝机构进退  --  反点动释放
void MiddelCircuitBreaker::on_pushButton_4_released()
{
    qDebug() << "中穿丝机构进退反点动释放";
    executeOperation(CENTER_ADVANCE_RETREAT_MOTOR, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}



//中穿丝机构进退  --  回零
void MiddelCircuitBreaker::on_pushButton_2_clicked()
{
    qDebug() << "中穿丝机构进退回零" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(CENTER_ADVANCE_RETREAT_MOTOR, SpindleOperation::RETURN_TO_ZERO, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}


//中穿丝机构进退  --  松闸
void MiddelCircuitBreaker::on_pushButton_7_clicked()
{
    qDebug() << "中穿丝机构进退松闸" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(CENTER_ADVANCE_RETREAT_MOTOR, SpindleOperation::RELEASE_BRAKE, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}

//中穿丝机构进退  --  抱闸
void MiddelCircuitBreaker::on_pushButton_8_clicked()
{
    qDebug() << "中穿丝机构进退抱闸" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(CENTER_ADVANCE_RETREAT_MOTOR, SpindleOperation::ENGAGE_BRAKE, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}

//中穿丝机构进退  --  停止
void MiddelCircuitBreaker::on_pushButton_9_clicked()
{
    qDebug() << "中穿丝机构进退停止" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(CENTER_ADVANCE_RETREAT_MOTOR, SpindleOperation::STOP, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}

//中穿丝机构进退  --  上使能
void MiddelCircuitBreaker::on_pushButton_3_clicked()
{
    qDebug() << "中穿丝机构进退上使能" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(CENTER_ADVANCE_RETREAT_MOTOR, SpindleOperation::MANUAL_MOTOR_ON, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}

//中穿丝机构进退  --  去使能
void MiddelCircuitBreaker::on_pushButton_5_clicked()
{
    qDebug() << "中穿丝机构进退去使能" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(CENTER_ADVANCE_RETREAT_MOTOR, SpindleOperation::MANUAL_MOTOR_OFF, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}

//中穿丝机构进退  --  绝对移动
void MiddelCircuitBreaker::on_pushButton_6_clicked()
{
    qDebug() << "中穿丝机构进退绝对移动" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(CENTER_ADVANCE_RETREAT_MOTOR, SpindleOperation::ABSOLUTE_POSITION_MOTION, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}


//中穿丝机构上下  --  正点动
void MiddelCircuitBreaker::on_pushButton_37_pressed()
{
    qDebug() << "中穿丝机构上下  --  正点动" << ui->lineEdit_29->text() << ui->lineEdit_30->text()  << ui->lineEdit_31->text();
    executeOperation(CENTER_LIFT_MOTOR, SpindleOperation::FORWARD_JOGING, ui->lineEdit_29->text().toDouble(), ui->lineEdit_30->text().toDouble(), ui->lineEdit_31->text().toDouble());
}


//中穿丝机构上下  --  正点动释放
void MiddelCircuitBreaker::on_pushButton_37_released()
{
    qDebug() << "中穿丝机构上下  --  正点动释放";
    executeOperation(CENTER_LIFT_MOTOR, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}

//中穿丝机构上下  --  反点动
void MiddelCircuitBreaker::on_pushButton_38_pressed()
{
    qDebug() << "中穿丝机构上下  --  反点动" << ui->lineEdit_29->text() << ui->lineEdit_30->text()  << ui->lineEdit_31->text();
    executeOperation(CENTER_LIFT_MOTOR, SpindleOperation::REVERSE_JOGING, ui->lineEdit_29->text().toDouble(), ui->lineEdit_30->text().toDouble(), ui->lineEdit_31->text().toDouble());
}

//中穿丝机构上下  --  反点动释放
void MiddelCircuitBreaker::on_pushButton_38_released()
{
    qDebug() << "中穿丝机构上下  --  反点动释放";
    executeOperation(CENTER_LIFT_MOTOR, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}

//中穿丝机构上下  --  回零
void MiddelCircuitBreaker::on_pushButton_39_clicked()
{
    qDebug() << "中穿丝机构上下  --  回零" << ui->lineEdit_29->text() << ui->lineEdit_30->text()  << ui->lineEdit_31->text();
    executeOperation(CENTER_LIFT_MOTOR, SpindleOperation::RETURN_TO_ZERO, ui->lineEdit_29->text().toDouble(), ui->lineEdit_30->text().toDouble(), ui->lineEdit_31->text().toDouble());
}

//中穿丝机构上下  --  松闸
void MiddelCircuitBreaker::on_pushButton_40_clicked()
{
    qDebug() << "中穿丝机构上下  --  抱闸" << ui->lineEdit_29->text() << ui->lineEdit_30->text()  << ui->lineEdit_31->text();
    executeOperation(CENTER_LIFT_MOTOR, SpindleOperation::RELEASE_BRAKE, ui->lineEdit_29->text().toDouble(), ui->lineEdit_30->text().toDouble(), ui->lineEdit_31->text().toDouble());
}

//中穿丝机构上下  --  抱闸
void MiddelCircuitBreaker::on_pushButton_41_clicked()
{
    qDebug() << "中穿丝机构上下  --  抱闸" << ui->lineEdit_29->text() << ui->lineEdit_30->text()  << ui->lineEdit_31->text();
    executeOperation(CENTER_LIFT_MOTOR, SpindleOperation::ENGAGE_BRAKE, ui->lineEdit_29->text().toDouble(), ui->lineEdit_30->text().toDouble(), ui->lineEdit_31->text().toDouble());
}

//中穿丝机构上下  --  停止
void MiddelCircuitBreaker::on_pushButton_42_clicked()
{
    qDebug() << "中穿丝机构上下  --  停止" << ui->lineEdit_29->text() << ui->lineEdit_30->text()  << ui->lineEdit_31->text();
    executeOperation(CENTER_LIFT_MOTOR, SpindleOperation::STOP, ui->lineEdit_29->text().toDouble(), ui->lineEdit_30->text().toDouble(), ui->lineEdit_31->text().toDouble());
}

//中穿丝机构上下  --  上使能
void MiddelCircuitBreaker::on_pushButton_43_clicked()
{
    qDebug() << "中穿丝机构上下  --  上使能" << ui->lineEdit_29->text() << ui->lineEdit_30->text()  << ui->lineEdit_31->text();
    executeOperation(CENTER_LIFT_MOTOR, SpindleOperation::MANUAL_MOTOR_ON, ui->lineEdit_29->text().toDouble(), ui->lineEdit_30->text().toDouble(), ui->lineEdit_31->text().toDouble());
}

//中穿丝机构上下  --  去使能
void MiddelCircuitBreaker::on_pushButton_44_clicked()
{
    qDebug() << "中穿丝机构上下  --  去使能" << ui->lineEdit_29->text() << ui->lineEdit_30->text()  << ui->lineEdit_31->text();
    executeOperation(CENTER_LIFT_MOTOR, SpindleOperation::MANUAL_MOTOR_OFF, ui->lineEdit_29->text().toDouble(), ui->lineEdit_30->text().toDouble(), ui->lineEdit_31->text().toDouble());
}

//中穿丝机构上下  --  绝对移动
void MiddelCircuitBreaker::on_pushButton_45_clicked()
{
    qDebug() << "中穿丝机构上下  --  绝对移动" << ui->lineEdit_29->text() << ui->lineEdit_30->text()  << ui->lineEdit_31->text();
    executeOperation(CENTER_LIFT_MOTOR, SpindleOperation::ABSOLUTE_POSITION_MOTION, ui->lineEdit_29->text().toDouble(), ui->lineEdit_30->text().toDouble(), ui->lineEdit_31->text().toDouble());
}



//撑线机构进退  --  正点动
void MiddelCircuitBreaker::on_pushButton_46_pressed()
{
    qDebug() << "撑线机构进退  --  正点动" << ui->lineEdit_35->text() << ui->lineEdit_36->text()  << ui->lineEdit_37->text();
    executeOperation(EXTENDABLE_ROD_MOTOR, SpindleOperation::FORWARD_JOGING, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}

//撑线机进退  --  正点动释放
void MiddelCircuitBreaker::on_pushButton_46_released()
{
    qDebug() << "撑线机构进退  --  正点动释放";
    executeOperation(EXTENDABLE_ROD_MOTOR, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}

//撑线机构进退  --  反点动
void MiddelCircuitBreaker::on_pushButton_47_pressed()
{
    qDebug() << "撑线机构进退  --  反点动" << ui->lineEdit_35->text() << ui->lineEdit_36->text()  << ui->lineEdit_37->text();
    executeOperation(EXTENDABLE_ROD_MOTOR, SpindleOperation::REVERSE_JOGING, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}

//撑线机构进退  --  反点动释放
void MiddelCircuitBreaker::on_pushButton_47_released()
{
    qDebug() << "撑线机构进退  --  反点动释放";
    executeOperation(EXTENDABLE_ROD_MOTOR, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}


//撑线机构进退  --  回零
void MiddelCircuitBreaker::on_pushButton_48_clicked()
{
    qDebug() << "撑线机构进退  --  回零" << ui->lineEdit_35->text() << ui->lineEdit_36->text()  << ui->lineEdit_37->text();
    executeOperation(EXTENDABLE_ROD_MOTOR, SpindleOperation::RETURN_TO_ZERO, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}

//撑线机构进退  --  松闸
void MiddelCircuitBreaker::on_pushButton_49_clicked()
{
    qDebug() << "撑线机构进退  --  松闸" << ui->lineEdit_35->text() << ui->lineEdit_36->text()  << ui->lineEdit_37->text();
    executeOperation(EXTENDABLE_ROD_MOTOR, SpindleOperation::RELEASE_BRAKE, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}

//撑线机构进退  --  抱闸
void MiddelCircuitBreaker::on_pushButton_50_clicked()
{
    qDebug() << "撑线机构进退  --  抱闸" << ui->lineEdit_35->text() << ui->lineEdit_36->text()  << ui->lineEdit_37->text();
    executeOperation(EXTENDABLE_ROD_MOTOR, SpindleOperation::ENGAGE_BRAKE, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}

//撑线机构进退  --  停止
void MiddelCircuitBreaker::on_pushButton_51_clicked()
{
    qDebug() << "撑线机构进退  --  停止" << ui->lineEdit_35->text() << ui->lineEdit_36->text()  << ui->lineEdit_37->text();
    executeOperation(EXTENDABLE_ROD_MOTOR, SpindleOperation::STOP, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}

//撑线机构进退  --  上使能
void MiddelCircuitBreaker::on_pushButton_52_clicked()
{
    qDebug() << "撑线机构进退  --  上使能" << ui->lineEdit_35->text() << ui->lineEdit_36->text()  << ui->lineEdit_37->text();
    executeOperation(EXTENDABLE_ROD_MOTOR, SpindleOperation::MANUAL_MOTOR_ON, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}

//撑线机构进退  --  去使能
void MiddelCircuitBreaker::on_pushButton_53_clicked()
{
    qDebug() << "撑线机构进退  --  去使能" << ui->lineEdit_35->text() << ui->lineEdit_36->text()  << ui->lineEdit_37->text();
    executeOperation(EXTENDABLE_ROD_MOTOR, SpindleOperation::MANUAL_MOTOR_OFF, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}

//撑线机构进退  --  绝对移动
void MiddelCircuitBreaker::on_pushButton_54_clicked()
{
    qDebug() << "撑线机构进退  --  绝对移动" << ui->lineEdit_35->text() << ui->lineEdit_36->text()  << ui->lineEdit_37->text();
    executeOperation(EXTENDABLE_ROD_MOTOR, SpindleOperation::ABSOLUTE_POSITION_MOTION, ui->lineEdit_35->text().toDouble(), ui->lineEdit_36->text().toDouble(), ui->lineEdit_37->text().toDouble());
}


