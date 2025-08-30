#ifndef MAINFLYER_H
#define MAINFLYER_H

#include <QWidget>

#include "../../src/shm_data.hpp"
#include "../../src/util/ring_buffer.hpp"
#include "../../src/enum/spindle_operation.h"


namespace Ui {
class MainFlyer;
}

    // //枚举动作按钮 
    // enum class SpindleOperation {
    //     FORWARD_JOGING,
    //     REVERSE_JOGING,
    //     RETURN_TO_ZERO,
    //     RELEASE_BRAKE,
    //     ENGAGE_BRAKE,
    //     STOP,
    //     MANUAL_MOTOR_ON,
    //     MANUAL_MOTOR_OFF,
    //     ABSOLUTE_POSITION_MOTION
    // };

class MainFlyer : public QWidget
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
        void on_pushButton_19_pressed();
        void on_pushButton_20_released();
        void on_pushButton_20_pressed();
        void on_pushButton_19_released();
        void on_pushButton_21_clicked();
        void on_pushButton_22_clicked();
        void on_pushButton_23_clicked();
        void on_pushButton_24_clicked();
        void on_pushButton_25_clicked();
        void on_pushButton_26_clicked();
        void on_pushButton_27_clicked();
        void on_pushButton_28_pressed();
        void on_pushButton_28_released();
        void on_pushButton_29_pressed();
        void on_pushButton_29_released();
        void on_pushButton_30_clicked();
        void on_pushButton_31_clicked();
        void on_pushButton_32_clicked();
        void on_pushButton_33_clicked();
        void on_pushButton_34_clicked();
        void on_pushButton_35_clicked();
        void on_pushButton_36_clicked();
        void on_pushButton_46_pressed();
        void on_pushButton_46_released();
        void on_pushButton_47_pressed();
        void on_pushButton_47_released();
        void on_pushButton_48_clicked();
        void on_pushButton_49_clicked();
        void on_pushButton_50_clicked();
        void on_pushButton_51_clicked();
        void on_pushButton_52_clicked();
        void on_pushButton_53_clicked();
        void on_pushButton_54_clicked();
        void on_pushButton_55_pressed();
        void on_pushButton_55_released();
        void on_pushButton_56_pressed();
        void on_pushButton_56_released();
        void on_pushButton_57_clicked();
        void on_pushButton_58_clicked();
        void on_pushButton_59_clicked();
        void on_pushButton_60_clicked();
        void on_pushButton_61_clicked();
        void on_pushButton_62_clicked();
        void on_pushButton_63_clicked();


    signals:
    public:
        explicit MainFlyer(QWidget *parent = nullptr);
        ~MainFlyer();

    private:
        Ui::MainFlyer *ui;
        RingBuffer<RINGBUFFER> buffer;

        
    //电机操作执行函数
    void executeOperation( int motorType, SpindleOperation operation, double speed, double acceleration, double position);

};

#endif // MAINFLYER_H
