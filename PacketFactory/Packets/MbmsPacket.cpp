#include "MbmsPacket.h"

MbmsPacket::MbmsPacket() {}

void MbmsPacket::populatePacket(const QByteArray& data) {
    //assign packet fields here
}

QJsonObject MbmsPacket::toJson() {
    QJsonObject json;
    //convert packet fields to json here
    return json;
}
