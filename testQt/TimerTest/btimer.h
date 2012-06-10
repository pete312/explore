#ifndef BTIMER_H
#define BTIMER_H

#include <QObject>

class BTimer : public QObject
{
    Q_OBJECT
public:
    explicit BTimer(QObject *parent = 0);

signals:
    void movment(int second);

public slots:
    void tock(int second);
    void tick();

private:
    int _second;

};

#endif // BTIMER_H
