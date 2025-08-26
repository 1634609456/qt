#ifndef FEEDING_H
#define FEEDING_H

#include <QWidget>

namespace Ui {
class feeding;
}

class feeding : public QWidget
{
    Q_OBJECT

public:
    explicit feeding(QWidget *parent = nullptr);
    ~feeding();

private:
    Ui::feeding *ui;
};

#endif // FEEDING_H
