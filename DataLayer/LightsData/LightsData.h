#pragma once

#include "I_LightsData.h"

class LightsData : public I_LightsData
{
public:
    LightsData();
    virtual ~LightsData();

    /* LightsData Gets */
    bool getAlive() const;
    bool getLowBeams() const;
    bool getHighBeams() const;
    bool getBrakes() const;
    bool getLeftSignal() const;
    bool getRightSignal() const;
    bool getBmsStrobeLight() const;


    /* LightsData Sets */
    void setAlive(const bool&);
    void setLightStatus(const unsigned char&);

private:
    bool alive_;
    unsigned char lightStatus_;
};
