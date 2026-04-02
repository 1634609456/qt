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
    applyWireWindPressWheelButtonColors();
    applyPickWheelLiftPairButtonColors();
    applyPickWheelAdvanceRetreatButtonColors();
    applyCradleBinFrontDoorButtonColors();

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
            }
        });

  auto sync_ring_buffers = [this]() {
      auto* d = ShmManager::get_instance().get_data();
      if (!d) {
          return;
      }
      buffer.set_buffer(&d->buffer_P);
      buffer_M.set_buffer(&d->buffer_M);
  };

  connect(
      &ShmManager::get_instance(), &ShmManager::loaded, [this, timer, sync_ring_buffers](bool success) {

        if (success) {
          sync_ring_buffers();
          timer->start(500);
        }
      });
  // 页面晚于 loaded(true) 创建时会错过信号，必须先绑环形缓冲，否则 push 空指针崩溃
  sync_ring_buffers();
  if (ShmManager::get_instance().get_data()) {
      timer->start(500);
  }
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


void Blanking::push_mode_fsm_manual_if_auto_dual() {
    auto* d = ShmManager::get_instance().get_data();
    if (!d) {
        QMessageBox::warning(this, tr("未连接"), tr("未连接到共享内存，请先加载共享内存"));
        return;
    }
    buffer.set_buffer(&d->buffer_P);
    buffer_M.set_buffer(&d->buffer_M);
    if (d->feedback.fsm_fdb.mode != AUTO) {
        return;
    }
    COMMOND_GROUPS mode_cmd{};
    mode_cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MODE_CMD;
    mode_cmd.mode_fsm_event_type = MODE_EVENT_MANUAL;
    buffer.push(mode_cmd);
    buffer_M.push(mode_cmd);
}

void Blanking::push_mode_fsm_ensure_manual_dual() {
    auto* d = ShmManager::get_instance().get_data();
    if (!d) {
        QMessageBox::warning(this, tr("未连接"), tr("未连接到共享内存，请先加载共享内存"));
        return;
    }
    buffer.set_buffer(&d->buffer_P);
    buffer_M.set_buffer(&d->buffer_M);
    if (d->feedback.fsm_fdb.mode == MANUAL) {
        return;
    }
    COMMOND_GROUPS mode_cmd{};
    mode_cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MODE_CMD;
    mode_cmd.mode_fsm_event_type = MODE_EVENT_MANUAL;
    buffer.push(mode_cmd);
    buffer_M.push(mode_cmd);
}

void Blanking::push_io_manual_dual(const COMMOND_GROUPS& cmd) {
    auto* d = ShmManager::get_instance().get_data();
    if (!d) {
        QMessageBox::warning(this, tr("未连接"), tr("未连接到共享内存，请先加载共享内存"));
        return;
    }
    buffer.set_buffer(&d->buffer_P);
    buffer_M.set_buffer(&d->buffer_M);
    buffer.push(cmd);
    buffer_M.push(cmd);
}

void Blanking::applyWireWindPressWheelButtonColors()
{
    static const char* const kGreen =
        "background-color: rgb(0, 255, 0); color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;";
    static const char* const kGray =
        "background-color: gray; color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;";
    switch (wire_wind_press_wheel_ui_highlight_) {
    case WireWindPressWheelUiHighlight::LiftGreen:
        ui->pushButton_28->setStyleSheet(kGreen);
        ui->pushButton_29->setStyleSheet(kGray);
        break;
    case WireWindPressWheelUiHighlight::LowGreen:
        ui->pushButton_28->setStyleSheet(kGray);
        ui->pushButton_29->setStyleSheet(kGreen);
        break;
    case WireWindPressWheelUiHighlight::Neutral:
    default:
        ui->pushButton_28->setStyleSheet(kGray);
        ui->pushButton_29->setStyleSheet(kGray);
        break;
    }
}

void Blanking::applyPickWheelAdvanceRetreatButtonColors()
{
    static const char* const kGreen =
        "background-color: rgb(0, 255, 0); color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;";
    static const char* const kRed =
        "background-color: rgb(220, 40, 40); color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;";
    static const char* const kGray =
        "background-color: gray; color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;";
    switch (pick_wheel_advance_ui_highlight_) {
    case PickWheelAdvanceRetreatUiHighlight::UpperGreen:
        ui->pushButton_32->setStyleSheet(kGreen);
        break;
    case PickWheelAdvanceRetreatUiHighlight::LowerRed:
        ui->pushButton_32->setStyleSheet(kRed);
        break;
    case PickWheelAdvanceRetreatUiHighlight::Neutral:
    default:
        ui->pushButton_32->setStyleSheet(kGray);
        break;
    }
}

