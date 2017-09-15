#pragma once

#include <QScopedArrayPointer>

#include "I_MotorDetailsData.h"
#include "MotorDetailsUnit.h"

class MotorDetailsData : public I_MotorDetailsData
{
public:
    MotorDetailsData(QList<I_MotorDetailsUnit*> units);
    I_MotorDetailsUnit& getMotorDetailsUnit(const unsigned char& index);

private:
    QList<I_MotorDetailsUnit*> motorDetailsUnits_;
};
