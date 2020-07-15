#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "selectemoji.h"
#include "contactform.h"
#include "define.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    login *loginDialog;
    bool eventFilter(QObject *watched, QEvent *event);
private:
    Ui::MainWindow *ui;
    void addImage2Editor();
    void getEmoji();
    int sendFile();
private slots:
    void loginSuccessful();
    void loginCancel();

    void on_label_sendimage_linkActivated(const QString &link);
    void on_pushButton_send_clicked();
    void on_pushButton_cancel_clicked();
    void on_getEmojiUrl(QString url);
    void addContact();
};
#endif // MAINWINDOW_H
