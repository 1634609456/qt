#ifndef FORM_H
#define FORM_H

#include <QWidget>

#include "../../src/shm_data.hpp"
#include "../../src/util/ring_buffer.hpp"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();


    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();

    


private:
    Ui::Form *ui;
    RingBuffer<RINGBUFFER> buffer;
};

#endif // FORM_H
