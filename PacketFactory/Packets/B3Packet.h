#ifndef B3PACKET_H
#define B3PACKET_H

#include "IPacket.h"

class B3Packet : public IPacket {
public:
    B3Packet();
    void populatePacket(const QByteArray& data) override;
    QJsonObject toJson() override;

private:
    //assign packet fields here
};

#endif // B3PACKET_H
