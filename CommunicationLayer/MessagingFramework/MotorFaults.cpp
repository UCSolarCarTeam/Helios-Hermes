#include "MotorFaults.h"

namespace
{
    // Error Flags
   const unsigned char MOTOR_OVER_SPEED_FLAG = 0x01;
   const unsigned char SOFTWARE_OVER_CURRENT_FLAG = 0x02;
   const unsigned char DC_BUS_OVER_VOLTAGE_FLAG = 0x04;
   const unsigned char BAD_MOTOR_POSITION_HALL_SEQUENCE_FLAG = 0x08;
   const unsigned char WATCHDOG_CAUSED_LAST_RESET_FLAG = 0x10;
   const unsigned char CONFIG_READ_ERROR_FLAG = 0x20;
   const unsigned char RAIL_UNDER_VOLTAGE_LOCK_OUT_FLAG = 0x40;
   const unsigned char DESATURATION_FAULT_FLAG = 0x80;

   // Limit Flags
   const unsigned char OUTPUT_VOLTAGE_PWM_LIMIT_FLAG = 0x01;
   const unsigned char MOTOR_CURRENT_LIMIT_FLAG = 0x02;
   const unsigned char VELOCITY_LIMIT_FLAG = 0x04;
   const unsigned char BUS_CURRENT_LIMIT_FLAG = 0x08;
   const unsigned char BUS_VOLTAGE_UPPER_LIMIT_FLAG = 0x10;
   const unsigned char BUS_VOLTAGE_LOWER_LIMIT_FLAG = 0x20;
   const unsigned char IPM_OR_MOTOR_TELEMETRY_LIMIT_FLAG = 0x40;
}

MotorFaults::MotorFaults(unsigned char errorFlags, unsigned char limitFlags)
: errorFlags_(errorFlags)
, limitFlags_(limitFlags)
{
}

bool MotorFaults::motorOverSpeed() const
{
    return static_cast<bool>(errorFlags_ & MOTOR_OVER_SPEED_FLAG);
}

bool MotorFaults::softwareOverCurrent() const
{
    return static_cast<bool>(errorFlags_ & SOFTWARE_OVER_CURRENT_FLAG);
}

bool MotorFaults::dcBusOverVoltage() const
{
    return static_cast<bool>(errorFlags_ & DC_BUS_OVER_VOLTAGE_FLAG);
}

bool MotorFaults::badMotorPositionHallSequence() const
{
    return static_cast<bool>(errorFlags_ & BAD_MOTOR_POSITION_HALL_SEQUENCE_FLAG);
}

bool MotorFaults::watchdogCausedLastReset() const
{
    return static_cast<bool>(errorFlags_ & WATCHDOG_CAUSED_LAST_RESET_FLAG);
}

bool MotorFaults::configReadError() const
{
    return static_cast<bool>(errorFlags_ & CONFIG_READ_ERROR_FLAG);
}

bool MotorFaults::railUnderVoltageLockOut() const
{
    return static_cast<bool>(errorFlags_ & RAIL_UNDER_VOLTAGE_LOCK_OUT_FLAG);
}

bool MotorFaults::desaturationFault() const
{
    return static_cast<bool>(errorFlags_ & DESATURATION_FAULT_FLAG);
}

bool MotorFaults::outputVoltagePwmLimit() const
{
    return static_cast<bool>(limitFlags_ & OUTPUT_VOLTAGE_PWM_LIMIT_FLAG);
}

bool MotorFaults::motorCurrentLimit() const
{
    return static_cast<bool>(limitFlags_ & MOTOR_CURRENT_LIMIT_FLAG);
}

bool MotorFaults::velocityLimit() const
{
    return static_cast<bool>(limitFlags_ & VELOCITY_LIMIT_FLAG);
}

bool MotorFaults::busCurrentLimit() const
{
    return static_cast<bool>(limitFlags_ & BUS_CURRENT_LIMIT_FLAG);
}

bool MotorFaults::busVoltageUpperLimit() const
{
    return static_cast<bool>(limitFlags_ & BUS_VOLTAGE_UPPER_LIMIT_FLAG);
}

bool MotorFaults::busVoltageLowerLimit() const
{
    return static_cast<bool>(limiFlags_ & BUS_VOLTAGE_LOWER_LIMIT_FLAG);
}

bool MotorFaults::ipmOrMotorTelemetryLimit() const
{
    return static_cast<bool>(limitFlags_ & IPM_OR_MOTOR_TELEMETRY_LIMIT_FLAG);
}

// TODO check this
QString MotorFaults::toString() const
{
   return "0x" + QString::number(errorFlags_, 16) + " 0x" + QString::number(limitFlags_, 16);
}
