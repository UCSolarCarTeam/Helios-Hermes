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

// TODO check these includes
// TODO delete the files in MessagingFramework that are not being used
#include "BatteryDataMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
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
    const int CMU_12V_CURRENT_CONSUMPTION = 57;
    const int BMS_CAN_LOCKED_OUT = 59;
}

BatteryDataMessage::BatteryDataMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

bool BatteryDataMessage::alive() const
{
    return static_cast<bool>(messageData_.at(BMU_ALIVE));
}

float BatteryDataMessage::packSocAmpHours() const
{
    return getFloat(messageData_, PACK_SOC_AMP_HOURS);
}

float BatteryDataMessage::packSocPercentage() const
{
    return getFloat(messageData_, PACK_SOC_PERCENTAGE);
}

float BatteryDataMessage::packBalanceSoc() const
{
    return getFloat(messageData_, PACK_BALANCE_SOC);
}

float BatteryDataMessage::packBalanceSocPercentage() const
{
    return getFloat(messageData_, PACK_BALANCE_SOC_PERCENTAGE);
}

unsigned short BatteryDataMessage::chargingCellVoltageError() const
{
    return getUnsignedShort(messageData_, CHARGING_CELL_VOLTAGE_ERROR);
}

unsigned short BatteryDataMessage::cellTemperatureMargin() const
{
    return getUnsignedShort(messageData_, CELL_TEMPERATURE_MARGIN);
}

unsigned short BatteryDataMessage::dischargingCellVoltageError() const
{
    return getUnsignedShort(messageData_, DISCHARGING_CELL_VOLTAGE_ERROR);
}

unsigned short BatteryDataMessage::totalPackCapacity() const
{
    return getUnsignedShort(messageData_, TOTAL_PACK_CAPACITY);
}

unsigned char BatteryDataMessage::prechargeContactorDriverStatus() const
{
    return getUnsignedChar(messageData_, PRECHARGE_CONTACTOR_DRIVER_STATUS);
}

unsigned char BatteryDataMessage::prechargeState() const
{
    return getUnsignedChar(messageData_, PRECHARGE_STATE);
}

unsigned char BatteryDataMessage::prechargeTimerElapsed() const
{
    return getUnsignedChar(messageData_, PRECHARGE_TIMER_ELAPSED);
}

unsigned short BatteryDataMessage::prechargeTimerCount() const
{
    return getUnsignedShort(messageData_, PRECHARGE_TIMER_COUNT);
}

unsigned short BatteryDataMessage::lowestCellVoltage() const
{
    return getUnsignedShort(messageData_, LOWEST_CELL_VOLTAGE);
}

unsigned char BatteryDataMessage::lowestCellVoltageNumber() const
{
    return getUnsignedChar(messageData_, LOWEST_CELL_VOLTAGE_NUMBER);
}

unsigned short BatteryDataMessage::highestCellVoltage() const
{
    return getUnsignedShort(messageData_, HIGHEST_CELL_VOLTAGE);
}

unsigned char BatteryDataMessage::highestCellVoltageNumber() const
{
    return getUnsignedChar(messageData_, HIGHEST_CELL_VOLTAGE_NUMBER);
}

unsigned short BatteryDataMessage::lowestCellTemperature() const
{
    return getUnsignedShort(messageData_, LOWEST_CELL_TEMPERATURE);
}

unsigned char BatteryDataMessage::lowestCellTemperatureNumber() const
{
    return getUnsignedChar(messageData_, LOWEST_CELL_TEMPERATURE_NUMBER);
}

unsigned short BatteryDataMessage::highestCellTemperature() const
{
    return getUnsignedShort(messageData_, HIGHEST_CELL_TEMPERATURE);
}

unsigned char BatteryDataMessage::highestCellTemperatureNumber() const
{
    return getUnsignedChar(messageData_, HIGHEST_CELL_TEMPERATURE_NUMBER);
}

unsigned int BatteryDataMessage::voltage() const
{
    return getUnsignedInt(messageData_, VOLTAGE);
}

unsigned int BatteryDataMessage::current() const
{
    return getUnsignedInt(messageData_, CURRENT);
}

unsigned short BatteryDataMessage::fan0Speed() const
{
    return getUnsignedShort(messageData_, FAN_0_SPEED);
}

unsigned short BatteryDataMessage::fan1Speed() const
{
    return getUnsignedShort(messageData_, FAN_1_SPEED);
}

unsigned short BatteryDataMessage::fanContactors12VCurrentConsumption() const
{
    return getUnsignedShort(messageData_, FAN_AND_CONTACTORS_12V_CURRENT_CONSUMPTION);
}

unsigned short BatteryDataMessage::cmu12VCurrentConsumption() const
{
    return getUnsignedShort(messageData_, CMU_12V_CURRENT_CONSUMPTION);
}

bool BatteryDataMessage::bmsCanLockedOut() const
{
    return static_cast<bool>(messageData_.at(BMS_CAN_LOCKED_OUT));
}


QString BatteryDataMessage::toString() const
{
    // TODO fix
    QString messageString;
    messageString += QString::number(MessageDefines::BATTERY_SERIAL_ID) + ", ";
    messageString += QString::number(alive()) + ", ";
    messageString += QString::number(packSocAmpHours()) + ", ";
    messageString += QString::number(packSocPercentage()) + ", ";
    messageString += QString::number(packBalanceSoc()) + ", ";
    messageString += QString::number(packBalanceSocPercentage()) + ", ";
    messageString += QString::number(chargingCellVoltageError()) + ", ";
    messageString += QString::number(cellTemperatureMargin()) + ", ";
    messageString += QString::number(dischargingCellVoltageError()) + ", ";
    messageString += QString::number(totalPackCapacity()) + ", ";
    messageString += QString::number(prechargeContactorDriverStatus()) + ", ";
    messageString += QString::number(prechargeState()) + ", ";
    messageString += QString::number(prechargeTimerElapsed()) + ", ";
    messageString += QString::number(prechargeTimerCount()) + ", ";
    messageString += QString::number(lowestCellVoltage()) + ", ";
    messageString += QString::number(lowestCellVoltageNumber()) + ", ";
    messageString += QString::number(highestCellVoltage()) + ", ";
    messageString += QString::number(highestCellVoltageNumber()) + ", ";
    messageString += QString::number(lowestCellTemperature()) + ", ";
    messageString += QString::number(lowestCellTemperatureNumber()) + ", ";
    messageString += QString::number(highestCellTemperature()) + ", ";
    messageString += QString::number(highestCellTemperatureNumber()) + ", ";
    messageString += QString::number(voltage()) + ", ";
    messageString += QString::number(current()) + ", ";
    messageString += QString::number(fan0Speed()) + ", ";
    messageString += QString::number(fan1Speed()) + ", ";
    messageString += QString::number(fanContactors12VCurrentConsumption()) + ", ";
    messageString += QString::number(cmu12VCurrentConsumption()) + ", ";
    messageString += QString::number(bmsCanLockedOut()) + ", ";
    return messageString;
}
