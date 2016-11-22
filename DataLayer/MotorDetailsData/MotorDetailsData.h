#pragma once

#include <QScopedArrayPointer>

#include "I_MotorDetailsUnit.h"

class MotorDetailsData: I_MotorDetailsData
{
public:
    MotorDetailsData(const unsigned char& numberOfMotors);

    I_MotorDetailsUnit& getMotorDetailsUnit(const unsigned char& index);

private:
    QScopedArrayPointer<I_MotorDetailsUnit> motorDetailsUnits_;
}