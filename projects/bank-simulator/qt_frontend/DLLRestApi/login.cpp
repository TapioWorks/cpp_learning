#include "login.h"

Login::Login(QObject *parent):QObject(parent)
{

}
Login::~Login()
{

}
void Login::checkloginLO(QString card, QString pin)
{
    QJsonObject json;
    json.insert("Cardnumber",card);
    json.insert("CardPIN",pin);
    QString site_url="http://localhost:3000/login/";
    QString credentials="admin:1234";
    QNetworkRequest request((site_url)); request.setHeader(QNetworkRequest::ContentTypeHeader,
    "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    Loginmanager = new QNetworkAccessManager(this);
    connect(Loginmanager, SIGNAL(finished (QNetworkReply*)),
            this, SLOT(LoginSlot(QNetworkReply*)));
    Loginreply = Loginmanager->post(request, QJsonDocument(json).toJson());
}
void Login::LoginSlot(QNetworkReply* reply)
{
    QByteArray response_data=reply->readAll();
    emit sendLoginInterface(response_data);
    reply->deleteLater();
    Loginreply->deleteLater();
    Loginmanager->deleteLater();
}
