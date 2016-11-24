#include "BatteryMessage.h"
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

BatteryMessage::BatteryMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

bool BatteryMessage::alive() const
{
    return static_cast<bool>(messageData_.at(BMU_ALIVE));
}

float BatteryMessage::packSocAmpHours() const
{
    return getFloat(messageData_, PACK_SOC_AMP_HOURS);
}

float BatteryMessage::packSocPercentage() const
{
    return getFloat(messageData_, PACK_SOC_PERCENTAGE);
}

float BatteryMessage::packBalanceSoc() const
{
    return getFloat(messageData_, PACK_BALANCE_SOC);
}

float BatteryMessage::packBalanceSocPercentage() const
{
    return getFloat(messageData_, PACK_BALANCE_SOC_PERCENTAGE);
}

unsigned short BatteryMessage::chargingCellVoltageError() const
{
    return getUnsignedShort(messageData_, CHARGING_CELL_VOLTAGE_ERROR);
}

unsigned short BatteryMessage::cellTemperatureMargin() const
{
    return getUnsignedShort(messageData_, CELL_TEMPERATURE_MARGIN);
}

unsigned short BatteryMessage::dischargingCellVoltageError() const
{
    return getUnsignedShort(messageData_, DISCHARGING_CELL_VOLTAGE_ERROR);
}

unsigned short BatteryMessage::totalPackCapacity() const
{
    return getUnsignedShort(messageData_, TOTAL_PACK_CAPACITY);
}

unsigned char BatteryMessage::prechargeContactorDriverStatus() const
{
    return getUnsignedChar(messageData_, PRECHARGE_CONTACTOR_DRIVER_STATUS);
}

unsigned char BatteryMessage::prechargeState() const
{
    return getUnsignedChar(messageData_, PRECHARGE_STATE);
}

unsigned char BatteryMessage::prechargeTimerElapsed() const
{
    return getUnsignedChar(messageData_, PRECHARGE_TIMER_ELAPSED);
}

unsigned short BatteryMessage::prechargeTimerCount() const
{
    return getUnsignedShort(messageData_, PRECHARGE_TIMER_COUNT);
}

unsigned short BatteryMessage::lowestCellVoltage() const
{
    return getUnsignedShort(messageData_, LOWEST_CELL_VOLTAGE);
}

unsigned char BatteryMessage::lowestCellVoltageNumber() const
{
    return getUnsignedChar(messageData_, LOWEST_CELL_VOLTAGE_NUMBER);
}

unsigned short BatteryMessage::highestCellVoltage() const
{
    return getUnsignedShort(messageData_, HIGHEST_CELL_VOLTAGE);
}

unsigned char BatteryMessage::highestCellVoltageNumber() const
{
    return getUnsignedChar(messageData_, HIGHEST_CELL_VOLTAGE_NUMBER);
}

unsigned short BatteryMessage::lowestCellTemperature() const
{
    return getUnsignedShort(messageData_, LOWEST_CELL_TEMPERATURE);
}

unsigned char BatteryMessage::lowestCellTemperatureNumber() const
{
    return getUnsignedChar(messageData_, LOWEST_CELL_TEMPERATURE_NUMBER);
}

unsigned short BatteryMessage::highestCellTemperature() const
{
    return getUnsignedShort(messageData_, HIGHEST_CELL_TEMPERATURE);
}

unsigned char BatteryMessage::highestCellTemperatureNumber() const
{
    return getUnsignedChar(messageData_, HIGHEST_CELL_TEMPERATURE_NUMBER);
}

unsigned int BatteryMessage::voltage() const
{
    return getUnsignedInt(messageData_, VOLTAGE);
}

unsigned int BatteryMessage::current() const
{
    return getUnsignedInt(messageData_, CURRENT);
}

unsigned short BatteryMessage::fan0Speed() const
{
    return getUnsignedShort(messageData_, FAN_0_SPEED);
}

unsigned short BatteryMessage::fan1Speed() const
{
    return getUnsignedShort(messageData_, FAN_1_SPEED);
}

unsigned short BatteryMessage::fanContactors12VCurrentConsumption() const
{
    return getUnsignedShort(messageData_, FAN_AND_CONTACTORS_12V_CURRENT_CONSUMPTION);
}

unsigned short BatteryMessage::cmu12VCurrentConsumption() const
{
    return getUnsignedShort(messageData_, CMU_12V_CURRENT_CONSUMPTION);
}

bool BatteryMessage::bmsCanLockedOut() const
{
    return static_cast<bool>(messageData_.at(BMS_CAN_LOCKED_OUT));
}


QString BatteryMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::Battery) + ", ";
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
