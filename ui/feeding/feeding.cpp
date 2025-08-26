#include "feeding.h"
#include "ui_feeding.h"

feeding::feeding(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::feeding)
{
    ui->setupUi(this);
}

feeding::~feeding()
{
    delete ui;
}
