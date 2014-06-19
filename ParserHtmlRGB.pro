#-------------------------------------------------
#
# Project created by QtCreator 2014-06-17T15:52:38
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = ParserHtmlRGB
TEMPLATE = app


SOURCES += main.cpp\
        Dialog.cpp \
    freeFunctions.cpp

HEADERS  += Dialog.h \
    freeFunctions.h \
    LogicError.h \
    EmptyArgument.h \
    Downloader.h

FORMS    += Dialog.ui
