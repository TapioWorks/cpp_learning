#include "dialoglock.h"
#include "ui_dialoglock.h"


Dialoglock::Dialoglock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialoglock)
{
    ui->setupUi(this);
    ptimer=new QTimer;
    timercounter=0;
    this->setWindowState(Qt::WindowMaximized);

    connect(ptimer,SIGNAL(timeout()),
            this,SLOT(timeslot()),Qt::QueuedConnection);
    ptimer->start(1000);
}

Dialoglock::~Dialoglock()
{
    delete ui;
}

void Dialoglock::lockedcard()
{
    timercounter=0;
    ptimer->start(1000);
    ui->label->setText("Korttisi on lukittu");
    show();
    exec();
}

void Dialoglock::lockingcard()
{
    timercounter=0;
    ptimer->start(1000);
    ui->label->setText("Korttisi lukitaan");
    show();
    exec();
}

void Dialoglock::timeslot()
{
    timercounter++;
    if(timercounter==5) {
        ptimer->stop();
        this->close();
    }
}
