#ifndef BATTERYFAULTSPOPULATOR_H
#define BATTERYFAULTSPOPULATOR_H

#include <QObject>
#include "../../CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "../../DataLayer/BatteryFaultsData/BatteryFaultsData.h"

class BatteryFaultsPopulator : public QObject {
    Q_OBJECT
public:
    BatteryFaultsPopulator(I_PacketDecoder& packetDecoder, BatteryFaultsData& data);

public slots:
    void populateData(const BatteryFaultsMessage);

private:
    I_PacketDecoder& packetDecoder_;
    BatteryFaultsData& data_;
};

#endif // BATTERYFAULTSPOPULATOR_H
