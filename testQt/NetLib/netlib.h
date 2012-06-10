#ifndef NETLIB_H
#define NETLIB_H

#include "NetLib_global.h"
#include <QString>

class NETLIBSHARED_EXPORT NetLib {
public:
    NetLib();
    QString version();

private:
    uint _major_version;
    uint _minor_version;
    uint _revision;
};

#endif // NETLIB_H
