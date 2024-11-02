#include "ProximitySensorsMessage.h"
#include "MessageDecodingUtils.h"

namespace {
    const int PROXIMITY_SENSOR_1_OFFSET = 1;
    const int PROXIMITY_SENSOR_2_OFFSET = 3;
    const int PROXIMITY_SENSOR_3_OFFSET = 5;
    const int PROXIMITY_SENSOR_4_OFFSET = 7;
}

ProximitySensorsMessage::ProximitySensorsMessage(const QByteArray& message) : message_(message) {}

unsigned short ProximitySensorsMessage::proximitySensor1() const {
    return MessageDecodingUtils::getUnsignedShort(message_, PROXIMITY_SENSOR_1_OFFSET);
}

unsigned short ProximitySensorsMessage::proximitySensor2() const {
    return MessageDecodingUtils::getUnsignedShort(message_, PROXIMITY_SENSOR_2_OFFSET);
}

unsigned short ProximitySensorsMessage::proximitySensor3() const {
    return MessageDecodingUtils::getUnsignedShort(message_, PROXIMITY_SENSOR_3_OFFSET);
}

unsigned short ProximitySensorsMessage::proximitySensor4() const {
    return MessageDecodingUtils::getUnsignedShort(message_, PROXIMITY_SENSOR_4_OFFSET);
}
