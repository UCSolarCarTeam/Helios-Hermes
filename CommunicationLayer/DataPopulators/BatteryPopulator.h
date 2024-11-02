#ifndef BATTERYPOPULATOR_H
#define BATTERYPOPULATOR_H

#include <QObject>
#include "../../CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "../../DataLayer/BatteryData/BatteryData.h"

class BatteryPopulator : public QObject {
    Q_OBJECT
public:
    BatteryPopulator(I_PacketDecoder& packetDecoder, BatteryData& data);

public slots:
    void populateData(const BatteryMessage);

private:
    I_PacketDecoder& packetDecoder_;
    BatteryData& data_;
};

#endif // BATTERYPOPULATOR_H
