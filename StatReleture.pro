QT += core
QT += gui

include(xlsx/qtxlsx.pri)
TARGET = StatReleture
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    resultat.cpp \
    lecture.cpp

HEADERS += \
    resultat.h \
    lecture.h


