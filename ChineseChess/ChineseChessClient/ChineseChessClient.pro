#-------------------------------------------------
#
# Project created by QtCreator 2019-12-31T11:32:08
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChineseChessClient
TEMPLATE = app


SOURCES += main.cpp\
        widget_login.cpp \
    widget_main.cpp \
    tcpclient.cpp \
    item.cpp

HEADERS  += widget_login.h \
    widget_main.h \
    tcpclient.h \
    item.h

FORMS    += widget_login.ui \
    widget_main.ui

RESOURCES += \
    img.qrc
