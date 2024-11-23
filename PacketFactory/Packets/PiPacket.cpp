#include "PiPacket.h"
#include "../../Config/JsonDefinitions.h"
#include <QDebug>

PiPacket::PiPacket() {
    wiegandData_ = 0;
}

void PiPacket::populatePacket(const QByteArray& data) {
    wiegandData_ = data;  // Use the setter to store Wiegand data
    // qDebug() << "Populated packet with Wiegand data:" << data;
}

QJsonObject PiPacket::toJson() {
    QJsonObject json;

    json[JsonDefinitions::RFID] = getDataAsLongLong();

    return json;
}

QByteArray PiPacket::getData() const {
    return wiegandData_;
}

qlonglong PiPacket::getDataAsLongLong() const {
    return wiegandData_.toLongLong();
}
