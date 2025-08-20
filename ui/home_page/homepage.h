#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <qtmetamacros.h>

namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();


private slots:
    void on_pushButton_14_clicked();

private:
    Ui::HomePage *ui;
};

#endif // HOMEPAGE_H
