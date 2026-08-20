#include "dllpincode.h"

DLLPinCode::DLLPinCode(QObject *parent):QObject(parent)
{
    pDialogpin = new DialogPin();
}
DLLPinCode::~DLLPinCode()
{

}
QString DLLPinCode::GetPin()
{
    QString PIN="0";
    PIN=pDialogpin->Getpin();
    return PIN;
}
QString DLLPinCode::GetPinAgain()
{
    QString PIN="";
    PIN=pDialogpin->GetPinAgain();
    qDebug()<<PIN;
    return PIN;
}
