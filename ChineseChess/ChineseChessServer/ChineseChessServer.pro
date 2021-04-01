#-------------------------------------------------
#
# Project created by QtCreator 2019-12-31T11:33:06
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChineseChessServer
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mythread.cpp \
    tcpserver.cpp

HEADERS  += widget.h \
    mythread.h \
    tcpserver.h

FORMS    += widget.ui
