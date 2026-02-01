#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <qtmetamacros.h>

#include "../../src/shm_data.hpp"
#include "../../src/util/ring_buffer.hpp"

namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();


private slots:
    void on_switchUserRoleButton_clicked();
    void updateUIBasedOnUserRole();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();


private:
    Ui::HomePage *ui;
    RingBuffer<RINGBUFFER> buffer;
};

#endif // HOMEPAGE_H
