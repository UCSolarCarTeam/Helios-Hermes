#include "BatteryMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
    const int BMU_ALIVE_OFFSET = 1;
    const int PACK_SOC_AMP_HOURS_OFFSET = 2;
    const int PACK_SOC_PERCENTAGE_OFFSET = 6;
    const int PACK_BALANCE_SOC_OFFSET = 10;
    const int PACK_BALANCE_SOC_PERCENTAGE_OFFSET = 14;
    const int CHARGING_CELL_VOLTAGE_ERROR_OFFSET = 18;
    const int CELL_TEMPERATURE_MARGIN_OFFSET = 20;
    const int DISCHARGING_CELL_VOLTAGE_ERROR_OFFSET = 22;
    const int TOTAL_PACK_CAPACITY_OFFSET = 24;
    const int PRECHARGE_CONTACTOR_DRIVER_STATUS_OFFSET = 26;
    const int PRECHARGE_STATE_OFFSET = 27;
    const int PRECHARGE_TIMER_ELAPSED_OFFSET = 28;
    const int PRECHARGE_TIMER_COUNT_OFFSET = 29;
    const int LOWEST_CELL_VOLTAGE_OFFSET = 31;
    const int LOWEST_CELL_VOLTAGE_NUMBER_OFFSET = 33;
    const int HIGHEST_CELL_VOLTAGE_OFFSET = 34;
    const int HIGHEST_CELL_VOLTAGE_NUMBER_OFFSET = 36;
    const int LOWEST_CELL_TEMPERATURE_OFFSET = 37;
    const int LOWEST_CELL_TEMPERATURE_NUMBER_OFFSET = 39;
    const int HIGHEST_CELL_TEMPERATURE_OFFSET = 40;
    const int HIGHEST_CELL_TEMPERATURE_NUMBER_OFFSET = 42;
    const int VOLTAGE_OFFSET = 43;
    const int CURRENT_OFFSET = 47;
    const int FAN_0_SPEED_OFFSET = 51;
    const int FAN_1_SPEED_OFFSET = 53;
    const int FAN_AND_CONTACTORS_12V_CURRENT_CONSUMPTION_OFFSET = 55;
    const int CMU_12V_CURRENT_CONSUMPTION_OFFSET = 57;
    const int BMS_CAN_LOCKED_OUT_OFFSET = 59;
}

BatteryMessage::BatteryMessage(const QByteArray& messageData)
    : messageData_(messageData)
{
}

bool BatteryMessage::alive() const
{
    return static_cast<bool>(messageData_.at(BMU_ALIVE_OFFSET));
}

float BatteryMessage::packSocAmpHours() const
{
    return getFloat(messageData_, PACK_SOC_AMP_HOURS_OFFSET);
}

float BatteryMessage::packSocPercentage() const
{
    return getFloat(messageData_, PACK_SOC_PERCENTAGE_OFFSET);
}

float BatteryMessage::packBalanceSoc() const
{
    return getFloat(messageData_, PACK_BALANCE_SOC_OFFSET);
}

float BatteryMessage::packBalanceSocPercentage() const
{
    return getFloat(messageData_, PACK_BALANCE_SOC_PERCENTAGE_OFFSET);
}

unsigned short BatteryMessage::chargingCellVoltageError() const
{
    return getUnsignedShort(messageData_, CHARGING_CELL_VOLTAGE_ERROR_OFFSET);
}

unsigned short BatteryMessage::cellTemperatureMargin() const
{
    return getUnsignedShort(messageData_, CELL_TEMPERATURE_MARGIN_OFFSET);
}

unsigned short BatteryMessage::dischargingCellVoltageError() const
{
    return getUnsignedShort(messageData_, DISCHARGING_CELL_VOLTAGE_ERROR_OFFSET);
}

unsigned short BatteryMessage::totalPackCapacity() const
{
    return getUnsignedShort(messageData_, TOTAL_PACK_CAPACITY_OFFSET);
}

unsigned char BatteryMessage::prechargeContactorDriverStatus() const
{
    return getUnsignedChar(messageData_, PRECHARGE_CONTACTOR_DRIVER_STATUS_OFFSET);
}

unsigned char BatteryMessage::prechargeState() const
{
    return getUnsignedChar(messageData_, PRECHARGE_STATE_OFFSET);
}

unsigned char BatteryMessage::prechargeTimerElapsed() const
{
    return getUnsignedChar(messageData_, PRECHARGE_TIMER_ELAPSED_OFFSET);
}

unsigned short BatteryMessage::prechargeTimerCount() const
{
    return getUnsignedShort(messageData_, PRECHARGE_TIMER_COUNT_OFFSET);
}

unsigned short BatteryMessage::lowestCellVoltage() const
{
    return getUnsignedShort(messageData_, LOWEST_CELL_VOLTAGE_OFFSET);
}

unsigned char BatteryMessage::lowestCellVoltageNumber() const
{
    return getUnsignedChar(messageData_, LOWEST_CELL_VOLTAGE_NUMBER_OFFSET);
}

unsigned short BatteryMessage::highestCellVoltage() const
{
    return getUnsignedShort(messageData_, HIGHEST_CELL_VOLTAGE_OFFSET);
}

unsigned char BatteryMessage::highestCellVoltageNumber() const
{
    return getUnsignedChar(messageData_, HIGHEST_CELL_VOLTAGE_NUMBER_OFFSET);
}

unsigned short BatteryMessage::lowestCellTemperature() const
{
    return getUnsignedShort(messageData_, LOWEST_CELL_TEMPERATURE_OFFSET);
}

unsigned char BatteryMessage::lowestCellTemperatureNumber() const
{
    return getUnsignedChar(messageData_, LOWEST_CELL_TEMPERATURE_NUMBER_OFFSET);
}

unsigned short BatteryMessage::highestCellTemperature() const
{
    return getUnsignedShort(messageData_, HIGHEST_CELL_TEMPERATURE_OFFSET);
}

unsigned char BatteryMessage::highestCellTemperatureNumber() const
{
    return getUnsignedChar(messageData_, HIGHEST_CELL_TEMPERATURE_NUMBER_OFFSET);
}

unsigned int BatteryMessage::voltage() const
{
    return getUnsignedInt(messageData_, VOLTAGE_OFFSET);
}

unsigned int BatteryMessage::current() const
{
    return getUnsignedInt(messageData_, CURRENT_OFFSET);
}

unsigned short BatteryMessage::fan0Speed() const
{
    return getUnsignedShort(messageData_, FAN_0_SPEED_OFFSET);
}

unsigned short BatteryMessage::fan1Speed() const
{
    return getUnsignedShort(messageData_, FAN_1_SPEED_OFFSET);
}

unsigned short BatteryMessage::fanContactors12VCurrentConsumption() const
{
    return getUnsignedShort(messageData_, FAN_AND_CONTACTORS_12V_CURRENT_CONSUMPTION_OFFSET);
}

unsigned short BatteryMessage::cmu12VCurrentConsumption() const
{
    return getUnsignedShort(messageData_, CMU_12V_CURRENT_CONSUMPTION_OFFSET);
}

bool BatteryMessage::bmsCanLockedOut() const
{
    return static_cast<bool>(messageData_.at(BMS_CAN_LOCKED_OUT_OFFSET));
}


QString BatteryMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::BATTERY) + ", ";
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
