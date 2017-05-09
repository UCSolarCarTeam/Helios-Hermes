#pragma once

#include "I_LightsData.h"

class FakeLightsData : public I_LightsData
{
public:
    FakeLightsData();
    virtual ~FakeLightsData();

    /* LightsData Gets */
    bool getAlive() const;
    unsigned char getLightStatus() const;

    /* LightsData Sets */
    void setAlive(const bool&);
    void setLightStatus(const unsigned char&);
}
