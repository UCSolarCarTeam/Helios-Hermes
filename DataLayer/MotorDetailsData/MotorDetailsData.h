#pragma once

#include <QScopedArrayPointer>

#include "I_MotorDetailsData.h"
#include "MotorDetailsUnit.h"

class MotorDetailsData: public I_MotorDetailsData
{
public:
    MotorDetailsData(const unsigned char& numberOfMotors);

    I_MotorDetailsUnit& getMotorDetailsUnit(const unsigned char& index);

private:
    QScopedArrayPointer<MotorDetailsUnit> motorDetailsUnits_;
};
