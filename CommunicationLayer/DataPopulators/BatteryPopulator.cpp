#include "BatteryPopulator.h"

BatteryPopulator::BatteryPopulator(I_PacketDecoder& packetDecoder, I_BatteryData& batteryData)
: packetDecoder_(packetDecoder)
, batteryData_(batteryData)
{
    connect(&packetDecoder_, SIGNAL(packetDecoded(const BatteryMessage)), this, SLOT(populateData(const BatteryMessage)));
}

void BatteryPopulator::populateData(const BatteryMessage message)
{
    batteryData_.setAlive(message.alive());
    batteryData_.setPackSocAmpHours(message.packSocAmpHours());
    batteryData_.setPackSocPercentage(message.packSocPercentage());
    batteryData_.setPackBalanceSoc(message.packBalanceSoc());
    batteryData_.setPackBalanceSocPercentage(message.packBalanceSocPercentage());
    batteryData_.setChargingCellVoltageError(message.chargingCellVoltageError());
    batteryData_.setCellTemperatureMargin(message.cellTemperatureMargin());
    batteryData_.setDischargingCellVoltageError(message.dischargingCellVoltageError());
    batteryData_.setTotalPackCapacity(message.totalPackCapacity());
    batteryData_.setPrechargeContactorDriverStatus(message.prechargeContactorDriverStatus());
    batteryData_.setPrechargeState(message.prechargeState());
    batteryData_.setPrechargeTimerElapsed(message.prechargeTimerElapsed());
    batteryData_.setPrechargeTimerCount(message.prechargeTimerCount());
    batteryData_.setLowestCellVoltage(message.lowestCellVoltage());
    batteryData_.setLowestCellVoltageNumber(message.lowestCellVoltageNumber());
    batteryData_.setHighestCellVoltage(message.highestCellVoltage());
    batteryData_.setHighestCellVoltageNumber(message.highestCellVoltageNumber());
    batteryData_.setLowestCellTemperature(message.lowestCellTemperature());
    batteryData_.setLowestCellTemperatureNumber(message.lowestCellTemperatureNumber());
    batteryData_.setHighestCellTemperature(message.highestCellTemperature());
    batteryData_.setHighestCellTemperatureNumber(message.highestCellTemperatureNumber());
    batteryData_.setVoltage(message.voltage());
    batteryData_.setCurrent(message.current());
    batteryData_.setFan0Speed(message.fan0Speed());
    batteryData_.setFan1Speed(message.fan1Speed());
    batteryData_.setFanContactors12VCurrentConsumption(message.fanContactors12VCurrentConsumption());
    batteryData_.setCmu12VCurrentConsumption(message.cmu12VCurrentConsumption());
    batteryData_.setBmsCanLockedOut(message.bmsCanLockedOut());
}
