#include "naytasaldo.h"
#include "ui_naytasaldo.h"

NaytaSaldo::NaytaSaldo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NaytaSaldo)
{
    ui->setupUi(this);
    pDLLrestapi = new DLLRestApi(this);
    pTimer = new QTimer(this);
    this->setWindowTitle("Näytä saldo");
    this->setWindowState(Qt::WindowMaximized);
    id = "0";
    Aid = "0";
    timercounter=0;

    connect(pTimer,SIGNAL(timeout()),
            this,SLOT(timerStop()),Qt::QueuedConnection);

    connect(pDLLrestapi,SIGNAL(sendAccountIdExe(QString))
            ,this,SLOT(saldoslot(QString)),Qt::QueuedConnection);

    connect(pDLLrestapi,SIGNAL(sendCustomerIdExe(QString,QString))
            ,this,SLOT(customerslot(QString)),Qt::QueuedConnection);

    connect(pDLLrestapi,SIGNAL(sendIdActionsExe(QString))
            ,this,SLOT(idactionsslot(QString)),Qt::QueuedConnection);

    pTimer->start(1000);
}

NaytaSaldo::~NaytaSaldo()
{
    delete ui;
    delete pTimer;
    pTimer=nullptr;
}
void NaytaSaldo::sendInformation(QString CustomerID, QString AccountID)
{
    id=CustomerID;
    Aid=AccountID;
    pDLLrestapi->GetCustomerID(id);
    pDLLrestapi->GetAccountID(Aid);
    pDLLrestapi->GetIdActionsEng(Aid);
}

void NaytaSaldo::on_CloseButton_clicked()
{
    pTimer->stop();
    this->close();
}
void NaytaSaldo::saldoslot(QString reply)
{
   ui->Saldoaccountballabel->setText(reply);
}
void NaytaSaldo::idactionsslot(QString reply)
{
    ui->Saldoactionslabel->setText(reply);
}
void NaytaSaldo::customerslot(QString reply)
{
    timercounter = 0;
    pTimer->start(1000);
    ui->Saldocustomerlabel->setText(reply);
}
void NaytaSaldo::timerStop()
{
    timercounter++;
    if(timercounter==10){
    pTimer->stop();
    this->close();
    }
}
