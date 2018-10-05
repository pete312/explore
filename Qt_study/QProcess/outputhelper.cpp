#include "outputhelper.h"
#include <iostream>

using namespace std;

OutputHelper::OutputHelper() : _proc(0)
{   
}

void OutputHelper::setProc(QProcess *p){
    _proc = p;
}


void OutputHelper::readStdOut(){
    QByteArray out = _proc->readAll();
    cout << "[" << out.constData() << "]" << endl;
}

