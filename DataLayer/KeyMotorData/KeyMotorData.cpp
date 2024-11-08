#include "KeyMotorData.h"

namespace {
    const unsigned char CONTROL_MODE_OFFSET = 0x01;
    const unsigned char MOTOR_MODE_OFFSET = 0x02;
    const unsigned char SOFTWARE_ENABLE_OFFSET = 0x04;
    const unsigned char DEBUG_MODE_ENABLE = 0x08;
}

KeyMotorData::KeyMotorData() {}

KeyMotorData::~KeyMotorData() {}

unsigned short KeyMotorData::getMotorSetpoint() const {
    return motorSetpoint_;
}

bool KeyMotorData::getControlMode() const {
    return controlMode_;
}

bool KeyMotorData::getMotorMode() const {
    return motorMode_;
}

bool KeyMotorData::getSoftwareEnable() const {
    return softwareEnable_;
}

bool KeyMotorData::getDebugMode() const {
    return debugMode_;
}

void KeyMotorData::setMotorSetpoint(const unsigned short& val){
    motorSetpoint_ = val;
}

void KeyMotorData::setControlBits(const unsigned char& val){
    controlMode_ = val & CONTROL_MODE_OFFSET;
    motorMode_ = val & MOTOR_MODE_OFFSET;
    softwareEnable_ = val & SOFTWARE_ENABLE_OFFSET;
    debugMode_ = val & DEBUG_MODE_ENABLE;
}
