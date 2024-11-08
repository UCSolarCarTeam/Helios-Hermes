#include "BatteryData.h"

namespace {
    const unsigned char DISCHARGE_RELAY_ENABLED_OFFSET = 0x01;
    const unsigned char CHARGE_RELAY_ENABLED_OFFSET = 0x02;
    const unsigned char CHARGER_SAFETY_ENABLED_OFFSET = 0x04;
    const unsigned char MALFUNCTION_INDICATOR_ACTIVE_OFFSET = 0x08;
    const unsigned char MULTI_PURPOSE_INPUT_SIGNAL_STATUS_OFFSET = 0x10;
    const unsigned char ALWAYS_ON_SIGNAL_STATUS_OFFSET = 0x20;
    const unsigned char IS_READY_SIGNAL_STATUS_OFFSET = 0x40;
    const unsigned char IS_CHARGING_SIGNAL_STATUS_OFFSET = 0x80;
}

BatteryData::BatteryData() {}

BatteryData::~BatteryData() {}

unsigned char BatteryData::bmuAlive() const
{
    return bmuAlive_;
}

void BatteryData::setBmuAlive(unsigned char newBmuAlive)
{
    bmuAlive_ = newBmuAlive;
}

bool BatteryData::dischargeRelayEnabled() const
{
    return dischargeRelayEnabled_;
}

bool BatteryData::chargeRelayEnabled() const
{
    return chargeRelayEnabled_;
}

bool BatteryData::chargerSafetyEnabled() const
{
    return chargerSafetyEnabled_;
}

bool BatteryData::malfunctionIndicatorActive() const
{
    return malfunctionIndicatorActive_;
}

bool BatteryData::multiPurposeInputSignalStatus() const
{
    return multiPurposeInputSignalStatus_;
}

bool BatteryData::alwaysOnSignalStatus() const
{
    return alwaysOnSignalStatus_;
}

bool BatteryData::isReadySignalStatus() const
{
    return isReadySignalStatus_;
}

bool BatteryData::isChargingSignalStatus() const
{
    return isChargingSignalStatus_;
}

unsigned char BatteryData::populatedCells() const
{
    return populatedCells_;
}

void BatteryData::setPopulatedCells(unsigned char newPopulatedCells)
{
    populatedCells_ = newPopulatedCells;
}

float BatteryData::input12V() const
{
    return input12V_;
}

void BatteryData::setInput12V(float newInput12V)
{
    input12V_ = newInput12V;
}

float BatteryData::fanVoltage() const
{
    return fanVoltage_;
}

void BatteryData::setFanVoltage(float newFanVoltage)
{
    fanVoltage_ = newFanVoltage;
}

float BatteryData::packCurrent() const
{
    return packCurrent_;
}

void BatteryData::setPackCurrent(float newPackCurrent)
{
    packCurrent_ = newPackCurrent;
}

float BatteryData::packVoltage() const
{
    return packVoltage_;
}

void BatteryData::setPackVoltage(float newPackVoltage)
{
    packVoltage_ = newPackVoltage;
}

float BatteryData::packStateOfCharge() const
{
    return packStateOfCharge_;
}

void BatteryData::setPackStateOfCharge(float newPackStateOfCharge)
{
    packStateOfCharge_ = newPackStateOfCharge;
}

float BatteryData::packAmphours() const
{
    return packAmphours_;
}

void BatteryData::setPackAmphours(float newPackAmphours)
{
    packAmphours_ = newPackAmphours;
}

float BatteryData::packDepthOfDischarge() const
{
    return packDepthOfDischarge_;
}

void BatteryData::setPackDepthOfDischarge(float newPackDepthOfDischarge)
{
    packDepthOfDischarge_ = newPackDepthOfDischarge;
}

unsigned char BatteryData::highTemperature() const
{
    return highTemperature_;
}

