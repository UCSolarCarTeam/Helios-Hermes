#pragma once

#include "I_LightsData.h"

class LightsData : public I_LightsData 
{
public:
    LightsData();
    virtual ~LightsData();

    /* LightsData Gets */
    unsigned char getLightStatus() const;

    /* LightsData Sets */
    void setLightStatus(const unsigned char&);

private:
    unsigned char lightStatus_;
};
