#include "KeyMotorPopulator.h"

KeyMotorPopulator::KeyMotorPopulator(I_PacketDecoder& packetDecoder, I_KeyMotorData& keyMotorData)
    : packetDecoder_(packetDecoder)
    , keyMotorData_(keyMotorData)
{
    connect(&packetDecoder_, SIGNAL(packetDecoded(const KeyMotorMessage)), this, SLOT(populateData(const KeyMotorMessage)));
}

void KeyMotorPopulator::populateData(const KeyMotorMessage message)
{
    keyMotorData_.setM0Alive(message.m0Alive());
    keyMotorData_.setM0SetCurrent(message.m0SetCurrent());
    keyMotorData_.setM0SetVelocity(message.m0SetVelocity());
    keyMotorData_.setM0BusCurrent(message.m0BusCurrent());
    keyMotorData_.setM0BusVoltage(message.m0BusVoltage());
    keyMotorData_.setM0VehicleVelocity(message.m0VehicleVelocity());
    keyMotorData_.setM1Alive(message.m1Alive());
    keyMotorData_.setM1SetCurrent(message.m1SetCurrent());
    keyMotorData_.setM1SetVelocity(message.m1SetVelocity());
    keyMotorData_.setM1BusCurrent(message.m1BusCurrent());
    keyMotorData_.setM1BusVoltage(message.m1BusVoltage());
    keyMotorData_.setM1VehicleVelocity(message.m1VehicleVelocity());
}
