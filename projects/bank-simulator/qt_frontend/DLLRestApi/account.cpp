#include "account.h"

Account::Account(QObject *parent):QObject(parent)
{

}
Account::~Account()
{

}
void Account::getAccountIdAC(QString id)
{
    QString site_url="http://localhost:3000/account/"+id;
    QString credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    idaccountmanager = new QNetworkAccessManager(this);
    connect(idaccountmanager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(AccountIdSlot(QNetworkReply*)));
    idaccountreply = idaccountmanager->get(request);
}
void Account::AccountIdSlot(QNetworkReply* reply)
{
    QByteArray response_data=reply->readAll();
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonArray json_array = json_doc.array();
        QString account;
        foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        account+=+"Tilinumero: "+QString::number(json_obj["Accountnumber"].toInt())+"\nTilivara: "+QString::number(json_obj["Accountbalance"].toDouble())+"\r\n";
        }
        emit sendIdAccountInterface(account);
        reply->deleteLater();
        idaccountmanager->deleteLater();
        idaccountreply->deleteLater();
}
