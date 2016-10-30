#include "FakeLightsData.h"

FakeLightsData::FakeLightsData()
{
}

FakeLightsData::~FakeLightsData()
{
}


/* LightsData Gets */
unsigned char FakeLightsData::getLightStatus() const
{
    return 1;
}

/* LightsData Sets */
void FakeLightsData::setLightStatus(const unsigned char& lightStatus) {}
