#include "KeyMotorPopulator.h"

KeyMotorPopulator::KeyMotorPopulator(I_PacketDecoder& packetDecoder, KeyMotorData& data)
    : packetDecoder_(packetDecoder), data_(data) {
    connect(&packetDecoder_, SIGNAL(packetDecoded(KeyMotorMessage)), this, SLOT(populatorData(KeyMotorMessage)));
}

void KeyMotorPopulator::populatorData(const KeyMotorMessage message){
    data_.setMotorSetpoint(message.motorSetpoint());
    data_.setControlBits(message.controlBits());
}
