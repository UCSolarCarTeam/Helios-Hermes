#include "MotorFaultsPopulator.h"

MotorFaultsPopulator::MotorFaultsPopulator(I_PacketDecoder& packetDecoder, I_MotorFaultsData& motorFaultsData)
: packetDecoder_(packetDecoder)
, motorFaultsData_(motorFaultsData)
{
    connect(&packetDecoder_, SIGNAL(packetDecoded(const MotorFaultsMessage)), this, SLOT(populateData(const MotorFaultsMessage)));
}

void MotorFaultsPopulator::populateData(const MotorFaultsMessage message)
{
    motorFaultsData_.setM0ErrorFlags(message.M0ErrorFlags());
    motorFaultsData_.setM1ErrorFlags(message.M1ErrorFlags());
    motorFaultsData_.setM0LimitFlags(message.M0LimitFlags());
    motorFaultsData_.setM1LimitFlags(message.M1LimitFlags());
    motorFaultsData_.setM0CanRxErrorCount(message.M0CanRxErrorCount());
    motorFaultsData_.setM0CanTxErrorCount(message.M0CanTxErrorCount());
    motorFaultsData_.setM1CanRxErrorCount(message.M1CanRxErrorCount());
    motorFaultsData_.setM1CanTxErrorCount(message.M1CanTxErrorCount());
}
