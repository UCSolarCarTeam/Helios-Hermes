TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

DESTDIR = ../../build/.lib

HEADERS += \
   DataContainer.h \
   SerialDefines.h \
   BatteryData/BatteryData.h \
   BatteryData/I_BatteryData.h \
   BatteryFaultsData/BatteryFaultsData.h \
   BatteryFaultsData/I_BatteryFaultsData.h \
   MotorFaultsData/MotorFaultsData.h \
   MotorFaultsData/I_MotorFaultsData.h \
   MotorDetailsData/MotorDetailsData.h \
   MotorDetailsData/I_MotorDetailsData.h \
   MotorDetailsData/MotorDetailsUnit.h \
   MotorDetailsData/I_MotorDetailsUnit.h \
   LightsData/LightsData.h \
   LightsData/I_LightsData.h \
   KeyMotorData/KeyMotorData.h \
   KeyMotorData/I_KeyMotorData.h \
   DriverControlsData/DriverControlsData.h \
   DriverControlsData/I_DriverControlsData.h \
   CmuData/CmuData.h \
   CmuData/I_CmuData.h \
   CmuData/I_CmuUnit.h \
   CmuData/CmuUnit.h \
   MpptData/MpptData.h \
   MpptData/I_MpptData.h \
   MpptData/I_MpptUnit.h \
   MpptData/MpptUnit.h

SOURCES += \
   DataContainer.cpp \
   BatteryData/BatteryData.cpp \
   BatteryFaultsData/BatteryFaultsData.cpp \
   MotorFaultsData/MotorFaultsData.cpp \
   MotorDetailsData/MotorDetailsData.cpp \
   MotorDetailsData/MotorDetailsUnit.cpp \
   LightsData/LightsData.cpp \
   KeyMotorData/KeyMotorData.cpp \
   DriverControlsData/DriverControlsData.cpp \
   CmuData/CmuData.cpp \
   CmuData/CmuUnit.cpp \
   MpptData/MpptData.cpp \
   MpptData/MpptUnit.cpp
