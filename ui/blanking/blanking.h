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
        void on_pushButton_100_pressed();
        void on_pushButton_100_released();
        void on_pushButton_101_pressed();
        void on_pushButton_101_released();
        void on_pushButton_102_clicked();
        void on_pushButton_103_clicked();
        void on_pushButton_104_clicked();
        void on_pushButton_105_clicked();
        void on_pushButton_106_clicked();
        void on_pushButton_107_clicked();
        void on_pushButton_108_clicked();
        void on_pushButton_109_pressed();
        void on_pushButton_109_released();
        void on_pushButton_110_pressed();
        void on_pushButton_110_released();
        void on_pushButton_111_clicked();
        void on_pushButton_112_clicked();
        void on_pushButton_113_clicked();
        void on_pushButton_114_clicked();
        void on_pushButton_115_clicked();
        void on_pushButton_116_clicked();
        void on_pushButton_117_clicked();


    public:
        explicit Blanking(QWidget *parent = nullptr);
        ~Blanking();

    private:
        Ui::Blanking *ui;
        RingBuffer<RINGBUFFER> buffer;
        RingBuffer<RINGBUFFER> buffer_M;



    //电机操作执行函数
    void executeOperation( int motorType, SpindleOperation operation, double speed, double acceleration, double position);

    //颜色操作函数
    void setEnableButtonState(QPushButton* enableButton, QPushButton* disableButton, bool isEnabled);
    };

#endif // BLANKING_H
