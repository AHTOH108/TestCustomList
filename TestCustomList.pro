#-------------------------------------------------
#
# Project created by QtCreator 2016-05-25T17:26:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestCustomList
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form.cpp \
    object/myobject.cpp \
    customWidget/mytableitem.cpp

HEADERS  += mainwindow.h \
    form.h \
    object/myobject.h \
    customWidget/mytableitem.h

FORMS    += mainwindow.ui \
    form.ui
