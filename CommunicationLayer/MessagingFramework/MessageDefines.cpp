#include "MessageDefines.h"

namespace
{
    const int BATTERY_DATA_LENGTH = 63;
    const int BATTERY_FAULTS_DATA_LENGTH = 6;
    const int CMU_DATA_LENGTH = 53;
    const int DRIVER_CONTROLS_DATA_LENGTH = 13;
    const int KEY_MOTOR_DATA_LENGTH = 46;
    const int LIGHTS_DATA_LENGTH = 5;
    const int MOTOR_DETAILS_DATA_LENGTH = 72;
    const int MOTOR_FAULTS_DATA_LENGTH = 12;
    const int MPPT_DATA_LENGTH = 13;
    const int OTHER_DATA_LENGTH = 20;
}

int MessageDefines::getLengthForMessage(MessageDefines::Type type)
{
   switch (type)
   {
    case Battery:
        return BATTERY_DATA_LENGTH;
    case BatteryFaults:
        return BATTERY_FAULTS_DATA_LENGTH;
    case Cmu:
        return CMU_DATA_LENGTH;
    case DriverControls:
        return DRIVER_CONTROLS_DATA_LENGTH;
    case KeyMotor:
        return KEY_MOTOR_DATA_LENGTH;
    case Lights:
        return LIGHTS_DATA_LENGTH;
    case Motor0Details:
    case Motor1Details:
        return MOTOR_DETAILS_DATA_LENGTH;
    case MotorFaults:
        return MOTOR_FAULTS_DATA_LENGTH;
    case Mppt:
        return MPPT_DATA_LENGTH;
    case Other:
        return OTHER_DATA_LENGTH;
    default:
        return 0;
   }
}
