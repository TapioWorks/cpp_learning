#include "nostowindow.h"
#include "ui_nostowindow.h"

NostoWindow::NostoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NostoWindow)
{
    ui->setupUi(this);
    pDLLrestapi = new DLLRestApi(this);
    pNostoReply = new NostoReply(this);
    pTimer = new QTimer(this);
    this->setWindowTitle("Rahan Nosto");
    this->setWindowState(Qt::WindowMaximized);
    timercounter=0;
    Aid="0";
    Cid="0";

    connect(pTimer,SIGNAL(timeout()),
            this,SLOT(timerStop()),Qt::QueuedConnection);

    connect(pDLLrestapi,SIGNAL(sendAccountIdExe(QString))
            ,this,SLOT(accountidslot(QString)),Qt::QueuedConnection);

    connect(pDLLrestapi,SIGNAL(sendCustomerIdExe(QString,QString))
            ,this,SLOT(customeridslot(QString)),Qt::QueuedConnection);

    connect(pDLLrestapi,SIGNAL(sendMoneyOttoExe(QString))
            ,this,SLOT(moneyottoslot(QString)),Qt::QueuedConnection);


    pTimer->start(1000);
}

NostoWindow::~NostoWindow()
{
    delete ui;
    delete pDLLrestapi;
    delete pNostoReply;
    delete pTimer;
    pDLLrestapi=nullptr;
    pNostoReply=nullptr;
    pTimer=nullptr;

}
void NostoWindow::sendInformation(QString AccountID, QString CustomerID)
{
    Cid=CustomerID;
    Aid=AccountID;
    pDLLrestapi->GetCustomerID(Cid);
    pDLLrestapi->GetAccountID(Aid);
}
void NostoWindow::on_button_1_clicked()
{
    pTimer->stop();
    timercounter=0;
    QString amount=ui->button_1->text();
    amount.chop(1);
    pDLLrestapi->PostMoneyOttoEng(Aid,amount);

}

void NostoWindow::on_button_2_clicked()
{
    pTimer->stop();
    timercounter=0;
    QString amount=ui->button_2->text();
    amount.chop(1);
    pDLLrestapi->PostMoneyOttoEng(Aid,amount);
}

void NostoWindow::on_button_3_clicked()
{
    pTimer->stop();
    timercounter=0;
    QString amount=ui->button_3->text();
    amount.chop(1);
    pDLLrestapi->PostMoneyOttoEng(Aid,amount);
}

void NostoWindow::on_button_4_clicked()
{
    pTimer->stop();
    timercounter=0;
    QString amount=ui->button_4->text();
    amount.chop(1);
    pDLLrestapi->PostMoneyOttoEng(Aid,amount);
}

void NostoWindow::on_button_5_clicked()
{
    pTimer->stop();
    timercounter=0;
    QString amount=ui->button_5->text();
    amount.chop(1);
    pDLLrestapi->PostMoneyOttoEng(Aid,amount);
}

void NostoWindow::on_button_6_clicked()
{
    pTimer->stop();
    timercounter=0;
    QString amount=ui->button_6->text();
    amount.chop(1);
    pDLLrestapi->PostMoneyOttoEng(Aid,amount);
}

void NostoWindow::on_CloseButton_clicked()
{
    Aid="0";
    Cid="0";
    pTimer->stop();
    this->close();
}
void NostoWindow::moneyottoslot(QString reply)
{
    pNostoReply->Reply(reply);
    pDLLrestapi->GetAccountID(Aid);
    pTimer->start(1000);
}
void NostoWindow::customeridslot(QString reply)
{
    timercounter=0;
    ui->CustomerLabel->setText(reply);
    pTimer->start(1000);
}
void NostoWindow::accountidslot(QString reply)
{
    ui->AccountLabel->setText(reply);
}
void NostoWindow::timerStop()
{
    timercounter++;
    if(timercounter==10){
        Aid="0";
        Cid="0";
        pTimer->stop();
        this->close();

    }
}