void Blanking::applyPickWheelLiftPairButtonColors()
{
    static const char* const kGreen =
        "background-color: rgb(0, 255, 0); color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;";
    static const char* const kGray =
        "background-color: gray; color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;";
    switch (pick_wheel_lift_pair_ui_highlight_) {
    case PickWheelLiftPairUiHighlight::LiftGreen:
        ui->pushButton_30->setStyleSheet(kGreen);
        ui->pushButton_31->setStyleSheet(kGray);
        break;
    case PickWheelLiftPairUiHighlight::LowGreen:
        ui->pushButton_30->setStyleSheet(kGray);
        ui->pushButton_31->setStyleSheet(kGreen);
        break;
    case PickWheelLiftPairUiHighlight::Neutral:
    default:
        ui->pushButton_30->setStyleSheet(kGray);
        ui->pushButton_31->setStyleSheet(kGray);
        break;
    }
}

void Blanking::applyCradleBinFrontDoorButtonColors()
{
    static const char* const kGreen =
        "background-color: rgb(0, 255, 0); color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;";
    static const char* const kGray =
        "background-color: gray; color: white; font-weight: bold; border: none; padding: 5px; border-radius: 3px;";
    switch (cradle_bin_front_door_ui_highlight_) {
    case CradleBinFrontDoorUiHighlight::OpenGreen:
        ui->pushButton_34->setStyleSheet(kGreen);
        ui->pushButton_35->setStyleSheet(kGray);
        break;
    case CradleBinFrontDoorUiHighlight::CloseGreen:
        ui->pushButton_34->setStyleSheet(kGray);
        ui->pushButton_35->setStyleSheet(kGreen);
        break;
    case CradleBinFrontDoorUiHighlight::Neutral:
    default:
        ui->pushButton_34->setStyleSheet(kGray);
        ui->pushButton_35->setStyleSheet(kGray);
        break;
    }
}

//收线轮压轮气缸阀 - 升（自动→手动；与降互锁，同 data_monitor IO）
void Blanking::on_pushButton_28_clicked()
{
    push_mode_fsm_manual_if_auto_dual();
    auto* d = ShmManager::get_instance().get_data();
    if (!d) {
        return;
    }
    const UINT8 q4 = d->io.valve_output[0];
    const int lift_bit = static_cast<int>(BIDIRECTIONAL_VALVE_LIFT_WIRE_WIND_PRESS_WHEEL_CYLINDER);
    const bool lift_on = (q4 >> lift_bit) & 1;

    // 互锁：升动作前先将「降」输出下使能（关）
    {
        COMMOND_GROUPS off_low{};
        off_low.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
        off_low.io_manual_control.output_signal_name = static_cast<int>(BIDIRECTIONAL_VALVE_LOW_WIRE_WIND_PRESS_WHEEL_CYLINDER);
        off_low.io_manual_control.value = YKE_BOOL::YKE_FALSE;
        push_io_manual_dual(off_low);
    }

    COMMOND_GROUPS cmd{};
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
    cmd.io_manual_control.output_signal_name = static_cast<int>(BIDIRECTIONAL_VALVE_LIFT_WIRE_WIND_PRESS_WHEEL_CYLINDER);
    cmd.io_manual_control.value = lift_on ? YKE_BOOL::YKE_FALSE : YKE_BOOL::YKE_TRUE;
    if (lift_on) {
        qDebug() << "收线压轮气缸 升 - 开启状态 → 关";
    } else {
        qDebug() << "收线压轮气缸 升 - 关闭状态 → 开";
    }
    push_io_manual_dual(cmd);

    wire_wind_press_wheel_ui_highlight_ = WireWindPressWheelUiHighlight::LiftGreen;
    applyWireWindPressWheelButtonColors();
}


