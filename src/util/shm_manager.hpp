#pragma once

#include <QMap>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <cstddef>
#include <random>  
#include <QDebug>
#include <QTimer>  // 新增：必须包含QTimer头文件，否则编译报错
#include <ctime>   // 新增：time(nullptr)需要这个头文件

#include "NoSys.h"
#include "../shm_data.hpp"

class ShmManager : public QObject {
    Q_OBJECT
public:
    static ShmManager &get_instance() {
        static ShmManager instance;
        return instance;
    }

    ShareMemData *get_data() {
        return shm_data_;
    }

    // ========== 关键修改：去掉前面的 ShmManager:: ==========
    void load_shared_memory() {  // 原错误写法：void ShmManager::load_shared_memory()
        int ret{0};
        UINT64 addr;
        ret = YKM_SysLoadLib(0);
        NOS_BOOL is_x64;
        QString rta_name, mem_name;
        QString dev;

        QFile file("sys.conf");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString system = in.readLine().trimmed();
            rta_name = in.readLine().trimmed();
            mem_name = in.readLine().trimmed();
            dev = in.readLine().trimmed();
            is_x64 = (system == "x64") ? NOS_FALSE : NOS_TRUE;
            file.close();
        } else {
            emit loaded(false);
            return;
        }

        if (dev == "dev") {
            shm_data_ = new ShareMemData{};
            // 原有基础测试数据（保留，简化调用：直接用this->get_data()，无需get_instance()）
            this->get_data()->feedback.wheel_fdb.master_meters_fdb = 1000.0;
            this->get_data()->feedback.wheel_fdb.feeding_length_ref = 99999.0;
            shm_data_->io.valve_output[0] = 0b00000100;

            // ========== 极简版随机主轴/牵引速度（定时器实现） ==========
            // 避免重复创建定时器
            if (dev_test_timer_ == nullptr) {
                dev_test_timer_ = new QTimer(this); // 父对象设为this，自动析构
                // 定时器槽函数：极简随机逻辑
                connect(dev_test_timer_, &QTimer::timeout, this, [this]() {
                    // 1. 初始化随机种子（基于当前时间）
                    srand(static_cast<unsigned int>(time(nullptr)));
                    // 2. 生成 -100 ~ 100 的随机速度
                    double main_spindle_speed = (rand() % 200) - 100.0;
                    double main_drawing_speed = (rand() % 200) - 100.0;
                    double main_torsion_speed = (rand() % 200) - 100.0;
                    // 3. 赋值给对应电机（MAIN_SPINDLE=主轴，MAIN_DRAWING=牵引）
                    const int main_spindle_idx = MAIN_SPINDLE;
                    const int main_drawing_idx = MAIN_DRAWING;
                    const int main_torsion_idx = MAIN_TORSION;
                    // 防越界检查
                    if (main_spindle_idx < MAX_MOTOR_TYPE_NUM && main_drawing_idx < MAX_MOTOR_TYPE_NUM) {
                        this->get_data()->feedback.motor_fdb[main_spindle_idx].running_speed = main_spindle_speed;
                        this->get_data()->feedback.motor_fdb[main_drawing_idx].running_speed = main_drawing_speed;
                        this->get_data()->feedback.motor_fdb[main_torsion_idx].running_speed = main_torsion_speed;
                    }
                    // 调试日志
                    qDebug() << "Dev随机数据 → 主轴速度：" << main_spindle_speed 
                             << " 牵引速度：" << main_drawing_speed 
                             << " 虚捻速度：" << main_torsion_speed;
                });
                // 启动定时器：每隔10ms生成一次随机数据
                dev_test_timer_->start(10);
            }

            emit loaded(true);
        } else {
            // 非dev模式：原有共享内存加载逻辑（完全保留）
            ret = NOS_OpenShareMemory(NOS_ECAT_A, rta_name.toStdString().data(), mem_name.toStdString().data(), &addr,
                                      is_x64);
            if (ret == 0) {
                shm_data_ = reinterpret_cast<ShareMemData *>(addr);
                if (shm_data_ != nullptr) {
                    emit loaded(true);
                    return;
                }
            }
            emit loaded(false);
        }
    }

    Q_SIGNAL void loaded(bool success);

private:
    ShmManager() = default;  // 私有构造函数，单例模式

    ShareMemData *shm_data_ = nullptr;
    QTimer* dev_test_timer_ = nullptr; // dev模式测试用定时器
};

