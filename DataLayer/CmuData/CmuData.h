#pragma once

#include <QScopedArrayPointer>

#include "CmuUnit.h"
#include "I_CmuData.h"

class CmuData: public I_CmuData
{
public:
    CmuData(const unsigned char& numberOfCmus);

    I_CmuUnit& getCmuUnit(const unsigned char& index);

private:
    QScopedArrayPointer<CmuUnit> cmuUnits_;
};
