#ifndef DIALOGLOCK_H
#define DIALOGLOCK_H

#include <QDialog>
#include <qtimer.h>

namespace Ui {
class Dialoglock;
}

class Dialoglock : public QDialog
{
    Q_OBJECT

public:
    explicit Dialoglock(QWidget *parent = nullptr);
    ~Dialoglock();
    void lockedcard();
    void lockingcard();


private:
    Ui::Dialoglock *ui;
    QTimer * ptimer;
    short timercounter;

private slots:

    void timeslot();
};

#endif // DIALOGLOCK_H
