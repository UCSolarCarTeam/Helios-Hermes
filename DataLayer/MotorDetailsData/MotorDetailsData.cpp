#include "MotorDetailsData.h"

MotorDetailsData::MotorDetailsData(const unsigned char& numberOfMotors)
: motorDetailsUnits_(new I_MotorDetailsUnit[numberOfMotors])
{
    for (unsigned char i = 0; i < numberOfMotors; i++)
    {
        motorDetailsUnits_[i] = new MotorDetailsUnit(i);
    }
}

I_MotorDetailsUnit& MotorDetailsData::getMotorDetailsUnit(const unsigned char& index)
{
    return motorDetailsUnits_[static_cast<int>(index)];
}