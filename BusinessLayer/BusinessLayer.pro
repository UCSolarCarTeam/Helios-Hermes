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
   JsonForwarder/BatteryJsonForwarder/BatteryJsonForwarder.h \
   JsonForwarder/BatteryJsonForwarder/I_BatteryJsonForwarder.h \
   JsonForwarder/FaultsJsonForwarder/FaultsJsonForwarder.h \
   JsonForwarder/FaultsJsonForwarder/I_FaultsJsonForwarder.h \
   JsonForwarder/PowerJsonForwarder/PowerJsonForwarder.h \
   JsonForwarder/PowerJsonForwarder/I_PowerJsonForwarder.h \
   JsonForwarder/VehicleJsonForwarder/VehicleJsonForwarder.h \
   JsonForwarder/VehicleJsonForwarder/I_VehicleJsonForwarder.h \
   JsonForwarder/I_JsonForwarder.h \
   JsonForwarder/JsonForwarder.h \
   JsonForwarder/JsonDefines.h \
   LoggerService/LoggerService.h \

SOURCES += \
   BusinessContainer.cpp \
   CommunicationsMonitoringService/CommunicationsMonitoringService.cpp \
   JsonForwarder/JsonForwarder.cpp \
   JsonForwarder/BatteryJsonForwarder/BatteryJsonForwarder.cpp \
   JsonForwarder/FaultsJsonForwarder/FaultsJsonForwarder.cpp \
   JsonForwarder/PowerJsonForwarder/PowerJsonForwarder.cpp \
   JsonForwarder/VehicleJsonForwarder/VehicleJsonForwarder.cpp \
   LoggerService/LoggerService.cpp \
