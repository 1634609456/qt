// spindle_operation.h
#ifndef SPINDLE_OPERATION_H
#define SPINDLE_OPERATION_H

enum SpindleOperation {
    FORWARD_JOGING,  // 正点动
    REVERSE_JOGING,  // 反点动
    RETURN_TO_ZERO,  // 回零
    RELEASE_BRAKE,   // 松闸
    ENGAGE_BRAKE,   // 抱闸
    STOP,           // 停止
    MANUAL_MOTOR_ON, // 上使能
    MANUAL_MOTOR_OFF, // 下使能
    ABSOLUTE_POSITION_MOTION // 绝对位置运动
};

#endif 