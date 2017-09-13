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
	 BusinessLayer/JsonForwarder/JsonForwarderTest.cpp 

TRAVIS_DEFINED = $$(TRAVIS)
count(TRAVIS_DEFINED, 0) {
   # rabbit mq message forwarder expects rabbitMQ server located at localhost, not applicable for TravisCI.
   SOURCES += \
      CommunicationLayer/CommDeviceControl/RabbitMqMessageForwarderTest.cpp
} else {
   message(TravisCI build)
}

!win32 {
    QMAKE_CXXFLAGS += -Werror
}

DESTDIR = ../../build/tests

copyfiles.commands = cp testconfig.ini $${DESTDIR}

QMAKE_EXTRA_TARGETS += copyfiles
POST_TARGETDEPS += copyfiles