void BatteryData::setHighTemperature(unsigned char newHighTemperature)
{
    highTemperature_ = newHighTemperature;
}

unsigned char BatteryData::highThermistorId() const
{
    return highThermistorId_;
}

void BatteryData::setHighThermistorId(unsigned char newHighThermistorId)
{
    highThermistorId_ = newHighThermistorId;
}

unsigned char BatteryData::lowTemperature() const
{
    return lowTemperature_;
}

void BatteryData::setLowTemperature(unsigned char newLowTemperature)
{
    lowTemperature_ = newLowTemperature;
}

unsigned char BatteryData::lowThermistorId() const
{
    return lowThermistorId_;
}

void BatteryData::setLowThermistorId(unsigned char newLowThermistorId)
{
    lowThermistorId_ = newLowThermistorId;
}

unsigned char BatteryData::averageTemperature() const
{
    return averageTemperature_;
}

void BatteryData::setAverageTemperature(unsigned char newAverageTemperature)
{
    averageTemperature_ = newAverageTemperature;
}

unsigned char BatteryData::internalTemperature() const
{
    return internalTemperature_;
}

void BatteryData::setInternalTemperature(unsigned char newInternalTemperature)
{
    internalTemperature_ = newInternalTemperature;
}

unsigned char BatteryData::fanSpeed() const
{
    return fanSpeed_;
}

void BatteryData::setFanSpeed(unsigned char newFanSpeed)
{
    fanSpeed_ = newFanSpeed;
}

unsigned char BatteryData::requestedFanSpeed() const
{
    return requestedFanSpeed_;
}

void BatteryData::setRequestedFanSpeed(unsigned char newRequestedFanSpeed)
{
    requestedFanSpeed_ = newRequestedFanSpeed;
}

short BatteryData::lowCellVoltage() const
{
    return lowCellVoltage_;
}

void BatteryData::setLowCellVoltage(short newLowCellVoltage)
{
    lowCellVoltage_ = newLowCellVoltage;
}

unsigned char BatteryData::lowCellVoltageId() const
{
    return lowCellVoltageId_;
}

void BatteryData::setLowCellVoltageId(unsigned char newLowCellVoltageId)
{
    lowCellVoltageId_ = newLowCellVoltageId;
}

short BatteryData::highCellVoltage() const
{
    return highCellVoltage_;
}

void BatteryData::setHighCellVoltage(short newHighCellVoltage)
{
    highCellVoltage_ = newHighCellVoltage;
}

unsigned char BatteryData::highCellVoltageId() const
{
    return highCellVoltageId_;
}

void BatteryData::setHighCellVoltageId(unsigned char newHighCellVoltageId)
{
    highCellVoltageId_ = newHighCellVoltageId;
}

short BatteryData::averageCellVoltage() const
{
    return averageCellVoltage_;
}

void BatteryData::setAverageCellVoltage(short newAverageCellVoltage)
{
    averageCellVoltage_ = newAverageCellVoltage;
}

void BatteryData::setBmsRelayStatus(unsigned char val)
{
    dischargeRelayEnabled_ = val & DISCHARGE_RELAY_ENABLED_OFFSET;
    chargeRelayEnabled_ = val & CHARGE_RELAY_ENABLED_OFFSET;
    chargerSafetyEnabled_ = val & CHARGER_SAFETY_ENABLED_OFFSET;
    malfunctionIndicatorActive_ = val & MALFUNCTION_INDICATOR_ACTIVE_OFFSET;
    multiPurposeInputSignalStatus_ = val & MULTI_PURPOSE_INPUT_SIGNAL_STATUS_OFFSET;
    alwaysOnSignalStatus_ = val & ALWAYS_ON_SIGNAL_STATUS_OFFSET;
    isReadySignalStatus_ = val & IS_READY_SIGNAL_STATUS_OFFSET;
    isChargingSignalStatus_ = val & IS_CHARGING_SIGNAL_STATUS_OFFSET;
}
