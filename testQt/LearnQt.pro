TEMPLATE = subdirs

SUBDIRS += \
    NetLib \
    IPCServer \
    QProcess \
    DNS \
    CommandLineOpts \
    SqlTest \
    WaitConditions \
    TimerTest


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/NetLib/release/ -lNetLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/NetLib/debug/ -lNetLib
else:symbian: LIBS += -lNetLib
else:unix: LIBS += -L$$OUT_PWD/NetLib/ -lNetLib

INCLUDEPATH += $$PWD/NetLib
DEPENDPATH += $$PWD/NetLib

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/NetLib/release/NetLib.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/NetLib/debug/NetLib.lib
else:unix:!symbian: PRE_TARGETDEPS += $$OUT_PWD/NetLib/libNetLib.a

