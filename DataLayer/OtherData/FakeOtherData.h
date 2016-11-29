#pragma once

#include "I_OtherData.h"

class FakeOtherData : public I_OtherData
{
public:
    FakeOtherData();
    virtual ~FakeOtherData();

    /* OtherData "Gets"*/
    unsigned char getGps() const;

    /*OtherData "Sets"*/
    void setGps(const unsigned char& gps);
}