#include "CmuData.h"

CmuData::CmuData(const unsigned char& numberOfCmus)
    : cmuUnits_(new CmuUnit[numberOfCmus])
{
}

CmuData::~CmuData()
{
}

I_CmuUnit& CmuData::getCmuUnit(const unsigned char& index)
{
    return cmuUnits_[index];
}
