#include "atimer.h"
#include <QTimer>

ATimer::ATimer(QObject *parent) :
    QObject(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this , SLOT(tick()));
    timer->start(1000);
}


void ATimer::tick()
{
    qDebug("a tick");
}



