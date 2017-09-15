#include "MpptData.h"

MpptData::MpptData(QList<I_MpptUnit*> units)
    : mpptUnits_(units)
{
}

I_MpptUnit& MpptData::getMpptUnit(const unsigned char& index)
{
    return *mpptUnits_[static_cast<int>(index)];
}
