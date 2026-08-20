#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H

#include<QtNetwork>
#include<QNetworkAccessManager>
#include<QJsonDocument>
#include<Actions.h>
#include<account.h>
#include<customer.h>
#include<card.h>
#include<login.h>
#include "DLLRestApi_global.h"
#include <QDebug>

class DLLRESTAPI_EXPORT DLLRestApi: public QObject
{
    Q_OBJECT
public:
   DLLRestApi(QObject *parent=nullptr);
   void GetAllactionsEng(QString, QString);
   void GetIdActionsEng(QString);
   void PostMoneyOttoEng(QString,QString);
   void GetAccountID(QString);
   void GetCustomerID(QString);
   void GetCardID(QString);
   void CheckLogin(QString,QString);
   void cardlock(QString);

private:
    Engineclass * pengineclass;
    Account * paccount;
    Customer * pcustomer;
    Card * pcard;
    Login * plogin;
private slots:
   void receiveEngineallactions(QString);
   void receiveEngineIdActions(QString);
   void receiveEngineMoneyOtto(QString);
   void receiveAccountId(QString);
   void receiveCustomerId(QString,QString);
   void receiveCardId(QString,QString,QString);
   void cardlockslot();
   void receiveLogin(QString);

signals:
   void sendallactionstoExe(QString);
   void sendIdActionsExe(QString);
   void sendMoneyOttoExe(QString);
   void sendAccountIdExe(QString);
   void sendCustomerIdExe(QString,QString);
   void sendCardIdExe(QString,QString,QString);
   void sendLoginExe(QString);
   void cardlockexe();

};

#endif // DLLRESTAPI_H
