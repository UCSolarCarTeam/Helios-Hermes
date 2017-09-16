#pragma once

#include "DataLayer/MotorDetailsData/I_MotorDetailsData.h"

class MockMotorDetailsData : public I_MotorDetailsData
{
public:

    /*MotorDetailsData "Gets"*/
    MOCK_CONST_METHOD0(getNumberOfUnits, unsigned char());
    MOCK_CONST_METHOD1(getMotorDetailsUnit, I_MotorDetailsUnit & (const unsigned char&));
};