// 以下原有常量映射代码完全保留，无需修改
const static QMap<MOTOR_TYPE, QString> motortype2name{{CARDLE_BIN_FAN_MOTOR, "摇篮风仓机"},
                                                      {MAIN_SPINDLE, "主轴"},
                                                      {MAIN_DRAWING, "牵引"},
                                                      {MAIN_TORSION, "虚捻"},
                                                      {LOAD_ROTATING_MOTOR, "上料旋转"},
                                                      {LIFTING_CYLINDER_MOTOR_1, "顶升电缸1"},
                                                      {LIFTING_CYLINDER_MOTOR_2, "顶升电缸2"},
                                                      {DUAL_SPEED_CHAIN_MOTOR, "倍速链"},
                                                      {FUSED_LIFT_MOTOR, "熔断器升降架"},
                                                      {MAIN_WINDING, "收线"},
                                                      {MAIN_LAYING, "排线"},
                                                      {ROTATING_PICK_WHEEL_MOTOR, "取轮旋转"},
                                                      {EDGE_ADVANCE_RETREAT_MOTOR, "边穿进退"},
                                                      {EDGE_LIFT_MOTOR, "边穿升降"},
                                                      {EDGE_EXTEND_RETRACT_MOTOR, "边穿伸缩"},
                                                      {EDGE_ROTATING_MOTOR, "边穿旋转"},
                                                      {CENTER_ADVANCE_RETREAT_MOTOR, "中穿进退"},
                                                      {CENTER_LIFT_MOTOR, "中穿升降"},
                                                      {EXTENDABLE_ROD_MOTOR, "撑杆进退"},
                                                      {FREE_WHEEL_LOCATOR, "空轮定位"}};

