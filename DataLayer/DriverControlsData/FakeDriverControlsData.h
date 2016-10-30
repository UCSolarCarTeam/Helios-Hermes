#pragma once

#include "I_DriverControlsData.h"

class FakeDriverControlsData : public I_DriverControlsData
{
public:
    FakeDriverControlsData();
    ~FakeDriverControlsData();

    /*Data "Gets"*/
    unsigned char getDriverControlsBoardAlive() const;
    unsigned char getLightsInputs() const;
    unsigned char getMusicInputs() const;
    unsigned short getAcceleration() const;
    unsigned short getRegenBraking() const;
    unsigned char getDriverInputs() const;

    /*DriverControlsData "Sets"*/
    void setDriverControlsBoardAlive(const unsigned char driverControlsBoardAlive);
    void setLightsInputs(const unsigned char lightsInputs);
    void setMusicInputs(const unsigned char musicInputs);
    void setAcceleration(const unsigned short acceleration);
    void setRegenBraking(const unsigned short regenBraking);
    void setDriverInputs(const unsigned char driverInputs);
}