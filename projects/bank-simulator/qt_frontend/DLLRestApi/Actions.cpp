#include "Actions.h"

Engineclass::Engineclass(QObject *parent):QObject(parent)
{

}
Engineclass::~Engineclass()
{

}
void Engineclass::getallactionsfunc(QString id, QString arr)
{
    QString site_url="http://localhost:3000/actions/"+id+"&"+arr;
    QString credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    allactionsmanager = new QNetworkAccessManager(this);
    connect(allactionsmanager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(getallactionsslot(QNetworkReply*)));
    allactionsreply = allactionsmanager->get(request);

}
void Engineclass::getallactionsslot(QNetworkReply* reply)
{

    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString actions;
    foreach (const QJsonValue &value, json_array) {
    QJsonObject json_obj = value.toObject();
    actions+=+"Rahaa tilillä: "+QString::number(json_obj["amount"].toDouble())+" Päivämäärä: "+json_obj["date"].toString()+" "
" "+json_obj["actiontype"].toString()+" Tilinumero: "+QString::number(json_obj["Accountnumber"].toInt())+"\r\n";
    }
    emit sendallactionsinterface(actions);
    reply->deleteLater();
    allactionsreply->deleteLater();
    allactionsmanager->deleteLater();
}
void Engineclass::getidactionsfunc(QString id)
{
    QString site_url="http://localhost:3000/actions/"+id+"/5";
    QString credentials="admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    IDactionsmanager = new QNetworkAccessManager(this);
    connect(IDactionsmanager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(IDactionsslot(QNetworkReply*)));
    IDactionsreply = IDactionsmanager->get(request);
}
void Engineclass::IDactionsslot(QNetworkReply* reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString actionsid;
    foreach (const QJsonValue &value, json_array) {
    QJsonObject json_obj = value.toObject();
    actionsid+=+"Rahaa tilillä: "+QString::number(json_obj["amount"].toDouble())+" Päivämäärä: "+json_obj["date"].toString()+" "
" "+json_obj["actiontype"].toString()+" Tilinumero: "+QString::number(json_obj["Accountnumber"].toInt())+"\r\n";
    }
    emit sendidactionsinterface(actionsid);
    reply->deleteLater();
    IDactionsreply->deleteLater();
    IDactionsmanager->deleteLater();
}
void Engineclass::postMoneyOtto(QString id, QString amount)
{
    QJsonObject json;
    json.insert("Accountnumber",id);
    json.insert("amount",amount);
    QString site_url="http://localhost:3000/actions/money_otto";
    QString credentials="admin:1234";
    QNetworkRequest request((site_url)); request.setHeader(QNetworkRequest::ContentTypeHeader,
    "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    nostoactionsmanager = new QNetworkAccessManager(this);
    connect(nostoactionsmanager, SIGNAL(finished (QNetworkReply*)), this, SLOT(nostoactionsslot(QNetworkReply*)));
    nostoactionsreply = nostoactionsmanager->post(request, QJsonDocument(json).toJson());
}
void Engineclass::nostoactionsslot(QNetworkReply*reply)
{
    QByteArray response_data=reply->readAll();
    if(response_data.compare("0")==0){
        emit sendMoneyOttointerface("nosto ei onnistunut");
    }
    else{
        emit sendMoneyOttointerface("nosto onnistui");
    }
    reply->deleteLater();
    nostoactionsreply->deleteLater();
    nostoactionsmanager->deleteLater();
}

