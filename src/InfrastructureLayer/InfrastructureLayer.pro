
TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

DESTDIR = ../../build/.lib

HEADERS += \
    InfrastructureContainer.h \
    Settings/Settings.h \
    Settings/I_Settings.h \
    Logging/Logging.h \

SOURCES += \
    InfrastructureContainer.cpp \
    Settings/Settings.cpp \
    Logging/Logging.cpp \

loggingDir.commands = mkdir -p ../../build/log

QMAKE_EXTRA_TARGETS += loggingDir
POST_TARGETDEPS += loggingDir
