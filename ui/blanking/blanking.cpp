#include "blanking.h"
#include "ui_blanking.h"

Blanking::Blanking(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Blanking)
{
    ui->setupUi(this);
}

Blanking::~Blanking()
{
    delete ui;
}
