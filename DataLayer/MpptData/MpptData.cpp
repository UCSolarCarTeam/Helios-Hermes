#include "MpptData.h"

MpptData::MpptData(const unsigned char& numberOfMppts)
: mpptUnits_(new I_MpptUnit[numberOfMppts])
{
    for (unsigned char i = 0; i < numberOfMppts; i++)
    {
        mpptUnits_[i] = new MpptUnit(i);
    }
}

I_MpptUnit& MpptData::getMpptUnit(const unsigned char& index)
{
    return mpptUnits_[static_cast<int>(index)];
}
