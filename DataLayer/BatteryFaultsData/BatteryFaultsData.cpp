#include "BatteryFaultsData.h"

#include <QDebug>

namespace {
    const unsigned int INTERNAL_COMMUNICATION_FAULT_OFFSET = 0x00000001;
    const unsigned int INTERNAL_CONVERSION_FAULT_OFFSET = 0x00000002;
    const unsigned int WEAK_CELL_FAULT_OFFSET = 0x00000004;
    const unsigned int LOW_CELL_VOLTAGE_FAULT_OFFSET = 0x00000008;
    const unsigned int OPEN_WIRING_FAULT_OFFSET = 0x00000010;
    const unsigned int CURRENT_SENSOR_FAULT_OFFSET = 0x00000020;
    const unsigned int PACK_VOLTAGE_SENSOR_FAULT_OFFSET = 0x00000040;
    const unsigned int WEAK_PACK_FAULT_OFFSET = 0x00000080;
    const unsigned int VOLTAGE_REDUNDANCY_FAULT_OFFSET = 0x00000100;
    const unsigned int FAN_MONITOR_FAULT_OFFSET = 0x00000200;
    const unsigned int THERMISTOR_FAULT_OFFSET = 0x00000400;
    const unsigned int CANBUS_COMMUNICATION_FAULT_OFFSET = 0x00000800;
    const unsigned int ALWAYS_ON_SUPPLY_FAULT_OFFSET = 0x00001000;
    const unsigned int HIGH_VOLTAGE_ISOLATION_FAULT_OFFSET = 0x00002000;
    const unsigned int POWER_SUPPLY_12V_FAULT_OFFSET = 0x00004000;
    const unsigned int CHARGE_LIMIT_ENFORCEMENT_FAULT_OFFSET = 0x00008000;
    const unsigned int DISCHARGE_LIMIT_ENFORCEMENT_FAULT_OFFSET = 0x00010000;
    const unsigned int CHARGER_SAFETY_RELAY_FAULT_OFFSET = 0x00020000;
    const unsigned int INTERNAL_MEMORY_FAULT_OFFSET = 0x00040000;
    const unsigned int INTERNAL_THERMISTOR_FAULT_OFFSET = 0x00080000;
    const unsigned int INTERNAL_LOGIC_FAULT_OFFSET = 0x00100000;

    const unsigned short DCL_REDUCED_DUE_TO_LOW_SOC_OFFSET = 0x0001;
    const unsigned short DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE_OFFSET = 0x0002;
    const unsigned short DCL_REDUCED_DUE_TO_TEMPERATURE_OFFSET = 0x0004;
    const unsigned short DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE_OFFSET = 0x0008;
    const unsigned short DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE_OFFSET = 0x0010;

    const unsigned short DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE_OFFSET = 0x0040;
    const unsigned short DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE_OFFSET = 0x0080;

    const unsigned short CCL_REDUCED_DUE_TO_HIGH_SOC_OFFSET = 0x0200;
    const unsigned short CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE_OFFSET = 0x0400;
    const unsigned short CCL_REDUCED_DUE_TO_TEMPERATURE_OFFSET = 0x0800;
    const unsigned short CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE_OFFSET = 0x1000;
    const unsigned short CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE_OFFSET = 0x2000;
    const unsigned short CCL_REDUCED_DUE_TO_CHARGER_LATCH_OFFSET = 0x4000;
    const unsigned short CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT_OFFSET = 0x8000;
}

BatteryFaultsData::BatteryFaultsData() {}

BatteryFaultsData::~BatteryFaultsData() {}

bool BatteryFaultsData::internalCommunicationFault() const
{
    return internalCommunicationFault_;
}

bool BatteryFaultsData::internalConverversionFault() const
{
    return internalConverversionFault_;
}

bool BatteryFaultsData::weakCellFault() const
{
    return weakCellFault_;
}

