#ifndef PAAWINDOW_H
#define PAAWINDOW_H

#include <QDialog>
#include "selaatilitapahtumia.h"
#include <naytasaldo.h>
#include <QTimer>
#include <nostowindow.h>
#include <dllrestapi.h>

namespace Ui {
class PaaWindow;
}

class PaaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PaaWindow(QWidget *parent = nullptr);
    ~PaaWindow();    
    void sendInfo(QString,QString);

public slots:
     void timerStop();
     void customerslot(QString,QString);

private slots:

    void on_SaldoButton_clicked();

    void on_SelaaButton_clicked();

    void on_NostaButton_clicked();

    void on_UlosButton_clicked();

private:
    Ui::PaaWindow *ui;
    SelaaTilitapahtumia *pselaa;
    NaytaSaldo *PNaytaSaldo;
    NostoWindow * pNostoWindow;
    DLLRestApi * pdllrestapi;
    QTimer * pTimer;
    short timercounter;
    QString AccountID;
    QString CustomerID;
};

#endif // PAAWINDOW_H
