#include "customer.h"

Customer::Customer(QObject *parent):QObject(parent)
{

}
Customer::~Customer()
{

}
void Customer::GetCustomerIdCU(QString id)
{
    QString site_url = "http://localhost:3000/customer/"+id;
    QString credentials = "admin:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData= "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() ),
    customeridmanager = new QNetworkAccessManager(this);
    connect(customeridmanager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(CustomerIdSlot(QNetworkReply*)));
    customeridreply = customeridmanager->get(request);
}
void Customer::CustomerIdSlot(QNetworkReply*reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString customer;
    QString name;
    foreach (const QJsonValue &value, json_array)
   {
     QJsonObject json_obj = value.toObject();
     customer+=+"Nimi: "+json_obj["Name"].toString()+"\nOsoite: "+json_obj["Address"].toString()+"\nPuhelin: "
     +json_obj["Phonenumber"].toString()+"\r\n";
     name+=json_obj["Name"].toString()+"\r\n";
     //+QString::number(json_obj["CustomerID"].toInt())
   }
  emit sendCustomerIdInterface(customer,name);
  reply->deleteLater();
  customeridreply->deleteLater();
  customeridmanager->deleteLater();
}
