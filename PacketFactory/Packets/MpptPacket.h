#ifndef MPPTPACKET_H
#define MPPTPACKET_H

#include "IPacket.h"

class MpptPacket : public IPacket {
public:
    MpptPacket();
    void populatePacket(const QByteArray& data) override;
    QJsonObject toJson() override;

private:
    //assign packet fields here
};

#endif // MPPTPACKET_H
