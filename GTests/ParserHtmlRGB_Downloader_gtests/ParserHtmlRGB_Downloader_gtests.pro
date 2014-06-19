
QT += network

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += "C:/GTEST/gtest-1.7.0/include"
LIBS += "C:/GTEST/lib/libGoogleTest.a"

INCLUDEPATH += "../../"

HEADERS += \
    ../../Downloader.h

SOURCES += \
    main.cpp