//收线轮压轮气缸阀 - 降（自动→手动；与升互锁）
void Blanking::on_pushButton_29_clicked()
{
    push_mode_fsm_manual_if_auto_dual();
    auto* d = ShmManager::get_instance().get_data();
    if (!d) {
        return;
    }
    const UINT8 q4 = d->io.valve_output[0];
    const int low_bit = static_cast<int>(BIDIRECTIONAL_VALVE_LOW_WIRE_WIND_PRESS_WHEEL_CYLINDER);
    const bool low_on = (q4 >> low_bit) & 1;

    // 互锁：降动作前先将「升」输出下使能（关）
    {
        COMMOND_GROUPS off_lift{};
        off_lift.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
        off_lift.io_manual_control.output_signal_name = static_cast<int>(BIDIRECTIONAL_VALVE_LIFT_WIRE_WIND_PRESS_WHEEL_CYLINDER);
        off_lift.io_manual_control.value = YKE_BOOL::YKE_FALSE;
        push_io_manual_dual(off_lift);
    }

    COMMOND_GROUPS cmd{};
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
    cmd.io_manual_control.output_signal_name = static_cast<int>(BIDIRECTIONAL_VALVE_LOW_WIRE_WIND_PRESS_WHEEL_CYLINDER);
    cmd.io_manual_control.value = low_on ? YKE_BOOL::YKE_FALSE : YKE_BOOL::YKE_TRUE;
    if (low_on) {
        qDebug() << "收线压轮气缸 降 - 开启状态 → 关";
    } else {
        qDebug() << "收线压轮气缸 降 - 关闭状态 → 开";
    }
    push_io_manual_dual(cmd);

    wire_wind_press_wheel_ui_highlight_ = WireWindPressWheelUiHighlight::LowGreen;
    applyWireWindPressWheelButtonColors();
}


//双向阀升，取轮升降（自动→手动；与降互锁；同收线压轮气缸阀格式）
void Blanking::on_pushButton_30_clicked()
{
    push_mode_fsm_manual_if_auto_dual();
    auto* d = ShmManager::get_instance().get_data();
    if (!d) {
        return;
    }
    const UINT8 q = d->io.valve_output[4];
    const bool lift_on = (q >> 0) & 1;

    // 互锁：升动作前先将「降」输出下使能（关）
    {
        COMMOND_GROUPS off_low{};
        off_low.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
        off_low.io_manual_control.output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LOW_PICK_WHEEL_LIFT;
        off_low.io_manual_control.value = YKE_BOOL::YKE_FALSE;
        push_io_manual_dual(off_low);
    }

    COMMOND_GROUPS cmd{};
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
    cmd.io_manual_control.output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LIFT_PICK_WHEEL_LIFT;
    cmd.io_manual_control.value = lift_on ? YKE_BOOL::YKE_FALSE : YKE_BOOL::YKE_TRUE;
    if (lift_on) {
        qDebug() << "双向阀升，取轮升降 - 开启状态 → 关";
    } else {
        qDebug() << "双向阀升，取轮升降 - 关闭状态 → 开";
    }
    push_io_manual_dual(cmd);

    pick_wheel_lift_pair_ui_highlight_ = PickWheelLiftPairUiHighlight::LiftGreen;
    applyPickWheelLiftPairButtonColors();
}


//双向阀降，取轮升降（自动→手动；与升互锁；同收线压轮气缸阀格式）
void Blanking::on_pushButton_31_clicked()
{
    push_mode_fsm_manual_if_auto_dual();
    auto* d = ShmManager::get_instance().get_data();
    if (!d) {
        return;
    }
    const UINT8 q = d->io.valve_output[4];
    const bool low_on = (q >> 1) & 1;

    // 互锁：降动作前先将「升」输出下使能（关）
    {
        COMMOND_GROUPS off_lift{};
        off_lift.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
        off_lift.io_manual_control.output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LIFT_PICK_WHEEL_LIFT;
        off_lift.io_manual_control.value = YKE_BOOL::YKE_FALSE;
        push_io_manual_dual(off_lift);
    }

    COMMOND_GROUPS cmd{};
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
    cmd.io_manual_control.output_signal_name = VALVE_OUTPUT_NAME::BIDIRECTIONAL_VALVE_LOW_PICK_WHEEL_LIFT;
    cmd.io_manual_control.value = low_on ? YKE_BOOL::YKE_FALSE : YKE_BOOL::YKE_TRUE;
    if (low_on) {
        qDebug() << "双向阀降，取轮升降 - 开启状态 → 关";
    } else {
        qDebug() << "双向阀降，取轮升降 - 关闭状态 → 开";
    }
    push_io_manual_dual(cmd);

    pick_wheel_lift_pair_ui_highlight_ = PickWheelLiftPairUiHighlight::LowGreen;
    applyPickWheelLiftPairButtonColors();
}


