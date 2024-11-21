#include "PiPacket.h"
#include <QDebug>


void PiPacket::populatePacket(const QByteArray& data) {
    wiegandData_ =
}

QByteArray PiPacket::getData() const {
    return wiegandData_;
}

qlonglong PiPacket::getDataAsLongLong() const {
    return wiegandData_.toLongLong();
}

// Set new Wiegand data
void PiPacket::setData(const QByteArray& data) {
    wiegandData_ = data;
}

void PiPacket::clearData() {
    wiegandData_.clear();
}
