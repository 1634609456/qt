#include "mainflyer.h"
#include "ui_mainflyer.h"

MainFlyer::MainFlyer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainFlyer)
{
    ui->setupUi(this);
}

MainFlyer::~MainFlyer()
{
    delete ui;
}
