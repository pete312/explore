#include <QtCore/QCoreApplication>
#include <dnslookup.h>
#include <QHostInfo>
#include <QObject>
#include <QDebug>

// test local DNS lookups.



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DNSLookup *t = new DNSLookup(a.parent());



    qDebug() << "this host is " << QHostInfo::localHostName();
    qDebug() << "its domain is " << QHostInfo::localDomainName();

    QString hostname("flux");
    QString ret = t->lookupHost(hostname);
    qDebug() << "lookup for" << hostname << "returns" << ret;
    return a.exec();
}


