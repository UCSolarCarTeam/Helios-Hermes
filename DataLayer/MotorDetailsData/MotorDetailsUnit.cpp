#include "MotorDetailsUnit.h"

namespace {
    const unsigned short CONTROL_MODE_OFFSET = 0x01;
    const unsigned short MOTOR_MODE_OFFSET = 0x02;
    const unsigned short SOFTWARE_ENABLE_OFFSET = 0x04;
    const unsigned short DEBUG_MODE_OFFSET = 0x08;

    const unsigned short MOTOR_ABOUT_TO_STALL_OFFSET = 0x0001;
    const unsigned short DELAY_IN_READING_TEMP_SENSOR_OFFSET = 0x0002;
    const unsigned short DELAY_IN_READING_POS_SENSOR_OFFSET = 0x0004;
    const unsigned short INVERTER_1_TEMP_VERY_HIGH_OFFSET = 0x0008;
    const unsigned short INVERTER_2_TEMP_VERY_HIGH_OFFSET = 0x0010;
    const unsigned short INVERTER_3_TEMP_VERY_HIGH_OFFSET = 0x0020;
    const unsigned short INVERTER_4_TEMP_VERY_HIGH_OFFSET = 0x0040;
    const unsigned short INVERTER_5_TEMP_VERY_HIGH_OFFSET = 0x0080;

    const unsigned short INVERTER_6_TEMP_VERY_HIGH_OFFSET = 0x0001;
    const unsigned short CPU_TEMPERATURE_VERY_HIGH_OFFSET = 0x0002;
    const unsigned short HALL_TEMPERATURE_VERY_HIGH_OFFSET = 0x0004;
    const unsigned short DCLINK_TEMPERATURE_VERY_HIGH_OFFSET = 0x0008;
    const unsigned short DELAY_IN_DCLINK_COMMUNICATION_OFFSET = 0x0010;
    const unsigned short INVERTER_1_OVER_CURRENT_OFFSET = 0x0020;
    const unsigned short INVERTER_2_OVER_CURRENT_OFFSET = 0x0040;
    const unsigned short INVERTER_3_OVER_CURRENT_OFFSET = 0x0080;

    const unsigned short INVERTER_4_OVER_CURRENT_OFFSET = 0x0001;
    const unsigned short INVERTER_5_OVER_CURRENT_OFFSET = 0x0002;
    const unsigned short INVERTER_6_OVER_CURRENT_OFFSET = 0x0004;
    const unsigned short DC_OVERVOLTAGE_WARNING_OFFSET = 0x0008;
    const unsigned short DC_UNDERVOLTAGE_WARNING_OFFSET = 0x0010;
    const unsigned short CAN_COMMS_TIMEOUT_OFFSET = 0x0020;
    const unsigned short INVERTER_1_FAULT_WARNING_OFFSET = 0x0040;
    const unsigned short INVERTER_2_FAULT_WARNING_OFFSET = 0x0080;

    const unsigned short INVERTER_3_FAULT_WARNING_OFFSET = 0x0001;
    const unsigned short INVERTER_4_FAULT_WARNING_OFFSET = 0x0002;
    const unsigned short INVERTER_5_FAULT_WARNING_OFFSET = 0x0004;
    const unsigned short INVERTER_6_FAULT_WARNING_OFFSET = 0x0008;
    const unsigned short CAN_SEND_WARNING_OFFSET = 0x0010;
    const unsigned short LOST_FRAMES_ON_CAN_BUS_WARNING_OFFSET = 0x0020;
    const unsigned short OVERSPEED_WARNING_OFFSET = 0x0040;
    const unsigned short CPU_OVERLOAD_OFFSET = 0x0080;

    const unsigned char TORQUE_LIMITED_OFFSET = 0x01;
    const unsigned char START_AT_HIGH_RPM_OFFSET = 0x02;

