#ifndef MOTORDETAILSPACKET_H
#define MOTORDETAILSPACKET_H

#include "IPacket.h"

class MotorDetailsPacket : public IPacket {
public:
    MotorDetailsPacket();
    void populatePacket(const QByteArray& data) override;
    QJsonObject toJson() override;

private:
    //assign packet fields here
};

#endif // MOTORDETAILSPACKET_H
