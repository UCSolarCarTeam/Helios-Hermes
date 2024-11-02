#include "BatteryFaultsMessage.h"
#include "MessageDecodingUtils.h"

namespace {
    const int ERROR_FLAGS_OFFSET = 1;
    const int LIMIT_FLAGS_OFFSET = 5;
}

BatteryFaultsMessage::BatteryFaultsMessage(const QByteArray& message) : message_(message) {}

unsigned int BatteryFaultsMessage::errorFlags() const {
    return MessageDecodingUtils::getUnsignedInt(message_, ERROR_FLAGS_OFFSET);
}

unsigned short BatteryFaultsMessage::limitFlags() const {
    return MessageDecodingUtils::getUnsignedShort(message_, LIMIT_FLAGS_OFFSET);
}
