#-------------------------------------------------
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

QT += core testlib
TEMPLATE = app

TARGET = packetUnstufferTest

RCC_DIR= ../../../../release

DESTDIR = ../../../../release
OBJECTS_DIR = ../../../../release/.obj
MOC_DIR = ../../../../release/.moc
RCC_DIR = ../../../../release/.rcc
UI_DIR = ../../../../release/.ui

SOURCES += \
   TestPacketUnstuffer.cpp \
   ../PacketUnstuffer.cpp \
   ../../PacketSynchronizer/FakePacketSynchronizer.cpp \

HEADERS += \
   TestPacketUnstuffer.h \
   ../PacketUnstuffer.h \
   ../I_PacketUnstuffer.h \
   ../../PacketSynchronizer/FakePacketSynchronizer.h \
   ../../PacketSynchronizer/I_PacketSynchronizer.h \
