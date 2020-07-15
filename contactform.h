#ifndef CONTACTFORM_H
#define CONTACTFORM_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include "define.h"

namespace Ui {
class ContactForm;
}

class ContactForm : public QWidget
{
    Q_OBJECT

public:
    explicit ContactForm(QWidget *parent = nullptr);
    ~ContactForm();
    void setListWidget(QListWidget *plistWiget);
    void setLisetWidgetItem(QListWidgetItem *plistWidgetItem);
private slots:
    void on_pushButton_close_clicked();

private:
    Ui::ContactForm *ui;
    QListWidget *listWiget;
    QListWidgetItem *listWidgetItem;
};

#endif // CONTACTFORM_H
