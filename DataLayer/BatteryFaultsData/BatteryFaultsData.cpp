#include "BatteryFaultsData.h"

namespace
{
   const unsigned char CELL_OVER_VOLTAGE_MASK = 0x0001;
   const unsigned char CELL_UNDER_VOLTAGE_MASK = 0x0002;
   const unsigned char CELL_OVER_TEMP_MASK = 0x0004;
   const unsigned char MEASUREMENT_UNTRUSTED_MASK = 0x0008;
   const unsigned char CMU_COMM_TIMEOUT_MASK = 0x0010;
   const unsigned char VEHICLE_COMM_TIMEOUT_MASK = 0x0020;
   const unsigned char BMU_IN_SETUP_MODE_MASK = 0x0040;
   const unsigned char CMU_CAN_BUS_POWER_STATUS_MASK = 0x0080;
   const unsigned char PACK_ISOLATION_TEST_FAILURE_MASK = 0x0100;
   const unsigned char SOFTWARE_OVER_CURRENT_MASK = 0x0200;
   const unsigned char CAN_SUPPLY_LOW_MASK = 0x0400;
   const unsigned char CONTACTOR_STUCK_MASK = 0x0800;
   const unsigned char CMU_DETECTED_EXTRA_CELL_MASK = 0x1000;
}

BatteryFaultsData::BatteryFaultsData()
    : errorFlag_(0)
{
    // Initialize to 0
}
BatteryFaultsData::~BatteryFaultsData()
{
}

/* BatteryFaults Gets */
unsigned short BatteryFaultsData::getErrorFlag() const {
    return errorFlag_;
}

/* BatteryFaults status */
bool BatteryFaultsData::cellOverVoltage() const
{
    return static_cast<bool>(errorFlag_ & CELL_OVER_VOLTAGE_MASK);
}

bool BatteryFaultsData::cellUnderVoltage() const
{
    return static_cast<bool>(errorFlag_ & CELL_UNDER_VOLTAGE_MASK);
}

bool BatteryFaultsData::cellOverTemperature() const
{
    return static_cast<bool>(errorFlag_ & CELL_OVER_TEMP_MASK);
}

bool BatteryFaultsData::measurementUntrusted() const
{
    return static_cast<bool>(errorFlag_ & MEASUREMENT_UNTRUSTED_MASK);
}

bool BatteryFaultsData::cmuCommTimeout() const
{
    return static_cast<bool>(errorFlag_ & CMU_COMM_TIMEOUT_MASK);
}

bool BatteryFaultsData::vehicleCommTimeout() const
{
    return static_cast<bool>(errorFlag_ & VEHICLE_COMM_TIMEOUT_MASK);
}

bool BatteryFaultsData::bmuIsInSetupMode() const
{
    return static_cast<bool>(errorFlag_ & BMU_IN_SETUP_MODE_MASK);
}

bool BatteryFaultsData::cmuCanBusPowerStatus() const
{
    // Note: This fault flag actually means everything is okay.
    return !static_cast<bool>(errorFlag_ & CMU_CAN_BUS_POWER_STATUS_MASK);
}

bool BatteryFaultsData::packIsolationTestFailure() const
{
    return static_cast<bool>(errorFlag_ & PACK_ISOLATION_TEST_FAILURE_MASK);
}

bool BatteryFaultsData::softwareOverCurrentMeasured() const
{
    return static_cast<bool>(errorFlag_ & SOFTWARE_OVER_CURRENT_MASK);
}

bool BatteryFaultsData::canSupplyIsLow() const
{
    return static_cast<bool>(errorFlag_ & CAN_SUPPLY_LOW_MASK);
}

bool BatteryFaultsData::contactorIsStuck() const
{
    return static_cast<bool>(errorFlag_ & CONTACTOR_STUCK_MASK);
}

bool BatteryFaultsData::cmuDetectedExtraCellPresent() const
{
    return static_cast<bool>(errorFlag_ & CMU_DETECTED_EXTRA_CELL_MASK);
}

bool BatteryFaultsData::operator==(const BatteryFaultsData& other) const
{
    return errorFlag_ == other.errorFlag_;
}

/* BatteryFaults Sets */

void BatteryFaultsData::setErrorFlag(const unsigned short& errorFlag) {
    errorFlag_ = errorFlag;
    emit errorFlagReceived(errorFlag_);
}

QString BatteryFaults::toString() const
{
    return "0x" + QString::number(flags_, 16);
}