#include "MbmsMessage.h"
#include "MessageDecodingUtils.h"

namespace {
    const int CONTACTOR_STATUS_OFFSET = 1;
    const int CONTACTOR_ERRORS_OFFSET = 2;
    const int MISCELLANEOUS_STATUS_OFFSET = 3;
    const int AUXILLARY_BATTERY_VOLTAGE_OFFSET = 4;
    const int MOTOR_VOLTAGE_OFFSET = 6;
    const int ARRAY_VOLTAGE_OFFSET = 8;
    const int LV_VOLTAGE_OFFSET = 10;
    const int CHARGE_VOLTAGE_OFFSET = 12;
    const int COMMON_CURRENT_OFFSET = 14;
    const int MOTOR_CURRENT_OFFSET = 16;
    const int ARRAY_CURRENT_OFFSET = 18;
    const int LV_CURRENT_OFFSET = 20;
    const int CHARGE_CURRENT_OFFSET = 22;
    const int TRIP_STATUSES_OFFSET = 24;
}

MbmsMessage::MbmsMessage(const QByteArray& message) : message_(message) {}

unsigned char MbmsMessage::contactorStatus() const {
    return MessageDecodingUtils::getUnsignedChar(message_, CONTACTOR_STATUS_OFFSET);
}

unsigned char MbmsMessage::contactorErrors() const {
    return MessageDecodingUtils::getUnsignedChar(message_, CONTACTOR_ERRORS_OFFSET);
}

unsigned char MbmsMessage::miscellanousStatus() const {
    return MessageDecodingUtils::getUnsignedChar(message_, MISCELLANEOUS_STATUS_OFFSET);
}

unsigned short MbmsMessage::auxillaryBatteryVoltage() const {
    return MessageDecodingUtils::getUnsignedShort(message_, AUXILLARY_BATTERY_VOLTAGE_OFFSET);
}

unsigned short MbmsMessage::motorVoltage() const {
    return MessageDecodingUtils::getUnsignedShort(message_, MOTOR_VOLTAGE_OFFSET);
}

unsigned short MbmsMessage::arrayVoltage() const {
    return MessageDecodingUtils::getUnsignedShort(message_, ARRAY_VOLTAGE_OFFSET);
}

unsigned short MbmsMessage::lvVoltage() const {
    return MessageDecodingUtils::getUnsignedShort(message_, LV_VOLTAGE_OFFSET);
}

unsigned short MbmsMessage::chargeVoltage() const {
    return MessageDecodingUtils::getUnsignedShort(message_, CHARGE_VOLTAGE_OFFSET);
}

unsigned short MbmsMessage::commonCurrent() const {
    return MessageDecodingUtils::getUnsignedShort(message_, COMMON_CURRENT_OFFSET);
}

unsigned short MbmsMessage::motorCurrent() const {
    return MessageDecodingUtils::getUnsignedShort(message_, MOTOR_CURRENT_OFFSET);
}

unsigned short MbmsMessage::arrayCurrent() const {
    return MessageDecodingUtils::getUnsignedShort(message_, ARRAY_CURRENT_OFFSET);
}

unsigned short MbmsMessage::lvCurrent() const {
    return MessageDecodingUtils::getUnsignedShort(message_, LV_CURRENT_OFFSET);
}

unsigned short MbmsMessage::chargeCurrent() const {
    return MessageDecodingUtils::getUnsignedShort(message_, CHARGE_CURRENT_OFFSET);
}

unsigned short MbmsMessage::tripStatuses() const {
    return MessageDecodingUtils::getUnsignedShort(message_, TRIP_STATUSES_OFFSET);
}
