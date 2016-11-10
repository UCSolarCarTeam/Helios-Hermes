#include "CmuData.h"

CmuData::CmuData(const unsigned char& numberOfCells)
{
    for (unsigned char i = 0; i < numberOfCells; i++) {
        cmuUnits_.append(&CmuUnit(i));
    }
}

I_CmuUnit* CmuData::getCmuUnit(const unsigned char& index) {
    return cmuUnits_.at(static_cast<int>(index));
}