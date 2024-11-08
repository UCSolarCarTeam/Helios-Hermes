#include "MbmsPopulator.h"

MbmsPopulator::MbmsPopulator(I_PacketDecoder& packetDecoder, MbmsData& data)
    : packetDecoder_(packetDecoder), data_(data) {
    connect(&packetDecoder_, SIGNAL(packetDecoded(MbmsMessage)), this, SLOT(populateData(MbmsMessage)));
}

void MbmsPopulator::populateData(const MbmsMessage message){
    data_.setContactorStatus(message.contactorStatus());
    data_.setContactorErrors(message.contactorErrors());
    data_.setMiscellanousStatus(message.miscellanousStatus());
    data_.setAuxillaryBatteryVoltage(message.auxillaryBatteryVoltage());
    data_.setMotorVoltage(message.motorVoltage());
    data_.setArrayVoltage(message.arrayVoltage());
    data_.setLvVoltage(message.lvVoltage());
    data_.setChargeVoltage(message.chargeVoltage());
    data_.setCommonCurrent(message.commonCurrent());
    data_.setMotorCurrent(message.motorCurrent());
    data_.setArrayCurrent(message.arrayCurrent());
    data_.setLvCurrent(message.lvCurrent());
    data_.setChargeCurrent(message.chargeCurrent());
    data_.setTripStatuses(message.tripStatuses());
}
