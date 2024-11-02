#include "TelemetryMessage.h"
#include "MessageDecodingUtils.h"

namespace {
    const int GPS_YEAR_OFFSET = 1;
    const int GPS_MONTH_OFFSET = 3;
    const int GPS_DAY_OFFSET = 4;
    const int GPS_HOUR_OFFSET = 5;
    const int GPS_MINUTE_OFFSET = 6;
    const int GPS_SECOND_OFFSET = 7;
    const int GPS_VALIDITY_FLAGS_OFFSET = 8;
    const int GPS_FIX_STATUS_FLAGS_OFFSET = 9;
    const int GPS_ADDITIONAL_FLAGS_OFFSET = 10;
    const int GPS_LONGITUDE_OFFSET = 11;
    const int GPS_LATITUDE_OFFSET = 15;
    const int MPU_ACCELERATION_X_OFFSET = 19;
    const int MPU_ACCELERATION_Y_OFFSET = 21;
    const int MPU_ACCELERATION_Z_OFFSET = 23;
    const int MPU_ROTATION_X_OFFSET = 25;
    const int MPU_ROTATION_Y_OFFSET = 27;
    const int MPU_ROTATION_Z_OFFSET = 29;
    const int MPU_TEMPERATURE_OFFSET = 31;
}

TelemetryMessage::TelemetryMessage(const QByteArray& message) : message_(message) {}

unsigned short TelemetryMessage::gpsYear() const {
    return MessageDecodingUtils::getUnsignedShort(message_, GPS_YEAR_OFFSET);
}

unsigned char TelemetryMessage::gpsMonth() const {
    return MessageDecodingUtils::getUnsignedChar(message_, GPS_MONTH_OFFSET);
}

unsigned char TelemetryMessage::gpsDay() const {
    return MessageDecodingUtils::getUnsignedChar(message_, GPS_DAY_OFFSET);
}

unsigned char TelemetryMessage::gpsHour() const {
    return MessageDecodingUtils::getUnsignedChar(message_, GPS_HOUR_OFFSET);
}

unsigned char TelemetryMessage::gpsMinute() const {
    return MessageDecodingUtils::getUnsignedChar(message_, GPS_MINUTE_OFFSET);
}

unsigned char TelemetryMessage::gpsSecond() const {
    return MessageDecodingUtils::getUnsignedChar(message_, GPS_SECOND_OFFSET);
}

unsigned char TelemetryMessage::gpsValidityFlags() const {
    return MessageDecodingUtils::getUnsignedChar(message_, GPS_VALIDITY_FLAGS_OFFSET);
}

unsigned char TelemetryMessage::gpsFixStatusFlags() const {
    return MessageDecodingUtils::getUnsignedChar(message_, GPS_FIX_STATUS_FLAGS_OFFSET);
}

unsigned char TelemetryMessage::gpsAdditionalFlags() const {
    return MessageDecodingUtils::getUnsignedChar(message_, GPS_ADDITIONAL_FLAGS_OFFSET);
}

int TelemetryMessage::gpsLongitude() const {
    return MessageDecodingUtils::getUnsignedInt(message_, GPS_LONGITUDE_OFFSET);
}

int TelemetryMessage::gpsLatitude() const {
    return MessageDecodingUtils::getUnsignedInt(message_, GPS_LATITUDE_OFFSET);
}

unsigned short TelemetryMessage::mpuAccelerationX() const {
    return MessageDecodingUtils::getUnsignedShort(message_, MPU_ACCELERATION_X_OFFSET);
}

unsigned short TelemetryMessage::mpuAccelerationY() const {
    return MessageDecodingUtils::getUnsignedShort(message_, MPU_ACCELERATION_Y_OFFSET);
}

unsigned short TelemetryMessage::mpuAccelerationZ() const {
    return MessageDecodingUtils::getUnsignedShort(message_, MPU_ACCELERATION_Z_OFFSET);
}

unsigned short TelemetryMessage::mpuRotationX() const {
    return MessageDecodingUtils::getUnsignedShort(message_, MPU_ROTATION_X_OFFSET);
}

unsigned short TelemetryMessage::mpuRotationY() const {
    return MessageDecodingUtils::getUnsignedShort(message_, MPU_ROTATION_Y_OFFSET);
}

unsigned short TelemetryMessage::mpuRotationZ() const {
    return MessageDecodingUtils::getUnsignedShort(message_, MPU_ROTATION_Z_OFFSET);
}

unsigned short TelemetryMessage::mpuTemperature() const {
    return MessageDecodingUtils::getUnsignedShort(message_, MPU_TEMPERATURE_OFFSET);
}