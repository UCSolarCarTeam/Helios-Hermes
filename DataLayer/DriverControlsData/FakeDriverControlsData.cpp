#include "FakeDriverControlsData.h"

FakeDriverControlsData::FakeDriverControlsData()
{
}

FakeDriverControlsData::~FakeDriverControlsData()
{
}

/*Data "Gets"*/
unsigned char FakeDriverControlsData::getDriverControlsBoardAlive() const
{
    return 1;
}

unsigned char FakeDriverControlsData::getLightsInputs() const
{
    return 2;
}

unsigned char FakeDriverControlsData::getMusicInputs() const
{
    return 3;
}

unsigned short FakeDriverControlsData::getAcceleration() const
{
    return 4;
}

unsigned short FakeDriverControlsData::getRegenBraking() const
{
    return 5;
}

unsigned char FakeDriverControlsData::getDriverInputs() const
{
    return 6;
}


/*DriverControlsData "Sets"*/
void FakeDriverControlsData::setDriverControlsBoardAlive(const unsigned char driverControlsBoardAlive) {}
void FakeDriverControlsData::setLightsInputs(const unsigned char lightsInputs) {}
void FakeDriverControlsData::setMusicInputs(const unsigned char musicInputs) {}
void FakeDriverControlsData::setAcceleration(const unsigned short acceleration) {}
void FakeDriverControlsData::setRegenBraking(const unsigned short regenBraking) {}
void FakeDriverControlsData::setDriverInputs(const unsigned char driverInputs) {}
