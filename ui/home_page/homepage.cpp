#include "homepage.h"
#include "ui_homepage.h"
#include "../../src/util/password_manager/password_manager.h"
#include "../../src/util/user_role.h"

#include <QDebug>
#include <QTimer>
#include <cstdlib>
#include <QMessageBox>      
#include <QInputDialog>
#include <qlogging.h>
#include <qtimer.h>
#include <winsock.h>

#include "../../src/util/shm_manager.hpp"

HomePage::HomePage(QWidget *parent)
    : QWidget(parent), 
    ui(new Ui::HomePage), 
    buffer(nullptr) // 初始化环形缓冲区
{
  ui->setupUi(this);

      // 初始化UI根据当前用户角色
      updateUIBasedOnUserRole();

          // 主轴速度读取
          auto timer = new QTimer(this);
          connect(timer, &QTimer::timeout, this, [this]() {
            // // 模拟数据更新
            // auto data = rand() % 100;

            // 主轴速度
            auto data = ShmManager::get_instance()
                            .get_data()
                            ->feedback.motor_fdb[MAIN_SPINDLE]
                            .running_speed;
            ui->label_5->setText(QString::number(data));

            // 排线电机上限位显示
            auto upper_limit = ShmManager::get_instance()
                                 .get_data()
                                 ->feedback.wheel_fdb.start_length_ref;
            ui->label_8->setText(QString::number(upper_limit/8388608));

            // 排线电机下限位显示
            auto lower_limit = ShmManager::get_instance()
                                 .get_data()
                                 ->feedback.wheel_fdb.finish_length_ref;
            ui->label_17->setText(QString::number(lower_limit/8388608));
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



// 在头文件中声明
void HomePage::on_switchUserRoleButton_clicked()
{
    // 创建选项列表
    QStringList items;
    items << tr("游客") << tr("操作员");
    
    bool ok;
    QString item = QInputDialog::getItem(this, tr("切换用户"),
                                         tr("选择用户角色:"), items, 
                                         static_cast<int>(UserManager::getInstance().getCurrentRole()),
                                         false, &ok);
    if (ok && !item.isEmpty()) {
        if (item == tr("游客")) {
            UserManager::getInstance().setCurrentRole(UserRole::Guest);
        } else if (item == tr("操作员")) {
            // 可以在这里添加密码验证
            UserManager::getInstance().setCurrentRole(UserRole::Operator);
        }
        
        // 更新界面显示
        updateUIBasedOnUserRole();
    }
}


// 权限使用
void HomePage::updateUIBasedOnUserRole()
{
    bool isOperator = UserManager::getInstance().isOperator();
    
    // 禁用/启用需要权限的控件
    // 主轴速度输入框
    ui->lineEdit_2->setEnabled(isOperator);  
    ui->pushButton->setEnabled(isOperator);  

    // 撑杆退PID参数：
    ui->lineEdit_3->setEnabled(isOperator);  
    ui->lineEdit_4->setEnabled(isOperator);
    ui->lineEdit_5->setEnabled(isOperator);  
    ui->pushButton_2->setEnabled(isOperator);

    // 撑杆进PID参数：
    ui->lineEdit_6->setEnabled(isOperator);
    ui->lineEdit_7->setEnabled(isOperator);
    ui->lineEdit_8->setEnabled(isOperator);
    ui->pushButton_3->setEnabled(isOperator);

    // 中穿进PID参数：
    ui->lineEdit_9->setEnabled(isOperator);
    ui->lineEdit_10->setEnabled(isOperator);
    ui->lineEdit_11->setEnabled(isOperator);
    ui->pushButton_4->setEnabled(isOperator);

    // 边穿进PID参数：
    ui->lineEdit_12->setEnabled(isOperator);
    ui->lineEdit_13->setEnabled(isOperator);
    ui->lineEdit_14->setEnabled(isOperator);
    ui->pushButton_5->setEnabled(isOperator);

    //上限位修改
    ui->lineEdit_15->setEnabled(isOperator);
    ui->pushButton_6->setEnabled(isOperator);
    //下限位修改
    ui->lineEdit_16->setEnabled(isOperator);
    ui->pushButton_7->setEnabled(isOperator);
}

// 运行
void HomePage::on_pushButton_14_clicked()
{
    COMMOND_GROUPS cmd;
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD;
    cmd.main_fsm_event_type = MAIN_EVENT_CONTROL_ON;
    buffer.push(cmd);

    qDebug() << "运行按钮";
}

// 停止
void HomePage::on_pushButton_13_clicked()
{
    COMMOND_GROUPS cmd;
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD;
    cmd.main_fsm_event_type = MAIN_EVENT_CONTROL_OFF;
    buffer.push(cmd);

    qDebug() << "停止按钮";
}

// 急停
void HomePage::on_pushButton_15_clicked()
{
    COMMOND_GROUPS cmd;
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD;
    cmd.main_fsm_event_type = MAIN_EVENT_EME_STOP;
    buffer.push(cmd);

    qDebug() << "急停按钮";
}

// 急停清除
void HomePage::on_pushButton_16_clicked()
{
    COMMOND_GROUPS cmd;
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD;
    cmd.main_fsm_event_type = MAIN_EVENT_EME_STOP_CLEAR;
    buffer.push(cmd);

    qDebug() << "急停清除按钮";
}

// 错误
void HomePage::on_pushButton_9_clicked()
{
    COMMOND_GROUPS cmd;
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD;
    cmd.main_fsm_event_type = MAIN_EVENT_ERROR;
    buffer.push(cmd);

    qDebug() << "错误按钮";
}

// 错误复位
void HomePage::on_pushButton_10_clicked()
{
    COMMOND_GROUPS cmd;
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD;
    cmd.main_fsm_event_type = MAIN_EVENT_ERROR_RESET;
    buffer.push(cmd);

    qDebug() << "错误复位按钮";
}

// 上电
void HomePage::on_pushButton_11_clicked()
{
    COMMOND_GROUPS cmd;
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD;
    cmd.main_fsm_event_type = MAIN_EVENT_MOTOR_ON;
    buffer.push(cmd);

    qDebug() << "上电按钮";
}

// 下电
void HomePage::on_pushButton_12_clicked()
{
    COMMOND_GROUPS cmd;
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD;
    cmd.main_fsm_event_type = MAIN_EVENT_MOTOR_OFF;
    buffer.push(cmd);

    qDebug() << "下电按钮";
}

// 自动
void HomePage::on_pushButton_17_clicked()
{
    COMMOND_GROUPS cmd;
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MODE_CMD;
    cmd.mode_fsm_event_type = MODE_EVENT_AUTO;
    buffer.push(cmd);

    qDebug() << "自动按钮";
}

// 手动
void HomePage::on_pushButton_18_clicked()
{
    COMMOND_GROUPS cmd;
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MODE_CMD;
    cmd.mode_fsm_event_type = MODE_EVENT_MANUAL;
    buffer.push(cmd);

    qDebug() << "手动按钮";
}



//设定主轴速度-确认
void HomePage::on_pushButton_clicked()
{

    // 检查用户权限
    if (!UserManager::getInstance().isOperator()) {
        QMessageBox::warning(this, tr("权限不足"), tr("只有操作员可以修改参数！"));
        return;
    }

      qDebug() << "速度值" << ui->lineEdit_2->text();
    ShmManager::get_instance().get_data()->config.motor_config[MAIN_SPINDLE].running_speed =
      ui->lineEdit_2->text().toDouble()/1.08;
}



//撑杆退pid
void HomePage::on_pushButton_2_clicked()
{

    PID pid_data;
    pid_data.Kp_Rod_retreat = ui->lineEdit_3->text().toDouble();
    pid_data.Ki_Rod_retreat = ui->lineEdit_4->text().toDouble();
    pid_data.Kd_Rod_retreat = ui->lineEdit_6->text().toDouble();
    ShmManager::get_instance().get_data()->pid = pid_data;
}

//撑杆进pid
void HomePage::on_pushButton_3_clicked()
{
    qDebug() << "撑杆进pid" << ui->lineEdit_6->text() << ui->lineEdit_7->text() << ui->lineEdit_8->text();
    // ShmManager::get_instance().get_data()->pid = {.Kp_Rod_advance = ui->lineEdit_6->text().toDouble(),
    //                                              .Ki_Rod_advance = ui->lineEdit_7->text().toDouble(),
    //                                              .Kd_Rod_advance = ui->lineEdit_8->text().toDouble()};


    PID pid_data;
    pid_data.Kp_Rod_advance = ui->lineEdit_6->text().toDouble();
    pid_data.Ki_Rod_advance = ui->lineEdit_7->text().toDouble();
    pid_data.Kd_Rod_advance = ui->lineEdit_8->text().toDouble();
    ShmManager::get_instance().get_data()->pid = pid_data;
}


//中穿进pid
void HomePage::on_pushButton_4_clicked()
{
   
    PID pid_data;
    pid_data.Kp_center_advance = ui->lineEdit_9->text().toDouble();
    pid_data.Ki_center_advance = ui->lineEdit_10->text().toDouble();
    pid_data.Kd_center_advance = ui->lineEdit_11->text().toDouble();
    ShmManager::get_instance().get_data()->pid = pid_data;
}


void HomePage::on_pushButton_5_clicked()
{
    PID pid_data;
    pid_data.Kp = ui->lineEdit_12->text().toDouble();
    pid_data.Ki = ui->lineEdit_13->text().toDouble();
    pid_data.Kd = ui->lineEdit_14->text().toDouble();
    ShmManager::get_instance().get_data()->pid = pid_data;
}



//登入权限切换
void HomePage::on_pushButton_19_clicked()
{
     // 获取当前角色
    UserRole currentRole = UserManager::getInstance().getCurrentRole();
    
    // 如果当前是游客，则切换到操作员（需要密码验证）
    if (currentRole == UserRole::Guest) {
        // 显示密码对话框进行验证
        if (PasswordManager::showPasswordDialog(this)) {
            UserManager::getInstance().setCurrentRole(UserRole::Operator);
            QMessageBox::information(this, tr("权限切换"), tr("已切换到操作员权限"));

            // 将文字改成 当前权限：操作员
            ui->pushButton_19->setText(tr("当前权限：操作员"));
            // 按钮背景改成绿色
            ui->pushButton_19->setStyleSheet("background-color: rgb(0, 255, 0);");
        } else {
            QMessageBox::warning(this, tr("权限切换失败"), tr("密码错误，无法切换到操作员权限"));
            return;
        }
    } 
    // 如果当前是操作员，则切换到游客
    else if (currentRole == UserRole::Operator) {
        UserManager::getInstance().setCurrentRole(UserRole::Guest);
        QMessageBox::information(this, tr("权限切换"), tr("已切换到游客权限"));

        // 将文字改成 当前权限：游客
            ui->pushButton_19->setText(tr("当前权限：游客"));
            // 按钮背景改成白色
            ui->pushButton_19->setStyleSheet("background-color: white;");
        
    }
    
    // 更新界面控件状态
    updateUIBasedOnUserRole();
}



//上限位修改
void HomePage::on_pushButton_6_clicked()
{
    // 检查用户权限
    if (!UserManager::getInstance().isOperator()) {
        QMessageBox::warning(this, tr("权限不足"), tr("只有操作员可以修改参数！"));
        return;
    }
    ShmManager::get_instance().get_data()->feedback.wheel_fdb.start_length_ref = ui->lineEdit_15->text().toDouble()*8388608+ ui->label_8->text().toDouble()*8388608;
}

//下限位修改
void HomePage::on_pushButton_7_clicked()
{
    // 检查用户权限
    if (!UserManager::getInstance().isOperator()) {
        QMessageBox::warning(this, tr("权限不足"), tr("只有操作员可以修改参数！"));
        return;
    }
    ShmManager::get_instance().get_data()->feedback.wheel_fdb.finish_length_ref = ui->lineEdit_16->text().toDouble()*8388608+ ui->label_17->text().toDouble()*8388608;
}

