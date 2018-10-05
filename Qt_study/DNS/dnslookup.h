#ifndef DNSLOOKUP_H
#define DNSLOOKUP_H


#include <QObject>
#include <QHostInfo>
#include <QDebug>


class DNSLookup : public QObject
{
    Q_OBJECT
public:
    explicit DNSLookup(QObject *parent = 0);

   QString lookupHost(const QString &hostname);

signals:


public slots:
    void getLookup(QHostInfo inf);

private:
    QString _ret;
    bool _finished;

};

#endif // DNSLOOKUP_H
