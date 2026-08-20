#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *maintimer=new MainWindow;
    QObject::connect(maintimer,SIGNAL(finishProgram()),&a,SLOT(quit()),
                     Qt::QueuedConnection);
    MainWindow w;
    w.show();
    int execvalue;
    execvalue=a.exec();
    delete maintimer;
    maintimer=nullptr;
    return execvalue;
}
