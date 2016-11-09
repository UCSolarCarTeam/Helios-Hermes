TEMPLATE = app
QT += testlib
CONFIG += testcase

LIBS += -L../../build/.lib -lBusinessLayer -lCommunicationLayer -lDataLayer -lInfrastructureLayer -lgmock

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

HEADERS += \
    CommunicationLayer/CommDeviceControl/MockMessageForwarder.h \
    InfrastructureLayer/Settings/MockSettings.h \
    DataLayer/BatteryData/MockBatteryData.h \
    DataLayer/FaultsData/MockFaultsData.h \
    DataLayer/PowerData/MockPowerData.h \
    DataLayer/VehicleData/MockVehicleData.h

SOURCES += \
    testmain.cpp \
    InfrastructureLayer/Settings/SettingsTest.cpp \
	BusinessLayer/JsonForwarder/JsonForwarderTest.cpp \
	BusinessLayer/JsonForwarder/BatteryJsonForwarder/BatteryJsonForwarderTest.cpp \
	BusinessLayer/JsonForwarder/FaultsJsonForwarder/FaultsJsonForwarderTest.cpp \
	BusinessLayer/JsonForwarder/PowerJsonForwarder/PowerJsonForwarderTest.cpp \
	BusinessLayer/JsonForwarder/VehicleJsonForwarder/VehicleJsonForwarderTest.cpp \
    CommunicationLayer/CommDeviceControl/UdpMessageForwarderTest.cpp

!win32 {
    QMAKE_CXXFLAGS += -Werror
}

DESTDIR = ../../build/.tests
