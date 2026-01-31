#include "blanking.h"
#include "ui_blanking.h"
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <qdebug.h>


#include "../../src/util/shm_manager.hpp"
#include "../../src/util/config_manager.hpp"


Blanking::Blanking(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Blanking)
    ,buffer(nullptr) 
    ,buffer_M(nullptr) 
{
    ui->setupUi(this);

        auto timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, [this]() {


        // 收线点动 -- 显示
        ui->lineEdit_2->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "speed"), 'f'));
        ui->lineEdit_3->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "acceleration"), 'f'));
        ui->lineEdit_6->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "position"), 'f'));


        //排线点动 -- 显示
        ui->lineEdit_4->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "speed"), 'f'));
        ui->lineEdit_5->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "acceleration"), 'f'));
        ui->lineEdit_10->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "position"), 'f'));


        //上下料旋转 - 显示
        ui->lineEdit_14->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "speed"), 'f'));
        ui->lineEdit_15->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "acceleration"), 'f'));
        ui->lineEdit_16->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "position"), 'f'));



        //压线机构升降  -- 显示
        ui->lineEdit_68->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "speed"), 'f'));
        ui->lineEdit_69->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "acceleration"), 'f'));
        ui->lineEdit_70->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "position"), 'f'));


        //空工字轮工位旋转  -- 显示
        ui->lineEdit_74->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "speed"), 'f'));
        ui->lineEdit_75->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "acceleration"), 'f'));
        ui->lineEdit_76->setText(QString::number(getMotorNum(CENTER_ADVANCE_RETREAT_MOTOR, "position"), 'f'));


    
            if (ShmManager::get_instance().get_data()) {
                
                //扭转控制
                UINT16 atn_on = ShmManager::get_instance().get_data()->mach_atm_to_planner.atm_to_planner.ATN_ON;
                if (atn_on == 1) {
            ui->pushButton_33->setStyleSheet("background-color: rgb(0, 255, 0); color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;");
                } else if (atn_on == 0) {
            ui->pushButton_33->setStyleSheet("background-color: rgba(255, 0, 0, 1); color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;");
                } else {
            ui->pushButton_33->setStyleSheet("background-color: gray; color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;");
                }
 

                //收线压轮气缸 升 - 监控
                if ((ShmManager::get_instance().get_data()->io.valve_output[0] >> 2) & 1 ) {
                    ui->pushButton_28->setStyleSheet("background-color: green; color: white; border: none; padding: 5px; border-radius: 3px;");
                } else {
                    ui->pushButton_28->setStyleSheet("background-color: gray; color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;");
                }

                //收线压轮气缸 降 - 监控
                if ((ShmManager::get_instance().get_data()->io.valve_output[0] >> 3) & 1) {
                    ui->pushButton_29->setStyleSheet("background-color: green; color: white; border: none; padding: 5px; border-radius: 3px;");
                } else {
                    ui->pushButton_29->setStyleSheet("background-color: gray; color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;");
                }

                //双向阀升，取轮升降 - 监控
                if ((ShmManager::get_instance().get_data()->io.valve_output[4] >> 0) & 1) { 
                    ui->pushButton_30->setStyleSheet("background-color: green; color: white; border: none; padding: 5px; border-radius: 3px;");
                } else {
                    ui->pushButton_30->setStyleSheet("background-color: gray; color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;");
                }
                
                //双向阀降，取轮升降 - 监控
                if (ShmManager::get_instance().get_data()->io.valve_output[4] >> 1 & 1) {
                    ui->pushButton_31->setStyleSheet("background-color: green; color: white; border: none; padding: 5px; border-radius: 3px;");
                } else {
                    ui->pushButton_31->setStyleSheet("background-color: gray; color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;");
                }

                // 取轮进退 - 监控
                if (ShmManager::get_instance().get_data()->io.valve_output[4] >> 6 & 1) {
                    ui->pushButton_32->setStyleSheet("background-color: green; color: white; border: none; padding: 5px; border-radius: 3px;");
                } else {
                    ui->pushButton_32->setStyleSheet("background-color: gray; color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;");
                }
            }
        });

  connect(
      &ShmManager::get_instance(), &ShmManager::loaded, [this, timer](bool success) {

        if (success) {
          buffer.set_buffer(&ShmManager::get_instance().get_data()->buffer_P);
          buffer_M.set_buffer(&ShmManager::get_instance().get_data()->buffer_M);
          timer->start(500);
        }
      });
}

