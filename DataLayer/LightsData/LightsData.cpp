#include "LightsData.h"

LightsData::LightsData()
    : lightStatus_(0)
{
//    Initialize to 0
}

LightsData::~LightsData()
{
}

/* LightsData Gets */
unsigned char LightsData::getLightStatus() const
{
    return lightStatus_;
}

/* LightsData Sets */
void LightsData::setLightStatus(const unsigned char& lightStatus)
{
    lightStatus_ = lightStatus;
    emit lightStatusReceived(lightStatus_);
}
