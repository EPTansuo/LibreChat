#include "contactform.h"
#include "ui_contactform.h"

ContactForm::ContactForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContactForm)
{
    ui->setupUi(this);
  /*  QPalette *pa = new QPalette;
    pa->setColor(QPalette::WindowText,Qt::gray);
    ui->label_userName->setPalette(*pa);
    ui->pushButton_close->setPalette(*pa);
    ui->pushButton_close->setText("X");
    ui->label_message->setText("Message");
    delete pa;*/

}

ContactForm::~ContactForm()
{
    delete ui;
}

void ContactForm::on_pushButton_close_clicked()
{
    this->listWiget->sortItems();
    this->close();

}

void ContactForm::setListWidget(QListWidget *plistWiget)
{
    this->listWiget = plistWiget;
}
void ContactForm::setLisetWidgetItem(QListWidgetItem *plistWidgetItem)
{
    this->listWidgetItem=plistWidgetItem;
}