const static QMap<INPUT_SIGNAL_NAME, QString> input2name = {
    {EME_STOP_1, "急停1"},
    {SAFETY_CIRCUIT_RESET_1, "安全回路复位1"},
    {SAFETY_CIRCUIT, "安全回路"},
    {MANUAL_WIRE_FEEDING, "手动放线点动"},
    {EDGE_ADVANCE_RETREAT_LOW, "边穿进退后限位"},
    {EDGE_ADVANCE_RETREAT_UP, "边穿进退前限位"},
    {EDGE_LIFT_LOW, "边穿升降后限位"},
    {EDGE_LIFT_UP, "边穿升降前限位"},
    {EDGE_EXTEND_RETRACT_LOW, "边穿伸缩后限位"},
    {EDGE_EXTEND_RETRACT_UP, "边穿伸缩前限位"},
    {EDGE_ROTATING_LIFT, "边穿旋转左限位"},
    {EDGE_ROTATING_RIGHT, "边穿旋转右限位"},
    {CENTER_ADVANCE_RETREA_LOW, "中穿进退后限位"},
    {CENTER_ADVANCE_RETREA_UP, "中穿进退前限位"},
    {CENTER_LIFT_LOW, "中穿升降下限位"},
    {CENTER_LIFT_UP, "中穿升降上限位"},
    {FUSE_STRUT_LOW, "撑杆后限位"},
    {FUSE_STRUT_UP, "撑杆前限位"},
    {FREE_WHEEL_LOCAT, "工字轮空轮定位"},
    {WIRE_PRESS_WHEEL_MECHANISM_B80_HELP, "压线轮机构B80辅助位"},
    {WHEEL_SET_IS_FULL, "满轮位置检测"},
    {LAYING_LOW, "排线下限位"},
    {LAYING_UP, "排线上限位"},
    {EDGE_FIXED_CLAW_CLAMPING, "边穿定爪夹紧"},
    {EDGE_ACTIVE_CLAW_CLAMPING, "边穿动爪夹紧"},
    {EDGE_GUIDE_CLAMPING, "边穿导向夹紧"},
    {EDGE_ACTIVE_CLAW_DRIVE_ORIGIN, "边穿动爪驱动原位"},
    {CENTER_FIXED_CLAW_CLAMPING, "中穿定爪夹紧"},
    {CENTER_ACTIVE_CLAW_CLAMPING, "中穿动爪夹紧"},
    {CENTER_GUIDE_CLAMPING, "中穿导向夹紧"},
    {CENTER_ACTIVE_CLAW_DRIVE_ORIGIN, "中穿动爪驱动原位"},
    {EDGE_PULL_TAB_MECHANISM_LIFT_ORIGIN, "拉扣机构升降原位"},
    {EDGE_PULL_TAB_ADVANCE_RETREAT_ORIGIN, "拉扣进退原位"},
    {EDGE_PULL_TAB_LIFT_ORIGIN, "拉扣升降原位"},
    {EDGE_GUIDE_RING_LIFT_ORIGIN, "导环升降原位"},
    {EDGE_GUIDE_RING_CLAMPING_ORIGIN, "导环夹紧原位"},
    {WIRE_PRESS_WHEEL_B80, "压线轮机构B80位"},
    {WIRE_PRESS_WHEEL_B40, "压线轮机构B40位"},
    {WIRE_PRESS_WHEEL_ORIGIN, "压线轮原位"},
    {EDGE_WIRE_DRAW_MECHANISM_ORIGIN, "拉丝机构原位"},
    {EDGE_WIRE_DRAW_ADVANCE_RETREAT_ORIGIN, "拉丝进退原位"},
    {EDGE_WIRE_DRAW_ORIGIN, "拉丝夹爪原位"},
    {WIRE_WIND_MECHANISM_LOCAT, "收线机构定位"},
    {I_WHEEL_WIRE_WIND_IN_POS, "工字轮收线位到位"},
    {EDGE_FIND_HOLE, "边孔寻孔"},
    {CENTER_FIND_HOLE, "中孔寻孔"},
    {FUSED_GUIDE_UPPER, "熔丝导向升位"},
    {FUSED_GUIDE_ORIGIN, "熔丝导向原位"},
    {FUSED_MECHANISM_UPPER, "熔丝机构升位"},
    {FUSED_MECHANISM_ORIGIN, "熔丝机构原位"},
    {ROTATING_PICK_WHEEL_UPPER, "旋转取轮升位"},
    {ROTATING_PICK_WHEEL_MOTOR_ORIGIN, "旋转取轮电机原位"},
    {ROTATING_PICK_WHEEL_ADVANCE_RETREAT_EXTEND_STATE, "旋转取轮进退伸位"},
    {ROTATING_PICK_WHEEL_ADVANCE_RETREAT_ORIGIN, "旋转取轮进退原位"},
    {WIRE_WIND_WHEEL_PRESS_MECHANISM_B80, "收线工字轮压紧机构B80位"},
    {WIRE_WIND_WHEEL_PRESS_MECHANISM_B40, "收线工字轮压紧机构B40位"},
    {WIRE_WIND_WHEEL_PRESS_POSITION, "收线工字轮压紧位"},
    {WIRE_WIND_WHEEL_PRESS_ORIGIN, "收线工字轮原位"},
    {AIR_PRESSURE_SENSOR, "气压监测"},
    {WIRE_WIND_WHEEL_IN_POSITION, "收线工字轮到位"},
    {FEED_FUSED_MECHANISM_POS_HIGH, "上料熔断机构高位"},
    {FEED_FUSED_MECHANISM_POS_LOW, "上料熔断机构低位"},
    {FEED_FUSED_ADVANCE_RETREAT_ORIGIN, "上料熔断进退原位"},
    {FEED_FUSED_ADVANCE_RETREAT_WORK_POS, "上料熔断进退工作位"},
    {BLOCKER_1_RELEASE_DETECTED, "阻挡器1释放检测"},
    {BLOCKER_2_RELEASE_DETECTED, "阻挡器2释放检测"},
    {BLOCKER_3_RELEASE_DETECTED, "阻挡器3释放检测"},
    {BLOCKER_4_RELEASE_DETECTED, "阻挡器4释放检测"},
    {FLYWHEEL_BOW_POSITION_DETECTED, "飞轮弓位置检测"},
    {DOUBLE_SPEED_CHAIN_FULL_WHEEL_TOOLING_POS, "倍速链满轮工装位"},
    {DOUBLE_SPEED_CHAIN_TOOLING_LOAD_UNLOAD_POS, "倍速链工装上下料位"},
    {DOUBLE_SPEED_CHAIN_TOOLING_EMPTY_WHEEL_POS, "倍速链工装空轮位"},
    {FEED_WHEEL_CHECKING_STATION_1, "上料工字轮1工位检测"},
    {FEED_WHEEL_CHECKING_STATION_2, "上料工字轮2工位检测"},
    {FEED_WHEEL_CHECKING_STATION_3, "上料工字轮3工位检测"},
    {WHEEL_SET_SM14_ORIGIN_HELP, "SM14定位辅助"},
    {FEED_WHEEL_LEFT_RELEASE, "上料工字轮左释放"},
    {FEED_WHEEL_LEFT_CLAMP, "上料工字轮左夹紧"},
    {FEED_WHEEL_RIGHT_RELEASE, "上料工字轮右释放"},
    {FEED_WHEEL_RIGHT_CLAMP, "上料工字轮右夹紧"},
    {CRADLE_FLIP_LOCK_LEFT_RELEASE, "摇篮翻转锁止左释放"},
    {CRADLE_FLIP_LOCK_LEFT_LOCK_ON, "摇篮翻转锁止左锁止"},
    {CRADLE_FLIP_LOCK_RIGHT_RELEASE, "摇篮翻转锁止右释放"},
    {CRADLE_FLIP_LOCK_RIGHT_LOCK_ON, "摇篮翻转锁止右锁止"},
    {LEFT_FRONT_DOOR_OPEN, "左前门开"},
    {LEFT_FRONT_DOOR_CLOSE, "左前门关"},
    {RIGHT_FRONT_DOOR_CLOSE, "右前门关"},
    {RIGHT_FRONT_DOOR_OPEN, "右前门开"},
    {LEFT_REAR_DOOR_OPEN, "左后门开"},
    {LEFT_REAR_DOOR_CLOSE, "左后门关"},
    {RIGHT_REAR_DOOR_CLOSE, "右后门关"},
    {RIGHT_REAR_DOOR_OPEN, "右后门开"},
    {BIN_DOOR_LEFT_CLOSE, "仓门左关"},
    {BIN_DOOR_LEFT_OPEN, "仓门左开"},
    {BIN_DOOR_RIGHT_CLOSE, "仓门右关"},
    {BIN_DOOR_RIGHT_OPEN, "仓门右开"},
    {BIN_DOOR_OPEN_LEFT_RELEASE, "仓门开左释放"},
    {BIN_DOOR_OPEN_LEFT_LOCK_ON, "仓门开左锁止"},
    {BIN_DOOR_OPEN_RIGHT_RELEASE, "仓门开右释放"},
    {BIN_DOOR_OPEN_RIGHT_LOCK_ON, "仓门开右锁止"},
    {BIN_DOOR_CLOSE_LEFT_RELEASE, "仓门关左释放"},
    {BIN_DOOR_CLOSE_LEFT_LOCK_ON, "仓门关左锁止"},
    {BIN_DOOR_CLOSE_RIGHT_RELEASE, "仓门关右释放"},
    {BIN_DOOR_CLOSE_RIGHT_LOCK_ON, "仓门关右锁止"},
    {SAFETY_LIGHT_CURTAIN_CHECKING, "安全光栅检测"},
    {SAFETY_LIGHT_CURTAIN_CHECKING_2, "安全光栅检测2"},
    {MAIN_METER_MEASURE, "主计米"},
    {AUX_METER_MEASURE, "辅计米"},
    {WIRE_BREAK_ALARM, "断丝告警"},
    {WIRE_ROPE_INSPECTION_ALARM, "钢丝绳检测仪告警"},
    {CRADLE_BIN_FAN_OVERHEAT_ALARM, "摇篮仓风机热告警"},
    {SPINDLE_MOTOR_FAN_OVERHEAT_ALARM, "主轴电机风机热告警"},
    {ELECTRICAL_CABINET_DOOR_OPEN_ALARM, "电柜门开门告警"},
    {LUBRICANT_LEVEL_LOW_ALARM, "润滑液面低告警"},
    {CHILLER_ALARM, "冷水机告警"},
    {MAIN_CABINET_AXIAL_FAN_ALARM, "主柜轴流风机告警"},
    {EME_STOP_2, "急停2"},
    {SAFETY_CIRCUIT_RESET_2, "安全回路复位2"},
    {CRADLE_BIN_LID_OPEN, "摇篮仓盖"},
    {CRADLE_BIN_DOOR_AUTO_MANUAL_MODE, "摇篮仓门自动/手动"},
    {WIRE_BIN_BRAKE_CHECK, "收线仓断丝检测"},
    {LOCK_WIRE_DRAWING_CHECK, "锁丝拉丝检测"},
    {WIRE_BIN_AXIS_FAN_FAULT_ALARM, "收线仓轴流风机故障告警"},
};

