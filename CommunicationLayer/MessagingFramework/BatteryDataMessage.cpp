/**
 *  Schulich Delta Hermes
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of Schulich Delta Hermes
 *
 *  Schulich Delta Hermes is free software: 
 *  you can redistribute it and/or modify it under the terms 
 *  of the GNU Affero General Public License as published by 
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  Schulich Delta Hermes is distributed 
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 *  without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero 
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General 
 *  Public License along with Schulich Delta Hermes.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#include "BatteryDataMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
   const int BATTERY_VOLTAGE_INDEX = 1;
   const int BATTERY_CURRENT_INDEX = 5;
}

BatteryDataMessage::BatteryDataMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

float BatteryDataMessage::batteryVoltage() const
{
   return getFloat(messageData_, BATTERY_VOLTAGE_INDEX);
}

float BatteryDataMessage::batteryCurrent() const
{
   return getFloat(messageData_, BATTERY_CURRENT_INDEX);
}

QString BatteryDataMessage::toString() const
{
   QString messageString;
   messageString += QString::number(MessageDefines::BatteryData) + ", ";
   messageString += QString::number(batteryVoltage()) + ", ";
   messageString += QString::number(batteryCurrent()) + ", ";
   return messageString;
}
