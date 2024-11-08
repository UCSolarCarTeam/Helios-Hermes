#include "BatteryFaultsPopulator.h"

BatteryFaultsPopulator::BatteryFaultsPopulator(I_PacketDecoder& packetDecoder, BatteryFaultsData& data)
    : packetDecoder_(packetDecoder), data_(data) {
    connect(&packetDecoder_, SIGNAL(packetDecoded(BatteryFaultsMessage)), this, SLOT(populateData(BatteryFaultsMessage)));
}

void BatteryFaultsPopulator::populateData(const BatteryFaultsMessage message){
    data_.setErrorFlags(message.errorFlags());
    data_.setLimitFlags(message.limitFlags());
}
