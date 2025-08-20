#include "homepage.h"
#include "ui_homepage.h"

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomePage)
{
    ui->setupUi(this);
}

HomePage::~HomePage()
{
    delete ui;
}


void HomePage::on_pushButton_14_clicked()
{
    qDebug() << "点击了电机主页的按钮";
}

