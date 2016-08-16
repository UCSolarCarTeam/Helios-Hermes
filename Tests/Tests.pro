#-------------------------------------------------
#
#  Project created by QtCreator 2014-10-13T12:01:32
#
#  Schulich Delta Hermes
#  Copyright (C) 2015 University of Calgary Solar Car Team
#
#  This file is part of Schulich Delta Hermes
#
#  Schulich Delta Hermes is free software:
#  you can redistribute it and/or modify it under the terms
#  of the GNU Affero General Public License as published by
#  the Free Software Foundation, either version 3 of the
#  License, or (at your option) any later version.
#
#  Schulich Delta Hermes is distributed
#  in the hope that it will be useful, but WITHOUT ANY WARRANTY;
#  without even the implied warranty of MERCHANTABILITY or
#  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero
#  General Public License for more details.
#
#  You should have received a copy of the GNU Affero General
#  Public License along with Schulich Delta Hermes.
#  If not, see <http://www.gnu.org/licenses/>.
#
#  For further contact, email <software@calgarysolarcar.ca>
#
#-------------------------------------------------

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
    CommunicationLayer/CommDeviceControl/udpmessageforwardertest.cpp

!win32 {
    QMAKE_CXXFLAGS += -Werror
}

DESTDIR = ../../build/.tests
