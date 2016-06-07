#-------------------------------------------------
#
# Project created by QtCreator 2016-06-01T12:54:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hole_in_one
TEMPLATE = app


SOURCES += main.cpp\
        gui.cpp \
    button.cpp \
    picbutton.cpp

HEADERS  += gui.h \
    button.h \
    main.h \
    picbutton.h

FORMS    +=

DISTFILES += \
    title.svg

RESOURCES += \
    images.qrc
