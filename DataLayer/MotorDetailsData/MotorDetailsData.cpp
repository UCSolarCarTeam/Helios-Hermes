#include "MotorDetailsData.h"
#include "MotorDetailsUnit.h"

MotorDetailsData::MotorDetailsData(QList<I_MotorDetailsUnit*> units)
    : motorDetailsUnits_(units)
{
}

unsigned char MotorDetailsData::getNumberOfUnits() const
{
	return motorDetailsUnits_.length();
}

I_MotorDetailsUnit& MotorDetailsData::getMotorDetailsUnit(const unsigned char& index) const
{
    return *motorDetailsUnits_[static_cast<int>(index)];
}
