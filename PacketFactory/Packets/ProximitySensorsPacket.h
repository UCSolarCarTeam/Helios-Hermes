#ifndef PROXIMITYSENSORSPACKET_H
#define PROXIMITYSENSORSPACKET_H

#include "IPacket.h"

class ProximitySensorsPacket : public IPacket {
public:
    ProximitySensorsPacket();
    void populatePacket(const QByteArray& data) override;
    QJsonObject toJson() override;

private:
    unsigned short proximitySensor1_;
    unsigned short proximitySensor2_;
    unsigned short proximitySensor3_;
    unsigned short proximitySensor4_;
};

#endif // PROXIMITYSENSORSPACKET_H
