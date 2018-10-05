#ifndef ATIMER_H
#define ATIMER_H
#include <QObject>


class ATimer : QObject
{
    Q_OBJECT

public:
    explicit ATimer(QObject *parent = 0);


public slots:
    void tick();

};

#endif // ATIMER_H
