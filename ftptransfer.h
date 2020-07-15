#ifndef FTPTRANSFER_H
#define FTPTRANSFER_H

#include <QObject>
#include <QTime>
#include <QEventLoop>
#include <QMessageBox>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QMetaEnum>
#include <QUrl>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QByteArray>
#include "define.h"

class FtpTransfer : public QObject
{
    Q_OBJECT
public:
    explicit FtpTransfer(QObject *parent = nullptr);
    bool initFtp(QString *ip,int port,QString* account,QString* password,QString *ftpPath);
    bool send(QString *localFilePath,QString* remoteFilePath);
    bool send(QString* remoteFilePath,QByteArray* data);
signals:
    void sendOver(bool OKorNOT);
    void process(int a);

public slots:
    void replyFinished(QNetworkReply*);
    void loadProgress(qint64 ,qint64);
    void replyError(QNetworkReply::NetworkError);
private:
    QString *password;
    QString *user;
    QString *ftpPath;
    int port;
    QString *ip;
    QNetworkReply* reply;
    QNetworkAccessManager *accessManager;

};

#endif // FTPTRANSFER_H
