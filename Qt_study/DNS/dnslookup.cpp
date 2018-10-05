#include "dnslookup.h"

DNSLookup::DNSLookup(QObject *parent) :
    QObject(parent),
    _finished(false)
{
}

QString DNSLookup::lookupHost(const QString &hostname)
{
    QHostInfo inf;
    _finished = false;

    inf.lookupHost(hostname, this, SLOT(getLookup(QHostInfo)));

    return _ret;

}

void DNSLookup::getLookup(QHostInfo hostInfo){
    qDebug() << "lookup on " << hostInfo.hostName();
    qDebug() << "ip count" << hostInfo.addresses().count();
    qDebug() << "ip address" << hostInfo.addresses().first().toString();

    _ret = hostInfo.hostName();
    _finished = true;
}

