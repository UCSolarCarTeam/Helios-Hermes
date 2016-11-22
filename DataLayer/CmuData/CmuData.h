#pragma once

#include <QScopedArrayPointer>

#include "I_CmuUnit.h"

class CmuData: I_CmuData
{
public:
    CmuData(const unsigned char& numberOfCmus);

    I_CmuUnit& getCmuUnit(const unsigned char& index);

private: 
    QScopedArrayPointer<I_CmuUnit> cmuUnits_;
}
