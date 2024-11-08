#include "MotorDetailsData.h"

MotorDetailsData::MotorDetailsData(QList<MotorDetailsUnit*> units) : motorDetailsUnits_(units) {}

unsigned char MotorDetailsData::getNumberOfUnits() const {
    return motorDetailsUnits_.size();
}

MotorDetailsUnit& MotorDetailsData::getMotorDetailsUnit(const unsigned char& index) const {
    return *motorDetailsUnits_[static_cast<int>(index)];
}
