#include "netlib.h"

NetLib::NetLib():
    _major_version(1),
    _minor_version(2),
    _revision(3)
{
}

QString NetLib::version()
{
    QString version("%d.%d.%d");
    version.arg(_major_version)
            .arg(_minor_version)
            .arg(_revision);
    return version;
}

