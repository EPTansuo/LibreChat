#include "login.h"
#include "ui_login.h"
#include <QDesktopWidget>
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


login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    ui->label_wrong->hide();
#ifdef DEBUG
    ui->lineEdit_account->setText("test123");
    ui->lineEdit_password->setText("123456");
#endif

    //move the form to the right place
    QDesktopWidget *desktop = QApplication::desktop();
    this->move((desktop->width()-this->width())/2,
               (desktop->height()-this->height()-this->height()/2)/2);
    delete desktop;
}

login::~login()
{
    delete ui;
}

//check login
bool login::checkPassword(QString account, QString password)
{

    QNetworkAccessManager manager;
    QUrl url;

    url.setScheme("ftp");
    url.setUserName(account);
    url.setPassword(password);
    url.setHost(SERVER_IP);
    url.setPort(SERVER_FTP_PORT);
    url.setPath("login_log");


    QDateTime * datetime = new QDateTime;
    QString *log = new QString(datetime->currentDateTimeUtc().toString("yyyy-MM-dd hh:mm:ss")+"\n");
    QByteArray data = log->toLatin1();



    QNetworkRequest request(url);
    QNetworkReply* reply = manager.get(request);

    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    /* 进入等待，但事件循环依然进行 */
    eventLoop.exec();
    data += reply->readAll();

    reply = manager.put(request, data);
    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    /* 进入等待，但事件循环依然进行 */
    eventLoop.exec();


    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error: " << reply->errorString();
        return false;
    }

    return true;
}

void login::on_pushButton_login_clicked()
{

    QPalette *pa = new QPalette;

    ui->pushButton_login->setDisabled(true);
    ui->pushButton_cancel->setDisabled(true);
    ui->lineEdit_account->setDisabled(true);
    ui->lineEdit_password->setDisabled(true);

    //show "Loading..." in gray
    pa->setColor(QPalette::WindowText,Qt::gray);
    ui->label_wrong->setPalette(*pa);
    ui->label_wrong->setText("Loading...");
    ui->label_wrong->show();

    if(checkPassword(ui->lineEdit_account->text(),ui->lineEdit_password->text()))
    {
        this->close();
        emit loginSuccessful();

    }
    else
    {
        //delay 2500ms
        QTime *delayTime = new QTime;
        *delayTime = QTime::currentTime().addMSecs(2500);
        while(QTime::currentTime() < *delayTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents,100);
        delete delayTime;


        //show "Wrong account or password!" in red
        pa->setColor(QPalette::WindowText,Qt::red);
        ui->label_wrong->setPalette(*pa);
        ui->label_wrong->setText("Wrong account or password!");
        ui->label_wrong->show();


    }

    ui->pushButton_login->setDisabled(false);
    ui->pushButton_cancel->setDisabled(false);
    ui->lineEdit_account->setDisabled(false);
    ui->lineEdit_password->setDisabled(false);

    delete  pa;
}

void login::on_pushButton_cancel_clicked()
{
    emit loginCancel();
}