bool BatteryFaultsData::lowCellVoltageFault() const
{
    return lowCellVoltageFault_;
}

bool BatteryFaultsData::openWiringFault() const
{
    return openWiringFault_;
}

bool BatteryFaultsData::currentSensorFault() const
{
    return currentSensorFault_;
}

bool BatteryFaultsData::packVoltageSensorFault() const
{
    return packVoltageSensorFault_;
}

bool BatteryFaultsData::weakPackFault() const
{
    return weakPackFault_;
}

bool BatteryFaultsData::voltageRedundancyFault() const
{
    return voltageRedundancyFault_;
}

bool BatteryFaultsData::fanMonitorFault() const
{
    return fanMonitorFault_;
}

bool BatteryFaultsData::thermistorFault() const
{
    return thermistorFault_;
}

bool BatteryFaultsData::canbusCommunicationFault() const
{
    return canbusCommunicationFault_;
}

bool BatteryFaultsData::alwaysOnSupplyFault() const
{
    return alwaysOnSupplyFault_;
}

bool BatteryFaultsData::highVoltageIsolationFault() const
{
    return highVoltageIsolationFault_;
}

bool BatteryFaultsData::powerSupply12VFault() const
{
    return powerSupply12VFault_;
}

bool BatteryFaultsData::chargeLimitEnforcementFault() const
{
    return chargeLimitEnforcementFault_;
}

bool BatteryFaultsData::dischargeLimitEnforcementFault() const
{
    return dischargeLimitEnforcementFault_;
}

bool BatteryFaultsData::chargerSafetyRelayFault() const
{
    return chargerSafetyRelayFault_;
}

bool BatteryFaultsData::internalMemoryFault() const
{
    return internalMemoryFault_;
}

bool BatteryFaultsData::internalThermistorFault() const
{
    return internalThermistorFault_;
}

bool BatteryFaultsData::internalLogicFault() const
{
    return internalLogicFault_;
}

bool BatteryFaultsData::dclReducedDueToLowSoc() const
{
    return dclReducedDueToLowSoc_;
}

bool BatteryFaultsData::dclReducedDueToHighCellResistance() const
{
    return dclReducedDueToHighCellResistance_;
}

bool BatteryFaultsData::dclReducedDueToTemperature() const
{
    return dclReducedDueToTemperature_;
}

bool BatteryFaultsData::dclReducedDueToLowCellVoltage() const
{
    return dclReducedDueToLowCellVoltage_;
}

bool BatteryFaultsData::dclReducedDueToLowPackVoltage() const
{
    return dclReducedDueToLowPackVoltage_;
}

bool BatteryFaultsData::dclAndCclReducedDueToVoltageFailsafe() const
{
    return dclAndCclReducedDueToVoltageFailsafe_;
}

bool BatteryFaultsData::dclAndCclReducedDueToCommunicationFailsafe() const
{
    return dclAndCclReducedDueToCommunicationFailsafe_;
}

bool BatteryFaultsData::cclReducedDueToHighSoc() const
{
    return cclReducedDueToHighSoc_;
}

bool BatteryFaultsData::cclReducedDueToHighCellResistance() const
{
    return cclReducedDueToHighCellResistance_;
}

bool BatteryFaultsData::cclReducedDueToTemperature() const
{
    return cclReducedDueToTemperature_;
}

bool BatteryFaultsData::cclReducedDueToHighCellVoltage() const
{
    return cclReducedDueToHighCellVoltage_;
}

bool BatteryFaultsData::cclReducedDueToHighPackVoltage() const
{
    return cclReducedDueToHighPackVoltage_;
}

bool BatteryFaultsData::cclReducedDueToChargerLatch() const
{
    return cclReducedDueToChargerLatch_;
}

bool BatteryFaultsData::cclReducedDueToAlternateCurrentLimit() const
{
    return cclReducedDueToAlternateCurrentLimit_;
}