void Blanking::executeOperation(int motorType, SpindleOperation operation, double speed, double acceleration, double position) {
    
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

    // COMMOND_GROUPS cmd;
    // cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD;
    // cmd.motor_manual_control = {
    //     cmdType,
    //     static_cast<MOTOR_TYPE>(motorType),
    //     speed,
    //     acceleration,
    //     position
    // }
    // buffer.push(cmd);


    COMMOND_GROUPS cmd;
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MOTOR_MANUAL_CONTROL_CMD;
    cmd.motor_manual_control.manual_control_cmd = cmdType;
    cmd.motor_manual_control.motor_type = static_cast<MOTOR_TYPE>(motorType);
    cmd.motor_manual_control.speed = speed;
    cmd.motor_manual_control.manual_acceleration = acceleration;
    cmd.motor_manual_control.manual_pos = position;
    buffer.push(cmd);
}
    

void Blanking::setEnableButtonState(QPushButton* enableButton, QPushButton* disableButton, bool isEnable)
{
    if (isEnable) {
        enableButton->setStyleSheet("background-color: green; color: white; border: none; padding: 5px; border-radius: 3px;");
        disableButton->setStyleSheet(""); 
    } else {
        disableButton->setStyleSheet("");
        enableButton->setStyleSheet(""); 
    }
}



// 获取电机的速度，加速度，位置
double Blanking::getMotorNum(int motorType, QString model) const
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


Blanking::~Blanking()
{
    delete ui;
}

