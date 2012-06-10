#ifndef MYPROCESS_H
#define MYPROCESS_H

#include <QProcess>

class MyProcess : public QProcess
{
    Q_OBJECT
public:
    MyProcess();

    void start();
    void stop();
    //void start2();

private:
    QProcess * _proc;
    bool _ended;

    void ShowScript(const QString & filename );

public slots:
    void readStdOut();
    void readStdErr();
    void hasEnded(int code);
    void changedState(QProcess::ProcessState state);
    void started();

signals:
    void done();

private:



};

#endif // MYPROCESS_H
