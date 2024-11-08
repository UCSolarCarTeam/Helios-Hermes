#include "MotorDetailsMessage.h"
#include "MessageDecodingUtils.h"

namespace {
    const int CONTROL_VALUE_OFFSET = 1;
    const int CONTROL_BITS_OFFSET = 3;
    const int CURRENT_MOTOR_TORQUE_OFFSET = 4;
    const int CURRENT_RPM_VALUE_OFFSET = 6;
    const int MOTOR_TEMPERATURE_OFFSET = 8;
    const int INVERTER_PEAK_CURRENT_OFFSET = 9;
    const int CURRENT_MOTOR_POWER_OFFSET = 11;
    const int ABSOLUTE_ANGLE_OFFSET = 13;
    const int WARNING_CODE_1_OFFSET = 15;
    const int WARNING_CODE_2_OFFSET = 17;
    const int WARNING_CODE_3_OFFSET = 19;
    const int WARNING_CODE_4_OFFSET = 21;
    const int WARNING_CODE_5_OFFSET = 23;
    const int ERROR_CODE_1_OFFSET = 24;
    const int ERROR_CODE_2_OFFSET = 26;
    const int ERROR_CODE_3_OFFSET = 28;
    const int ERROR_CODE_4_OFFSET = 30;
    const int ERROR_CODE_5_OFFSET = 32;
}

MotorDetailsMessage::MotorDetailsMessage(const QByteArray& message, const int& id) : message_(message), motorId_(id) {}

unsigned short MotorDetailsMessage::controlValue() const {
    return MessageDecodingUtils::getUnsignedShort(message_, CONTROL_VALUE_OFFSET);
}

unsigned char MotorDetailsMessage::controlBits() const {
    return MessageDecodingUtils::getUnsignedChar(message_, CONTROL_BITS_OFFSET);
}

short MotorDetailsMessage::currentMotorTorque() const {
    return MessageDecodingUtils::getUnsignedShort(message_, CURRENT_MOTOR_TORQUE_OFFSET);
}

short MotorDetailsMessage::currentRpmValue() const {
    return MessageDecodingUtils::getUnsignedShort(message_, CURRENT_RPM_VALUE_OFFSET);
}

char MotorDetailsMessage::motorTemperature() const {
    return MessageDecodingUtils::getUnsignedChar(message_, MOTOR_TEMPERATURE_OFFSET);
}

unsigned short MotorDetailsMessage::inverterPeakCurrent() const {
    return MessageDecodingUtils::getUnsignedShort(message_, INVERTER_PEAK_CURRENT_OFFSET);
}

unsigned short MotorDetailsMessage::currentMotorPower() const {
    return MessageDecodingUtils::getUnsignedShort(message_, CURRENT_MOTOR_POWER_OFFSET);
}

unsigned short MotorDetailsMessage::AbsoluteAngle() const {
    return MessageDecodingUtils::getUnsignedShort(message_, ABSOLUTE_ANGLE_OFFSET);
}

unsigned short MotorDetailsMessage::warningCode1() const {
    return MessageDecodingUtils::getUnsignedShort(message_, WARNING_CODE_1_OFFSET);
}

unsigned short MotorDetailsMessage::warningCode2() const {
    return MessageDecodingUtils::getUnsignedShort(message_, WARNING_CODE_2_OFFSET);
}

unsigned short MotorDetailsMessage::warningCode3() const {
    return MessageDecodingUtils::getUnsignedShort(message_, WARNING_CODE_3_OFFSET);
}

unsigned short MotorDetailsMessage::warningCode4() const {
    return MessageDecodingUtils::getUnsignedShort(message_, WARNING_CODE_4_OFFSET);
}

unsigned char MotorDetailsMessage::warningCode5() const {
    return MessageDecodingUtils::getUnsignedChar(message_, WARNING_CODE_5_OFFSET);
}

unsigned short MotorDetailsMessage::errorCode1() const {
    return MessageDecodingUtils::getUnsignedShort(message_, ERROR_CODE_1_OFFSET);
}

unsigned short MotorDetailsMessage::errorCode2() const {
    return MessageDecodingUtils::getUnsignedShort(message_, ERROR_CODE_2_OFFSET);
}

unsigned short MotorDetailsMessage::errorCode3() const {
    return MessageDecodingUtils::getUnsignedShort(message_, ERROR_CODE_3_OFFSET);
}

unsigned short MotorDetailsMessage::errorCode4() const {
    return MessageDecodingUtils::getUnsignedShort(message_, ERROR_CODE_4_OFFSET);
}

unsigned char MotorDetailsMessage::errorCode5() const {
    return MessageDecodingUtils::getUnsignedChar(message_, ERROR_CODE_5_OFFSET);
}

int MotorDetailsMessage::motorId() const
{
    return motorId_;
}
