#-------------------------------------------------
#
# Project created by QtCreator 2017-08-07T12:32:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TGApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    results.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    results.h \
    about.h

FORMS    += mainwindow.ui \
    results.ui \
    about.ui
