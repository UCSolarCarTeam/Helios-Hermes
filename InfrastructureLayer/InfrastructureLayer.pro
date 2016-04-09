TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

DESTDIR = ../../build/.lib

HEADERS += \
    Settings/Settings.h \
    Settings/I_Settings.h 

SOURCES += \
    Settings/Settings.cpp
