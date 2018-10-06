#include "FakeDriverControlsData.h"

FakeDriverControlsData::FakeDriverControlsData()
{
}

FakeDriverControlsData::~FakeDriverControlsData()
{
}

/*Data "Gets"*/
bool FakeDriverControlsData::getDriverControlsBoardAlive() const
{
    return true;
}

bool FakeDriverControlsData::getHeadlightsOff() const
{
    return true;
}

bool FakeDriverControlsData::getHeadlightsLow() const
{
    return true;
}

bool FakeDriverControlsData::getHeadlightsHigh() const
{
    return true;
}

bool FakeDriverControlsData::getSignalRight() const
{
    return true;
}

bool FakeDriverControlsData::getSignalLeft() const
{
    return true;
}

bool FakeDriverControlsData::getHazard() const
{
    return true;
}

bool FakeDriverControlsData::getInterior() const
{
    return true;
}

bool FakeDriverControlsData::getAux() const
{
    return true;
}

bool FakeDriverControlsData::getVolumeUp() const
{
    return true;
}

bool FakeDriverControlsData::getVolumeDown() const
{
    return true;
}

bool FakeDriverControlsData::getNextSong() const
{
    return true;
}

bool FakeDriverControlsData::getPreviousSong() const
{
    return true;
}

bool FakeDriverControlsData::getBrakes() const
{
    return true;
}

bool FakeDriverControlsData::getForward() const
{
    return true;
}

bool FakeDriverControlsData::getReverse() const
{
    return true;
}

bool FakeDriverControlsData::getPushToTalk() const
{
    return true;
}

bool FakeDriverControlsData::getHorn() const
{
    return true;
}

bool FakeDriverControlsData::getReset() const
{
    return true;
}

unsigned short FakeDriverControlsData::getAcceleration() const
{
    return 4;
}

unsigned short FakeDriverControlsData::getRegenBraking() const
{
    return 5;
}


/*DriverControlsData "Sets"*/
void FakeDriverControlsData::setDriverControlsBoardAlive(const unsigned char driverControlsBoardAlive) {}
void FakeDriverControlsData::setLightsInputs(const unsigned char lightsInputs) {}
void FakeDriverControlsData::setMusicInputs(const unsigned char musicInputs) {}
void FakeDriverControlsData::setAcceleration(const unsigned short acceleration) {}
void FakeDriverControlsData::setRegenBraking(const unsigned short regenBraking) {}
void FakeDriverControlsData::setDriverInputs(const unsigned char driverInputs) {}
