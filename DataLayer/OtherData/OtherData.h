#pragma once

#include "I_OtherData.h"

class OtherData : public I_OtherData
{
public:
    OtherData();
    virtual ~OtherData();

    /* OtherData "Gets"*/
    unsigned char getGps() const;

    /*OtherData "Sets"*/
    void setGps(const unsigned char& gps);


private:
    unsigned char gps_;
};
