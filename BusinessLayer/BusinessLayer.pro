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
   BusinessContainer.h \
   CommunicationsMonitoringService/CommunicationsMonitoringService.h \
   CommunicationsMonitoringService/I_CommunicationsMonitoringService.h \
   JsonForwarder/BatteryJsonForwarder/BatteryJsonForwarder.h \
   JsonForwarder/FaultsJsonForwarder/FaultsJsonForwarder.h \
   JsonForwarder/I_JsonForwarder.h \
   JsonForwarder/JsonDefines.h \
   JsonForwarder/JsonForwarder.h \
   JsonForwarder/PowerJsonForwarder/PowerJsonForwarder.h \
   JsonForwarder/VehicleJsonForwarder/VehicleJsonForwarder.h \
   LoggerService/LoggerService.h \

SOURCES += \
   BusinessContainer.cpp \
   CommunicationsMonitoringService/CommunicationsMonitoringService.cpp \
   JsonForwarder/BatteryJsonForwarder/BatteryJsonForwarder.cpp \
   JsonForwarder/FaultsJsonForwarder/FaultsJsonForwarder.cpp \
   JsonForwarder/JsonForwarder.cpp \
   JsonForwarder/PowerJsonForwarder/PowerJsonForwarder.cpp \
   JsonForwarder/VehicleJsonForwarder/VehicleJsonForwarder.cpp \
   LoggerService/LoggerService.cpp \
