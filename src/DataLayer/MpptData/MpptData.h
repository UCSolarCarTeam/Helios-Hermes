#pragma once

#include <QScopedArrayPointer>

#include "MpptUnit.h"
#include "I_MpptData.h"

class MpptData: public I_MpptData
{
public:
    MpptData(QList<I_MpptUnit*> units);
    unsigned char getNumberOfUnits() const;
    I_MpptUnit& getMpptUnit(const unsigned char& index) const;

private:
    QList<I_MpptUnit*> mpptUnits_;
};
