#ifndef BATTERYFAULTSPACKET_H
#define BATTERYFAULTSPACKET_H

#include "IPacket.h"

class BatteryFaultsPacket : public IPacket {
public:
    BatteryFaultsPacket();
    void populatePacket(const QByteArray& data) override;
    QJsonObject toJson() override;

private:
    //assign packet fields here
};

#endif // BATTERYFAULTSPACKET_H
