#include "MpptData.h"

MpptData::MpptData(const unsigned char& numberOfMppts)
    : mpptUnits_(new MpptUnit[numberOfMppts])
{
}

I_MpptUnit& MpptData::getMpptUnit(const unsigned char& index)
{
    return mpptUnits_[static_cast<int>(index)];
}
