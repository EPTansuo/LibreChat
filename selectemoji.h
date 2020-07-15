#ifndef SELECTEMOJI_H
#define SELECTEMOJI_H

#include <QWidget>
#include "define.h"


namespace Ui {
class SelectEmoji;
}

class SelectEmoji : public QWidget
{
    Q_OBJECT

public:
    explicit SelectEmoji(QWidget *parent = nullptr);
    ~SelectEmoji();

private:
    Ui::SelectEmoji *ui;
    bool eventFilter(QObject *watched, QEvent *event);
    bool event(QEvent *event);
signals:
    void emojiUrl(QString url);
};

#endif // SELECTEMOJI_H
