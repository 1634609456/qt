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
#include <QGridLayout>
#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>

#include "../../src/util/shm_manager.hpp"
#include "../meters_display_widget.hpp"

HomePage::HomePage(QWidget *parent)
    : QWidget(parent), 
    ui(new Ui::HomePage), 
    buffer(nullptr),
    buffer_m_(nullptr)
{
  ui->setupUi(this);

      // 初始化UI根据当前用户角色
      updateUIBasedOnUserRole();

      // =========================
      // 页面拆分：主页只保留你指定的控件
      // 保留：
      // - 操作权限按钮（pushButton_19）
      // - 主状态机按钮：错误复位/上电/下电/停止/运行/急停/急停清除（10/11/12/13/14/15/16）
      // 计米显示：仅展示数值，无清零/修改按钮
      //
      // 迁移到“手动控制 -> 主机参数”：
      // - 设定/实际速度显示
      // - 模式状态机（自动/手动）
      // - PID 参数
      // - 大小头设置（上/下限位显示与修改）
      // =========================
      // 速度相关（整行隐藏）
      if (ui->lineEdit_2) ui->lineEdit_2->parentWidget()->hide();
      if (ui->label_4) ui->label_4->parentWidget()->hide();
      if (ui->pushButton) ui->pushButton->hide();

      // 模式状态机（自动/手动）隐藏
      if (ui->pushButton_17) ui->pushButton_17->parentWidget()->parentWidget()->hide();

      // PID 参数相关隐藏（隐藏每一行的父容器）
      if (ui->lineEdit_3) ui->lineEdit_3->parentWidget()->hide();
      if (ui->lineEdit_6) ui->lineEdit_6->parentWidget()->hide();
      if (ui->lineEdit_9) ui->lineEdit_9->parentWidget()->hide();
      if (ui->lineEdit_12) ui->lineEdit_12->parentWidget()->hide();

      // 大小头设置隐藏（label_14 在该块内，隐藏其父容器即可）
      if (ui->label_14) ui->label_14->parentWidget()->hide();

      // 主状态机：隐藏“错误”，其余含上电/下电
      if (ui->pushButton_9) ui->pushButton_9->hide();   // 错误

      // ===== 电机主页卡片布局 =====
      // 左上：五轴速度 | 右上：权限 + 计米显示（无按钮）
      // 下方：主状态机（横跨全宽）
      auto* main_layout = new QVBoxLayout(this);
      main_layout->setContentsMargins(16, 16, 16, 16);
      main_layout->setSpacing(16);

      auto* grid = new QGridLayout();
      grid->setSpacing(16);

      auto make_card = [this](const QString& title) -> QWidget* {
          auto* card = new QFrame(this);
          card->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
          card->setStyleSheet("QFrame { background-color: #fafafa; border: 1px solid #e0e0e0; border-radius: 8px; padding: 4px; }");
          auto* v = new QVBoxLayout(card);
          v->setContentsMargins(12, 10, 12, 10);
          v->setSpacing(6);
          auto* title_label = new QLabel(title, this);
          title_label->setStyleSheet("font-weight: bold; font-size: 14pt; color: #333;");
          v->addWidget(title_label);
          return card;
      };

      // 左上：五轴速度
      struct AxisInfo { int type; const char* name; };
      const AxisInfo axes[] = {
          {MAIN_SPINDLE, "主轴"},
          {MAIN_TORSION, "虚捻"},
          {MAIN_DRAWING, "牵引"},
          {MAIN_WINDING, "收线"},
          {MAIN_LAYING, "排线"},
      };
      auto* speed_card = make_card("五轴速度");
      auto* speed_layout = qobject_cast<QVBoxLayout*>(speed_card->layout());
      QLabel* speed_labels[5] = {nullptr};
      for (int i = 0; i < 5; ++i) {
          auto* row = new QHBoxLayout();
          row->addWidget(new QLabel(QString("%1:").arg(axes[i].name), this));
          speed_labels[i] = new QLabel("--", this);
          speed_labels[i]->setMinimumWidth(80);
          speed_labels[i]->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
          row->addWidget(speed_labels[i]);
          row->addWidget(new QLabel("r/min", this));
          row->addStretch();
          speed_layout->addLayout(row);
      }
      speed_layout->addStretch();
      grid->addWidget(speed_card, 0, 0);

      // 右上：权限 + 计米显示（纯展示，无清零/修改按钮）
      auto* right_card = new QFrame(this);
      right_card->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
      right_card->setStyleSheet("QFrame { background-color: #fafafa; border: 1px solid #e0e0e0; border-radius: 8px; }");
      auto* right_layout = new QVBoxLayout(right_card);
      right_layout->setContentsMargins(12, 10, 12, 10);
      right_layout->setSpacing(10);
      auto* perm_title = new QLabel("权限", right_card);
      perm_title->setStyleSheet("font-weight: bold; font-size: 14pt; color: #333;");
      right_layout->addWidget(perm_title);
      ui->pushButton_19->setParent(right_card);
      right_layout->addWidget(ui->pushButton_19);
      right_layout->addSpacing(16);
      auto* meter_title = new QLabel("计米显示", right_card);
      meter_title->setStyleSheet("font-weight: bold; font-size: 14pt; color: #333;");
      right_layout->addWidget(meter_title);
      auto* meters_display = new MetersDisplayWidget(right_card);
      right_layout->addWidget(meters_display);
      right_layout->addStretch();
      grid->addWidget(right_card, 0, 1);

      // 下方：主状态机（横跨整行）
      auto* fsm_card = make_card("主状态机");
      auto* fsm_layout = qobject_cast<QVBoxLayout*>(fsm_card->layout());
      auto* fsm_btn_layout = new QVBoxLayout();
      auto* fsm_row1 = new QHBoxLayout();
      ui->pushButton_10->setParent(fsm_card);
      ui->pushButton_11->setParent(fsm_card);
      ui->pushButton_12->setParent(fsm_card);
      fsm_row1->addWidget(ui->pushButton_10);
      fsm_row1->addWidget(ui->pushButton_11);
      fsm_row1->addWidget(ui->pushButton_12);
      fsm_row1->addStretch();
      fsm_btn_layout->addLayout(fsm_row1);
      auto* fsm_row2 = new QHBoxLayout();
      ui->pushButton_13->setParent(fsm_card);
      ui->pushButton_14->setParent(fsm_card);
      ui->pushButton_15->setParent(fsm_card);
      ui->pushButton_16->setParent(fsm_card);
      fsm_row2->addWidget(ui->pushButton_13);
      fsm_row2->addWidget(ui->pushButton_14);
      fsm_row2->addWidget(ui->pushButton_15);
      fsm_row2->addWidget(ui->pushButton_16);
      fsm_row2->addStretch();
      fsm_btn_layout->addLayout(fsm_row2);
      fsm_layout->addLayout(fsm_btn_layout);
      fsm_layout->addStretch();
      grid->addWidget(fsm_card, 1, 0, 1, 2);  // 主状态机横跨两列

      grid->setColumnStretch(0, 1);
      grid->setColumnStretch(1, 1);
      grid->setRowStretch(0, 1);
      grid->setRowStretch(1, 0);  // 主状态机保持紧凑
      main_layout->addLayout(grid);

      const QList<QWidget*> direct_children = findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly);
      for (QWidget* w : direct_children) {
          if (w != speed_card && w != right_card && w != fsm_card) {
              w->hide();
          }
      }

      auto timer = new QTimer(this);
      connect(timer, &QTimer::timeout, this, [this, speed_labels]() {
          auto* d = ShmManager::get_instance().get_data();
          if (!d) return;

          const int axis_types[] = {MAIN_SPINDLE, MAIN_TORSION, MAIN_DRAWING, MAIN_WINDING, MAIN_LAYING};
          for (int i = 0; i < 5; ++i) {
              double sp = d->feedback.motor_fdb[axis_types[i]].running_speed;
              speed_labels[i]->setText(QString::number(sp, 'f', 2));
          }
      });

  auto sync_ring_buffers = [this]() {
      auto* d = ShmManager::get_instance().get_data();
      if (!d) {
          return;
      }
      buffer.set_buffer(&d->buffer_P);
      buffer_m_.set_buffer(&d->buffer_M);
  };

  connect(
      &ShmManager::get_instance(), &ShmManager::loaded, [this, timer, sync_ring_buffers](bool success) {

        if (success) {
          sync_ring_buffers();
          timer->start(200);
        }
      });
  // 共享内存若在 HomePage 创建前已加载，会错过 loaded，需补绑缓冲避免 push 空指针
  sync_ring_buffers();
  if (ShmManager::get_instance().get_data()) {
      timer->start(200);
  }
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
    pushMainFsmCommand(MAIN_EVENT_CONTROL_ON);
    Q_EMIT mainRunStateForDbCollection(true);
    qDebug() << "运行按钮";
}

