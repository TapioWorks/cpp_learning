#include "dllrestapi.h"

DLLRestApi::DLLRestApi(QObject *parent):QObject(parent)
{
    pengineclass=new Engineclass(this);
    paccount=new Account(this);
    pcustomer=new Customer(this);
    pcard=new Card(this);
    plogin=new Login(this);

    connect(pengineclass,SIGNAL(sendallactionsinterface(QString)),
            this,SLOT(receiveEngineallactions(QString)),Qt::QueuedConnection);

    connect(pengineclass,SIGNAL(sendidactionsinterface(QString))
            ,this,SLOT(receiveEngineIdActions(QString)),Qt::QueuedConnection);

    connect(pengineclass,SIGNAL(sendMoneyOttointerface(QString))
            ,this,SLOT(receiveEngineMoneyOtto(QString)),Qt::QueuedConnection);

    connect(paccount,SIGNAL(sendIdAccountInterface(QString))
            ,this,SLOT(receiveAccountId(QString)),Qt::QueuedConnection);

    connect(pcustomer,SIGNAL(sendCustomerIdInterface(QString,QString))
            ,this,SLOT(receiveCustomerId(QString,QString)),Qt::QueuedConnection);

    connect(pcard,SIGNAL(sendCardIdInterface(QString,QString,QString))
            ,this,SLOT(receiveCardId(QString,QString,QString)),Qt::QueuedConnection);

    connect(plogin,SIGNAL(sendLoginInterface(QString))
            ,this,SLOT(receiveLogin(QString)),Qt::QueuedConnection);

    connect(pcard,SIGNAL(sendcardlock(QString))
            ,this,SLOT(cardlockslot()),Qt::QueuedConnection);
}
void DLLRestApi::GetAllactionsEng(QString id, QString arr)
{
    pengineclass->getallactionsfunc(id, arr);
}

void DLLRestApi::receiveEngineallactions(QString reply)
{
    emit sendallactionstoExe(reply);
}
void DLLRestApi::GetIdActionsEng(QString id)
{
    pengineclass->getidactionsfunc(id);
}
void DLLRestApi::receiveEngineIdActions(QString reply)
{
    emit sendIdActionsExe(reply);
}
void DLLRestApi::PostMoneyOttoEng(QString id,QString amount)
{
    pengineclass->postMoneyOtto(id,amount);
}
void DLLRestApi::receiveEngineMoneyOtto(QString reply)
{
    emit sendMoneyOttoExe(reply);
}
void DLLRestApi::GetAccountID(QString id)
{
    paccount->getAccountIdAC(id);
}
void DLLRestApi::receiveAccountId(QString reply)
{
    emit sendAccountIdExe(reply);
}
void DLLRestApi::GetCustomerID(QString id)
{
    pcustomer->GetCustomerIdCU(id);
}
void DLLRestApi::receiveCustomerId(QString reply,QString name)
{
    emit sendCustomerIdExe(reply,name);
}
void DLLRestApi::GetCardID(QString id)
{
    pcard->getCardIdCA(id);
}
void DLLRestApi::receiveCardId(QString cardid,QString CustomerN,QString AccountN)
{
    emit sendCardIdExe(cardid,CustomerN,AccountN);
}
void DLLRestApi::CheckLogin(QString card, QString pin)
{
    plogin->checkloginLO(card,pin);
}
void DLLRestApi::receiveLogin(QString reply)
{
    emit sendLoginExe(reply);
}

void DLLRestApi::cardlock(QString id)
{
    pcard->cardlock(id);
}

void DLLRestApi::cardlockslot()
{
    emit cardlockexe();
}
