#ifndef NAYTASALDO_H
#define NAYTASALDO_H

#include <QDialog>
#include <QTimer>
#include <dllrestapi.h>
#include <QDebug>

namespace Ui {
class NaytaSaldo;
}

class NaytaSaldo : public QDialog
{
    Q_OBJECT

public:
    explicit NaytaSaldo(QWidget *parent = nullptr);
    ~NaytaSaldo();
    void sendInformation(QString,QString);
public slots:
    void saldoslot(QString);
    void idactionsslot(QString);
    void timerStop();
    void customerslot(QString);

private slots:
    void on_CloseButton_clicked();

private:
    Ui::NaytaSaldo *ui;
    DLLRestApi * pDLLrestapi;
    QTimer * pTimer;
    short timercounter;
    QString id;
    QString Aid;
};

#endif // NAYTASALDO_H
