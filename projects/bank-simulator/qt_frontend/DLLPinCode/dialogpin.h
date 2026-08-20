#ifndef DIALOGPIN_H
#define DIALOGPIN_H

#include <QDialog>
#include <QTimer>
#include <QVector>

namespace Ui {
class DialogPin;
}

class DialogPin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPin(QWidget *parent = nullptr);
    ~DialogPin();
    QString Getpin();
    QString GetPinAgain();
    void updateLine(QString);
private slots:

    void on_Button_1_clicked();
    void on_Button_2_clicked();
    void on_Button_3_clicked();
    void on_Button_4_clicked();
    void on_Button_5_clicked();
    void on_Button_6_clicked();
    void on_Button_7_clicked();
    void on_Button_8_clicked();
    void on_Button_9_clicked();
    void on_CancelBut_clicked();
    void on_OkBut_clicked();

    void on_Button_0_clicked();

    void on_backbutton_clicked();

public slots:
    void timeslot();

private:
    Ui::DialogPin *ui;
    QTimer * ptimer;
    QString PIN;
    QString Line;
    short timercount;
};

#endif // DIALOGPIN_H
