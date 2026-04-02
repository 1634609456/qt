#ifndef BLANKING_H
#define BLANKING_H

#include <QWidget>
#include <QPushButton>


#include "../../src/shm_data.hpp"
#include "../../src/util/ring_buffer.hpp"
#include "../../src/enum/spindle_operation.h"

namespace Ui {
class Blanking;
}

class Blanking : public QWidget
{
    Q_OBJECT

    private slots:
        double getMotorNum(int motorType, QString model) const;
        void on_pushButton_pressed();
        void on_pushButton_released();
        void on_pushButton_2_clicked();
        void on_pushButton_3_clicked();
        void on_pushButton_4_pressed();
        void on_pushButton_4_released();
        void on_pushButton_5_clicked();
        void on_pushButton_6_clicked();
        void on_pushButton_7_clicked();
        void on_pushButton_8_clicked();
        void on_pushButton_9_clicked();
        void on_pushButton_10_pressed();
        void on_pushButton_10_released();
        void on_pushButton_11_pressed();
        void on_pushButton_11_released();
        void on_pushButton_12_clicked();
        void on_pushButton_13_clicked();
        void on_pushButton_14_clicked();
        void on_pushButton_15_clicked();
        void on_pushButton_16_clicked();
        void on_pushButton_17_clicked();
        void on_pushButton_18_clicked();
        void on_pushButton_19_pressed();
        void on_pushButton_19_released();
        void on_pushButton_20_pressed();
        void on_pushButton_20_released();
        void on_pushButton_21_clicked();
        void on_pushButton_22_clicked();
        void on_pushButton_23_clicked();
        void on_pushButton_24_clicked();
        void on_pushButton_25_clicked();
        void on_pushButton_26_clicked();
        void on_pushButton_27_clicked();
        void on_pushButton_28_clicked();
        void on_pushButton_29_clicked();
        void on_pushButton_30_clicked();
        void on_pushButton_31_clicked();
        void on_pushButton_32_clicked();


    public:
        explicit Blanking(QWidget *parent = nullptr);
        ~Blanking();

    private:
        Ui::Blanking *ui;
        RingBuffer<RINGBUFFER> buffer;
        RingBuffer<RINGBUFFER> buffer_M;

        /** 取轮进退：已下发指令，等待 valve_output[4] bit6 与 target 一致后才允许下一次 */
        bool pick_wheel_advance_pending_ = false;
        bool pick_wheel_advance_target_bit_ = false;



    //电机操作执行函数
    void executeOperation( int motorType, SpindleOperation operation, double speed, double acceleration, double position);

    //颜色操作函数
    void setEnableButtonState(QPushButton* enableButton, QPushButton* disableButton, bool isEnabled);

    /** 与 data_monitor_page「手动」一致：当前为自动模式时切手动，双缓冲各推一条 */
    void push_mode_fsm_manual_if_auto_dual();

    /** 与 data_monitor_page IO 控制一致：IO 手动命令写入 buffer_P + buffer_M */
    void push_io_manual_dual(const COMMOND_GROUPS& cmd);

    /** 收线轮压轮气缸升/降：由定时器按 valve_output[0] 反馈着色（升绿、降红、未激活灰） */
    void updateWireWindPressWheelButtonStyles(bool lift_on, bool low_on);

    /** 取轮进退：由定时器按 valve_output[4] bit6 反馈着色（上使能绿、下使能红） */
    void updatePickWheelAdvanceRetreatButtonStyle(bool upper_enable);
    };

#endif // BLANKING_H