    const unsigned short INIT_ERROR_OFFSET = 0x0001;
    const unsigned short SETTINGS_NOT_FOUND_OFFSET = 0x0002;
    const unsigned short MOTOR_STALLED_OFFSET = 0x0004;
    const unsigned short CONTROLLER_DATA_READING_TIMEOUT_OFFSET = 0x0008;
    const unsigned short INVALID_HALL_SENSOR_SEQUENCE_OFFSET = 0x0010;
    const unsigned short INVALID_HALL_SECTOR_OFFSET = 0x0020;
    const unsigned short ERROR_READING_TEMP_SENSOR_OFFSET = 0x0040;
    const unsigned short POSITION_SENSOR_READING_ERROR_OFFSET = 0x0080;

    const unsigned short ERROR_READING_ENCODER_OFFSET = 0x0001;
    const unsigned short ZERO_POSITION_OFFSET_NOT_SET_OFFSET = 0x0002;
    const unsigned short HW_ENABLE_NOT_SET_OFFSET = 0x0004;
    const unsigned short INVERTER_1_TEMP_TOO_HIGH_OFFSET = 0x0008;
    const unsigned short INVERTER_2_TEMP_TOO_HIGH_OFFSET = 0x0010;
    const unsigned short INVERTER_3_TEMP_TOO_HIGH_OFFSET = 0x0020;
    const unsigned short INVERTER_4_TEMP_TOO_HIGH_OFFSET = 0x0040;
    const unsigned short INVERTER_5_TEMP_TOO_HIGH_OFFSET = 0x0080;

    const unsigned short INVERTER_6_TEMP_TOO_HIGH_OFFSET = 0x0001;
    const unsigned short CPU_TEMPERATURE_TOO_HIGH_OFFSET = 0x0002;
    const unsigned short HALL_TEMPERATURE_TOO_HIGH_OFFSET = 0x0004;
    const unsigned short DCLINK_TEMPERATURE_TOO_HIGH_OFFSET = 0x0008;
    const unsigned short ERROR_IN_DCLINK_COMMUNICATION_OFFSET = 0x0010;
    const unsigned short INVERTER_1_OVERCURRENT_OFFSET = 0x0020;
    const unsigned short INVERTER_2_OVERCURRENT_OFFSET = 0x0040;
    const unsigned short INVERTER_3_OVERCURRENT_OFFSET = 0x0080;

    const unsigned short INVERTER_4_OVERCURRENT_OFFSET = 0x0001;
    const unsigned short INVERTER_5_OVERCURRENT_OFFSET = 0x0002;
    const unsigned short INVERTER_6_OVERCURRENT_OFFSET = 0x0004;
    const unsigned short DC_OVERVOLTAGE_ERROR_OFFSET = 0x0008;
    const unsigned short DC_UNDERVOLTAGE_ERROR_OFFSET = 0x0010;
    const unsigned short DOUBLE_CAN_COMMS_TIMEOUT_OFFSET = 0x0020;
    const unsigned short CAN_COMMS_TIMEOUT_ERROR_OFFSET = 0x0040;
    const unsigned short INVERTER_1_FAULT_ERROR_OFFSET = 0x0080;
    const unsigned short INVERTER_2_FAULT_ERROR_OFFSET = 0x0100;
    const unsigned short INVERTER_3_FAULT_ERROR_OFFSET = 0x0200;
    const unsigned short INVERTER_4_FAULT_ERROR_OFFSET = 0x0400;
    const unsigned short INVERTER_5_FAULT_ERROR_OFFSET = 0x0800;
    const unsigned short INVERTER_6_FAULT_ERROR_OFFSET = 0x1000;
    const unsigned short CAN_SEND_ERROR_OFFSET = 0x2000;
    const unsigned short LOST_FRAMES_ON_CAN_BUS_ERROR_OFFSET = 0x4000;
    const unsigned short OVERSPEED_ERROR_OFFSET = 0x8000;
    
    const unsigned char CPU_OVERLOADED_OFFSET = 0x01;
}

MotorDetailsUnit::MotorDetailsUnit() {}

MotorDetailsUnit::~MotorDetailsUnit() {}

