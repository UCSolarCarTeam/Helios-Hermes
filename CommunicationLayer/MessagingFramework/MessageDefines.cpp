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
    case BatteryData:
        return BATTERY_DATA_LENGTH;
    case BatteryFaultsData:
        return BATTERY_FAULTS_DATA_LENGTH;
    case CmuData:
        return CMU_DATA_LENGTH;
    case DriverControlsData:
        return DRIVER_CONTROLS_DATA_LENGTH;
    case KeyMotorData:
        return KEY_MOTOR_DATA_LENGTH;
    case LightsData:
        return LIGHTS_DATA_LENGTH;
    case MotorDetailsData:
        return MOTOR_DETAILS_DATA_LENGTH;
    case MotorFaultsData:
        return MOTOR_FAULTS_DATA_LENGTH;
    case MpptData:
        return MPPT_DATA_LENGTH;
    case OtherData:
        return OTHER_DATA_LENGTH;
    default:
        return 0;
   }
}
