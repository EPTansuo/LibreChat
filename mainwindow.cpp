#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QMessageBox>
#include <QDir>
#include <QDesktopServices>
#include <QFileDialog>
#include <QCursor>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //   this->hide();
    //  this->show();

    //create login dialog
    loginDialog = new login;
    loginDialog->show();
    connect(loginDialog,SIGNAL(loginCancel()),this,SLOT(loginCancel()));
    connect(loginDialog,SIGNAL(loginSuccessful()),this,SLOT(loginSuccessful()));


    ui->label_sendimage->installEventFilter(this);
    ui->label_emoji->installEventFilter(this);
    ui->label_sendFile->installEventFilter(this);


/*
    QListWidgetItem* pListWidgetItem1 = new QListWidgetItem;
   QListWidgetItem* pListWidgetItem2 = new QListWidgetItem;
   QListWidgetItem* pListWidgetItem3 = new QListWidgetItem;
   ContactForm* pDeviceItem1 = new ContactForm;
   ContactForm* pDeviceItem2 = new ContactForm;
   ContactForm* pDeviceItem3 = new ContactForm;
   pListWidgetItem1->setSizeHint(QSize(0,60));
   pListWidgetItem2->setSizeHint(QSize(0,60));
   pListWidgetItem3->setSizeHint(QSize(0,60));
   ui->listWidget_contacts->addItem(pListWidgetItem1);
   ui->listWidget_contacts->addItem(pListWidgetItem2);
   ui->listWidget_contacts->addItem(pListWidgetItem3);
   ui->listWidget_contacts->setItemWidget(pListWidgetItem1,pDeviceItem1);
   ui->listWidget_contacts->setItemWidget(pListWidgetItem2,pDeviceItem2);
   ui->listWidget_contacts->setItemWidget(pListWidgetItem3,pDeviceItem3);*/
   addContact();
   addContact();
   QFile file("./test.html");

       if(!file.open(QFile::ReadOnly | QFile::Text))
           QMessageBox::information(this, tr("提示"), tr("打不开用户协议文件"));

       QTextStream textStream(&file);

       ui->textBrowser->setHtml(textStream.readAll());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::loginCancel()
{
    qApp->quit();
}

void MainWindow::loginSuccessful()
{
    //move the form to the right place
    QDesktopWidget *desktop = QApplication::desktop();
    this->move((desktop->width()-this->width())/2,
               (desktop->height()-this->height()-this->height()/2)/2);
    delete desktop;
    this->show();
}

void MainWindow::on_label_sendimage_linkActivated(const QString &)    //(const QString &link)
{

}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    //click label
    if(watched == ui->label_sendimage)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->button() == Qt::LeftButton)
            {
                //     QMessageBox::information(NULL,"点击","点击了我",
                //                        QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
                addImage2Editor();
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else if(watched == ui->label_emoji)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->button() == Qt::LeftButton)
            {
                //     QMessageBox::information(NULL,"点击","点击了我",
                //                        QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
                getEmoji();
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else if(watched == ui->label_sendFile)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->button() == Qt::LeftButton)
            {
                //     QMessageBox::information(NULL,"点击","点击了我",
                //                        QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
                sendFile();
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        // pass the event on to the parent class
        return QMainWindow::eventFilter(watched, event);
    }
}


//add Image to editor
void MainWindow::addImage2Editor()
{
    //  QString *path = new QString;
    //  *path = QDir::toNativeSeparators(QApplication::applicationDirPath());
    //  QDesktopServices::openUrl(QUrl::fromLocalFile(*path));
    QString* file_name = new QString;
    *file_name = QFileDialog::getOpenFileName(this,
                                              tr("Open File"),"","*.jpg *.png *.gif *.bmp");
    if(!file_name->isNull())
        ui->textEdit->setHtml(ui->textEdit->toHtml()+\
                              "<img src=\""+*file_name+"\" width=300 /></p>");

}

void MainWindow::on_pushButton_send_clicked()
{

}

void MainWindow::on_pushButton_cancel_clicked()
{
    ui->textEdit->setHtml("");
}

//to get emoji
void MainWindow::getEmoji()
{
    SelectEmoji *selectEmoji = new SelectEmoji();
    selectEmoji->setAttribute(Qt::WA_DeleteOnClose,true);
    QPoint *pos = new QPoint;
    *pos = QCursor::pos();
    selectEmoji->move(pos->x()-10,pos->y()-selectEmoji->height()-30);
   // connect(selectEmoji,SIGNAL(emojiUrl(QString),this,SLOT()))
    connect(selectEmoji,SIGNAL(emojiUrl(QString)),this,SLOT(on_getEmojiUrl(QString)));
    selectEmoji->show();
}


//add emoji to testEdit
void MainWindow::on_getEmojiUrl(QString url)
{
    ui->textEdit->setHtml(ui->textEdit->toHtml()+\
                          "<img src=\""+url+"\" width=30 />");
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor);
}


//send file
int MainWindow::sendFile()
{
    QString* file_name = new QString;
    *file_name = QFileDialog::getOpenFileName(this,
                                              tr("Open File"),"","");


    /********Need to do *********/



    return 0;
}

void MainWindow::addContact()
{
   QListWidgetItem* pListWidgetItem = new QListWidgetItem;
   ContactForm* contact = new ContactForm;
   pListWidgetItem->setSizeHint(QSize(0,60));
   ui->listWidget_contacts->addItem(pListWidgetItem);
   ui->listWidget_contacts->setItemWidget(pListWidgetItem,contact);
   contact->setListWidget(ui->listWidget_contacts);
   contact->setLisetWidgetItem(pListWidgetItem);
}

