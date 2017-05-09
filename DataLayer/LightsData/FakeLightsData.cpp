#include "FakeLightsData.h"

FakeLightsData::FakeLightsData()
{
}

FakeLightsData::~FakeLightsData()
{
}


/* LightsData Gets */
bool FakeLightsData::getAlive() const
{
    return true;
}

unsigned char FakeLightsData::getLightStatus() const
{
    return 1;
}

/* LightsData Sets */
void FakeLightsData::setAlive(const bool&) {}

void FakeLightsData::setLightStatus(const unsigned char& lightStatus) {}
