#include "TelemetryPacket.h"

TelemetryPacket::TelemetryPacket() {}

void TelemetryPacket::populatePacket(const QByteArray& data) {
    //assign packet fields here
}

QJsonObject TelemetryPacket::toJson() {
    QJsonObject json;
    //convert packet fields to json here
    return json;
}
