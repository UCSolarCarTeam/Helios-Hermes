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
   DataContainer.h \
   BatteryData/BatteryData.h \
   BatteryData/I_BatteryData.h \
   BatteryFaultsData/BatteryFaultsData.h \
   BatteryFaultsData/I_BatterFaultsData.h \
   MotorFaultsData/MotorFaultsData.h \
   MotorFaultsData/I_MotorFaultsData.h \
   MotorDetailsData/MotorDetailsData.h \
   MotorDetailsData/I_MotorDetailsData.h \
   LightsData/LightsData.h \
   LightsData/I_LightsData.h \
   KeyMotorData/KeyMotorData.h \
   KeyMotorData/I_KeyMotorData.h \
   DriverControlsData/DriverControlsData.h \
   DriverControlsData/I_DriverControlsData.h \
   CmuData/CmuData.h \
   CmuData/I_CmuData.h \
   MpptData/MpptData.h \
   MpptData/I_MpptData.h

SOURCES += \
   DataContainer.cpp \
   BatteryData/BatteryData.cpp \
   BatteryFaultsData/BatteryFaultsData.cpp \
   MotorFaultsData/MotorFaultsData.cpp \
   MotorDetailsData/MotorDetailsData.cpp \
   LightsData/LightsData.cpp \
   KeyMotorData/KeyMotorData.cpp \
   DriverControlsData/DriverControlsData.cpp \
   CmuData/CmuData.cpp \
   MpptData/MpptData.cpp
