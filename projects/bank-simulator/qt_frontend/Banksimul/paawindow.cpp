#include "paawindow.h"
#include "ui_paawindow.h"

PaaWindow::PaaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PaaWindow)
{
    PNaytaSaldo = new NaytaSaldo;
    ui->setupUi(this);
    pselaa = new SelaaTilitapahtumia;
    pdllrestapi = new DLLRestApi;
    pNostoWindow = new NostoWindow(this);
    this->setWindowTitle("Pääkäyttöliittymä");
    this->setWindowState(Qt::WindowMaximized);
    pTimer = new QTimer(this);
    timercounter=0;
    CustomerID="0";
    AccountID="0";

    connect(pTimer,SIGNAL(timeout()),
            this,SLOT(timerStop()),Qt::QueuedConnection);
    connect(pdllrestapi,SIGNAL(sendCustomerIdExe(QString,QString)),
            this,SLOT(customerslot(QString,QString)),Qt::QueuedConnection);
    pTimer->start(1000);
}

PaaWindow::~PaaWindow()
{
    delete ui;
    delete pselaa;
    pselaa = nullptr;
    delete pTimer;
    delete pNostoWindow;
    pNostoWindow=nullptr;
    pTimer=nullptr;
}


void PaaWindow::sendInfo(QString Aid, QString Cid)
{
    timercounter=0;
    AccountID=Aid;
    CustomerID=Cid;
    pdllrestapi->GetCustomerID(CustomerID);
    pTimer->start(1000);
}


void PaaWindow::on_SaldoButton_clicked()
{
    pTimer->stop();
    timercounter=0;
    PNaytaSaldo->show();
    PNaytaSaldo->sendInformation(CustomerID,AccountID);
    PNaytaSaldo->exec();
    pTimer->start(1000);
}

void PaaWindow::on_NostaButton_clicked()
{
    pTimer->stop();
    timercounter=0;
    pNostoWindow->show();
    pNostoWindow->sendInformation(AccountID,CustomerID);
    pNostoWindow->exec();
    pTimer->start(1000);
}
void PaaWindow::on_SelaaButton_clicked()
{ 
    pTimer->stop();
    timercounter=0;
    pselaa->show();
    pselaa->sendInformation(CustomerID, AccountID);
    pselaa->exec();
    pTimer->start(1000);
}

void PaaWindow::on_UlosButton_clicked()
{
    CustomerID="0";
    AccountID="0";
    pTimer->stop();
    this->close();

}
void PaaWindow::customerslot(QString reply, QString name)
{
   QString reply1=reply;
   ui->NameLabel->setText(name);
}

void PaaWindow::timerStop()
{
    timercounter++;
    if(timercounter==30){
        pTimer->stop();
        CustomerID="0";
        AccountID="0";
        this->close();
    }
}
