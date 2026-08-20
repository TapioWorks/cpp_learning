#ifndef NOSTOWINDOW_H
#define NOSTOWINDOW_H

#include <QDialog>
#include <dllrestapi.h>
#include <nostoreply.h>
#include <QTimer>

namespace Ui {
class NostoWindow;
}

class NostoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NostoWindow(QWidget *parent = nullptr);
    ~NostoWindow();
    void sendInformation(QString,QString);
public slots:
    void moneyottoslot(QString);
    void customeridslot(QString);
    void accountidslot(QString);
    void timerStop();
private slots:
    void on_button_1_clicked();

    void on_button_2_clicked();

    void on_button_3_clicked();

    void on_button_4_clicked();

    void on_button_5_clicked();

    void on_button_6_clicked();

    void on_CloseButton_clicked();

private:
    Ui::NostoWindow *ui;
    DLLRestApi * pDLLrestapi;
    NostoReply * pNostoReply;
    QTimer * pTimer;
    short timercounter;
    QString Cid;
    QString Aid;
};

#endif // NOSTOWINDOW_H
