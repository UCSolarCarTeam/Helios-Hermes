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

TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

DESTDIR = ../../build/.lib

HEADERS += \
   CommDeviceControl/I_CommDevice.h \
   CommDeviceControl/I_ConnectionService.h \
   CommDeviceControl/RadioCommDevice.h \
   CommDeviceControl/UdpMessageForwarder.h \
   CommDeviceControl/I_MessageForwarder.h \
   CommunicationContainer.h \
   DataPopulators/BatteryPopulator.h \
   DataPopulators/CmuPopulator.h \
   DataPopulators/DriverDetailsPopulator.h \
   DataPopulators/FaultsPopulator.h \
   DataPopulators/KeyDriverControlPopulator.h \
   MessagingFramework/BatteryDataMessage.h \
   MessagingFramework/BatteryFaults.h \
   MessagingFramework/CmuDataMessage.h \
   MessagingFramework/DriverControlDetails.h \
   MessagingFramework/FaultsMessage.h \
   MessagingFramework/KeyDriverControlTelemetry.h \
   MessagingFramework/LimitFlags.h \
   MessagingFramework/MessageDecodingHelpers.h \
   MessagingFramework/MessageDefines.h \
   MessagingFramework/MotorFaults.h \
   PacketChecksumChecker/I_PacketChecksumChecker.h \
   PacketChecksumChecker/PacketChecksumChecker.h \
   PacketDecoder/I_PacketDecoder.h \
   PacketDecoder/PacketDecoder.h \
   PacketSynchronizer/I_PacketSynchronizer.h \
   PacketSynchronizer/PacketSynchronizer.h \
   PacketUnstuffer/I_DataInjectionService.h \
   PacketUnstuffer/I_PacketUnstuffer.h \
   PacketUnstuffer/PacketUnstuffer.h

SOURCES += \
   CommDeviceControl/RadioCommDevice.cpp \
   CommDeviceControl/UdpMessageForwarder.cpp \
   CommunicationContainer.cpp \
   DataPopulators/BatteryPopulator.cpp \
   DataPopulators/CmuPopulator.cpp \
   DataPopulators/DriverDetailsPopulator.cpp \
   DataPopulators/FaultsPopulator.cpp \
   DataPopulators/KeyDriverControlPopulator.cpp \
   MessagingFramework/BatteryDataMessage.cpp \
   MessagingFramework/BatteryFaults.cpp \
   MessagingFramework/CmuDataMessage.cpp \
   MessagingFramework/DriverControlDetails.cpp \
   MessagingFramework/FaultsMessage.cpp \
   MessagingFramework/KeyDriverControlTelemetry.cpp \
   MessagingFramework/LimitFlags.cpp \
   MessagingFramework/MessageDecodingHelpers.cpp \
   MessagingFramework/MessageDefines.cpp \
   MessagingFramework/MotorFaults.cpp \
   PacketChecksumChecker/PacketChecksumChecker.cpp \
   PacketDecoder/PacketDecoder.cpp \
   PacketSynchronizer/PacketSynchronizer.cpp \
   PacketUnstuffer/PacketUnstuffer.cpp
