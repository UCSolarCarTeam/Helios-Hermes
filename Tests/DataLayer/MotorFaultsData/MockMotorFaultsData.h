#pragma once

#include "DataLayer/MotorFaultsData/I_MotorFaultsData.h"

class MockMotorFaultsData : public I_MotorFaultsData
{
public:
    MOCK_CONST_METHOD0(toString, QString());

    /*MotorFaultsData "Gets"*/
    MOCK_CONST_METHOD0(getM0ErrorFlags, unsigned char());
    MOCK_CONST_METHOD0(getM1ErrorFlags, unsigned char());
    MOCK_CONST_METHOD0(getM0LimitFlags, unsigned char());
    MOCK_CONST_METHOD0(getM1LimitFlags, unsigned char());
    MOCK_CONST_METHOD0(getM0CanRxErrorCount, unsigned char());
    MOCK_CONST_METHOD0(getM0CanTxErrorCount, unsigned char());
    MOCK_CONST_METHOD0(getM1CanRxErrorCount, unsigned char());
    MOCK_CONST_METHOD0(getM1CanTxErrorCount, unsigned char());
    MOCK_CONST_METHOD0(m0MotorOverSpeed, bool());
    MOCK_CONST_METHOD0(m0SoftwareOverCurrent, bool());
    MOCK_CONST_METHOD0(m0DcBusOverVoltage, bool());
    MOCK_CONST_METHOD0(m0BadMotorPositionHallSequence, bool());
    MOCK_CONST_METHOD0(m0WatchdogCausedLastReset, bool());
    MOCK_CONST_METHOD0(m0ConfigReadError, bool());
    MOCK_CONST_METHOD0(m0RailUnderVoltageLockOut, bool());
    MOCK_CONST_METHOD0(m0DesaturationFault, bool());
    MOCK_CONST_METHOD0(m1MotorOverSpeed, bool());
    MOCK_CONST_METHOD0(m1SoftwareOverCurrent, bool());
    MOCK_CONST_METHOD0(m1DcBusOverVoltage, bool());
    MOCK_CONST_METHOD0(m1BadMotorPositionHallSequence, bool());
    MOCK_CONST_METHOD0(m1WatchdogCausedLastReset, bool());
    MOCK_CONST_METHOD0(m1ConfigReadError, bool());
    MOCK_CONST_METHOD0(m1RailUnderVoltageLockOut, bool());
    MOCK_CONST_METHOD0(m1DesaturationFault, bool());
    MOCK_CONST_METHOD0(m0OutputVoltagePwmLimit, bool());
    MOCK_CONST_METHOD0(m0MotorCurrentLimit, bool());
    MOCK_CONST_METHOD0(m0VelocityLimit, bool());
    MOCK_CONST_METHOD0(m0BusCurrentLimit, bool());
    MOCK_CONST_METHOD0(m0BusVoltageUpperLimit, bool());
    MOCK_CONST_METHOD0(m0BusVoltageLowerLimit, bool());
    MOCK_CONST_METHOD0(m0IpmOrMotorTemperatureLimit, bool());
    MOCK_CONST_METHOD0(m1OutputVoltagePwmLimit, bool());
    MOCK_CONST_METHOD0(m1MotorCurrentLimit, bool());
    MOCK_CONST_METHOD0(m1VelocityLimit, bool());
    MOCK_CONST_METHOD0(m1BusCurrentLimit, bool());
    MOCK_CONST_METHOD0(m1BusVoltageUpperLimit, bool());
    MOCK_CONST_METHOD0(m1BusVoltageLowerLimit, bool());
    MOCK_CONST_METHOD0(m1IpmOrMotorTemperatureLimit, bool());

    /* MotorFaults Sets */
    MOCK_METHOD1(setM0ErrorFlags, void(const unsigned char&));
    MOCK_METHOD1(setM1ErrorFlags, void(const unsigned char&));
    MOCK_METHOD1(setM0LimitFlags, void(const unsigned char&));
    MOCK_METHOD1(setM1LimitFlags, void(const unsigned char&));
    MOCK_METHOD1(setM0CanRxErrorCount, void(const unsigned char&));
    MOCK_METHOD1(setM0CanTxErrorCount, void(const unsigned char&));
    MOCK_METHOD1(setM1CanRxErrorCount, void(const unsigned char&));
    MOCK_METHOD1(setM1CanTxErrorCount, void(const unsigned char&));
};
