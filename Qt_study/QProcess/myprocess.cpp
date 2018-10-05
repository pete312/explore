#include "myprocess.h"
#include <iostream>
#include <QFile>
#include <QDebug>


using namespace std;


MyProcess::MyProcess():
    _proc(0),
    _ended(false)
{
}



//void MyProcess::start2 ()
//{

//    cout << "this is it" << endl;

//    QString command("cd");
//    QStringList arg;
//    //connect(this, SIGNAL(started()), this, SLOT(itsStarted()) );

//    start(command,arg);
//    bool ret = waitForStarted(6000);
//    cout << "started with " << ret << endl;
//    ret = waitForFinished(6000);
//    cout << "fin with " << ret << endl;

//}





void MyProcess::start()
{

    QStringList args;
    //QString command("cmd.exe");
    //QString command("c:/bin/test.bat");
    QString command("c:/bin/TestAgent.py");
    //args <<  "arg_1" << "arg_2";
    //args << "start" << "c:/bin/TestAgent.py";
    //args << "/c" << "c:/bin/TestAgent.py" ;
    //ShowScript(command);a



    if ( _proc == 0 ){
        _proc = new QProcess;

        connect(_proc, SIGNAL(readyReadStandardOutput()), this, SLOT(readStdOut()) );
        connect(_proc, SIGNAL(readyReadStandardError()), this, SLOT(readStdErr()) );

        connect(_proc, SIGNAL(stateChanged(QProcess::ProcessState)), this, SLOT(changedState(QProcess::ProcessState)) );
        connect(_proc, SIGNAL(finished(int)), this, SLOT(hasEnded(int)));
        connect(_proc, SIGNAL(started()), this, SLOT(started()));

        _proc->start(command,args);
    }
    else {
        qWarning("Process already running.");
    }
}

void MyProcess::ShowScript(const QString & filename )
{
    QFile in(filename);
    if( !in.exists() ){
        qErrnoWarning("No such script!");
        return;
    }
    in.open(QIODevice::ReadOnly | QIODevice::Text);
    qDebug() << filename << "contents:";
    qDebug() << "-------------------";
    while (!in.atEnd()) {
        QByteArray buf = in.readLine();
        qDebug() << buf ;
    }
    qDebug() << "-------------------";
}

void MyProcess::stop()
{
    done();
}

void MyProcess::readStdOut()
{
    QByteArray buffer;
    buffer = _proc->readAllStandardOutput();

    qDebug(buffer.data());
}

void MyProcess::readStdErr()
{
    QByteArray buffer;
    buffer = _proc->readAllStandardError();

    qDebug(buffer.data());
}

void MyProcess::hasEnded(int code)
{
    qDebug() << "process ended with" << (code ? "CRASH" : "OK") ;
    _ended = true;
    done();
}


void MyProcess::changedState(QProcess::ProcessState state)
{
    QString status;
    qDebug() << "state changed to" << state ;
}

void MyProcess::started()
{
    qDebug() << "process started";
}


