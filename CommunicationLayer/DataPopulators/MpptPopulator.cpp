#include "MpptPopulator.h"

MpptPopulator::MpptPopulator(I_PacketDecoder& packetDecoder, I_MpptData& mpptData)
: packetDecoder_(packetDecoder)
, mpptData_(mpptData)
{
    connect(&packetDecoder_, SIGNAL(packetDecoded(const MpptMessage)), this, SLOT(populateData(const MpptMessage)));
}

void MpptPopulator::populateData(const MpptMessage message)
{
    I_MpptUnit& mpptUnit = mpptData_.getMpptUnit(message.mpptStatus());
    mpptUnit.setArrayVoltage(message.arrayVoltage());
    mpptUnit.setArrayCurrent(message.arrayCurrent());
    mpptUnit.setBatteryVoltage(message.batteryVoltage());
    mpptUnit.setTemperature(message.temperature());
}
