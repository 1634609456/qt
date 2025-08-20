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
    void on_pushButton_14_clicked();

private:
    Ui::HomePage *ui;
    RingBuffer<RINGBUFFER> buffer;

};

#endif // HOMEPAGE_H
