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
   BatteryData/BatteryData.h \
   BatteryData/I_BatteryData.h \
   DataContainer.h \
   FaultsData/FaultsData.h \
   FaultsData/I_FaultsData.h \
   PowerData/I_PowerData.h \
   PowerData/PowerData.h \
   VehicleData/I_VehicleData.h \
   VehicleData/VehicleData.h

SOURCES += \
   BatteryData/BatteryData.cpp \
   DataContainer.cpp \
   FaultsData/FaultsData.cpp \
   PowerData/PowerData.cpp \
   VehicleData/VehicleData.cpp
