#include "MpptPopulator.h"

MpptPopulator::MpptPopulator(I_PacketDecoder& packetDecoder, MpptData& data)
    : packetDecoder_(packetDecoder), data_(data) {
    connect(&packetDecoder_, SIGNAL(packetDecoded(MpptMessage)), this, SLOT(populateData(MpptMessage)));
}

void MpptPopulator::populateData(const MpptMessage message){
    MpptUnit& mpptUnit = data_.getMpptUnit(message.mpptNumber());
    mpptUnit.setMpptStatus(message.mpptStatus());
    mpptUnit.setArrayVoltage(message.arrayVoltage());
    mpptUnit.setArrayCurrent(message.arrayCurrent());
    mpptUnit.setBatteryVoltage(message.batteryVoltage());
    mpptUnit.setTemperature(message.temperature());
}
