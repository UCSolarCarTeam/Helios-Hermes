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

#include "DriverControlDetails.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
   const int MOTOR_VELOCITY_INDEX = 1;
   const int MOTOR_VOLTAGE_INDEX = 5;
   const int MOTOR_CURRENT_REAL_INDEX = 9;
   const int BACK_EMF_INDEX = 13;
   const int DSP_BOARD_TEMPERATURE_INDEX = 17;
   const int DC_BUS_AMP_HOURS_INDEX = 21;
   const int ODOMETER_INDEX = 25;
}

DriverControlDetails::DriverControlDetails(
   const QByteArray& messageData)
: messageData_(messageData)
{
}

float DriverControlDetails::motorVelocity() const
{
   return getFloat(messageData_, MOTOR_VELOCITY_INDEX);
}

float DriverControlDetails::motorVoltage() const
{
   return getFloat(messageData_, MOTOR_VOLTAGE_INDEX);
}

float DriverControlDetails::motorCurrentReal() const
{
   return getFloat(messageData_, MOTOR_CURRENT_REAL_INDEX);
}

float DriverControlDetails::backEmf() const
{
   return getFloat(messageData_, BACK_EMF_INDEX);
}

float DriverControlDetails::dpsBoardTemperature() const
{
   return getFloat(messageData_, DSP_BOARD_TEMPERATURE_INDEX);
}

float DriverControlDetails::dcBusAmpHours() const
{
   return getFloat(messageData_, DC_BUS_AMP_HOURS_INDEX);
}

float DriverControlDetails::odometer() const 
{
   return getFloat(messageData_, ODOMETER_INDEX);
}

QString DriverControlDetails::toString() const
{
   QString messageString;
   messageString += QString::number(MessageDefines::DriverControlDetails) + ", ";
   messageString += QString::number(motorVelocity()) + ", ";
   messageString += QString::number(motorVoltage()) + ", ";
   messageString += QString::number(motorCurrentReal()) + ", ";
   messageString += QString::number(backEmf()) + ", ";
   messageString += QString::number(dpsBoardTemperature()) + ", ";
   messageString += QString::number(dcBusAmpHours()) + ", ";
   return messageString;
}
