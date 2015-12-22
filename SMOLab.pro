#-------------------------------------------------
#
# Project created by QtCreator 2015-12-02T02:53:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SMOLab
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    Simulator/ArrivalProcess.cpp \
    Simulator/Buffer.cpp \
    Simulator/Customer.cpp \
    Simulator/Generator.cpp \
    Simulator/Poisson.cpp \
    Simulator/Server.cpp \
    Simulator/ServerRow.cpp \
    Simulator/ServiceProcess.cpp \
    Simulator/Simulator.cpp \
    Simulator/Source.cpp \
    Simulator/SourceRow.cpp \
    Simulator/Statistic.cpp \
    Simulator/stdafx.cpp \
    stepwin.cpp \
    completewin.cpp \
    utils.cpp

HEADERS  += mainwindow.h \
    Simulator/ArrivalProcess.h \
    Simulator/Buffer.h \
    Simulator/Customer.h \
    Simulator/Generator.h \
    Simulator/Poisson.h \
    Simulator/Server.h \
    Simulator/ServerRow.h \
    Simulator/ServiceProcess.h \
    Simulator/Simulator.h \
    Simulator/Source.h \
    Simulator/SourceRow.h \
    Simulator/Statistic.h \
    Simulator/stdafx.h \
    Simulator/targetver.h \
    stepwin.h \
    completewin.h \
    utils.h

FORMS    += mainwindow.ui \
    stepwin.ui \
    completewin.ui
RESOURCES = qdarkstyle/style.qrc
