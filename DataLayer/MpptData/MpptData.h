#pragma once

#include <QScopedArrayPointer>

#include "I_MpptUnit.h"

class MpptData: I_CmuData
{
public:
    MpptData(const unsigned char& numberOfMppts);

    I_MpptUnit& getMpptUnit(const unsigned char& index)

private:
    QScopedArrayPointer<I_MpptUnit> mpptUnits_;
}
