#ifndef MAINFLYER_H
#define MAINFLYER_H

#include <QWidget>

namespace Ui {
class MainFlyer;
}

class MainFlyer : public QWidget
{
    Q_OBJECT

public:
    explicit MainFlyer(QWidget *parent = nullptr);
    ~MainFlyer();

private:
    Ui::MainFlyer *ui;
};

#endif // MAINFLYER_H
