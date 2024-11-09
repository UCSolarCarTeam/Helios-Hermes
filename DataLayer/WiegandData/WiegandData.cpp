#include "WiegandData.h"
#include <QDebug>

// Retrieve the stored Wiegand data
QByteArray WiegandData::getData() const {
    return wiegandData_;
}

qlonglong WiegandData::getDataAsLongLong() const {
    return wiegandData_.toLongLong();
}

// Set new Wiegand data
void WiegandData::setData(const QByteArray& data) {
    wiegandData_ = data;
}

void WiegandData::clearData() {
    wiegandData_.clear();  // Assuming data_ is a QByteArray or similar type
}
