#pragma once

#include "DataLayer/BatteryFaultsData/I_BatteryFaultsData.h"

class MockBatteryFaultsData : public I_BatteryFaultsData
{
public:
    /* BatteryFaultsData Gets */
    MOCK_CONST_METHOD0(getErrorFlags, unsigned int());
    MOCK_CONST_METHOD0(getLimitFlags, unsigned short());

    /* BatteryFaultsData status (error flags) */
    MOCK_CONST_METHOD0(internalCommunicationFault, bool());
    MOCK_CONST_METHOD0(internalConversionFault, bool());
    MOCK_CONST_METHOD0(weakCellFault, bool());
    MOCK_CONST_METHOD0(lowCellVoltageFault, bool());
    MOCK_CONST_METHOD0(openWiringFault, bool());
    MOCK_CONST_METHOD0(currentSensorFault, bool());
    MOCK_CONST_METHOD0(packVoltageSensorFault, bool());
    MOCK_CONST_METHOD0(weakPackFault, bool());
    MOCK_CONST_METHOD0(voltageRedundancyFault, bool());
    MOCK_CONST_METHOD0(fanMonitorFault, bool());
    MOCK_CONST_METHOD0(thermistorFault, bool());
    MOCK_CONST_METHOD0(canbusCommunicationsFault, bool());
    MOCK_CONST_METHOD0(alwaysOnSupplyFault, bool());
    MOCK_CONST_METHOD0(highVoltageIsolationFault, bool());
    MOCK_CONST_METHOD0(powerSupply12VFault, bool());
    MOCK_CONST_METHOD0(chargeLimitEnforcementFault, bool());
    MOCK_CONST_METHOD0(dischargeLimitEnforcementFault, bool());
    MOCK_CONST_METHOD0(chargerSafetyRelayFault, bool());
    MOCK_CONST_METHOD0(internalMemoryFault, bool());
    MOCK_CONST_METHOD0(internalThermistorFault, bool());
    MOCK_CONST_METHOD0(internalLogicFault, bool());

    /* BatteryFaultsData status (limit flags) */
    MOCK_CONST_METHOD0(dclReducedDueToLowSoc, bool());
    MOCK_CONST_METHOD0(dclReducedDueToHighCellResistence, bool());
    MOCK_CONST_METHOD0(dclReducedDueToTemperature, bool());
    MOCK_CONST_METHOD0(dclReducedDueToLowCellVoltage, bool());
    MOCK_CONST_METHOD0(dclReducedDueToLowPackVoltage, bool());
    MOCK_CONST_METHOD0(dclAndCclReducedDueToVoltageFailsafe, bool());
    MOCK_CONST_METHOD0(dclAndCclReducedDueToCommunicationFailsafe, bool());
    MOCK_CONST_METHOD0(cclReducedDueToHighSoc, bool());
    MOCK_CONST_METHOD0(cclReducedDueToHighCellResistence, bool());
    MOCK_CONST_METHOD0(cclReducedDueToTemperature, bool());
    MOCK_CONST_METHOD0(cclReducedDueToHighCellVoltage, bool());
    MOCK_CONST_METHOD0(cclReducedDueToHighPackVoltage, bool());
    MOCK_CONST_METHOD0(cclReducedDueToChargerLatch, bool());
    MOCK_CONST_METHOD0(cclReducedDueToAlternateCurrentLimit, bool());

    MOCK_CONST_METHOD1(Equals, bool(const I_BatteryFaultsData&));
    virtual bool operator==(const I_BatteryFaultsData& rhs) const { return Equals(rhs); }

    /* BatteryFaults Sets */
    MOCK_METHOD1(setErrorFlags, void(const unsigned int& errorFlags));
    MOCK_METHOD1(setLimitFlags, void(const unsigned short& limitFlags));
};