short MotorDetailsUnit::controlValue() const
{
    return controlValue_;
}

void MotorDetailsUnit::setControlValue(short newControlValue)
{
    controlValue_ = newControlValue;
}

bool MotorDetailsUnit::controlMode() const
{
    return controlMode_;
}

bool MotorDetailsUnit::motorMode() const
{
    return motorMode_;
}

bool MotorDetailsUnit::softwareEnable() const
{
    return softwareEnable_;
}

bool MotorDetailsUnit::debugMode() const
{
    return debugMode_;
}

short MotorDetailsUnit::currentMotorTorque() const
{
    return currentMotorTorque_;
}

void MotorDetailsUnit::setCurrentMotorTorque(short newCurrentMotorTorque)
{
    currentMotorTorque_ = newCurrentMotorTorque;
}

short MotorDetailsUnit::currentRpmValue() const
{
    return currentRpmValue_;
}

void MotorDetailsUnit::setCurrentRpmValue(short newCurrentRpmValue)
{
    currentRpmValue_ = newCurrentRpmValue;
}

char MotorDetailsUnit::motorTemperature() const
{
    return motorTemperature_;
}

void MotorDetailsUnit::setMotorTemperature(char newMotorTemperature)
{
    motorTemperature_ = newMotorTemperature;
}

short MotorDetailsUnit::inverterPeakCurrent() const
{
    return inverterPeakCurrent_;
}

void MotorDetailsUnit::setInverterPeakCurrent(short newInverterPeakCurrent)
{
    inverterPeakCurrent_ = newInverterPeakCurrent;
}

short MotorDetailsUnit::currentMotorPower() const
{
    return currentMotorPower_;
}

void MotorDetailsUnit::setCurrentMotorPower(short newCurrentMotorPower)
{
    currentMotorPower_ = newCurrentMotorPower;
}

unsigned short MotorDetailsUnit::AbsoluteAngle() const
{
    return AbsoluteAngle_;
}

void MotorDetailsUnit::setAbsoluteAngle(unsigned short newAbsoluteAngle)
{
    AbsoluteAngle_ = newAbsoluteAngle;
}

bool MotorDetailsUnit::motorAboutToStall() const
{
    return motorAboutToStall_;
}

bool MotorDetailsUnit::delayInReadingTempSensor() const
{
    return delayInReadingTempSensor_;
}

bool MotorDetailsUnit::delayInReadingPosSensor() const
{
    return delayInReadingPosSensor_;
}

bool MotorDetailsUnit::inverter1TempVeryHigh() const
{
    return inverter1TempVeryHigh_;
}

bool MotorDetailsUnit::inverter2TempVeryHigh() const
{
    return inverter2TempVeryHigh_;
}

bool MotorDetailsUnit::inverter3TempVeryHigh() const
{
    return inverter3TempVeryHigh_;
}

bool MotorDetailsUnit::inverter4TempVeryHigh() const
{
    return inverter4TempVeryHigh_;
}

bool MotorDetailsUnit::inverter5TempVeryHigh() const
{
    return inverter5TempVeryHigh_;
}

bool MotorDetailsUnit::inverter6TempVeryHigh() const
{
    return inverter6TempVeryHigh_;
}

bool MotorDetailsUnit::cpuTemperatureVeryHigh() const
{
    return cpuTemperatureVeryHigh_;
}

bool MotorDetailsUnit::hallTemperatureVeryHigh() const
{
    return hallTemperatureVeryHigh_;
}

bool MotorDetailsUnit::dclinkTemperatureVeryHigh() const
{
    return dclinkTemperatureVeryHigh_;
}

bool MotorDetailsUnit::delayInDclinkCommunication() const
{
    return delayInDclinkCommunication_;
}

bool MotorDetailsUnit::inverter1OverCurrent() const
{
    return inverter1OverCurrent_;
}

bool MotorDetailsUnit::inverter2OverCurrent() const
{
    return inverter2OverCurrent_;
}

