#ifndef SelaaTilitapahtumia_H
#define SelaaTilitapahtumia_H

#include <QDialog>
#include <dllrestapi.h>
#include <QTimer>

namespace Ui {
class SelaaTilitapahtumia;
}

class SelaaTilitapahtumia : public QDialog
{
    Q_OBJECT

public:
    explicit SelaaTilitapahtumia(QWidget *parent = nullptr);
    ~SelaaTilitapahtumia();
    void sendInformation(QString,QString);
public slots:
    void customeridslot(QString);
    void accountidslot(QString);
    void idactionsslot(QString);
    void timerStop();
private slots:
    void on_CloseButton_clicked();

    void on_forwButton_clicked();

    void on_backButton_clicked();

private:
    Ui::SelaaTilitapahtumia *ui;
    DLLRestApi * pDLLrestapi;
    QTimer * pTimer;
    short timercounter;
    QString id;
    QString Aid;
    QString arr;
    int count;
};

#endif // SelaaTilitapahtumia_H
