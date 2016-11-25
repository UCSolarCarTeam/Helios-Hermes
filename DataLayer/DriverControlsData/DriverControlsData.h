#pragma once

#include "I_DriverControlsData.h"

class DriverControlsData : public I_DriverControlsData
{
public:
    DriverControlsData();
    virtual ~DriverControlsData();

    /*Data "Gets"*/
    unsigned char getDriverControlsBoardAlive() const;
    unsigned char getLightsInputs() const;
    unsigned char getMusicInputs() const;
    unsigned short getAcceleration() const;
    unsigned short getRegenBraking() const;
    unsigned char getDriverInputs() const;

    /*DriverControlsData "Sets"*/
    void setDriverControlsBoardAlive(const unsigned char& driverControlsBoardAlive);
    void setLightsInputs(const unsigned char& lightsInputs);
    void setMusicInputs(const unsigned char& musicInputs);
    void setAcceleration(const unsigned short& acceleration);
    void setRegenBraking(const unsigned short& regenBraking);
    void setDriverInputs(const unsigned char& driverInputs);

private:
    unsigned char driverControlsBoardAlive_;
    unsigned char lightsInputs_;
    unsigned char musicInputs_;
    unsigned short acceleration_;
    unsigned short regenBraking_;
    unsigned char driverInputs_;
};
