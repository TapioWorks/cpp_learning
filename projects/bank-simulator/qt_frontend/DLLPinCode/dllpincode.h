#ifndef DLLPINCODE_H
#define DLLPINCODE_H

#include "DLLPinCode_global.h"
#include <QObject>
#include "dialogpin.h"
#include <qdebug.h>
class DLLPINCODE_EXPORT DLLPinCode : public QObject

{
    Q_OBJECT
public:
    DLLPinCode(QObject *parent);
    ~DLLPinCode();
    QString GetPin();
    QString GetPinAgain();
private:
    DialogPin * pDialogpin;

};

#endif // DLLPINCODE_H
