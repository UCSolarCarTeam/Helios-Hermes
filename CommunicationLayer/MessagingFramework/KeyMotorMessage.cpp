#include "KeyMotorMessage.h"
#include "MessageDecodingUtils.h"

namespace{
    const int MOTOR_SETPOINT_OFFSET = 1;
    const int CONTROL_BITS_OFFSET = 3;
}

KeyMotorMessage::KeyMotorMessage(const QByteArray& message) : message_(message) {}

unsigned short KeyMotorMessage::motorSetpoint() const {
    return MessageDecodingUtils::getUnsignedShort(message_, MOTOR_SETPOINT_OFFSET);
}

unsigned char KeyMotorMessage::controlBits() const {
    return MessageDecodingUtils::getUnsignedChar(message_, CONTROL_BITS_OFFSET);
}
