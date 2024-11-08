#ifndef PROXIMITYSENSORSPOPULATOR_H
#define PROXIMITYSENSORSPOPULATOR_H

#include <QObject>
#include "../../CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "../../DataLayer/ProximitySensorsData/ProximitySensorsData.h"

class ProximitySensorsPopulator : public QObject {
    Q_OBJECT
public:
    ProximitySensorsPopulator(I_PacketDecoder& packetDecoder, ProximitySensorsData& data);

public slots:
    void populateData(const ProximitySensorsMessage);

private:
    I_PacketDecoder& packetDecoder_;
    ProximitySensorsData& data_;
};

#endif // PROXIMITYSENSORSPOPULATOR_H
