#include "ftptransfer.h"

FtpTransfer::FtpTransfer(QObject *parent) : QObject(parent)
{

}

bool FtpTransfer::initFtp(QString *ip,int port,QString* account,QString* password,QString *ftpPath)
{

    this->ftpPath = ftpPath;
    this->user = account;
    this->password = password;
    this->port = port;
    this->ip = ip;
    return true;
}

bool FtpTransfer::send(QString *localFilePath,QString* remoteFilePath)
{

    QFile *file = new QFile;
    file = new QFile(*localFilePath);
    file->open(QIODevice::ReadOnly);
    QByteArray byte_file = file->readAll();

    //把文件上传到服务器
    accessManager = new QNetworkAccessManager(this);
    accessManager->setNetworkAccessible(QNetworkAccessManager::Accessible);
    QUrl url(tr("ftp://")+*this->ip+*remoteFilePath);
    url.setPort(21);
    url.setUserName(*this->user);
    url.setPassword(*this->password);

    QNetworkRequest request(url);
    reply = accessManager->put(request, byte_file);

    connect(accessManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
    connect(reply, SIGNAL(uploadProgress(qint64 ,qint64)), this, SLOT(loadProgress(qint64 ,qint64)));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),SLOT(replyError(QNetworkReply::NetworkError)));

    delete file;

    return true;

}

bool FtpTransfer::send(QString* remoteFilePath,QByteArray* data)
{

    //把data上传到服务器
    accessManager = new QNetworkAccessManager(this);
    accessManager->setNetworkAccessible(QNetworkAccessManager::Accessible);
    QUrl url(tr("ftp://")+*this->ip+*remoteFilePath);
    url.setPort(21);
    url.setUserName(*this->user);
    url.setPassword(*this->password);

    QNetworkRequest request(url);
  //  QNetworkReply* reply = accessManager->put(request, data);
    reply = accessManager->put(request,*data);

    connect(accessManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),SLOT(replyError(QNetworkReply::NetworkError)));
    return true;
}
