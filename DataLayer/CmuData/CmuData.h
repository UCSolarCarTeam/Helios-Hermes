#pragma once

#include <QList>

#include "I_CmuUnit.h"

class CmuData: I_CmuData
{
public:
    CmuData(const unsigned char& numberOfCells);

    I_CmuUnit getCmuUnit(const unsigned char& index);

private: 
    QList<I_CmuUnit*> cmuUnits_;
}
