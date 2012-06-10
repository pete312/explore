#include <QtCore/QCoreApplication>
#include <atimer.h>
#include <btimer.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ATimer t;
    BTimer t2;

    return a.exec();
}
