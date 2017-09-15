#include "MotorDetailsData.h"
#include "MotorDetailsUnit.h"

MotorDetailsData::MotorDetailsData(QList<I_MotorDetailsUnit*> units)
    : motorDetailsUnits_(units)
{
}

I_MotorDetailsUnit& MotorDetailsData::getMotorDetailsUnit(const unsigned char& index)
{
    return *motorDetailsUnits_[static_cast<int>(index)];
}
