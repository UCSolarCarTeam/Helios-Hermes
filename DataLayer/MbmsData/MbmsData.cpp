#include "MbmsData.h"

namespace {
    const unsigned char COMMON_CONTACTOR_STATE_OFFSET = 0x01;
    const unsigned char MOTOR_CONTACTOR_STATE_OFFSET = 0x02;
    const unsigned char ARRAY_CONTACTOR_STATE_OFFSET = 0x04;
    const unsigned char LV_CONTACTOR_STATE_OFFSET = 0x08;
    const unsigned char CHARGE_CONTACTOR_STATE_OFFSET = 0x10;

    const unsigned char COMMON_CONTACTOR_ERROR_OFFSET = 0x01;
    const unsigned char MOTOR_CONTACTOR_ERROR_OFFSET = 0x02;
    const unsigned char ARRAY_CONTACTOR_ERROR_OFFSET = 0x04;
    const unsigned char LV_CONTACTOR_ERROR_OFFSET = 0x08;
    const unsigned char CHARGE_CONTACTOR_ERROR_OFFSET = 0x10;

    const unsigned char STROBE_BMS_LIGHT_OFFSET = 0x01;
    const unsigned char ALLOW_CHARGE_OFFSET = 0x02;
    const unsigned char HIGH_VOLTAGE_ENABLE_STATE_OFFSET = 0x04;
    const unsigned char ALLOW_DISCHARGE_OFFSET = 0x08;
    const unsigned char ORION_CAN_RECEIVED_RECENTLY_OFFSET = 0x10;
    const unsigned char DISCHARGE_SHOULD_TRIP_OFFSET = 0x20;
    const unsigned char CHARGE_SHOULD_TRIP_OFFSET = 0x40;

    const unsigned short HIGH_CELL_VOLTAGE_TRIP_OFFSET = 0x0001;
    const unsigned short LOW_CELL_VOLTAGE_TRIP_OFFSET = 0x0002;
    const unsigned short HIGH_COMMON_CURRENT_TRIP_OFFSET = 0x0004;
    const unsigned short MOTOR_HIGH_TEMPERATURE_CURRENT_TRIP_OFFSET = 0x0008;
    const unsigned short ARRAY_HIGH_TEMPERATURE_CURRENT_TRIP_OFFSET = 0x0010;
    const unsigned short LV_HIGH_TEMPERATURE_CURRENT_TRIP_OFFSET = 0x0020;
    const unsigned short CHARGE_HIGH_TEMPERATURE_CURRENT_TRIP_OFFSET = 0x0040;
    const unsigned short PROTECTION_TRIP_OFFSET = 0x0080;
    const unsigned short ORION_MESSAGE_TIMEOUT_TRIP_OFFSET = 0x0100;
    const unsigned short CONTACTOR_DISCONNECTED_UNEXPECTEDLY_TRIP_OFFSET = 0x0200;
}

MbmsData::MbmsData() {}

MbmsData::~MbmsData() {}

bool MbmsData::commonContactorState() const
{
    return commonContactorState_;
}

bool MbmsData::motorContactorState() const
{
    return motorContactorState_;
}

bool MbmsData::arrayContactorState() const
{
    return arrayContactorState_;
}

bool MbmsData::lvContactorState() const
{
    return lvContactorState_;
}

bool MbmsData::chargeContactorState() const
{
    return chargeContactorState_;
}

bool MbmsData::commonContactorError() const
{
    return commonContactorError_;
}

bool MbmsData::motorContactorError() const
{
    return motorContactorError_;
}

bool MbmsData::arrayContactorError() const
{
    return arrayContactorError_;
}

bool MbmsData::lvContactorError() const
{
    return lvContactorError_;
}

bool MbmsData::chargeContactorError() const
{
    return chargeContactorError_;
}

bool MbmsData::strobeBmsLight() const
{
    return strobeBmsLight_;
}

bool MbmsData::allowCharge() const
{
    return allowCharge_;
}

bool MbmsData::highVoltageEnableState() const
{
    return highVoltageEnableState_;
}

bool MbmsData::allowDischarge() const
{
    return allowDischarge_;
}

bool MbmsData::orionCanReceivedRecently() const
{
    return orionCanReceivedRecently_;
}

bool MbmsData::dischargeShouldTrip() const
{
    return dischargeShouldTrip_;
}

bool MbmsData::chargeShouldTrip() const
{
    return chargeShouldTrip_;
}

unsigned short MbmsData::auxillaryBatteryVoltage() const
{
    return auxillaryBatteryVoltage_;
}

void MbmsData::setAuxillaryBatteryVoltage(unsigned short newAuxillaryBatteryVoltage)
{
    auxillaryBatteryVoltage_ = newAuxillaryBatteryVoltage;
}

unsigned short MbmsData::motorVoltage() const
{
    return motorVoltage_;
}

void MbmsData::setMotorVoltage(unsigned short newMotorVoltage)
{
    motorVoltage_ = newMotorVoltage;
}

unsigned short MbmsData::arrayVoltage() const
{
    return arrayVoltage_;
}

void MbmsData::setArrayVoltage(unsigned short newArrayVoltage)
{
    arrayVoltage_ = newArrayVoltage;
}

unsigned short MbmsData::lvVoltage() const
{
    return lvVoltage_;
}

void MbmsData::setLvVoltage(unsigned short newLvVoltage)
{
    lvVoltage_ = newLvVoltage;
}

unsigned short MbmsData::chargeVoltage() const
{
    return chargeVoltage_;
}

void MbmsData::setChargeVoltage(unsigned short newChargeVoltage)
{
    chargeVoltage_ = newChargeVoltage;
}

