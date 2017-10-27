#include "mainwindow.h"
#include <QApplication>

#include "myHelper.h"

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);

    myHelper::SetStyle("default");

    MainWindow w;
    w.setWindowTitle(u8"主界面");
    w.show();

    return a.exec();
}