//收线点动  -- 正点动
void Blanking::on_pushButton_pressed()
{
    qDebug() << "收线点动  --  正点动" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(MAIN_WINDING, SpindleOperation::FORWARD_JOGING, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}

void Blanking::on_pushButton_released()
{
    qDebug() << "收线点动  --  正点动释放";
    executeOperation(MAIN_WINDING, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}

//收线点动  -- 反点动点动
void Blanking::on_pushButton_4_pressed()
{
    qDebug() << "收线点动  --  反点动" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(MAIN_WINDING, SpindleOperation::REVERSE_JOGING, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}

void Blanking::on_pushButton_4_released()
{
    qDebug() << "收线点动  --  反点动释放";
    executeOperation(MAIN_WINDING, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}


//收线点动 -- 回零
void Blanking::on_pushButton_2_clicked()
{
    qDebug() << "收线点动 -- 回零" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(MAIN_WINDING, SpindleOperation::RETURN_TO_ZERO, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}


void Blanking::on_pushButton_7_clicked()
{
    qDebug() << "收线点动 -- 松闸" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(MAIN_WINDING, SpindleOperation::RELEASE_BRAKE, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}


void Blanking::on_pushButton_8_clicked()
{
    qDebug() << "收线点动 -- 抱闸" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(MAIN_WINDING, SpindleOperation::ENGAGE_BRAKE, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}


void Blanking::on_pushButton_9_clicked()
{
    qDebug() << "收线点动 -- 停止";
    executeOperation(MAIN_WINDING, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}


void Blanking::on_pushButton_3_clicked()
{
    qDebug() << "收线点动 -- 上使能";
    executeOperation(MAIN_WINDING, SpindleOperation::MANUAL_MOTOR_ON, 0.0, 0.0, 0.0);
    setEnableButtonState(ui->pushButton_3, ui->pushButton_5, true);
}


void Blanking::on_pushButton_5_clicked()
{
    qDebug() << "收线点动 -- 下使能";
    executeOperation(MAIN_WINDING, SpindleOperation::MANUAL_MOTOR_OFF, 0.0, 0.0, 0.0);
    setEnableButtonState(ui->pushButton_3, ui->pushButton_5, false);

}


void Blanking::on_pushButton_6_clicked()
{
    qDebug() << "收线点动 -- 绝对移动" << ui->lineEdit_9->text() << ui->lineEdit_8->text() << ui->lineEdit_7->text();
    executeOperation(MAIN_WINDING, SpindleOperation::ABSOLUTE_POSITION_MOTION, ui->lineEdit_9->text().toDouble(), ui->lineEdit_8->text().toDouble(), ui->lineEdit_7->text().toDouble());
}




// 排线点动  -- 正点动


void Blanking::on_pushButton_10_pressed()
{
    qDebug() << "排线点动  --  正点动" << ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(MAIN_LAYING, SpindleOperation::FORWARD_JOGING, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());
}


void Blanking::on_pushButton_10_released()
{
    qDebug() << "排线点动  --  正点动释放";
    executeOperation(MAIN_LAYING, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}


void Blanking::on_pushButton_11_pressed()
{
    qDebug() << "排线点动  --  反点动" << ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(MAIN_LAYING, SpindleOperation::REVERSE_JOGING, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());
}

void Blanking::on_pushButton_11_released()
{
    qDebug() << "排线点动  --  反点动释放";
    executeOperation(MAIN_LAYING, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}

void Blanking::on_pushButton_12_clicked()
{
    qDebug() << "排线点动 -- 回零" << ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(MAIN_LAYING, SpindleOperation::RETURN_TO_ZERO, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());

}
void Blanking::on_pushButton_13_clicked()
{
    qDebug() << "排线点动 -- 松闸" << ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(MAIN_LAYING, SpindleOperation::RELEASE_BRAKE, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());
}


void Blanking::on_pushButton_14_clicked()
{
    qDebug() << "排线点动 -- 抱闸" << ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(MAIN_LAYING, SpindleOperation::ENGAGE_BRAKE, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());

}


void Blanking::on_pushButton_15_clicked()
{
    qDebug() << "排线点动 -- 停止";
    executeOperation(MAIN_LAYING, SpindleOperation::STOP, 0.0, 0.0, 0.0);

}


void Blanking::on_pushButton_16_clicked()
{
    qDebug() << "排线点动 -- 上使能"<< ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(MAIN_WINDING, SpindleOperation::MANUAL_MOTOR_ON, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());
    setEnableButtonState(ui->pushButton_16, ui->pushButton_17, true);
}


void Blanking::on_pushButton_17_clicked()
{
    qDebug() << "排线点动 -- 下使能" << ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(MAIN_WINDING, SpindleOperation::MANUAL_MOTOR_OFF, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());
    setEnableButtonState(ui->pushButton_16, ui->pushButton_17, false);

}


void Blanking::on_pushButton_18_clicked()
{
    qDebug() << "排线点动 -- 绝对移动" << ui->lineEdit_11->text() << ui->lineEdit_12->text() << ui->lineEdit_13->text();
    executeOperation(MAIN_LAYING, SpindleOperation::ABSOLUTE_POSITION_MOTION, ui->lineEdit_11->text().toDouble(), ui->lineEdit_12->text().toDouble(), ui->lineEdit_13->text().toDouble());
}


// 上料旋转  -- 正点动
void Blanking::on_pushButton_19_pressed()
{
    qDebug() << "上下料旋转  --  正点动" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(LOAD_ROTATING_MOTOR, SpindleOperation::FORWARD_JOGING, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}

void Blanking::on_pushButton_19_released()
{
    qDebug() << "上下料旋转  --  正点动释放";
    executeOperation(LOAD_ROTATING_MOTOR, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}



void Blanking::on_pushButton_20_pressed()
{
    qDebug() << "上下料旋转  --  反点动" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(LOAD_ROTATING_MOTOR, SpindleOperation::REVERSE_JOGING, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}

void Blanking::on_pushButton_20_released()
{
    qDebug() << "上下料旋转  --  反点动释放";
    executeOperation(LOAD_ROTATING_MOTOR, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}

void Blanking::on_pushButton_21_clicked()
{
    qDebug() << "上下料旋转 -- 回零" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(LOAD_ROTATING_MOTOR, SpindleOperation::RETURN_TO_ZERO, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}


void Blanking::on_pushButton_22_clicked()
{
    qDebug() << "上下料旋转 -- 松闸" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(LOAD_ROTATING_MOTOR, SpindleOperation::RELEASE_BRAKE, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}


void Blanking::on_pushButton_23_clicked()
{
    qDebug() << "上下料旋转 -- 抱闸" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(LOAD_ROTATING_MOTOR, SpindleOperation::ENGAGE_BRAKE, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}


void Blanking::on_pushButton_24_clicked()
{
    qDebug() << "上下料旋转 -- 停止";
    executeOperation(LOAD_ROTATING_MOTOR, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}


void Blanking::on_pushButton_25_clicked()
{
    qDebug() << "上下料旋转 -- 上使能" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(LOAD_ROTATING_MOTOR, SpindleOperation::MANUAL_MOTOR_ON, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
    setEnableButtonState(ui->pushButton_25, ui->pushButton_26, true);

}   


void Blanking::on_pushButton_26_clicked()
{
    qDebug() << "上下料旋转 -- 下使能" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(LOAD_ROTATING_MOTOR, SpindleOperation::MANUAL_MOTOR_OFF, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
    setEnableButtonState(ui->pushButton_25, ui->pushButton_26, false);

}   


void Blanking::on_pushButton_27_clicked()
{
    qDebug() << "上下料旋转 -- 绝对移动" << ui->lineEdit_17->text() << ui->lineEdit_18->text() << ui->lineEdit_19->text();
    executeOperation(LOAD_ROTATING_MOTOR, SpindleOperation::ABSOLUTE_POSITION_MOTION, ui->lineEdit_17->text().toDouble(), ui->lineEdit_18->text().toDouble(), ui->lineEdit_19->text().toDouble());
}



//压线机构升降  -- 正点动
void Blanking::on_pushButton_100_pressed()
{
    
}



void Blanking::on_pushButton_100_released()
{

}


void Blanking::on_pushButton_101_pressed()
{

}
void Blanking::on_pushButton_101_released()
{

}


void Blanking::on_pushButton_102_clicked()
{

}


void Blanking::on_pushButton_103_clicked()
{

}


void Blanking::on_pushButton_104_clicked()
{

}


void Blanking::on_pushButton_105_clicked()
{

}


void Blanking::on_pushButton_106_clicked()
{

}


void Blanking::on_pushButton_107_clicked()
{

}


void Blanking::on_pushButton_108_clicked()
{

}



//空轮定位 -- 正点动
void Blanking::on_pushButton_109_pressed()
{
    qDebug() << "空工字轮工位旋转  --  正点动" << ui->lineEdit_77->text() << ui->lineEdit_78->text() << ui->lineEdit_79->text();
    executeOperation(    FREE_WHEEL_LOCATOR, SpindleOperation::FORWARD_JOGING, ui->lineEdit_77->text().toDouble(), ui->lineEdit_78->text().toDouble(), ui->lineEdit_79->text().toDouble());
}

void Blanking::on_pushButton_109_released()
{
    qDebug() << "空工字轮工位旋转  --  正点动释放";
    executeOperation(    FREE_WHEEL_LOCATOR, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}


void Blanking::on_pushButton_110_pressed()
{
    qDebug() << "空工字轮工位旋转  --  反点动" << ui->lineEdit_77->text() << ui->lineEdit_78->text() << ui->lineEdit_79->text();
    executeOperation(    FREE_WHEEL_LOCATOR, SpindleOperation::REVERSE_JOGING, ui->lineEdit_77->text().toDouble(), ui->lineEdit_78->text().toDouble(), ui->lineEdit_79->text().toDouble());
}

void Blanking::on_pushButton_110_released()
{
    qDebug() << "空工字轮工位旋转  --  反点动释放";
    executeOperation(    FREE_WHEEL_LOCATOR, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}


void Blanking::on_pushButton_111_clicked()
{
    qDebug() << "空工字轮工位旋转 -- 回零" << ui->lineEdit_77->text() << ui->lineEdit_78->text() << ui->lineEdit_79->text();
    executeOperation(    FREE_WHEEL_LOCATOR, SpindleOperation::RETURN_TO_ZERO, ui->lineEdit_77->text().toDouble(), ui->lineEdit_78->text().toDouble(), ui->lineEdit_79->text().toDouble());
}


void Blanking::on_pushButton_112_clicked()
{
    qDebug() << "空工字轮工位旋转 -- 松闸" << ui->lineEdit_77->text() << ui->lineEdit_78->text() << ui->lineEdit_79->text();
    executeOperation(    FREE_WHEEL_LOCATOR, SpindleOperation::RELEASE_BRAKE, ui->lineEdit_77->text().toDouble(), ui->lineEdit_78->text().toDouble(), ui->lineEdit_79->text().toDouble());
}


void Blanking::on_pushButton_113_clicked()
{
    qDebug() << "空工字轮工位旋转 -- 抱闸" << ui->lineEdit_77->text() << ui->lineEdit_78->text() << ui->lineEdit_79->text();
    executeOperation(    FREE_WHEEL_LOCATOR, SpindleOperation::ENGAGE_BRAKE, ui->lineEdit_77->text().toDouble(), ui->lineEdit_78->text().toDouble(), ui->lineEdit_79->text().toDouble());
}


void Blanking::on_pushButton_114_clicked()
{
    qDebug() << "空工字轮工位旋转 -- 停止";
    executeOperation(    FREE_WHEEL_LOCATOR, SpindleOperation::STOP, 0.0, 0.0, 0.0);
}


void Blanking::on_pushButton_115_clicked()
{
    qDebug() << "空工字轮工位旋转 -- 上使能" << ui->lineEdit_77->text() << ui->lineEdit_78->text() << ui->lineEdit_79->text();
    executeOperation(    FREE_WHEEL_LOCATOR, SpindleOperation::MANUAL_MOTOR_ON, ui->lineEdit_77->text().toDouble(), ui->lineEdit_78->text().toDouble(), ui->lineEdit_79->text().toDouble());
    setEnableButtonState(ui->pushButton_115, ui->pushButton_117, true);
}


void Blanking::on_pushButton_116_clicked()
{
    qDebug() << "空工字轮工位旋转 -- 下使能" << ui->lineEdit_77->text() << ui->lineEdit_78->text() << ui->lineEdit_79->text();
    executeOperation(    FREE_WHEEL_LOCATOR, SpindleOperation::MANUAL_MOTOR_OFF, ui->lineEdit_77->text().toDouble(), ui->lineEdit_78->text().toDouble(), ui->lineEdit_79->text().toDouble());
    setEnableButtonState(ui->pushButton_115, ui->pushButton_117, false);
}


void Blanking::on_pushButton_117_clicked()
{
    qDebug() << "空工字轮工位旋转 -- 绝对移动" << ui->lineEdit_77->text() << ui->lineEdit_78->text() << ui->lineEdit_79->text();
    executeOperation(    FREE_WHEEL_LOCATOR, SpindleOperation::ABSOLUTE_POSITION_MOTION, ui->lineEdit_77->text().toDouble(), ui->lineEdit_78->text().toDouble(), ui->lineEdit_79->text().toDouble());
}


//收线轮压轮气缸阀 - 升
void Blanking::on_pushButton_28_clicked()
{
    //查询当前状态
    if (ShmManager::get_instance().get_data()->io.valve_output[0] >> VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LIFT_WIRE_WIND_PRESS_WHEEL_CYLINDER & 1) {

        qDebug() << "收线压轮气缸 升 - 开启状态";

        //  buffer_M.push({
        // .cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD,
        // .io_manual_control = {
        //     .output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LIFT_WIRE_WIND_PRESS_WHEEL_CYLINDER,   
        //     .value = YKE_BOOL::YKE_FALSE
        // }});

        COMMOND_GROUPS cmd;
        cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
        cmd.io_manual_control.output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LIFT_WIRE_WIND_PRESS_WHEEL_CYLINDER;
        cmd.io_manual_control.value = YKE_BOOL::YKE_FALSE;
        buffer_M.push(cmd);
    } else {
        
        qDebug() << "收线压轮气缸 升 - 关闭状态";

        //  buffer_M.push({
        // .cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD,
        // .io_manual_control = {
        //     .output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LIFT_WIRE_WIND_PRESS_WHEEL_CYLINDER,
        //     .value = YKE_BOOL::YKE_TRUE
        // }});
        COMMOND_GROUPS cmd;
        cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
        cmd.io_manual_control.output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LIFT_WIRE_WIND_PRESS_WHEEL_CYLINDER;
        cmd.io_manual_control.value = YKE_BOOL::YKE_TRUE;
        buffer_M.push(cmd);
    }
}


//收线轮压轮气缸阀 - 降
void Blanking::on_pushButton_29_clicked()
{
    //查询当前状态
    if (ShmManager::get_instance().get_data()->io.valve_output[0] >> VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LOW_WIRE_WIND_PRESS_WHEEL_CYLINDER & 1) {

        qDebug() << "收线压轮气缸 降 - 开启状态";

        //  buffer_M.push({
        // .cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD,
        // .io_manual_control = {
        //     .output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LOW_WIRE_WIND_PRESS_WHEEL_CYLINDER,
        //     .value = YKE_BOOL::YKE_FALSE
        // }});

        COMMOND_GROUPS cmd;
        cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
        cmd.io_manual_control.output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LOW_WIRE_WIND_PRESS_WHEEL_CYLINDER;
        cmd.io_manual_control.value = YKE_BOOL::YKE_FALSE;
        buffer_M.push(cmd);

    } else {
    
        qDebug() << "收线压轮气缸 降 - 关闭状态";

        //  buffer_M.push({
        // .cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD,
        // .io_manual_control = {
        //     .output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LOW_WIRE_WIND_PRESS_WHEEL_CYLINDER,
        //     .value = YKE_BOOL::YKE_TRUE
        // }});

        COMMOND_GROUPS cmd;
        cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
        cmd.io_manual_control.output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LOW_WIRE_WIND_PRESS_WHEEL_CYLINDER;
        cmd.io_manual_control.value = YKE_BOOL::YKE_TRUE;
        buffer_M.push(cmd);
    }
}


//双向阀升，取轮升降
void Blanking::on_pushButton_30_clicked()
{
    //查询当前状态
    if (ShmManager::get_instance().get_data()->io.valve_output[4] >> 0 & 1) {

        qDebug() << "双向阀升，取轮升降 - 开启状态";

        //  buffer_M.push({
        // .cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD,
        // .io_manual_control = {
        //     .output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LIFT_PICK_WHEEL_LIFT,
        //     .value = YKE_BOOL::YKE_FALSE
        // }});
        
        COMMOND_GROUPS cmd;
        cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
        cmd.io_manual_control.output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LIFT_PICK_WHEEL_LIFT;
        cmd.io_manual_control.value = YKE_BOOL::YKE_FALSE;
        buffer_M.push(cmd);
    } else {
    
        qDebug() << "双向阀升，取轮升降 - 关闭状态";

        //  buffer_M.push({
        // .cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD,
        // .io_manual_control = {
        //     .output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LIFT_PICK_WHEEL_LIFT,
        //     .value = YKE_BOOL::YKE_TRUE
        // }});

        COMMOND_GROUPS cmd;
        cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
        cmd.io_manual_control.output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LIFT_PICK_WHEEL_LIFT;
        cmd.io_manual_control.value = YKE_BOOL::YKE_TRUE;
        buffer_M.push(cmd);
    }
}



//双向阀降，取轮升降
void Blanking::on_pushButton_31_clicked()
{
     //查询当前状态
    if (ShmManager::get_instance().get_data()->io.valve_output[4] >> 1 & 1) {

        qDebug() << "双向阀降，取轮升降 - 开启状态";

        //  buffer_M.push({
        // .cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD,
        // .io_manual_control = {
        //     .output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LOW_PICK_WHEEL_LIFT,
        //     .value = YKE_BOOL::YKE_FALSE
        // }});

        COMMOND_GROUPS cmd;
        cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
        cmd.io_manual_control.output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LOW_PICK_WHEEL_LIFT;
        cmd.io_manual_control.value = YKE_BOOL::YKE_FALSE;
        buffer_M.push(cmd);
    } else {
    
        qDebug() << "双向阀降，取轮升降 - 关闭状态";

        //  buffer_M.push({
        // .cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD,
        // .io_manual_control = {
        //     .output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LOW_PICK_WHEEL_LIFT,
        //     .value = YKE_BOOL::YKE_TRUE
        // }});

        COMMOND_GROUPS cmd;
        cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
        cmd.io_manual_control.output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LOW_PICK_WHEEL_LIFT;
        cmd.io_manual_control.value = YKE_BOOL::YKE_TRUE;
        buffer_M.push(cmd);
    }
}


//取轮进退 PICK_WHEEL_ADVANCE_RETREAT
void Blanking::on_pushButton_32_clicked()
{
     //查询当前状态
    if (ShmManager::get_instance().get_data()->io.valve_output[4] >> 6 & 1) {

        qDebug() << "取轮进退 - 开启状态";

        //  buffer_M.push({
        // .cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD,
        // .io_manual_control = {
        //     .output_signal_name = VALVE_OUTPUT_NAME::PICK_WHEEL_ADVANCE_RETREAT,
        //     .value = YKE_BOOL::YKE_FALSE
        // }});

        COMMOND_GROUPS cmd;
        cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
        cmd.io_manual_control.output_signal_name = VALVE_OUTPUT_NAME::PICK_WHEEL_ADVANCE_RETREAT;
        cmd.io_manual_control.value = YKE_BOOL::YKE_FALSE;
        buffer_M.push(cmd);
    } else {
    
        qDebug() << "取轮进退 - 关闭状态";

        //  buffer_M.push({
        // .cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD,
        // .io_manual_control = {
        //     .output_signal_name = VALVE_OUTPUT_NAME::PICK_WHEEL_ADVANCE_RETREAT,
        //     .value = YKE_BOOL::YKE_TRUE
        // }});

        COMMOND_GROUPS cmd;
        cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
        cmd.io_manual_control.output_signal_name = VALVE_OUTPUT_NAME::PICK_WHEEL_ADVANCE_RETREAT;
        cmd.io_manual_control.value = YKE_BOOL::YKE_TRUE;
        buffer_M.push(cmd);
    }
}

