#ifndef MAINFLYER_H
#define MAINFLYER_H

#include <QWidget>

#include "../../src/shm_data.hpp"
#include "../../src/util/ring_buffer.hpp"


namespace Ui {
class MainFlyer;
}

class MainFlyer : public QWidget
{
    Q_OBJECT

    private slots:
        void on_pushButton_clicked();
        void on_pushButton_2_clicked();
        void on_pushButton_3_clicked();
        void on_pushButton_4_clicked();
        void on_pushButton_5_clicked();
        void on_pushButton_6_clicked();
        void on_pushButton_7_clicked();
        void on_pushButton_8_clicked();
        void on_pushButton_9_clicked();

    public:
        explicit MainFlyer(QWidget *parent = nullptr);
        ~MainFlyer();

    private:
        Ui::MainFlyer *ui;
        RingBuffer<RINGBUFFER> buffer;

};

#endif // MAINFLYER_H
