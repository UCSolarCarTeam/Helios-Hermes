#ifndef KEYMOTORPACKET_H
#define KEYMOTORPACKET_H

#include "IPacket.h"

class KeyMotorPacket : public IPacket {
public:
    KeyMotorPacket();
    void populatePacket(const QByteArray& data) override;
    QJsonObject toJson() override;

private:
    //assign packet fields here
};

#endif // KEYMOTORPACKET_H
