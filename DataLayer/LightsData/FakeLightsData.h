#pragma once

#include "I_LightsData.h"

class FakeLightsData : public I_LightsData
{
public:
    FakeLightsData();
    virtual ~FakeLightsData();

    /* LightsData Gets */
    unsigned char getLightStatus() const;

    /* LightsData Sets */
    void setLightStatus(const unsigned char&);
}