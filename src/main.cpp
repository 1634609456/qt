#include <QApplication>

#include "../ui/main_window.hpp"
#include "ElaApplication.h"
#include "qdevtools.h"

int main(int argc, char *argv[]) {    
    QApplication a(argc, argv);
    eApp->init();
    MainWindow w;
    w.show();

    // QDevTool debug;
    // debug.setObject(&w);
    // debug.show();

    return a.exec();
}
