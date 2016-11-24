#pragma once

#include <QObject>
#include "CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "DataLayer/BatteryFaultsData/I_BatteryFaultsData.h"

class BatteryFaultsPopulator : public QObject
{
    Q_OBJECT
public:
    BatteryFaultsPopulator(I_PacketDecoder& packetDecoder,
                     I_BatteryFaultsData& batteryFaultsData);
public slots:
    void populateData(const BatteryFaultsMessage);

private:
    I_PacketDecoder& packetDecoder_;
    I_BatteryFaultsData& batteryFaultsData_;
};
