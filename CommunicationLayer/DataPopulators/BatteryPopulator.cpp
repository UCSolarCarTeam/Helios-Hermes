#include "BatteryPopulator.h"

BatteryPopulator::BatteryPopulator(I_PacketDecoder& packetDecoder, BatteryData& data)
    : packetDecoder_(packetDecoder), data_(data) {
    connect(&packetDecoder_, SIGNAL(packetDecoded(BatteryMessage)), this, SLOT(populateData(BatteryMessage)));
}

void BatteryPopulator::populateData(const BatteryMessage message){
    data_.setBmuAlive(message.bmuAlive());
    data_.setBmsRelayStatus(message.bmsRelayStatus());
    data_.setPopulatedCells(message.populatedCells());
    data_.setInput12V(message.input12V());
    data_.setFanVoltage(message.fanVoltage());
    data_.setPackCurrent(message.packCurrent());
    data_.setPackVoltage(message.packVoltage());
    data_.setPackStateOfCharge(message.packStateOfCharge());
    data_.setPackAmphours(message.packAmphours());
    data_.setPackDepthOfDischarge(message.packDepthOfDischarge());
    data_.setHighTemperature(message.highTemperature());
    data_.setHighThermistorId(message.highThermistorId());
    data_.setLowTemperature(message.lowTemperature());
    data_.setLowThermistorId(message.lowThermistorId());
    data_.setAverageTemperature(message.averageTemperature());
    data_.setInternalTemperature(message.internalTemperature());
    data_.setFanSpeed(message.fanSpeed());
    data_.setRequestedFanSpeed(message.requestedFanSpeed());
    data_.setLowCellVoltage(message.lowCellVoltage());
    data_.setLowCellVoltageId(message.lowCellVoltageId());
    data_.setHighCellVoltage(message.highCellVoltage());
    data_.setHighCellVoltageId(message.highCellVoltageId());
    data_.setAverageCellVoltage(message.averageCellVoltage());
}
