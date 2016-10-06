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
   const int STATE_OF_CHARGE_INDEX = 9;
   const int BALANCE_SOC_INDEX = 13;
   const int SECONDARY_ERROR_INDEX = 17;

    const int BMU_ALIVE = 1;
    const int PACK_SOC_AMP_HOURS = 2;
    const int PACK_SOC_PERCENTAGE = 6;
    const int PACK_BALANCE_SOC = 10;
    const int PACK_BALANCE_SOC_PERCENTAGE = 14;
    const int CHARGING_CELL_VOLTAGE_ERROR = 18;
    const int CELL_TEMPERATURE_MARGIN = 20;
    const int DISCHARGING_CELL_VOLTAGE_ERROR = 22;
    const int TOTAL_PACK_CAPACITY = 24;
    const int PRECHARGE_CONTACTOR_DRIVER_STATUS = 26;
    const int PRECHARGE_STATE = 27;
    const int PRECHARGE_TIMER_ELAPSED = 28;
    const int PRECHARGE_TIMER_COUNT = 29;
    const int LOWEST_CELL_VOLTAGE = 31;
    const int LOWEST_CELL_VOLTAGE_NUMBER = 33;
    const int HIGHEST_CELL_VOLTAGE = 34;
    const int HIGHEST_CELL_VOLTAGE_NUMBER = 36;
    const int LOWEST_CELL_TEMPERATURE = 37;
    const int LOWEST_CELL_TEMPERATURE_NUMBER = 39;
    const int HIGHEST_CELL_TEMPERATURE = 40;
    const int HIGHEST_CELL_TEMPERATURE_NUMBER = 42;
    const int VOLTAGE = 43;
    const int CURRENT = 47;
    const int FAN_0_SPEED = 51;
    const int FAN_1_SPEED = 53;
    const int FAN_AND_CONTACTORS_12V_CURRENT_CONSUMPTION = 55;
    const int CMU_12V_CURRENT_CONSUMPTION = 59;
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

float BatteryDataMessage::stateOfCharge() const
{
	return getFloat(messageData_, STATE_OF_CHARGE_INDEX);
}

float BatteryDataMessage::balanceStateOfCharge() const
{
	return getFloat(messageData_, BALANCE_SOC_INDEX);
}

bool BatteryDataMessage::secondaryBatteryUnderVoltage() const
{
	return static_cast<bool>(messageData_.at(SECONDARY_ERROR_INDEX));
}

QString BatteryDataMessage::toString() const
{
   QString messageString;
   messageString += QString::number(MessageDefines::BatteryData) + ", ";
   messageString += QString::number(batteryVoltage()) + ", ";
   messageString += QString::number(batteryCurrent()) + ", ";
   messageString += QString::number(stateOfCharge()) + ", ";
   messageString += QString::number(balanceStateOfCharge()) + ", ";
   messageString += QString::number(secondaryBatteryUnderVoltage()) + ", ";   
   return messageString;
}
