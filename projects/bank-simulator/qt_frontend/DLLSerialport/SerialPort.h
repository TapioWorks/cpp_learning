#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include <QDebug>

class engine : public QObject
{
    Q_OBJECT
public:
    engine(QObject *parent = nullptr);

    void openSerialPort();
    void closeSerialPort();

    QString returnSerialportData();

private:
    QSerialPort *objectQSerialPort = nullptr;
    QString serialportData;

private slots:
    void readSerialPort();

signals:
    void serialportDataReadDone();
};

#endif // SERIALPORT_H