const static QMap<OUTPUT_SIGNAL_NAME, QString> output2name = {{SAFETY_CIRCUIT_RESET, "安全回路复位"},
                                                              {YELLOW_LIGHT, "黄灯"},
                                                              {GREEN_LIGHT, "绿灯"},
                                                              {RED_LIGHT, "红灯"},
                                                              {BUZZER, "嗡鸣器"},
                                                              {ELECTRICAL_BOX_FAN_1_2, "电箱风机1&2"},
                                                              {ELECTRICAL_BOX_FAN_3_4, "电箱风机3&4"},
                                                              {ELECTRICAL_BOX_FAN_5_6, "电箱风机5&6"},
                                                              {ELECTRICAL_BOX_FAN_7_8, "电箱风机7&8"},
                                                              {CRADLE_BIN_FAN, "摇篮仓风机"},
                                                              {FEED_FUSED_MECHANISM_LOW, "上料熔丝机构降"},
                                                              {FEED_FUSED_MECHANISM_UP, "上料熔丝机构升"},
                                                              {POWER_SYSTEM_SUPPLY, "动力系统供电"},
                                                              {SPINDLE_MOTOR_FAN, "主轴电机风机"},
                                                              {GREASE_PUMP_CONTROL, "油脂泵控制"},
                                                              {CHILLER_POWER_SUPPLY, "冷水机供电"},
                                                              {CHILLER_POWER_CONTROL, "冷水机控制"},
                                                              {CONTROL_CABINET_COOLING_FAN, "控制柜散热风机"}};

