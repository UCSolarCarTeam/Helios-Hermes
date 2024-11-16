#include "BatteryFaultsPacket.h"

BatteryFaultsPacket::BatteryFaultsPacket() {}

void BatteryFaultsPacket::populatePacket(const QByteArray& data) {
    //assign packet fields here
}

QJsonObject BatteryFaultsPacket::toJson() {
    QJsonObject json;
    //convert packet fields to json here
    return json;
}
