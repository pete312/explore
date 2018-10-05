#include <QtCore/QCoreApplication>
#include <myprocess.h>
#include <iostream>
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QDebug>

using namespace std;

void ReadFile(QString & filename){

    qDebug() << "open " << filename;
    QFile file(filename);

    QTextStream in(&file);
    QString text = in.readAll();
    qDebug(">>---------------------");

    qDebug() << text;
    qDebug("<<---------------------");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QStringList l = QProcess::systemEnvironment();

    cout << "begin" << endl;
    for (QStringList::ConstIterator it = l.begin(); it !=  l.end(); ++it){
        cout << (*it).toLocal8Bit().constData() <<endl;
    }
    cout << "end "  << endl;

    MyProcess p;
    p.start();


    return a.exec();
}

