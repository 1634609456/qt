#include "middelcircuitbreaker.h"
#include "ui_middelcircuitbreaker.h"

MiddelCircuitBreaker::MiddelCircuitBreaker(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MiddelCircuitBreaker)
{
    ui->setupUi(this);
}

MiddelCircuitBreaker::~MiddelCircuitBreaker()
{
    delete ui;
}
