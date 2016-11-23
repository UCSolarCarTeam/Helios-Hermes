#pragma once

#include "I_CmuUnit.h"

class FakeCmuUnit : public I_CmuUnit
{
public:
    FakeCmuUnit();
    virtual ~FakeCmuUnit();

    /* CmuUnit Gets */
    unsigned char getCmuNumber() const;
    short getCellVoltage(const int&) const;
    unsigned short getPcbTemp() const;
    unsigned short getCellTemp(const int&) const;

    /* CmuUnit Sets */
    void setCellVoltage(const int&, const short&);
    void setPcbTemp(const unsigned short&);
    void setCellTemp(const int&, const unsigned short&);
}