#ifndef MIDDELCIRCUITBREAKER_H
#define MIDDELCIRCUITBREAKER_H

#include "../../src/shm_data.hpp"
#include "../../src/util/ring_buffer.hpp"
#include "../../src/enum/spindle_operation.h"

#include <QWidget>

namespace Ui {
class MiddelCircuitBreaker;
}


class MiddelCircuitBreaker : public QWidget
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
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_37_pressed();
    void on_pushButton_37_released();
    void on_pushButton_38_pressed();
    void on_pushButton_38_released();
    void on_pushButton_39_clicked();
    void on_pushButton_40_clicked();
    void on_pushButton_41_clicked();
    void on_pushButton_42_clicked();
    void on_pushButton_43_clicked();
    void on_pushButton_44_clicked();
    void on_pushButton_45_clicked();
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


        
public:
    explicit MiddelCircuitBreaker(QWidget *parent = nullptr);
    ~MiddelCircuitBreaker();

private:
    Ui::MiddelCircuitBreaker *ui;
    RingBuffer<RINGBUFFER> buffer;

void executeOperation( int motorType, SpindleOperation operation, double speed, double acceleration, double position);
};

#endif 
