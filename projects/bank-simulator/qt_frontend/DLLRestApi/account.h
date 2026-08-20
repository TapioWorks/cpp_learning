#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<QtNetwork>
#include<QNetworkAccessManager>
#include<QJsonDocument>

class Account:public QObject
{
    Q_OBJECT
public:
    Account(QObject*parent=nullptr);
    ~Account();
    void getAccountIdAC(QString);
signals:
    void sendIdAccountInterface(QString);
private slots:
    void AccountIdSlot(QNetworkReply*);
private:
    QNetworkAccessManager *idaccountmanager;
    QNetworkReply *idaccountreply;

};

#endif // ACCOUNT_H
