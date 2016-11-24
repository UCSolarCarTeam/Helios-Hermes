#include "BatteryFaultsPopulator.h"

BatteryFaultsPopulator::BatteryFaultsPopulator(I_PacketDecoder& packetDecoder, I_BatteryFaultsData& batteryFaultsData)
: packetDecoder_(packetDecoder)
, batteryFaultsData_(batteryFaultsData)
{
    connect(&packetDecoder&, SIGNAL(packetDecoded(const BatteryFaultsMessage)), this, SLOT(populateData(const BatteryFaultsMessage)));
}

void BatteryFaultsPopulator::populateData(const BatteryFaultsMessage)
{
    batteryFaultsData_.setErrorFlag(message.errorFlag());
}
