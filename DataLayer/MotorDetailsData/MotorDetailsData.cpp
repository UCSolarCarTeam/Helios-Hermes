#include "MotorDetailsData.h"
#include "MotorDetailsUnit.h"

MotorDetailsData::MotorDetailsData(const unsigned char& numberOfMotors)
: motorDetailsUnits_(new MotorDetailsUnit[numberOfMotors])
{
}

I_MotorDetailsUnit& MotorDetailsData::getMotorDetailsUnit(const unsigned char& index)
{
    return motorDetailsUnits_[static_cast<int>(index)];
}
