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
   BatteryData/FakeBatteryData.h \
   BatteryFaultsData/BatteryFaultsData.h \
   BatteryFaultsData/I_BatteryFaultsData.h \
   MotorFaultsData/MotorFaultsData.h \
   MotorFaultsData/I_MotorFaultsData.h \
   MotorDetailsData/MotorDetailsData.h \
   MotorDetailsData/I_MotorDetailsData.h \
   MotorDetailsData/MotorDetailsUnit.h \
   MotorDetailsData/I_MotorDetailsUnit.h \
   MotorDetailsData/FakeMotorDetailsUnit.h \
   LightsData/LightsData.h \
   LightsData/I_LightsData.h \
   LightsData/FakeLightsData.h \
   KeyMotorData/KeyMotorData.h \
   KeyMotorData/I_KeyMotorData.h \
   KeyMotorData/FakeKeyMotorData.h \
   DriverControlsData/DriverControlsData.h \
   DriverControlsData/I_DriverControlsData.h \
   DriverControlsData/FakeDriverControlsData.h \
   CmuData/CmuData.h \
   CmuData/I_CmuData.h \
   CmuData/FakeCmuData.h \
   CmuData/I_CmuUnit.h \
   CmuData/CmuUnit.h \
   MpptData/MpptData.h \
   MpptData/I_MpptData.h \
   MpptData/FakeMpptData.h \
   MpptData/I_MpptUnit.h \
   MpptData/MpptUnit.h \
   OtherData/I_OtherData.h \
   OtherData/OtherData.h \
   OtherData/FakeOtherData.h

SOURCES += \
   DataContainer.cpp \
   BatteryData/BatteryData.cpp \
   BatteryData/FakeBatteryData.cpp \
   BatteryFaultsData/BatteryFaultsData.cpp \
   MotorFaultsData/MotorFaultsData.cpp \
   MotorDetailsData/MotorDetailsData.cpp \
   MotorDetailsData/FakeMotorDetailsData.cpp \
   MotorDetailsData/MotorDetailsUnit.cpp \
   LightsData/LightsData.cpp \
   LightsData/FakeLightsData.cpp \
   KeyMotorData/KeyMotorData.cpp \
   KeyMotorData/FakeKeyMotorData.cpp \
   DriverControlsData/DriverControlsData.cpp \
   DriverControlsData/FakeDriverControlsData.cpp \
   CmuData/CmuData.cpp \
   CmuData/FakeCmuData.cpp \
   CmuData/CmuUnit.cpp \
   MpptData/MpptData.cpp \
   MpptData/FakeMpptData.cpp \
   MpptData/MpptUnit.cpp \
   OtherData/OtherData.cpp \
   OtherData/FakeOtherData.cpp
