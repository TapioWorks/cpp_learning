#include "SerialPort.h"

engine::engine(QObject *parent): QObject(parent)
{
   objectQSerialPort = new QSerialPort;

  connect (objectQSerialPort, SIGNAL(readyRead()), this, SLOT(readSerialPort()));
}
void engine::openSerialPort()
{
    objectQSerialPort->setPortName("COM3");
    objectQSerialPort->setBaudRate(QSerialPort::Baud9600);
    objectQSerialPort->setDataBits(QSerialPort::Data8);
    objectQSerialPort->setParity(QSerialPort::NoParity);
    objectQSerialPort->setStopBits(QSerialPort::OneStop);
    objectQSerialPort->setFlowControl(QSerialPort::NoFlowControl);
    if (objectQSerialPort->open(QIODevice::ReadWrite))
    {
        qDebug () << "serial port open";
    }

    else
    {
        qDebug () << "Fail to open";
    }
}
void engine::closeSerialPort()
{
    objectQSerialPort->close();
}

QString engine::returnSerialportData()
{
  return serialportData;
}

void engine::readSerialPort()
{
    serialportData="";
    serialportData=objectQSerialPort->readAll();
    serialportData.remove(0,3);
    serialportData.chop(3);
    emit serialportDataReadDone();
}
