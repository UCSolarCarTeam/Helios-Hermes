#include "MotorDetailsPacket.h"

MotorDetailsPacket::MotorDetailsPacket() {}

void MotorDetailsPacket::populatePacket(const QByteArray& data) {
    //assign packet fields here
}

QJsonObject MotorDetailsPacket::toJson() {
    QJsonObject json;
    //convert packet fields to json here
    return json;
}