bool MotorDetailsUnit::inverter3OverCurrent() const
{
    return inverter3OverCurrent_;
}

bool MotorDetailsUnit::inverter4OverCurrent() const
{
    return inverter4OverCurrent_;
}

bool MotorDetailsUnit::inverter5OverCurrent() const
{
    return inverter5OverCurrent_;
}

bool MotorDetailsUnit::inverter6OverCurrent() const
{
    return inverter6OverCurrent_;
}

bool MotorDetailsUnit::dcOvervoltageWarning() const
{
    return dcOvervoltageWarning_;
}

bool MotorDetailsUnit::dcUndervoltageWarning() const
{
    return dcUndervoltageWarning_;
}

bool MotorDetailsUnit::canCommsTimeout() const
{
    return canCommsTimeout_;
}

bool MotorDetailsUnit::inverter1faultWarning() const
{
    return inverter1faultWarning_;
}

bool MotorDetailsUnit::inverter2faultWarning() const
{
    return inverter2faultWarning_;
}

bool MotorDetailsUnit::inverter3faultWarning() const
{
    return inverter3faultWarning_;
}

bool MotorDetailsUnit::inverter4faultWarning() const
{
    return inverter4faultWarning_;
}

bool MotorDetailsUnit::inverter5faultWarning() const
{
    return inverter5faultWarning_;
}

bool MotorDetailsUnit::inverter6faultWarning() const
{
    return inverter6faultWarning_;
}

bool MotorDetailsUnit::canSendWarning() const
{
    return canSendWarning_;
}

bool MotorDetailsUnit::lostFramesOnCanBusWarning() const
{
    return lostFramesOnCanBusWarning_;
}

bool MotorDetailsUnit::overspeedWarning() const
{
    return overspeedWarning_;
}

bool MotorDetailsUnit::cpuOverload() const
{
    return cpuOverload_;
}

bool MotorDetailsUnit::torqueLimited() const
{
    return torqueLimited_;
}

bool MotorDetailsUnit::startAtHighRpm() const
{
    return startAtHighRpm_;
}

bool MotorDetailsUnit::initError() const
{
    return initError_;
}

bool MotorDetailsUnit::settingsNotFound() const
{
    return settingsNotFound_;
}

bool MotorDetailsUnit::motorStalled() const
{
    return motorStalled_;
}

bool MotorDetailsUnit::controllerDataReadingTimeout() const
{
    return controllerDataReadingTimeout_;
}

bool MotorDetailsUnit::invalidHallSensorSequence() const
{
    return invalidHallSensorSequence_;
}

bool MotorDetailsUnit::invalidHallSector() const
{
    return invalidHallSector_;
}

bool MotorDetailsUnit::errorReadingTempSensor() const
{
    return errorReadingTempSensor_;
}

bool MotorDetailsUnit::positionSensorReadingError() const
{
    return positionSensorReadingError_;
}

bool MotorDetailsUnit::errorReadingEncoder() const
{
    return errorReadingEncoder_;
}

bool MotorDetailsUnit::zeroPositionOffsetNotSet() const
{
    return zeroPositionOffsetNotSet_;
}

bool MotorDetailsUnit::hwEnableNotSet() const
{
    return hwEnableNotSet_;
}

bool MotorDetailsUnit::inverter1TempTooHigh() const
{
    return inverter1TempTooHigh_;
}

bool MotorDetailsUnit::inverter2TempTooHigh() const
{
    return inverter2TempTooHigh_;
}

bool MotorDetailsUnit::inverter3TempTooHigh() const
{
    return inverter3TempTooHigh_;
}

bool MotorDetailsUnit::inverter4TempTooHigh() const
{
    return inverter4TempTooHigh_;
}

bool MotorDetailsUnit::inverter5TempTooHigh() const
{
    return inverter5TempTooHigh_;
}

bool MotorDetailsUnit::inverter6TempTooHigh() const
{
    return inverter6TempTooHigh_;
}

