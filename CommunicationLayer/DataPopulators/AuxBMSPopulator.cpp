#include "AuxBMSPopulator.h"

AuxBMSPopulator::AuxBMSPopulator(I_PacketDecoder& packetDecoder, I_AuxBMSData& auxBmsData)
    : packetDecoder_(packetDecoder)
    , auxBmsData_(auxBmsData)
{
    connect(&packetDecoder_, SIGNAL(packetDecoded(const AuxBMSMessage)), this, SLOT(populateData(const AuxBMSMessage)));
}

void AuxBMSPopulator::populateData(const AuxBMSMessage message)
{
    auxBmsData_.setPrechargeState(message.prechargeState());
    auxBmsData_.setAuxVoltage(message.auxVoltage());
    auxBmsData_.setAuxBmsAlive(message.auxBmsAlive());
    auxBmsData_.setStrobeBmsLight(message.strobeBmsLight());
    auxBmsData_.setAllowCharge(message.allowCharge());
    auxBmsData_.setContactorError(message.contactorError());
}
