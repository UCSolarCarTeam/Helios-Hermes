#ifndef MBMSPACKET_H
#define MBMSPACKET_H

#include "IPacket.h"

class MbmsPacket : public IPacket {
public:
    MbmsPacket();
    void populatePacket(const QByteArray& data) override;
    QJsonObject toJson() override;

private:
    //assign packet fields here
};

#endif // MBMSPACKET_H