bool MotorDetailsUnit::cpuTemperatureTooHigh() const
{
    return cpuTemperatureTooHigh_;
}

bool MotorDetailsUnit::hallTemperatureTooHigh() const
{
    return hallTemperatureTooHigh_;
}

bool MotorDetailsUnit::dclinkTemperatureTooHigh() const
{
    return dclinkTemperatureTooHigh_;
}

bool MotorDetailsUnit::errorInDclinkCommunication() const
{
    return errorInDclinkCommunication_;
}

bool MotorDetailsUnit::inverter1Overcurrent() const
{
    return inverter1Overcurrent_;
}

bool MotorDetailsUnit::inverter2Overcurrent() const
{
    return inverter2Overcurrent_;
}

bool MotorDetailsUnit::inverter3Overcurrent() const
{
    return inverter3Overcurrent_;
}

bool MotorDetailsUnit::inverter4Overcurrent() const
{
    return inverter4Overcurrent_;
}

bool MotorDetailsUnit::inverter5Overcurrent() const
{
    return inverter5Overcurrent_;
}

bool MotorDetailsUnit::inverter6Overcurrent() const
{
    return inverter6Overcurrent_;
}

bool MotorDetailsUnit::dcOvervoltageError() const
{
    return dcOvervoltageError_;
}

bool MotorDetailsUnit::dcUndervoltageError() const
{
    return dcUndervoltageError_;
}

bool MotorDetailsUnit::doubleCanCommsTimeout() const
{
    return doubleCanCommsTimeout_;
}

bool MotorDetailsUnit::inverter1FaultError() const
{
    return inverter1FaultError_;
}

bool MotorDetailsUnit::inverter2FaultError() const
{
    return inverter2FaultError_;
}

bool MotorDetailsUnit::inverter3FaultError() const
{
    return inverter3FaultError_;
}

bool MotorDetailsUnit::inverter4FaultError() const
{
    return inverter4FaultError_;
}

bool MotorDetailsUnit::inverter5FaultError() const
{
    return inverter5FaultError_;
}

bool MotorDetailsUnit::inverter6FaultError() const
{
    return inverter6FaultError_;
}

bool MotorDetailsUnit::canSendError() const
{
    return canSendError_;
}

bool MotorDetailsUnit::lostFramesOnCanBusError() const
{
    return lostFramesOnCanBusError_;
}

bool MotorDetailsUnit::overspeedError() const
{
    return overspeedError_;
}

bool MotorDetailsUnit::cpuOverloaded() const
{
    return cpuOverloaded_;
}

bool MotorDetailsUnit::canCommsTimeoutError() const
{
    return canCommsTimeoutError_;
}

void MotorDetailsUnit::setControlBits(const unsigned char& val)
{
    controlMode_ = val & CONTROL_MODE_OFFSET;
    motorMode_ = val & MOTOR_MODE_OFFSET;
    softwareEnable_ = val & SOFTWARE_ENABLE_OFFSET;
    debugMode_ = val & DEBUG_MODE_OFFSET;
}

void MotorDetailsUnit::setWarningCode1(const unsigned short& val)
{
    motorAboutToStall_ = val & MOTOR_ABOUT_TO_STALL_OFFSET;
    delayInReadingTempSensor_ = val & DELAY_IN_READING_TEMP_SENSOR_OFFSET;
    delayInReadingPosSensor_ = val & DELAY_IN_READING_POS_SENSOR_OFFSET;
    inverter1TempVeryHigh_ = val & INVERTER_1_TEMP_VERY_HIGH_OFFSET;
    inverter2TempVeryHigh_ = val & INVERTER_2_TEMP_VERY_HIGH_OFFSET;
    inverter3TempVeryHigh_ = val & INVERTER_3_TEMP_VERY_HIGH_OFFSET;
    inverter4TempVeryHigh_ = val & INVERTER_4_TEMP_VERY_HIGH_OFFSET;
    inverter5TempVeryHigh_ = val & INVERTER_5_TEMP_VERY_HIGH_OFFSET;
}

