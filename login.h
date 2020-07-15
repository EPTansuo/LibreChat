#ifndef LOGIN_H
#define LOGIN_H

#include <define.h>
#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::login *ui;
    bool checkPassword(QString account,QString password);
signals:
    void loginCancel();
    void loginSuccessful();

};

#endif // LOGIN_H
