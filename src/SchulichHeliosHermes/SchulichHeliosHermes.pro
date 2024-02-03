TEMPLATE = app

LIBS += \
    -L../BusinessLayer/.lib -lBusinessLayer \
    -L../CommunicationLayer/.lib -lCommunicationLayer \
    -L../DataLayer/.lib -lDataLayer \
    -L../InfrastructureLayer/.lib -lInfrastructureLayer

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

PRE_TARGETDEPS += \
    ../BusinessLayer/.lib/* \
    ../CommunicationLayer/.lib/* \
    ../DataLayer/.lib/* \
    ../InfrastructureLayer/.lib/*

TARGET = SchulichHeliosHermes
DESTDIR = ../bin

HEADERS += \
    SchulichHeliosHermes.h

SOURCES += \
   SchulichHeliosHermes.cpp \
   main.cpp

copyconfigfile.commands = cp $$PWD/../config.ini.example ../bin/config.ini
QMAKE_EXTRA_TARGETS += copyconfigfile
POST_TARGETDEPS += copyconfigfile
