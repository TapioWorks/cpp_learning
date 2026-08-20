#ifndef CARD_H
#define CARD_H
#include<QtNetwork>
#include<QNetworkAccessManager>
#include<QJsonDocument>

class Card:public QObject
{
    Q_OBJECT
public:
    Card(QObject *parent=nullptr);
    ~Card();
    void getCardIdCA(QString);
    void cardlock(QString);

signals:
    void sendCardIdInterface(QString,QString,QString);
    void sendcardlock(QString);

private slots:
    void CardIdSlot(QNetworkReply*);
    void cardlockslot(QNetworkReply*);

private:
    QNetworkAccessManager *cardidmanager;
    QNetworkReply *cardidreply;
    QNetworkAccessManager *cardlockmanager;
    QNetworkReply *cardlockreply;
};

#endif // CARD_H