void MotorDetailsUnit::setWarningCode2(const unsigned short& val)
{
    inverter6TempVeryHigh_ = val & INVERTER_6_TEMP_VERY_HIGH_OFFSET;
    cpuTemperatureVeryHigh_ = val & CPU_TEMPERATURE_VERY_HIGH_OFFSET;
    hallTemperatureVeryHigh_ = val & HALL_TEMPERATURE_VERY_HIGH_OFFSET;
    dclinkTemperatureVeryHigh_ = val & DCLINK_TEMPERATURE_VERY_HIGH_OFFSET;
    delayInDclinkCommunication_ = val & DELAY_IN_DCLINK_COMMUNICATION_OFFSET;
    inverter1OverCurrent_ = val & INVERTER_1_OVER_CURRENT_OFFSET;
    inverter2OverCurrent_ = val & INVERTER_2_OVER_CURRENT_OFFSET;
    inverter3OverCurrent_ = val & INVERTER_3_OVER_CURRENT_OFFSET;
}

void MotorDetailsUnit::setWarningCode3(const unsigned short& val)
{
    inverter4OverCurrent_ = val & INVERTER_4_OVER_CURRENT_OFFSET;
    inverter5OverCurrent_ = val & INVERTER_5_OVER_CURRENT_OFFSET;
    inverter6OverCurrent_ = val & INVERTER_6_OVER_CURRENT_OFFSET;
    dcOvervoltageWarning_ = val & DC_OVERVOLTAGE_WARNING_OFFSET;
    dcUndervoltageWarning_ = val & DC_UNDERVOLTAGE_WARNING_OFFSET;
    canCommsTimeout_ = val & CAN_COMMS_TIMEOUT_OFFSET;
    inverter1faultWarning_ = val & INVERTER_1_FAULT_WARNING_OFFSET;
    inverter2faultWarning_ = val & INVERTER_2_FAULT_WARNING_OFFSET;
}

void MotorDetailsUnit::setWarningCode4(const unsigned short& val)
{
    inverter3faultWarning_ = val & INVERTER_3_FAULT_WARNING_OFFSET;
    inverter4faultWarning_ = val & INVERTER_4_FAULT_WARNING_OFFSET;
    inverter5faultWarning_ = val & INVERTER_5_FAULT_WARNING_OFFSET;
    inverter6faultWarning_ = val & INVERTER_6_FAULT_WARNING_OFFSET;
    canSendWarning_ = val & CAN_SEND_WARNING_OFFSET;
    lostFramesOnCanBusWarning_ = val & LOST_FRAMES_ON_CAN_BUS_WARNING_OFFSET;
    overspeedWarning_ = val & OVERSPEED_WARNING_OFFSET;
    cpuOverload_ = val & CPU_OVERLOAD_OFFSET;
}

void MotorDetailsUnit::setWarningCode5(const unsigned char& val)
{
    torqueLimited_ = val & TORQUE_LIMITED_OFFSET;
    startAtHighRpm_ = val & START_AT_HIGH_RPM_OFFSET;
}

void MotorDetailsUnit::setErrorCode1(const unsigned short& val)
{
    initError_ = val & INIT_ERROR_OFFSET;
    settingsNotFound_ = val & SETTINGS_NOT_FOUND_OFFSET;
    motorStalled_ = val & MOTOR_STALLED_OFFSET;
    controllerDataReadingTimeout_ = val & CONTROLLER_DATA_READING_TIMEOUT_OFFSET;
    invalidHallSensorSequence_ = val & INVALID_HALL_SENSOR_SEQUENCE_OFFSET;
    invalidHallSector_ = val & INVALID_HALL_SECTOR_OFFSET;
    errorReadingTempSensor_ = val & ERROR_READING_TEMP_SENSOR_OFFSET;
    positionSensorReadingError_ = val & POSITION_SENSOR_READING_ERROR_OFFSET;
}

