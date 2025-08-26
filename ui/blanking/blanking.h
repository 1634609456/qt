#ifndef BLANKING_H
#define BLANKING_H

#include <QWidget>

namespace Ui {
class Blanking;
}

class Blanking : public QWidget
{
    Q_OBJECT

public:
    explicit Blanking(QWidget *parent = nullptr);
    ~Blanking();

private:
    Ui::Blanking *ui;
};

#endif // BLANKING_H
