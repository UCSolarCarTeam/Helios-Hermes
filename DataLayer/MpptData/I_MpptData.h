#pragma once

#include <QObject>
#include "I_MpptUnit.h"

class I_MpptData : public QObject
{
    Q_OBJECT
public:
    virtual ~I_MpptData() {}

    /* MpptData gets */
    virtual unsigned char getNumberOfUnits() const = 0;
    virtual I_MpptUnit& getMpptUnit(const unsigned char& index) const = 0;
};