// 停止
void HomePage::on_pushButton_13_clicked()
{
    pushMainFsmCommand(MAIN_EVENT_CONTROL_OFF);
    Q_EMIT mainRunStateForDbCollection(false);
    qDebug() << "停止按钮";
}

// 急停
void HomePage::on_pushButton_15_clicked()
{
    pushMainFsmCommand(MAIN_EVENT_EME_STOP);
    qDebug() << "急停按钮";
}

// 急停清除
void HomePage::on_pushButton_16_clicked()
{
    pushMainFsmCommand(MAIN_EVENT_EME_STOP_CLEAR);
    qDebug() << "急停清除按钮";
}

// 错误
void HomePage::on_pushButton_9_clicked()
{
    pushMainFsmCommand(MAIN_EVENT_ERROR);
    qDebug() << "错误按钮";
}

// 错误复位
void HomePage::on_pushButton_10_clicked()
{
    pushMainFsmCommand(MAIN_EVENT_ERROR_RESET);
    qDebug() << "错误复位按钮";
}

// 上电：与 data_monitor_page 一致 — 自动 → 初始化 → 初始化错误 → 配置 → 上电（均双缓冲）
void HomePage::on_pushButton_11_clicked()
{
    pushModeFsmCommand(MODE_EVENT_AUTO);
    pushMainFsmCommand(MAIN_EVENT_INIT);
    pushMainFsmCommand(MAIN_EVENT_INIT_ERROR);
    pushMainFsmCommand(MAIN_EVENT_CONFIG);
    pushMainFsmCommand(MAIN_EVENT_MOTOR_ON);
    qDebug() << "上电（已前置 自动 / 初始化 / 初始化错误 / 配置）";
}

