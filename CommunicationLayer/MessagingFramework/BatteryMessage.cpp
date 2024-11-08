#include "BatteryMessage.h"
#include "MessageDecodingUtils.h"

namespace {
    const int BMU_ALIVE_OFFSET = 1;
    const int BMS_RELAY_STATUS_OFFSET = 2;
    const int POPULATED_CELLS_OFFSET = 3;
    const int INPUT_12V_OFFSET = 4;
    const int FAN_VOLTAGE_OFFSET = 8;
    const int PACK_CURRENT_OFFSET = 12;
    const int PACK_VOLTAGE_OFFSET = 16;
    const int PACK_STATE_OF_CHARGE_OFFSET = 20;
    const int PACK_AMPHOURS_OFFSET = 24;
    const int PACK_DEPTH_OF_DISCHARGE_OFFSET = 28;
    const int HIGH_TEMPERATURE_OFFSET = 32;
    const int HIGH_THERMISTOR_ID_OFFSET = 33;
    const int LOW_TEMPERATURE_OFFSET = 34;
    const int LOW_THERMISTOR_ID_OFFSET = 35;
    const int AVERAGE_TEMPERATURE_OFFSET = 36;
    const int INTERNAL_TEMPERATURE_OFFSET = 37;
    const int FAN_SPEED_OFFSET = 38;
    const int REQUESTED_FAN_SPEED_OFFSET = 39;
    const int LOW_CELL_VOLTAGE_OFFSET = 40;
    const int LOW_CELL_VOLTAGE_ID_OFFSET = 42;
    const int HIGH_CELL_VOLTAGE_OFFSET = 43;
    const int HIGH_CELL_VOLTAGE_ID_OFFSET = 45;
    const int AVERAGE_CELL_VOLTAGE_OFFSET = 46;
}

BatteryMessage::BatteryMessage(const QByteArray& message) : message_(message) {}

unsigned char BatteryMessage::bmuAlive() const {
    return MessageDecodingUtils::getUnsignedChar(message_, BMU_ALIVE_OFFSET);
}

unsigned char BatteryMessage::bmsRelayStatus() const {
    return MessageDecodingUtils::getUnsignedChar(message_, BMS_RELAY_STATUS_OFFSET);
}

unsigned char BatteryMessage::populatedCells() const {
    return MessageDecodingUtils::getUnsignedChar(message_, POPULATED_CELLS_OFFSET);
}

float BatteryMessage::input12V() const {
    return MessageDecodingUtils::getFloat(message_, INPUT_12V_OFFSET);
}

float BatteryMessage::fanVoltage() const {
    return MessageDecodingUtils::getFloat(message_, FAN_VOLTAGE_OFFSET);
}

float BatteryMessage::packCurrent() const {
    return MessageDecodingUtils::getFloat(message_, PACK_CURRENT_OFFSET);
}

float BatteryMessage::packVoltage() const {
    return MessageDecodingUtils::getFloat(message_, PACK_VOLTAGE_OFFSET);
}

float BatteryMessage::packStateOfCharge() const {
    return MessageDecodingUtils::getFloat(message_, PACK_STATE_OF_CHARGE_OFFSET);
}

float BatteryMessage::packAmphours() const {
    return MessageDecodingUtils::getFloat(message_, PACK_AMPHOURS_OFFSET);
}

float BatteryMessage::packDepthOfDischarge() const {
    return MessageDecodingUtils::getFloat(message_, PACK_DEPTH_OF_DISCHARGE_OFFSET);
}

unsigned char BatteryMessage::highTemperature() const {
    return MessageDecodingUtils::getUnsignedChar(message_, HIGH_TEMPERATURE_OFFSET);
}

unsigned char BatteryMessage::highThermistorId() const {
    return MessageDecodingUtils::getUnsignedChar(message_, HIGH_THERMISTOR_ID_OFFSET);
}

unsigned char BatteryMessage::lowTemperature() const {
    return MessageDecodingUtils::getUnsignedChar(message_, LOW_TEMPERATURE_OFFSET);
}

unsigned char BatteryMessage::lowThermistorId() const {
    return MessageDecodingUtils::getUnsignedChar(message_, LOW_THERMISTOR_ID_OFFSET);
}

unsigned char BatteryMessage::averageTemperature() const {
    return MessageDecodingUtils::getUnsignedChar(message_, AVERAGE_TEMPERATURE_OFFSET);
}

unsigned char BatteryMessage::internalTemperature() const {
    return MessageDecodingUtils::getUnsignedChar(message_, INTERNAL_TEMPERATURE_OFFSET);
}

unsigned char BatteryMessage::fanSpeed() const {
    return MessageDecodingUtils::getUnsignedChar(message_, FAN_SPEED_OFFSET);
}

unsigned char BatteryMessage::requestedFanSpeed() const {
    return MessageDecodingUtils::getUnsignedChar(message_, REQUESTED_FAN_SPEED_OFFSET);
}

short int BatteryMessage::lowCellVoltage() const {
    return MessageDecodingUtils::getUnsignedShort(message_, LOW_CELL_VOLTAGE_OFFSET);
}

unsigned char BatteryMessage::lowCellVoltageId() const {
    return MessageDecodingUtils::getUnsignedChar(message_, LOW_CELL_VOLTAGE_ID_OFFSET);
}

short int BatteryMessage::highCellVoltage() const {
    return MessageDecodingUtils::getUnsignedShort(message_, HIGH_CELL_VOLTAGE_OFFSET);
}

unsigned char BatteryMessage::highCellVoltageId() const {
    return MessageDecodingUtils::getUnsignedChar(message_, HIGH_CELL_VOLTAGE_ID_OFFSET);
}

short int BatteryMessage::averageCellVoltage() const {
    return MessageDecodingUtils::getUnsignedShort(message_, AVERAGE_CELL_VOLTAGE_OFFSET);
}
