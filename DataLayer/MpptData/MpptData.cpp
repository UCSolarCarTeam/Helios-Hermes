#include "MpptData.h"

MpptData::MpptData(QList<I_MpptUnit*> units)
    : mpptUnits_(units)
{
}

unsigned char MpptData::getNumberOfUnits() const
{
    return mpptUnits_.length();
}


I_MpptUnit& MpptData::getMpptUnit(const unsigned char& index) const
{
    return *mpptUnits_[static_cast<int>(index)];
}