void HomePage::pushMainFsmCommand(MAIN_FSM_EVENT_TYPE event_type)
{
    if (!ShmManager::get_instance().get_data()) {
        return;
    }
    COMMOND_GROUPS cmd;
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MAIN_CMD;
    cmd.main_fsm_event_type = event_type;
    buffer.push(cmd);
    buffer_m_.push(cmd);
}

void HomePage::pushModeFsmCommand(MODE_FSM_EVENT_TYPE event_type)
{
    if (!ShmManager::get_instance().get_data()) {
        return;
    }
    COMMOND_GROUPS cmd;
    cmd.cmd_type = COMMOND_GROUPS::CMD_TYPE::MODE_CMD;
    cmd.mode_fsm_event_type = event_type;
    buffer.push(cmd);
    buffer_m_.push(cmd);
}

// 下电
void HomePage::on_pushButton_12_clicked()
{
    pushMainFsmCommand(MAIN_EVENT_MOTOR_OFF);
    qDebug() << "下电按钮";
}

// 自动
void HomePage::on_pushButton_17_clicked()
{
    pushModeFsmCommand(MODE_EVENT_AUTO);
    qDebug() << "自动按钮";
}

// 手动
void HomePage::on_pushButton_18_clicked()
{
    pushModeFsmCommand(MODE_EVENT_MANUAL);
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

    // 通知主窗口更新左侧“手动控制”显示/隐藏
    Q_EMIT operatorModeChanged(UserManager::getInstance().isOperator());
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

// 计米清零（原“计米参数设置”里的清零逻辑）
void HomePage::on_pushButton_20_clicked()
{
    if (ShmManager::get_instance().get_data() == nullptr) {
        QMessageBox::warning(this, tr("未连接"), tr("未连接到共享内存，请先加载共享内存"));
        return;
    }

    ShmManager::get_instance().get_data()->feedback.wheel_fdb.master_meters_fdb = 0.0;
    qDebug() << "计米清零";
}

