#include "ProximitySensorsPacket.h"

ProximitySensorsPacket::ProximitySensorsPacket() {}

void ProximitySensorsPacket::populatePacket(const QByteArray& data) {
    //assign packet fields here
}

QJsonObject ProximitySensorsPacket::toJson() {
    QJsonObject json;
    //convert packet fields to json here
    return json;
}
