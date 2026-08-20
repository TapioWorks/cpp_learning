#ifndef ACTIONS_H
#define ACTIONS_H
#include<QtNetwork>
#include<QNetworkAccessManager>
#include<QJsonDocument>

class Engineclass:public QObject
{
    Q_OBJECT
public:
    Engineclass(QObject *parent =nullptr);
    ~Engineclass();
    void getallactionsfunc(QString, QString);
    void getidactionsfunc(QString);
    void postMoneyOtto(QString,QString);

signals:
    void sendallactionsinterface(QString);
    void sendidactionsinterface(QString);
    void sendMoneyOttointerface(QString);
private slots:
    void getallactionsslot(QNetworkReply*);
    void IDactionsslot(QNetworkReply*);
    void nostoactionsslot(QNetworkReply*);
private:
    QNetworkAccessManager *allactionsmanager;
    QNetworkReply *allactionsreply;
    QNetworkAccessManager *IDactionsmanager;
    QNetworkReply *IDactionsreply;
    QNetworkAccessManager *nostoactionsmanager;
    QNetworkReply *nostoactionsreply;
};

#endif // ACTIONS_H
