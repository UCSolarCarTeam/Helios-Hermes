#pragma once

#include <QScopedArrayPointer>

#include "I_CmuUnit.h"
#include "I_CmuData.h"

class CmuData: public I_CmuData
{
public:
    CmuData(const unsigned char& numberOfCmus);

    I_CmuUnit& getCmuUnit(const unsigned char& index);

private: 
    QScopedArrayPointer<I_CmuUnit> cmuUnits_;
};
