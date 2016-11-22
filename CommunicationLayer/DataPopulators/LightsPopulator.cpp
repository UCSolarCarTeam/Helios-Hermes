#include "LightsPopulator.h"

LightsPopulator::LightsPopulator(I_PacketDecoder& packetDecoder, I_LightsData& lightsData)
: packetDecoder_(packetDecoder)
, lightsData(lightsData_)
{
    connect(&packetDecoder_, SIGNAL(packetDecoded(const LightsMessage)), this, SLOT(populateData(const LightsMessage)));
}

void LightsPopulator::populateData(const LightsMessage& message)
{
    lightsData_.setLightStatus(message.lightStatus());
}
