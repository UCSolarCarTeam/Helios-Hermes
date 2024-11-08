#include "WiegandData.h"
#include <QDebug>

// Retrieve the stored Wiegand data
QByteArray WiegandData::getData() const {
    return wiegandData_;
}

// Set new Wiegand data
void WiegandData::setData(const QByteArray& data) {
    wiegandData_ = data;
}

// Extract a Wiegand ID
int WiegandData::getWiegandId() const {
    if (wiegandData_.isEmpty()) {
        qDebug() << "WiegandData: No data available.";
        return -1;  // Invalid ID
    }
    // Replace with real extraction logic
    return static_cast<int>(wiegandData_.at(0));
}
