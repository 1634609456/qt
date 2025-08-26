#ifndef MIDDELCIRCUITBREAKER_H
#define MIDDELCIRCUITBREAKER_H

#include <QWidget>

namespace Ui {
class MiddelCircuitBreaker;
}

class MiddelCircuitBreaker : public QWidget
{
    Q_OBJECT

public:
    explicit MiddelCircuitBreaker(QWidget *parent = nullptr);
    ~MiddelCircuitBreaker();

private:
    Ui::MiddelCircuitBreaker *ui;
};

#endif // MIDDELCIRCUITBREAKER_H