void MotorDetailsUnit::setErrorCode2(const unsigned short& val)
{
    errorReadingEncoder_ = val & ERROR_READING_ENCODER_OFFSET;
    zeroPositionOffsetNotSet_ = val & ZERO_POSITION_OFFSET_NOT_SET_OFFSET;
    hwEnableNotSet_ = val & HW_ENABLE_NOT_SET_OFFSET;
    inverter1TempTooHigh_ = val & INVERTER_1_TEMP_TOO_HIGH_OFFSET;
    inverter2TempTooHigh_ = val & INVERTER_2_TEMP_TOO_HIGH_OFFSET;
    inverter3TempTooHigh_ = val & INVERTER_3_TEMP_TOO_HIGH_OFFSET;
    inverter4TempTooHigh_ = val & INVERTER_4_TEMP_TOO_HIGH_OFFSET;
    inverter5TempTooHigh_ = val & INVERTER_5_TEMP_TOO_HIGH_OFFSET;
}

void MotorDetailsUnit::setErrorCode3(const unsigned short& val)
{
    inverter6TempTooHigh_ = val & INVERTER_6_TEMP_TOO_HIGH_OFFSET;
    cpuTemperatureTooHigh_ = val & CPU_TEMPERATURE_TOO_HIGH_OFFSET;
    hallTemperatureTooHigh_ = val & HALL_TEMPERATURE_TOO_HIGH_OFFSET;
    dclinkTemperatureTooHigh_ = val & DCLINK_TEMPERATURE_TOO_HIGH_OFFSET;
    errorInDclinkCommunication_ = val & ERROR_IN_DCLINK_COMMUNICATION_OFFSET;
    inverter1Overcurrent_ = val & INVERTER_1_OVERCURRENT_OFFSET;
    inverter2Overcurrent_ = val & INVERTER_2_OVERCURRENT_OFFSET;
    inverter3Overcurrent_ = val & INVERTER_3_OVERCURRENT_OFFSET;
}

void MotorDetailsUnit::setErrorCode4(const unsigned short& val)
{
    inverter4Overcurrent_ = val & INVERTER_4_OVERCURRENT_OFFSET;
    inverter5Overcurrent_ = val & INVERTER_5_OVERCURRENT_OFFSET;
    inverter6Overcurrent_ = val & INVERTER_6_OVERCURRENT_OFFSET;
    dcOvervoltageError_ = val & DC_OVERVOLTAGE_ERROR_OFFSET;
    dcUndervoltageError_ = val & DC_UNDERVOLTAGE_ERROR_OFFSET;
    doubleCanCommsTimeout_ = val & DOUBLE_CAN_COMMS_TIMEOUT_OFFSET;
    canCommsTimeoutError_ = val & CAN_COMMS_TIMEOUT_ERROR_OFFSET;
    inverter1FaultError_ = val & INVERTER_1_FAULT_ERROR_OFFSET;
    inverter2FaultError_ = val & INVERTER_2_FAULT_ERROR_OFFSET;
    inverter3FaultError_ = val & INVERTER_3_FAULT_ERROR_OFFSET;
    inverter4FaultError_ = val & INVERTER_4_FAULT_ERROR_OFFSET;
    inverter5FaultError_ = val & INVERTER_5_FAULT_ERROR_OFFSET;
    inverter6FaultError_ = val & INVERTER_6_FAULT_ERROR_OFFSET;
    canSendError_ = val & CAN_SEND_ERROR_OFFSET;
    lostFramesOnCanBusError_ = val & LOST_FRAMES_ON_CAN_BUS_ERROR_OFFSET;
    overspeedError_ = val & OVERSPEED_ERROR_OFFSET;
    cpuOverloaded_ = val & CPU_OVERLOADED_OFFSET;
    canCommsTimeoutError_ = val & CAN_COMMS_TIMEOUT_ERROR_OFFSET;
}

void MotorDetailsUnit::setErrorCode5(const unsigned char& val)
{
    cpuOverloaded_ = val & CPU_OVERLOADED_OFFSET;
}
