#include "besidepass.h"
#include "ui_besidepass.h"

BesidePass::BesidePass(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BesidePass)
{
    ui->setupUi(this);
}

BesidePass::~BesidePass()
{
    delete ui;
}
