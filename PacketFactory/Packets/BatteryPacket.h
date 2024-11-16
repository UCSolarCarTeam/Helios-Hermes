#ifndef BATTERYPACKET_H
#define BATTERYPACKET_H

#include "IPacket.h"

class BatteryPacket : public IPacket {
public:
    BatteryPacket();
    void populatePacket(const QByteArray& data) override;
    QJsonObject toJson() override;

private:
    //assign packet fields here
};

#endif // BATTERYPACKET_H
