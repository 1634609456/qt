#ifndef BESIDEPASS_H
#define BESIDEPASS_H

#include <QWidget>

namespace Ui {
class BesidePass;
}

class BesidePass : public QWidget
{
    Q_OBJECT

public:
    explicit BesidePass(QWidget *parent = nullptr);
    ~BesidePass();

private:
    Ui::BesidePass *ui;
};

#endif // BESIDEPASS_H