unsigned short MbmsData::commonCurrent() const
{
    return commonCurrent_;
}

void MbmsData::setCommonCurrent(unsigned short newCommonCurrent)
{
    commonCurrent_ = newCommonCurrent;
}

unsigned short MbmsData::motorCurrent() const
{
    return motorCurrent_;
}

void MbmsData::setMotorCurrent(unsigned short newMotorCurrent)
{
    motorCurrent_ = newMotorCurrent;
}

unsigned short MbmsData::arrayCurrent() const
{
    return arrayCurrent_;
}

void MbmsData::setArrayCurrent(unsigned short newArrayCurrent)
{
    arrayCurrent_ = newArrayCurrent;
}

unsigned short MbmsData::lvCurrent() const
{
    return lvCurrent_;
}

void MbmsData::setLvCurrent(unsigned short newLvCurrent)
{
    lvCurrent_ = newLvCurrent;
}

unsigned short MbmsData::chargeCurrent() const
{
    return chargeCurrent_;
}

void MbmsData::setChargeCurrent(unsigned short newChargeCurrent)
{
    chargeCurrent_ = newChargeCurrent;
}

bool MbmsData::highCellVoltageTrip() const
{
    return highCellVoltageTrip_;
}

bool MbmsData::lowCellVoltageTrip() const
{
    return lowCellVoltageTrip_;
}

bool MbmsData::highCommonCurrentTrip() const
{
    return highCommonCurrentTrip_;
}

bool MbmsData::motorHighTemperatureCurrentTrip() const
{
    return motorHighTemperatureCurrentTrip_;
}

bool MbmsData::arrayHighTemperatureCurrentTrip() const
{
    return arrayHighTemperatureCurrentTrip_;
}

bool MbmsData::lvHighTemperatureCurrentTrip() const
{
    return lvHighTemperatureCurrentTrip_;
}

bool MbmsData::chargeHighTemperatureCurrentTrip() const
{
    return chargeHighTemperatureCurrentTrip_;
}

bool MbmsData::protectionTrip() const
{
    return protectionTrip_;
}

bool MbmsData::orionMessageTimeoutTrip() const
{
    return orionMessageTimeoutTrip_;
}

bool MbmsData::contactorDisconnectedUnexpectedlyTrip() const
{
    return contactorDisconnectedUnexpectedlyTrip_;
}

void MbmsData::setContactorStatus(const unsigned char& val)
{
    commonContactorState_ = val & COMMON_CONTACTOR_STATE_OFFSET;
    motorContactorState_ = val & MOTOR_CONTACTOR_STATE_OFFSET;
    arrayContactorState_ = val & ARRAY_CONTACTOR_STATE_OFFSET;
    lvContactorState_ = val & LV_CONTACTOR_STATE_OFFSET;
    chargeContactorState_ = val & CHARGE_CONTACTOR_STATE_OFFSET;
}

void MbmsData::setContactorErrors(const unsigned char& val)
{
    commonContactorError_ = val & COMMON_CONTACTOR_ERROR_OFFSET;
    motorContactorError_ = val & MOTOR_CONTACTOR_ERROR_OFFSET;
    arrayContactorError_ = val & ARRAY_CONTACTOR_ERROR_OFFSET;
    lvContactorError_ = val & LV_CONTACTOR_ERROR_OFFSET;
    chargeContactorError_ = val & CHARGE_CONTACTOR_ERROR_OFFSET;
}

void MbmsData::setMiscellanousStatus(const unsigned char& val)
{
    strobeBmsLight_ = val & STROBE_BMS_LIGHT_OFFSET;
    allowCharge_ = val & ALLOW_CHARGE_OFFSET;
    highVoltageEnableState_ = val & HIGH_VOLTAGE_ENABLE_STATE_OFFSET;
    allowDischarge_ = val & ALLOW_DISCHARGE_OFFSET;
    orionCanReceivedRecently_ = val & ORION_CAN_RECEIVED_RECENTLY_OFFSET;
    dischargeShouldTrip_ = val & DISCHARGE_SHOULD_TRIP_OFFSET;
    chargeShouldTrip_ = val & CHARGE_SHOULD_TRIP_OFFSET;
}

void MbmsData::setTripStatuses(const unsigned short& val)
{
    highCellVoltageTrip_ = val & HIGH_CELL_VOLTAGE_TRIP_OFFSET;
    lowCellVoltageTrip_ = val & LOW_CELL_VOLTAGE_TRIP_OFFSET;
    highCommonCurrentTrip_ = val & HIGH_COMMON_CURRENT_TRIP_OFFSET;
    motorHighTemperatureCurrentTrip_ = val & MOTOR_HIGH_TEMPERATURE_CURRENT_TRIP_OFFSET;
    arrayHighTemperatureCurrentTrip_ = val & ARRAY_HIGH_TEMPERATURE_CURRENT_TRIP_OFFSET;
    lvHighTemperatureCurrentTrip_ = val & LV_HIGH_TEMPERATURE_CURRENT_TRIP_OFFSET;
    chargeHighTemperatureCurrentTrip_ = val & CHARGE_HIGH_TEMPERATURE_CURRENT_TRIP_OFFSET;
    protectionTrip_ = val & PROTECTION_TRIP_OFFSET;
    orionMessageTimeoutTrip_ = val & ORION_MESSAGE_TIMEOUT_TRIP_OFFSET;
    contactorDisconnectedUnexpectedlyTrip_ = val & CONTACTOR_DISCONNECTED_UNEXPECTEDLY_TRIP_OFFSET;
}
