#include "BatteryPacket.h"

BatteryPacket::BatteryPacket() {}

void BatteryPacket::populatePacket(const QByteArray& data) {
    //assign packet fields here
}

QJsonObject BatteryPacket::toJson() {
    QJsonObject json;
    //convert packet fields to json here
    return json;
}
