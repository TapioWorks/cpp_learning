#include "selaatilitapahtumia.h"
#include "ui_selaatilitapahtumia.h"

SelaaTilitapahtumia::SelaaTilitapahtumia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelaaTilitapahtumia)
{
    ui->setupUi(this);
    pDLLrestapi = new DLLRestApi(this);
    pTimer = new QTimer(this);
    arr = "0";
    id = "0";
    Aid = "0";
    count = 0;
    this->setWindowTitle("Selaa Tilitapahtumia");
    this->setWindowState(Qt::WindowMaximized);

    connect(pTimer,SIGNAL(timeout()),
            this,SLOT(timerStop()),Qt::QueuedConnection);

    connect(pDLLrestapi,SIGNAL(sendAccountIdExe(QString))
            ,this,SLOT(accountidslot(QString)),Qt::QueuedConnection);

    connect(pDLLrestapi,SIGNAL(sendCustomerIdExe(QString,QString))
            ,this,SLOT(customeridslot(QString)),Qt::QueuedConnection);

    connect(pDLLrestapi,SIGNAL(sendallactionstoExe(QString))
            ,this,SLOT(idactionsslot(QString)));

    pTimer->start(1000);
}

SelaaTilitapahtumia::~SelaaTilitapahtumia()
{
    delete ui;
    delete pTimer;
    pTimer=nullptr;
}

void SelaaTilitapahtumia::sendInformation(QString CustomerID, QString AccountID)
{
    id=CustomerID;
    Aid=AccountID;
    pDLLrestapi->GetCustomerID(id);
    pDLLrestapi->GetAccountID(Aid);
    pDLLrestapi->GetAllactionsEng(Aid, arr);
    timercounter=0;
    pTimer->start(1000);
}

void SelaaTilitapahtumia::on_CloseButton_clicked()
{
    arr = "0";
    id = "0";
    Aid = "0";
    count = 0;
    this->close();
}

void SelaaTilitapahtumia::idactionsslot(QString reply)
{
    ui->TiliLabel->setText(reply);
}

void SelaaTilitapahtumia::customeridslot(QString reply)
{
    ui->CustLabel->setText(reply);
}

void SelaaTilitapahtumia::accountidslot(QString reply)
{
    ui->AccountLabel->setText(reply);
}

void SelaaTilitapahtumia::timerStop()
{
    timercounter++;
    if(timercounter==10){
        arr = "0";
        id = "0";
        Aid = "0";
        count = 0;
        this->close();
    }
}

void SelaaTilitapahtumia::on_forwButton_clicked()
{
    timercounter=0;
    count = count + 10;
    arr = QString::number(count);
    pDLLrestapi->GetAllactionsEng(Aid, arr);
}

void SelaaTilitapahtumia::on_backButton_clicked()
{
    timercounter=0;
    count = count - 10;
    arr = QString::number(count);
    if (arr<"0"){
        arr = "0";
        count = 0;
    }
    pDLLrestapi->GetAllactionsEng(Aid, arr);
}
