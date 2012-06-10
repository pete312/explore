#ifndef OUTPUTHELPER_H
#define OUTPUTHELPER_H
#include <QObject>
#include <QProcess>

class OutputHelper : public QObject
{
    Q_OBJECT

public:
    OutputHelper();

    void setProc(QProcess *p);


public slots:
    void readStdOut();

private:
    QProcess * _proc;

};

#endif // OUTPUTHELPER_H
