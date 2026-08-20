#ifndef DLLSERIALPORT_H
#define DLLSERIALPORT_H

#include "dllserialport_global.h"
#include <SerialPort.h>
#include <QDebug>


class DLLSERIALPORTSHARED_EXPORT DLLSerialport : public QObject
{
   Q_OBJECT

public:
    DLLSerialport(QObject *parent = nullptr);

    void openSerialPorteng();
    void closeSerialPorteng();

private:
    engine *Pengine;

public slots:
    void SerialportData();

signals:
    void serialportDatatoExe(QString);

};

#endif // DLLSERIALPORT_H
