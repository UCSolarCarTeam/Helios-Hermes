#include "CmuData.h"

CmuData::CmuData(const unsigned char& numberOfCmus)
    : cmuUnits_(new CmuUnit[numberOfCmus])
{
}

I_CmuUnit& CmuData::getCmuUnit(const unsigned char& index)
{
    return cmuUnits_[static_cast<int>(index)];
}
