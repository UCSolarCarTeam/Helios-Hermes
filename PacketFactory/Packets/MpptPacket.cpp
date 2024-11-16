#include "MpptPacket.h"

MpptPacket::MpptPacket() {}

void MpptPacket::populatePacket(const QByteArray& data) {
    //assign packet fields here
}

QJsonObject MpptPacket::toJson() {
    QJsonObject json;
    //convert packet fields to json here
    return json;
}
