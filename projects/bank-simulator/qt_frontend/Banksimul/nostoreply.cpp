#include "nostoreply.h"
#include "ui_nostoreply.h"

NostoReply::NostoReply(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NostoReply)
{
    ui->setupUi(this);
    ptimer = new QTimer(this);
    timercounter=0;
    this->setWindowState(Qt::WindowMaximized);

    connect(ptimer,SIGNAL(timeout()),
            this,SLOT(timerStop()),Qt::QueuedConnection);
    ptimer->start(1000);
}

NostoReply::~NostoReply()
{
    delete ui;
    delete ptimer;
    ptimer=nullptr;
}

void NostoReply::Reply(QString reply)
{
    timercounter=0;
    ptimer->start(1000);
    show();
    ui->label->setText(reply);
    exec();
}

void NostoReply::on_pushButton_clicked()
{
    ptimer->stop();
    this->close();
}
void NostoReply::timerStop()
{
    timercounter++;
    if(timercounter==10){
        ptimer->stop();
        this->close();
    }

}
