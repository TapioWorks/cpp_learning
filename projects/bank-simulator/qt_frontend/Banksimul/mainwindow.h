#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dllrestapi.h>
#include <dllpincode.h>
#include <dllserialport.h>
#include <QTimer>
#include <QDebug>
#include <paawindow.h>
#include "dialoglock.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void openSerialPort();
    void closeSerialPort();

    QString returnSerialportData();

signals:

    void finishProgram();
    void timersignal();
    void serialportDataReadDone();

public slots:

    void cardidslot(QString,QString,QString);
    void loginslot(QString);
    void readSerialPort(QString);
    void cardlockslot();

private slots:


private:
    Ui::MainWindow *ui;
    DLLRestApi *    pRestApi;
    DLLPinCode *    pPinCode;
    DLLSerialport * pSerialPort;
    Dialoglock * pDialoglock;
    QTimer * ptimer;
    PaaWindow * pPaawindow;
    short timercounter;
    QString PIN;
    QString cardID;
    QString CustomerID;
    QString AccountID;

    QString serialportData;

    QString CardInfo;
    int lock;
    int pincheck;

};
#endif // MAINWINDOW_H
