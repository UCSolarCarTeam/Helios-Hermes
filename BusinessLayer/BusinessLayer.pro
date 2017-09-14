TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
   error( "Couldn't find the common.pri file!" )
}

DESTDIR = ../../build/.lib

HEADERS += \
   BusinessContainer.h \
   CommunicationsMonitoringService/CommunicationsMonitoringService.h \
   CommunicationsMonitoringService/I_CommunicationsMonitoringService.h \
   JsonForwarder/I_JsonForwarder.h \
   JsonForwarder/JsonForwarder.h \
   JsonMessageBuilder/JsonMessageBuilder.h \
   JsonMessageBuilder/I_JsonMessageBuilder.h \
   JsonForwarder/JsonDefines.h \
   LoggerService/LoggerService.h \

SOURCES += \
   BusinessContainer.cpp \
   CommunicationsMonitoringService/CommunicationsMonitoringService.cpp \
   JsonMessageBuilder/JsonMessageBuilder.cpp \
   JsonForwarder/JsonForwarder.cpp \
   LoggerService/LoggerService.cpp \
