#-------------------------------------------------
#
# Project created by QtCreator 2019-12-30T09:03:24
#
#-------------------------------------------------

QT       += core gui
QT       += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Keypad
TEMPLATE = app
RC_ICONS = bitbug_favicon.ico
CONFIG  += C++11

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

RESOURCES += \
    img.qrc

