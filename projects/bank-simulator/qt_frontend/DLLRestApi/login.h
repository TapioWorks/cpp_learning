#ifndef LOGIN_H
#define LOGIN_H
#include<QtNetwork>
#include<QNetworkAccessManager>
#include<QJsonDocument>

class Login:public QObject
{
    Q_OBJECT
public:
    Login(QObject *parent=nullptr);
    ~Login();
    void checkloginLO(QString,QString);
signals:
    void sendLoginInterface(QString);
private slots:
    void LoginSlot(QNetworkReply*);
private:
    QNetworkAccessManager *Loginmanager;
    QNetworkReply *Loginreply;
};

#endif // LOGIN_H
