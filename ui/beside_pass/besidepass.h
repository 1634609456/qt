#ifndef BESIDEPASS_H
#define BESIDEPASS_H

#include "../../src/shm_data.hpp"
#include "../../src/util/ring_buffer.hpp"
#include "../../src/enum/spindle_operation.h"

#include <QWidget>

namespace Ui {
class BesidePass;
}

class BesidePass : public QWidget
{
    Q_OBJECT
    private slots:
        double getMotorNum(int motorType, QString model) const;
        void on_pushButton_pressed();
        void on_pushButton_released();
        void on_pushButton_4_pressed();
        void on_pushButton_4_released();
        void on_pushButton_2_clicked();
        void on_pushButton_3_clicked();
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
        



    public:
        explicit BesidePass(QWidget *parent = nullptr);
        ~BesidePass();

    private:
        Ui::BesidePass *ui;
        RingBuffer<RINGBUFFER> buffer;

    //电机操作执行函数
    void executeOperation( int motorType, SpindleOperation operation, double speed, double acceleration, double position);

};

#endif // BESIDEPASS_H
