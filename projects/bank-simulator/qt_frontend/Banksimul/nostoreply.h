#ifndef NOSTOREPLY_H
#define NOSTOREPLY_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class NostoReply;
}

class NostoReply : public QDialog
{
    Q_OBJECT

public:
    explicit NostoReply(QWidget *parent = nullptr);
    ~NostoReply();
    void Reply(QString);

private slots:
    void on_pushButton_clicked();
public slots:
   void timerStop();
private:
    Ui::NostoReply *ui;
    QTimer * ptimer;
    short timercounter;
};

#endif // NOSTOREPLY_H
