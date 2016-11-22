#include "CmuData.h"

CmuData::CmuData(const unsigned char& numberOfCmus)
: cmuUnits_(new I_CmuUnit[numberOfCmus])
{
    for (unsigned char i = 0; i < numberOfCmus; i++) 
    {
        cmuUnits_[i] = new CmuUnit(i);
    }
}

I_CmuUnit& CmuData::getCmuUnit(const unsigned char& index) {
    return cmuUnits_[static_cast<int>(index)];
}