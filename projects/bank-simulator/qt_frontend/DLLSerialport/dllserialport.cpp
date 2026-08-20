#include "dllserialport.h"


DLLSerialport::DLLSerialport(QObject *parent): QObject(parent)
{
    Pengine = new engine(this);

    connect(Pengine, SIGNAL(serialportDataReadDone()),
            this,SLOT(SerialportData()));
}
void DLLSerialport::SerialportData()
{
    QString serialportData;
    serialportData = Pengine->returnSerialportData();
    emit serialportDatatoExe(serialportData);
}
void DLLSerialport::openSerialPorteng()
{
    Pengine->openSerialPort();

}
void DLLSerialport::closeSerialPorteng()
{
    Pengine->closeSerialPort();
}

