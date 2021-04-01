#-------------------------------------------------
#
# Project created by QtCreator 2019-11-20T12:18:37
#
#-------------------------------------------------

QT       += core gui network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
TARGET = SerialAndNetwork
TEMPLATE = app


SOURCES += main.cpp\
        widgetmain.cpp \
    serial.cpp \
    widgetserial.cpp \
    mythread.cpp \
    tcpclient.cpp \
    tcpserver.cpp \
    udp.cpp \
    widgetnetwork.cpp

HEADERS  += widgetmain.h \
    serial.h \
    widgetserial.h \
    mythread.h \
    tcpclient.h \
    tcpserver.h \
    udp.h \
    widgetnetwork.h

FORMS    += widgetmain.ui \
    widgetserial.ui \
    widgetnetwork.ui

RESOURCES += \
    image.qrc
