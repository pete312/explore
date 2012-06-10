#-------------------------------------------------
#
# Project created by QtCreator 2011-10-17T16:24:21
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = NetLib
TEMPLATE = lib

CONFIG += staticlib

#VER_MAJ = 1
#VER_MIN = 0
#V#ER_PAT = 0

#VERSION = $$sprintf( %1.%2.%3, $$VER_MAJ, $$VER_MIN, $$VER_PAT)

#VERSION = 1.2.3

DEFINES += NETLIB_LIBRARY

SOURCES += netlib.cpp

HEADERS += netlib.h\
        NetLib_global.h




#unix:!symbian {
#    maemo5 {
#        target.path = /opt/usr/lib
#    } else {
#        target.path = /usr/lib
#    }
#    INSTALLS += target
#}


#unix {
#    DESTDIR = /usr/opt/lib/learnqt
#}

win32 {
    #DESTDIR = C:/lib68/learnqt

    message( this version is [$$VERSION] )
}
