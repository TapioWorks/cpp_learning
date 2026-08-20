#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("AloitusLiittymä");
    this->setWindowState(Qt::WindowMaximized);
    pRestApi = new DLLRestApi;
    pPinCode = new DLLPinCode(this);
    pSerialPort = new DLLSerialport;
    pPaawindow = new PaaWindow;
    pDialoglock = new Dialoglock;
    ptimer=new QTimer();
    timercounter=0;
    PIN="0";
    CustomerID="0";
    AccountID="0";
    cardID="0";
    CardInfo="0";
    lock=0;
    pincheck=0;

    connect(pRestApi,SIGNAL(sendCardIdExe(QString,QString,QString))
            ,this,SLOT(cardidslot(QString,QString,QString)));

    connect(pRestApi,SIGNAL(sendLoginExe(QString))
            ,this,SLOT(loginslot(QString)),Qt::QueuedConnection);

    connect(pSerialPort,SIGNAL(serialportDatatoExe(QString))
            ,this,SLOT(readSerialPort(QString)),Qt::QueuedConnection);

    connect(pRestApi,SIGNAL(cardlockexe())
            ,this,SLOT(cardlockslot()),Qt::QueuedConnection);

    pSerialPort->openSerialPorteng();

}
MainWindow::~MainWindow()
{
    delete ui;
    delete pRestApi;
    pRestApi=nullptr;
    delete pSerialPort;
    delete pPinCode;
    delete pPaawindow;
    pSerialPort=nullptr;
    pPinCode=nullptr;
    pPaawindow=nullptr;

}

void MainWindow::cardidslot(QString cardid,QString CustomerN,QString AccountN)
{
    CustomerID="0";
    AccountID="0";
    CardInfo="0";
    CardInfo=cardid;
    CustomerID=CustomerN;
    AccountID=AccountN;
    qDebug()<<CustomerID;
    qDebug()<<AccountID;
    qDebug()<<CardInfo;

    if(pincheck==CardInfo.compare("Active1",CardInfo))
    {
                PIN=pPinCode->GetPin();
        if(pincheck==PIN.compare("",PIN)){
            pSerialPort->openSerialPorteng();

        }
        else {
           pRestApi->CheckLogin(cardID,PIN);
        }

    }
    else
    {
       pDialoglock->lockedcard();
       pSerialPort->openSerialPorteng();
    }
}

void MainWindow::loginslot(QString reply)
{
    qDebug()<<reply;
    qDebug()<<PIN;
    qDebug()<<PIN.toInt();

    if(reply=="true"){
        pPaawindow->show();
        pPaawindow->sendInfo(AccountID,CustomerID);
        pPaawindow->exec();
        cardID="0";
        PIN="0";
        lock=0;
    }

    if(reply=="false" && pincheck==PIN.toInt())
    {
        cardID="0";
        pSerialPort->openSerialPorteng();
        ui->label->setText("syötä kortti");
    }

    else if(reply=="false"){

        if(lock==3) {
            pRestApi->cardlock(cardID);
            lock=0;
            pDialoglock->lockingcard();
        }
        else {
            lock++;
            PIN="";
            PIN=pPinCode->GetPinAgain();
            pRestApi->CheckLogin(cardID,PIN);
        }

    }
    else {
        cardID="0";
        PIN="0";
        pSerialPort->openSerialPorteng();
        ui->label->setText("syötä kortti");
    }

}

void MainWindow::readSerialPort(QString cardid)
{
    cardID=cardid;
    pRestApi->GetCardID(cardID);
}

void MainWindow::cardlockslot()
{
    ui->label->setText("Kortti on lukittu");
    pSerialPort->openSerialPorteng();
    ui->label->setText("Syötä kortti");
}

