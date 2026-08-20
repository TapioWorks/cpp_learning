#include "card.h"

Card::Card(QObject *parent):QObject(parent)
{

}
Card::~Card()
{

}
void Card::getCardIdCA(QString id)
{
    QString site_url="http://localhost:3000/card/"+id;
    QString credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    cardidmanager = new QNetworkAccessManager(this);
    connect(cardidmanager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(CardIdSlot(QNetworkReply*)));
    cardidreply = cardidmanager->get(request);
}
void Card::CardIdSlot(QNetworkReply*reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString idcard;
    QString AccountN;
    QString CustomerN;
    foreach (const QJsonValue &value, json_array)
   {
    QJsonObject json_obj = value.toObject();
    idcard+=+"Active"+QString::number(json_obj["Active"].toInt());
    AccountN+=QString::number(json_obj["Accountnumber"].toInt());
    CustomerN+=QString::number(json_obj["CustomerID"].toInt());
   }
    emit sendCardIdInterface(idcard,CustomerN,AccountN);
    reply->deleteLater();
    cardidreply->deleteLater();
    cardidmanager->deleteLater();
}

void Card::cardlock(QString id)
{
    QString site_url="http://localhost:3000/card/"+id+"/lock";
    QString credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    cardlockmanager = new QNetworkAccessManager(this);
    connect(cardlockmanager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(cardlockslot(QNetworkReply*)));
    cardlockreply = cardlockmanager->get(request);
}

void Card::cardlockslot(QNetworkReply*reply)
{
    QByteArray response_data=reply->readAll();

    emit sendcardlock(response_data);
    reply->deleteLater();
    cardlockreply->deleteLater();
    cardlockmanager->deleteLater();
}

