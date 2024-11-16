#ifndef PROXIMITYSENSORSPACKET_H
#define PROXIMITYSENSORSPACKET_H

#include "IPacket.h"

class ProximitySensorsPacket : public IPacket {
public:
    ProximitySensorsPacket();
    void populatePacket(const QByteArray& data) override;
    QJsonObject toJson() override;

private:
    //assign packet fields here
};

#endif // PROXIMITYSENSORSPACKET_H
