#include "ProximitySensorsPopulator.h"

ProximitySensorsPopulator::ProximitySensorsPopulator(I_PacketDecoder& packetDecoder, ProximitySensorsData& data)
    : packetDecoder_(packetDecoder), data_(data) {
    connect(&packetDecoder_, SIGNAL(packetDecoded(ProximitySensorsMessage)), this, SLOT(populateData(ProximitySensorsMessage)));
}

void ProximitySensorsPopulator::populateData(const ProximitySensorsMessage message){
    data_.setProximitySensor1(message.proximitySensor1());
    data_.setProximitySensor2(message.proximitySensor2());
    data_.setProximitySensor3(message.proximitySensor3());
    data_.setProximitySensor4(message.proximitySensor4());
}
