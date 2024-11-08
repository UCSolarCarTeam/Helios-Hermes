#include "B3Message.h"
#include "MessageDecodingUtils.h"

namespace {
    const int LIGHT_INPUTS_OFFSET = 1;
    const int DRIVER_INPUTS_OFFSET = 2;
    const int ACCELERATION_OFFSET = 3;
    const int REGEN_BRAKING_OFFSET = 5;
    const int LIGHT_OUTPUTS_OFFSET = 7; // ** VERIFY WITH SPREADSHEET **
}

B3Message::B3Message(const QByteArray& message) : message_(message) {}

unsigned char B3Message::lightInputs() const {
    return MessageDecodingUtils::getUnsignedChar(message_, LIGHT_INPUTS_OFFSET);
}

unsigned char B3Message::driverInputs() const {
    return MessageDecodingUtils::getUnsignedChar(message_, DRIVER_INPUTS_OFFSET);
}

unsigned short B3Message::acceleration() const {
    return MessageDecodingUtils::getUnsignedShort(message_, ACCELERATION_OFFSET);
}

unsigned short B3Message::regenBraking() const {
    return MessageDecodingUtils::getUnsignedShort(message_, REGEN_BRAKING_OFFSET);
}

unsigned char B3Message::lightOutputs() const {
    return MessageDecodingUtils::getUnsignedChar(message_, LIGHT_OUTPUTS_OFFSET);
}
