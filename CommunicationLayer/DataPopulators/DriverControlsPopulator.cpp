#include "DriverControlsPopulator.h"

DriverControlsPopulator::DriverControlsPopulator(I_PacketDecoder& packetDecoder, I_DriverControlsData& driverControlsData)
    : packetDecoder_(packetDecoder)
    , driverControlsData_(driverControlsData)
{
    connect(&packetDecoder_, SIGNAL(packetDecoded(const DriverControlsMessage)), this, SLOT(populateData(const DriverControlsMessage)));
}

void DriverControlsPopulator::populateData(const DriverControlsMessage message)
{
    driverControlsData_.setDriverControlsBoardAlive(message.driverControlsBoardAlive());
    driverControlsData_.setLightsInputs(message.lightsInputs());
    driverControlsData_.setMusicInputs(message.musicInputs());
    driverControlsData_.setAcceleration(message.acceleration());
    driverControlsData_.setRegenBraking(message.regenBraking());
    driverControlsData_.setDriverInputs(message.driverInputs());
}