void BatteryFaultsData::setErrorFlags(const unsigned int& val)
{
    qDebug() << "ASSIGNING --------------------------------------------------" << val;
    internalCommunicationFault_ = val & INTERNAL_COMMUNICATION_FAULT_OFFSET;
    internalConverversionFault_ = val & INTERNAL_CONVERSION_FAULT_OFFSET;
    weakCellFault_ = val & WEAK_CELL_FAULT_OFFSET;
    lowCellVoltageFault_ = val & LOW_CELL_VOLTAGE_FAULT_OFFSET;
    openWiringFault_ = val & OPEN_WIRING_FAULT_OFFSET;
    currentSensorFault_ = val & CURRENT_SENSOR_FAULT_OFFSET;
    packVoltageSensorFault_ = val & PACK_VOLTAGE_SENSOR_FAULT_OFFSET;
    weakPackFault_ = val & WEAK_PACK_FAULT_OFFSET;
    voltageRedundancyFault_ = val & VOLTAGE_REDUNDANCY_FAULT_OFFSET;
    fanMonitorFault_ = val & FAN_MONITOR_FAULT_OFFSET;
    thermistorFault_ = val & THERMISTOR_FAULT_OFFSET;
    canbusCommunicationFault_ = val & CANBUS_COMMUNICATION_FAULT_OFFSET;
    alwaysOnSupplyFault_ = val & ALWAYS_ON_SUPPLY_FAULT_OFFSET;
    highVoltageIsolationFault_ = val & HIGH_VOLTAGE_ISOLATION_FAULT_OFFSET;
    powerSupply12VFault_ = val & POWER_SUPPLY_12V_FAULT_OFFSET;
    chargeLimitEnforcementFault_ = val & CHARGE_LIMIT_ENFORCEMENT_FAULT_OFFSET;
    dischargeLimitEnforcementFault_ = val & DISCHARGE_LIMIT_ENFORCEMENT_FAULT_OFFSET;
    chargerSafetyRelayFault_ = val & CHARGER_SAFETY_RELAY_FAULT_OFFSET;
    internalMemoryFault_ = val & INTERNAL_MEMORY_FAULT_OFFSET;
    internalThermistorFault_ = val & INTERNAL_THERMISTOR_FAULT_OFFSET;
    internalLogicFault_ = val & INTERNAL_LOGIC_FAULT_OFFSET;
}

void BatteryFaultsData::setLimitFlags(const unsigned short& val){
    qDebug() << "ASSIGNING2 --------------------------------------------------" << val;
    dclReducedDueToLowSoc_ = val & DCL_REDUCED_DUE_TO_LOW_SOC_OFFSET;
    dclReducedDueToHighCellResistance_ = val & DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE_OFFSET;
    dclReducedDueToTemperature_ = val & DCL_REDUCED_DUE_TO_TEMPERATURE_OFFSET;
    dclReducedDueToLowCellVoltage_ = val & DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE_OFFSET;
    dclReducedDueToLowPackVoltage_ = val & DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE_OFFSET;
    dclAndCclReducedDueToVoltageFailsafe_ = val & DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE_OFFSET;
    dclAndCclReducedDueToCommunicationFailsafe_ = val & DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE_OFFSET;
    cclReducedDueToHighSoc_ = val & CCL_REDUCED_DUE_TO_HIGH_SOC_OFFSET;
    cclReducedDueToHighCellResistance_ = val & CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE_OFFSET;
    cclReducedDueToTemperature_ = val & CCL_REDUCED_DUE_TO_TEMPERATURE_OFFSET;
    cclReducedDueToHighCellVoltage_ = val & CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE_OFFSET;
    cclReducedDueToHighPackVoltage_ = val & CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE_OFFSET;
    cclReducedDueToChargerLatch_ = val & CCL_REDUCED_DUE_TO_CHARGER_LATCH_OFFSET;
    cclReducedDueToAlternateCurrentLimit_ = val & CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT_OFFSET;
}
