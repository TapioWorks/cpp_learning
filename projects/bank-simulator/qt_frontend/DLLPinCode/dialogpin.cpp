#include "dialogpin.h"
#include "ui_dialogpin.h"

DialogPin::DialogPin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPin)
{
    ui->setupUi(this);
    ptimer = new QTimer(this);
    PIN="0";
    timercount=0;
    Line="";
    this->setWindowState(Qt::WindowMaximized);

    connect(ptimer,SIGNAL(timeout()),
            this,SLOT(timeslot()),Qt::QueuedConnection);
    ptimer->start(1000);
}

DialogPin::~DialogPin()
{
    delete ui;
}

QString DialogPin::Getpin()
{
    ui->label->setText("Syötä pin");
    show();
    exec();
    return PIN;
}
QString DialogPin::GetPinAgain()
{
    ui->label->setText("Väärä pin, yritä uudelleen");
    show();
    exec();
    return PIN;
}

void DialogPin::timeslot()
{
    timercount++;
    if(timercount==10){
        ptimer->stop();
        ui->linePin->clear();
        this->close();
    }
}

void DialogPin::on_Button_1_clicked()
{
    QString a=ui->Button_1->text();
    updateLine(a);
}

void DialogPin::on_Button_2_clicked()
{
    QString a=ui->Button_2->text();
    updateLine(a);
}

void DialogPin::on_Button_3_clicked()
{
    QString a=ui->Button_3->text();
    updateLine(a);
}

void DialogPin::on_Button_4_clicked()
{
    QString a=ui->Button_4->text();
    updateLine(a);
}

void DialogPin::on_Button_5_clicked()
{
    QString a=ui->Button_5->text();
    updateLine(a);
}

void DialogPin::on_Button_6_clicked()
{
    QString a=ui->Button_6->text();
    updateLine(a);
}

void DialogPin::on_Button_7_clicked()
{
    QString a=ui->Button_7->text();
    updateLine(a);
}

void DialogPin::on_Button_8_clicked()
{
    QString a=ui->Button_8->text();
    updateLine(a);
}

void DialogPin::on_Button_9_clicked()
{
    QString a=ui->Button_9->text();
    updateLine(a);
}
void DialogPin::on_Button_0_clicked()
{
    QString a=ui->Button_0->text();
    updateLine(a);
}
void DialogPin::on_CancelBut_clicked()
{
    PIN="";
    Line="";
    ui->linePin->clear();
    this->close();
}

void DialogPin::updateLine(QString a)
{
    Line+=a;
    ui->linePin->setText(Line);
}
void DialogPin::on_OkBut_clicked()
{
    PIN="";
    PIN=ui->linePin->text();
    ui->linePin->clear();
    Line="";
    this->close();
}


void DialogPin::on_backbutton_clicked()
{
    Line.chop(1);
    ui->linePin->setText(Line);
}
