#ifndef FTPTHREAD_H
#define FTPTHREAD_H

#include <QObject>
#include <QThread>
#include "ftptransfer.h"
#include "define.h"


class FtpThread : public QThread
{
        Q_OBJECT
public:
    FtpThread();
protected:
    void run();
signals:
    void process(int a);
    bool sendOver();
};

#endif // FTPTHREAD_H