//取轮进退（自动→手动；按 valve_output[4] bit6 翻转；同收线压轮 IO 双缓冲格式）
void Blanking::on_pushButton_32_clicked()
{
    push_mode_fsm_manual_if_auto_dual();
    auto* d = ShmManager::get_instance().get_data();
    if (!d) {
        return;
    }
    const bool bit = (d->io.valve_output[4] >> 6) & 1;

    const YKE_BOOL val = bit ? YKE_BOOL::YKE_FALSE : YKE_BOOL::YKE_TRUE;
    if (val == YKE_BOOL::YKE_TRUE) {
        qDebug() << "取轮进退 - 上使能";
    } else {
        qDebug() << "取轮进退 - 下使能";
    }

    COMMOND_GROUPS cmd{};
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
    cmd.io_manual_control.output_signal_name = VALVE_OUTPUT_NAME::PICK_WHEEL_ADVANCE_RETREAT;
    cmd.io_manual_control.value = val;
    push_io_manual_dual(cmd);

    pick_wheel_advance_ui_highlight_ = (val == YKE_BOOL::YKE_TRUE) ? PickWheelAdvanceRetreatUiHighlight::UpperGreen
                                                                    : PickWheelAdvanceRetreatUiHighlight::LowerRed;
    applyPickWheelAdvanceRetreatButtonColors();
}


//摇篮仓前门开（双向阀开，摇篮仓前对开门；与关互锁；非手动先切手动）
void Blanking::on_pushButton_34_clicked()
{
    push_mode_fsm_ensure_manual_dual();
    auto* d = ShmManager::get_instance().get_data();
    if (!d) {
        return;
    }
    const int open_e = static_cast<int>(BIDIRECTIONAL_VALVE_OPEN_CRADLE_BIN_FRONT_DOOR_OPEN);
    const int close_e = static_cast<int>(BIDIRECTIONAL_VALVE_CLOSE_CRADLE_BIN_FRONT_DOOR_OPEN);
    const UINT8 qb = d->io.valve_output[open_e / 8];
    const bool open_on = (qb >> (open_e % 8)) & 1;

    {
        COMMOND_GROUPS off_close{};
        off_close.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
        off_close.io_manual_control.output_signal_name = close_e;
        off_close.io_manual_control.value = YKE_BOOL::YKE_FALSE;
        push_io_manual_dual(off_close);
    }

    COMMOND_GROUPS cmd{};
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
    cmd.io_manual_control.output_signal_name = open_e;
    cmd.io_manual_control.value = open_on ? YKE_BOOL::YKE_FALSE : YKE_BOOL::YKE_TRUE;
    if (open_on) {
        qDebug() << "摇篮仓前门开 - 开启状态 → 关";
    } else {
        qDebug() << "摇篮仓前门开 - 关闭状态 → 开";
    }
    push_io_manual_dual(cmd);

    cradle_bin_front_door_ui_highlight_ = CradleBinFrontDoorUiHighlight::OpenGreen;
    applyCradleBinFrontDoorButtonColors();
}


//摇篮仓前门关（双向阀关，摇篮仓前对开门；与开互锁；非手动先切手动）
void Blanking::on_pushButton_35_clicked()
{
    push_mode_fsm_ensure_manual_dual();
    auto* d = ShmManager::get_instance().get_data();
    if (!d) {
        return;
    }
    const int open_e = static_cast<int>(BIDIRECTIONAL_VALVE_OPEN_CRADLE_BIN_FRONT_DOOR_OPEN);
    const int close_e = static_cast<int>(BIDIRECTIONAL_VALVE_CLOSE_CRADLE_BIN_FRONT_DOOR_OPEN);
    const UINT8 qb = d->io.valve_output[close_e / 8];
    const bool close_on = (qb >> (close_e % 8)) & 1;

    {
        COMMOND_GROUPS off_open{};
        off_open.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
        off_open.io_manual_control.output_signal_name = open_e;
        off_open.io_manual_control.value = YKE_BOOL::YKE_FALSE;
        push_io_manual_dual(off_open);
    }

    COMMOND_GROUPS cmd{};
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::IO_MANUAL_CONTROL_CMD;
    cmd.io_manual_control.output_signal_name = close_e;
    cmd.io_manual_control.value = close_on ? YKE_BOOL::YKE_FALSE : YKE_BOOL::YKE_TRUE;
    if (close_on) {
        qDebug() << "摇篮仓前门关 - 开启状态 → 关";
    } else {
        qDebug() << "摇篮仓前门关 - 关闭状态 → 开";
    }
    push_io_manual_dual(cmd);

    cradle_bin_front_door_ui_highlight_ = CradleBinFrontDoorUiHighlight::CloseGreen;
    applyCradleBinFrontDoorButtonColors();
}

