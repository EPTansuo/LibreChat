#include "selectemoji.h"
#include "ui_selectemoji.h"
#include <QMouseEvent>

SelectEmoji::SelectEmoji(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectEmoji)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->widget->setFixedSize(ui->widget->width(),ui->widget->height()-3);
    ui->widget_2->setFixedSize(ui->widget->width(),ui->widget->height()-3);
    ui->widget_3->setFixedSize(ui->widget->width(),ui->widget->height()-3);
    ui->widget_4->setFixedSize(ui->widget->width(),ui->widget->height()-3);

    QImage *img = new QImage;

    {
        img->load(":/emoji/emoji/0.png");
        ui->label_0->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/1.png");
        ui->label_1->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/2.png");
        ui->label_2->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/3.png");
        ui->label_3->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/4.png");
        ui->label_4->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/5.png");
        ui->label_5->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/6.png");
        ui->label_6->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/7.png");
        ui->label_7->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/8.png");
        ui->label_8->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/9.png");
        ui->label_9->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/10.png");
        ui->label_10->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/11.png");
        ui->label_11->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/12.png");
        ui->label_12->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/13.png");
        ui->label_13->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/14.png");
        ui->label_14->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/15.png");
        ui->label_15->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/16.png");
        ui->label_16->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/17.png");
        ui->label_17->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/18.png");
        ui->label_18->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/19.png");
        ui->label_19->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/20.png");
        ui->label_20->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/21.png");
        ui->label_21->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/22.png");
        ui->label_22->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/23.png");
        ui->label_23->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/24.png");
        ui->label_24->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/25.png");
        ui->label_25->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/26.png");
        ui->label_26->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/27.png");
        ui->label_27->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/28.png");
        ui->label_28->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/29.png");
        ui->label_29->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/30.png");
        ui->label_30->setPixmap(QPixmap::fromImage(*img));
        img->load(":/emoji/emoji/31.png");
        ui->label_31->setPixmap(QPixmap::fromImage(*img));
    }
    delete  img;

    {
        ui->label_0->installEventFilter(this);
        ui->label_1->installEventFilter(this);
        ui->label_2->installEventFilter(this);
        ui->label_3->installEventFilter(this);
        ui->label_4->installEventFilter(this);
        ui->label_5->installEventFilter(this);
        ui->label_6->installEventFilter(this);
        ui->label_7->installEventFilter(this);
        ui->label_8->installEventFilter(this);
        ui->label_9->installEventFilter(this);
        ui->label_10->installEventFilter(this);
        ui->label_11->installEventFilter(this);
        ui->label_12->installEventFilter(this);
        ui->label_13->installEventFilter(this);
        ui->label_14->installEventFilter(this);
        ui->label_15->installEventFilter(this);
        ui->label_16->installEventFilter(this);
        ui->label_17->installEventFilter(this);
        ui->label_18->installEventFilter(this);
        ui->label_19->installEventFilter(this);
        ui->label_20->installEventFilter(this);
        ui->label_21->installEventFilter(this);
        ui->label_22->installEventFilter(this);
        ui->label_23->installEventFilter(this);
        ui->label_24->installEventFilter(this);
        ui->label_25->installEventFilter(this);
        ui->label_26->installEventFilter(this);
        ui->label_27->installEventFilter(this);
        ui->label_28->installEventFilter(this);
        ui->label_29->installEventFilter(this);
        ui->label_30->installEventFilter(this);
        ui->label_31->installEventFilter(this);
    }
}

SelectEmoji::~SelectEmoji()
{
    delete ui;
}

bool SelectEmoji::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_0)
    {
        emit emojiUrl(tr(":/emoji/emoji/0.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_1)
    {
        emit emojiUrl(tr(":/emoji/emoji/1.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_2)
    {
        emit emojiUrl(tr(":/emoji/emoji/2.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_3)
    {
        emit emojiUrl(tr(":/emoji/emoji/3.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_4)
    {
        emit emojiUrl(tr(":/emoji/emoji/4.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_5)
    {
        emit emojiUrl(tr(":/emoji/emoji/5.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_6)
    {
        emit emojiUrl(tr(":/emoji/emoji/6.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_7)
    {
        emit emojiUrl(tr(":/emoji/emoji/7.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_8)
    {
        emit emojiUrl(tr(":/emoji/emoji/8.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_9)
    {
        emit emojiUrl(tr(":/emoji/emoji/9.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_10)
    {
        emit emojiUrl(tr(":/emoji/emoji/10.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_11)
    {
        emit emojiUrl(tr(":/emoji/emoji/11.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_12)
    {
        emit emojiUrl(tr(":/emoji/emoji/12.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_13)
    {
        emit emojiUrl(tr(":/emoji/emoji/13.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_14)
    {
        emit emojiUrl(tr(":/emoji/emoji/14.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_15)
    {
        emit emojiUrl(tr(":/emoji/emoji/15.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_16)
    {
        emit emojiUrl(tr(":/emoji/emoji/16.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_17)
    {
        emit emojiUrl(tr(":/emoji/emoji/17.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_18)
    {
        emit emojiUrl(tr(":/emoji/emoji/18.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_19)
    {
        emit emojiUrl(tr(":/emoji/emoji/19.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_20)
    {
        emit emojiUrl(tr(":/emoji/emoji/20.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_21)
    {
        emit emojiUrl(tr(":/emoji/emoji/21.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_22)
    {
        emit emojiUrl(tr(":/emoji/emoji/22.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_23)
    {
        emit emojiUrl(tr(":/emoji/emoji/23.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_24)
    {
        emit emojiUrl(tr(":/emoji/emoji/24.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_25)
    {
        emit emojiUrl(tr(":/emoji/emoji/25.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_26)
    {
        emit emojiUrl(tr(":/emoji/emoji/26.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_27)
    {
        emit emojiUrl(tr(":/emoji/emoji/27.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_28)
    {
        emit emojiUrl(tr(":/emoji/emoji/28.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_29)
    {
        emit emojiUrl(tr(":/emoji/emoji/29.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_30)
    {
        emit emojiUrl(tr(":/emoji/emoji/30.png"));
        this->close();
    }
    else if(event->type()==QEvent::MouseButtonPress&&watched==ui->label_31)
    {
        emit emojiUrl(tr(":/emoji/emoji/31.png"));
        this->close();
    }
    //   this->close();
    return false;
}


bool SelectEmoji::event(QEvent *event)
{
    if (event->type() == QEvent::ActivationChange)
    {
        if(QApplication::activeWindow() != this)
        {
            this->close();

        }
    }
    return QWidget::event(event);

}
