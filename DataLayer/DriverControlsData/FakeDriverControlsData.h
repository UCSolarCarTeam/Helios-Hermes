#pragma once

#include "I_DriverControlsData.h"

class FakeDriverControlsData : public I_DriverControlsData
{
public:
    FakeDriverControlsData();
    virtual ~FakeDriverControlsData();

    /*Data "Gets"*/
    bool getDriverControlsBoardAlive() const;
    bool getHeadlightsOff() const;
    bool getHeadlightsLow() const;
    bool getHeadlightsHigh() const;
    bool getSignalRight() const;
    bool getSignalLeft() const;
    bool getHazard() const;
    bool getInterior() const;
    bool getVolumeUp() const;
    bool getVolumeDown() const;
    bool getNextSong() const;
    bool getPreviousSong() const;
    bool getBrakes() const;
    bool getForward() const;
    bool getReverse() const;
    bool getPushToTalk() const;
    bool getHorn() const;
    bool getReset() const;
    bool getAux() const;
    unsigned short getAcceleration() const;
    unsigned short getRegenBraking() const;

    /*DriverControlsData "Sets"*/
    void setDriverControlsBoardAlive(const unsigned char driverControlsBoardAlive);
    void setLightsInputs(const unsigned char lightsInputs);
    void setMusicInputs(const unsigned char musicInputs);
    void setAcceleration(const unsigned short acceleration);
    void setRegenBraking(const unsigned short regenBraking);
    void setDriverInputs(const unsigned char driverInputs);
}