#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T17:02:23
#
#-------------------------------------------------

QT      += core gui
QT      += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = project
TEMPLATE = app
    target.files=project
    target.path=/home/root/qt
INSTALLS+=target

SOURCES += main.cpp\
        mainwindow.cpp \
    clock.cpp \
    databasecomfiguretion.cpp \
    labelshowtime.cpp\
    SimpleGPIO.cpp \
    controller.cpp \
    gpio_config.cpp \
    timeclock.cpp

HEADERS  += mainwindow.h \
    clock.h \
    databasecomfiguretion.h \
    labelshowtime.h\
    SimpleGPIO.h \
    controller.h \
    gpio_config.h \
    timeclock.h

FORMS    += mainwindow.ui
