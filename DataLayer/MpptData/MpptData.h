#pragma once

#include <QScopedArrayPointer>

#include "I_MpptUnit.h"
#include "I_MpptData.h"

class MpptData: public I_MpptData
{
public:
    MpptData(const unsigned char& numberOfMppts);

    I_MpptUnit& getMpptUnit(const unsigned char& index);

private:
    QScopedArrayPointer<I_MpptUnit> mpptUnits_;
};
