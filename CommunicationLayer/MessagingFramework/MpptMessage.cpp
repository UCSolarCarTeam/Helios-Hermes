#include "MpptMessage.h"
#include "MessageDecodingUtils.h"

namespace {
    const int MPPT_STATUS_OFFSET = 1;
    const int ARRAY_VOLTAGE_OFFSET = 2;
    const int ARRAY_CURRENT_OFFSET = 4;
    const int BATTERY_VOLTAGE_OFFSET = 6;
    const int TEMPERATURE_OFFSET = 8;

    const unsigned char MPPT_NUMBER_MASK = 0x03;
    const unsigned char MPPT_STATUS_MASK = 0x80;
}

MpptMessage::MpptMessage(const QByteArray& message) : message_(message) {}

unsigned char MpptMessage::mpptStatus() const {
    return MessageDecodingUtils::getUnsignedChar(message_, MPPT_STATUS_OFFSET) & MPPT_STATUS_MASK;
}

unsigned char MpptMessage::mpptNumber() const {
    return MessageDecodingUtils::getUnsignedChar(message_, MPPT_STATUS_OFFSET) & MPPT_NUMBER_MASK;
}

unsigned short MpptMessage::arrayVoltage() const {
    return MessageDecodingUtils::getUnsignedShort(message_, ARRAY_VOLTAGE_OFFSET);
}

unsigned short MpptMessage::arrayCurrent() const {
    return MessageDecodingUtils::getUnsignedShort(message_, ARRAY_CURRENT_OFFSET);
}

unsigned short MpptMessage::batteryVoltage() const {
    return MessageDecodingUtils::getUnsignedShort(message_, BATTERY_VOLTAGE_OFFSET);
}

unsigned short MpptMessage::temperature() const {
    return MessageDecodingUtils::getUnsignedShort(message_, TEMPERATURE_OFFSET);
}
