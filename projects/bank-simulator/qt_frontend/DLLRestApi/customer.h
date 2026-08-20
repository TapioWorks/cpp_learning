#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<QtNetwork>
#include<QNetworkAccessManager>
#include<QJsonDocument>

class Customer:public QObject
{
    Q_OBJECT
public:
    Customer(QObject *parent=nullptr);
    ~Customer();
    void GetCustomerIdCU(QString);
signals:
    void sendCustomerIdInterface(QString, QString);
private slots:
    void CustomerIdSlot(QNetworkReply*);
private:
    QNetworkAccessManager *customeridmanager;
    QNetworkReply *customeridreply;
};

#endif // CUSTOMER_H
