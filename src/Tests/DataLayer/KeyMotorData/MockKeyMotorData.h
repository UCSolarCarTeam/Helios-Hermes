#pragma once

#include "DataLayer/KeyMotorData/I_KeyMotorData.h"

class MockKeyMotorData : public I_KeyMotorData
{
public:

    /*KeyMotorData "Gets"*/
    MOCK_CONST_METHOD0(getM0Alive, unsigned char());
    MOCK_CONST_METHOD0(getM0SetCurrent, float());
    MOCK_CONST_METHOD0(getM0SetVelocity, float());
    MOCK_CONST_METHOD0(getM0BusCurrent, float());
    MOCK_CONST_METHOD0(getM0BusVoltage, float());
    MOCK_CONST_METHOD0(getM0VehicleVelocity, float());
    MOCK_CONST_METHOD0(getM1Alive, unsigned char());
    MOCK_CONST_METHOD0(getM1SetCurrent, float());
    MOCK_CONST_METHOD0(getM1SetVelocity, float());
    MOCK_CONST_METHOD0(getM1BusCurrent, float());
    MOCK_CONST_METHOD0(getM1BusVoltage, float());
    MOCK_CONST_METHOD0(getM1VehicleVelocity, float());

    /*KeyMotorData "Sets"*/
    MOCK_METHOD1(setM0Alive, void(const unsigned char&));
    MOCK_METHOD1(setM0SetCurrent, void(const float&));
    MOCK_METHOD1(setM0SetVelocity, void(const float&));
    MOCK_METHOD1(setM0BusCurrent, void(const float&));
    MOCK_METHOD1(setM0BusVoltage, void(const float&));
    MOCK_METHOD1(setM0VehicleVelocity, void(const float&));
    MOCK_METHOD1(setM1Alive, void(const unsigned char&));
    MOCK_METHOD1(setM1SetCurrent, void(const float&));
    MOCK_METHOD1(setM1SetVelocity, void(const float&));
    MOCK_METHOD1(setM1BusCurrent, void(const float&));
    MOCK_METHOD1(setM1BusVoltage, void(const float&));
    MOCK_METHOD1(setM1VehicleVelocity, void(const float&));
};
