#pragma once
#include "I_MotorDetailsUnit.h"

#include <QObject>

class I_MotorDetailsData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_MotorDetailsData() {}

    /* MotorDetailsData gets */
    virtual unsigned char getNumberOfUnits() const = 0;
    virtual I_MotorDetailsUnit& getMotorDetailsUnit(const unsigned char& index) const = 0;
};
