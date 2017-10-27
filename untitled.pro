#-------------------------------------------------
#
# Project created by QtCreator 2017-10-19T18:01:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    ckeypressfater.cpp \
    mycheckbox.cpp \
    customdialog.cpp \
    CPushButtonTabItem.cpp \
    CCheckBoxTabItem.cpp \
    CLineEditTabItem.cpp \
    CSpinBoxTabItem.cpp \
    CSliderTabItem.cpp \
    CScrollAreaTabItem.cpp \
    CToolBoxTabItem.cpp \
    CTrayMenu.cpp

HEADERS += \
        mainwindow.h \
    ckeypressfater.h \
    mycheckbox.h \
    customdialog.h \
    myHelper.h \
    CPushButtonTabItem.h \
    CCheckBoxTabItem.h \
    CLineEditTabItem.h \
    CSpinBoxTabItem.h \
    CSliderTabItem.h \
    CScrollAreaTabItem.h \
    CToolBoxTabItem.h \
    CTrayMenu.h

FORMS += \
        mainwindow.ui \
    customdialog.ui

DISTFILES +=

DESTDIR = bin

RESOURCES += \
    skin.qrc
