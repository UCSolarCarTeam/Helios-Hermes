#include "B3Populator.h"

B3Populator::B3Populator(I_PacketDecoder& packetDecoder, B3Data& data)
    : packetDecoder_(packetDecoder), data_(data) {
    connect(&packetDecoder_, SIGNAL(packetDecoded(B3Message)), this, SLOT(populateData(B3Message)));
}

void B3Populator::populateData(const B3Message message){
    data_.setLightInputs(message.lightInputs());
    data_.setDriverInputs(message.driverInputs());
    data_.setAcceleration(message.acceleration());
    data_.setRegenBraking(message.regenBraking());
    data_.setLightsOutputs(message.lightOutputs());
}
