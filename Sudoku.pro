#-------------------------------------------------
#
# Project created by QtCreator 2016-11-20T10:38:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sudoku
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    secondwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    secondwindow.h \
    dialog.h

FORMS    += mainwindow.ui \
    secondwindow.ui \
    dialog.ui

RESOURCES += \
    resources.qrc
