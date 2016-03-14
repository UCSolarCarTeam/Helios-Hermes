TEMPLATE = app
QT += testlib
CONFIG += testcase

LIBS += -L../../build/.lib -LC:\gtest\lib -lBusinessLayer -lCommunicationLayer -lDataLayer libgmock.a

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

HEADERS += *.h
SOURCES += *.cpp

!win32 {
    QMAKE_CXXFLAGS += -Werror
}

PRE_TARGETDEPS += \
   ../../build/.lib/*
INCLUDEPATH += C:\gtest\include
DESTDIR = ../../build/.tests