const static QMap<VALVE_OUTPUT_NAME, QString> valve2name = {
    {BIDIRECTIONAL_VALVE_LIFT_B80_B40_TURN, "双向阀升，B80/B40工位转换"},
    {BIDIRECTIONAL_VALVE_LOW_B80_B40_TURN, "双向阀降，B80/B40工位转换"},
    {BIDIRECTIONAL_VALVE_LIFT_WIRE_WIND_PRESS_WHEEL_CYLINDER, "双向阀升，收线轮压轮气缸"},
    {BIDIRECTIONAL_VALVE_LOW_WIRE_WIND_PRESS_WHEEL_CYLINDER, "双向阀降，收线轮压轮气缸"},
    {INDUCE_VALVE_LIFT_WIRE_PRESS_WHEEL_B80, "诱导阀升，压线轮B80位"},
    {INDUCE_VALVE_LOW_WIRE_PRESS_WHEEL_B40, "诱导阀降，压线轮B40位"},
    {EDGE_FIXED_CLAW, "边穿定爪"},
    {EDGE_ACTIVE_CLAW, "边穿动爪"},
    {EDGE_ACTIVE_CLAW_DRIVE, "边穿动爪驱动"},
    {EDGE_GUIDE, "边穿导向"},
    {CENTER_FIXED_CLAW, "中穿定爪"},
    {CENTER_ACTIVE_CLAW, "中穿动爪"},
    {CENTER_ACTIVE_CLAW_DRIVE, "中穿动爪驱动"},
    {CENTER_GUIDE, "中穿导向"},
    {EDGE_PULL_TAB_MECHANISM_LIFT, "拉扣机构升降"},
    {EDGE_PULL_TAB_ADVANCE_RETREAT, "拉扣进退"},
    {EDGE_PULL_TAB_UP_DOWN, "拉扣上下"},
    {EDGE_GUIDE_RING_MECHANISM_LIFT, "导环机构升降"},
    {BIDIRECTIONAL_VALVE_LIFT_PICK_WHEEL_LIFT, "双向阀升，取轮升降"},
    {BIDIRECTIONAL_VALVE_LOW_PICK_WHEEL_LIFT, "双向阀降，取轮升降"},
    {PICK_WHEEL_ADVANCE_RETREAT, "取轮进退"},
    {WIRE_PRESS_WHEEL_EXTEND_RETRACT, "压线轮伸缩"},
    {FUSED_GUIDE, "熔丝导向"},
    {FUSED_GUIDE_MECHANISM_LIFT, "熔丝机构升降"},
    {DISCHARGE_FUSED_CLAW, "下料熔丝气爪"},
    {WIRE_DRAW_MECHANISM_LIFT, "拉丝机构升降"},
    {WIRE_DRAW_MECHANISM_ADVANCE_RETREAT, "拉丝机构进退"},
    {WIRE_DRAW_AIR_CLAW, "拉丝气爪"},
    {EDGE_ACTIVE_CLAW_ANTI_DETACH, "边穿动爪防脱"},
    {CENTER_ACTIVE_CLAW_ANTI_DETACH, "中穿动爪防脱"},
    {GUIDE_RING_OPEN_CLOSE, "导环开合"},
    {BIDIRECTIONAL_VALVE_CLOSE_CRADLE_BIN_FRONT_DOOR_OPEN, "双向阀关，摇篮仓前对开门"},
    {BIDIRECTIONAL_VALVE_OPEN_CRADLE_BIN_FRONT_DOOR_OPEN, "双向阀开，摇篮仓前对开门"},
    {BIDIRECTIONAL_VALVE_CLOSE_CRADLE_BIN_REAR_DOOR_OPEN, "双向阀关，摇篮仓后对开门"},
    {BIDIRECTIONAL_VALVE_OPEN_CRADLE_BIN_REAR_DOOR_OPEN, "双向阀开，摇篮仓后对开门"},
    {BIDIRECTIONAL_VALVE_CLOSE_CRADLE_BIN_TOP_COVER, "双向阀关，摇篮仓上盖"},
    {BIDIRECTIONAL_VALVE_OPEN_CRADLE_BIN_TOP_COVER, "双向阀开，摇篮仓上盖"},
    {BIDIRECTIONAL_VALVE_LOWER_CRADLE_FLIP_LOCK_MECHANISM, "双向阀降，摇篮翻转锁止机构"},
    {BIDIRECTIONAL_VALVE_UP_CRADLE_FLIP_LOCK_MECHANISM, "双向阀升，摇篮翻转锁止机构"},
    {BIDIRECTIONAL_VALVE_RETREAT_FEED_FUSED_ADVANCE_RETREAT, "双向阀退，上料熔断进退"},
    {BIDIRECTIONAL_VALVE_ADVANCE_FEED_FUSED_ADVANCE_RETREAT, "双向阀进，上料熔断进退"},
    {BIDIRECTIONAL_VALVE_RELEASE_FEED_WHEEL_LOCK, "双向阀释放，上料工字轮锁紧"},
    {BIDIRECTIONAL_VALVE_CLAW_FEED_WHEEL_LOCK, "双向阀夹紧，上料工字轮锁紧"},
    {BIDIRECTIONAL_VALVE_LOCK_CRADLE_BIN_TOP_COVER_OPEN_LOCK, "双向锁止，摇篮仓上盖开锁止"},
    {BIDIRECTIONAL_VALVE_RELEASE_CRADLE_BIN_TOP_COVER_OPEN_LOCK, "双向阀释放，摇篮仓上盖开锁止"},
    {BIDIRECTIONAL_VALVE_LOCK_CRADLE_BIN_TOP_COVER_CLOSE_LOCK, "双向阀锁止，摇篮仓上盖关锁止"},
    {BIDIRECTIONAL_VALVE_RELEEASE_CRADLE_BIN_TOP_COVER_CLOSE_LOCK, "双向阀释放，摇篮仓上盖关锁止"},
    {DOUBLE_SPEED_CHAIN_STOP_1, "倍速链阻挡器1"},
    {DOUBLE_SPEED_CHAIN_STOP_2, "倍速链阻挡器2"},
    {FEED_FUSED_PNEUMATIC_GRIPPER, "上料熔断气爪"},
    {SPINDLE_AIR_BRAKE, "主轴气动刹车"}};

inline int find_key_by_name(const QMap<INPUT_SIGNAL_NAME, QString> &map, const QString &name) {
    for (auto it = map.begin(); it != map.end(); ++it) {
        if (it.value() == name) {
            return it.key();
        }
    }
    return IN_MAX;
}

inline int find_key_by_name(const QMap<OUTPUT_SIGNAL_NAME, QString> &map, const QString &name) {
    for (auto it = map.begin(); it != map.end(); ++it) {
        if (it.value() == name) {
            return it.key();
        }
    }
    return OUT_MAX;
}

inline int find_key_by_name(const QMap<VALVE_OUTPUT_NAME, QString> &map, const QString &name) {
    for (auto it = map.begin(); it != map.end(); ++it) {
        if (it.value() == name) {
            return it.key();
        }
    }
    return VALVE_MAX;
}