#-------------------------------------------------
#
# Project created by QtCreator 2016-12-02T16:57:05
#
#-------------------------------------------------

QT       += core gui gamepad

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = Scarabeus
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcp.cpp \
    gamepad.cpp \
    avr_button.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui



CONFIG += c++11
