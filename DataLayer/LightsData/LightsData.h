#pragma once

#include "I_LightsData.h"

class LightsData : public I_LightsData
{
public:
    LightsData();
    virtual ~LightsData();

    /* LightsData Gets */
    bool getLowBeams() const;
    bool getHighBeams() const;
    bool getBrakes() const;
    bool getLeftSignal() const;
    bool getRightSignal() const;
    bool getBmsStrobeLight() const;


    /* LightsData Sets */
    void setLightStatus(const unsigned char&);

private:
    unsigned char lightStatus_;
};
