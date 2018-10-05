#include "btimer.h"
#include <QTimer>
#include <QDebug>

BTimer::BTimer(QObject *parent) :
    QObject(parent), _second(0)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    connect(this, SIGNAL(movment(int)), this, SLOT(tock(int)));
    timer->start(1000);
}



void BTimer::tock(int second)
{
    qDebug() << "b tock" << second;
}

void BTimer::tick()
{
    _second ++;
    qDebug() << "b tick";
    emit movment(_second);

}
