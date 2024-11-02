#ifndef JSONDEFINES_H
#define JSONDEFINES_H

#include <QString>

namespace JsonFormat {

    constexpr const char* PACKET_TITLE = "PacketTitle";
    constexpr const char* TIMESTAMP = "TimeStamp";

    constexpr const char* KEY_MOTOR = "KeyMotor";
    constexpr const char* MOTOR_SETPOINT = "MotorSetpoint";
    constexpr const char* CONTROL_MODE = "ControlMode";
    constexpr const char* MOTOR_MODE = "MotorMode";
    constexpr const char* SOFTWARE_ENABLE = "SoftwareEnable";
    constexpr const char* DEBUG_MODE= "DebugMode";

    constexpr const char* PROXIMITY_SENSORS = "ProximitySensors";
    constexpr const char* PROXIMITY_SENSOR_1 = "ProximitySensor1";
    constexpr const char* PROXIMITY_SENSOR_2 = "ProximitySensor2";
    constexpr const char* PROXIMITY_SENSOR_3 = "ProximitySensor3";
    constexpr const char* PROXIMITY_SENSOR_4 = "ProximitySensor4";

    constexpr const char* B3 = "B3";
    constexpr const char* RIGHT_SIGNAL_IN = "RightSignalIn";
    constexpr const char* LEFT_SIGNAL_IN = "LeftSignalIn";
    constexpr const char* HAZARD_LIGHTS = "HazardLights";
    constexpr const char* HEADLIGHTS_SWITCH = "HeadightsSwitch";
    constexpr const char* FORWARD_SWITCH = "ForwardSwitch";
    constexpr const char* HORN_SWITCH = "HornSwitch";
    constexpr const char* FORWARD = "Forward";
    constexpr const char* NEUTRAL = "Neutral";
    constexpr const char* REVERSE = "Reverse";
    constexpr const char* BRAKE_SWITCH = "BrakeSwitch";
    constexpr const char* HANDBRAKE_SWITCH = "HandbrakeSwitch";
    constexpr const char* MOTOR_RESET = "MotorReset";
    constexpr const char* RACE_MODE = "RaceMode";
    constexpr const char* LAP = "Lap";
    constexpr const char* ZOOM_ZOOM = "ZoomZoom";
    constexpr const char* ACCELERATION = "Acceleration";
    constexpr const char* REGEN_BRAKING = "RegenBraking";
    constexpr const char* RIGHT_SIGNAL_OUT = "RightSignalOut";
    constexpr const char* LEFT_SIGNAL_OUT = "LeftSignalOut";
    constexpr const char* DAYTIME_RUNNING_LIGHT_SIGNAL = "DaytimeRunningLightSignal";
    constexpr const char* HEADLIGHT_SIGNAL = "HeadlightSignal";
    constexpr const char* BRAKE_LIGHT_SIGNAL = "BrakeLightSignal";
    constexpr const char* HORN_SIGNAL = "HornSignal";

    constexpr const char* TELEMETRY = "Telemetry";
    constexpr const char* GPS_YEAR = "GpsYear";
    constexpr const char* GPS_MONTH = "GpsMonth";
    constexpr const char* GPS_DAY = "GpsDay";
    constexpr const char* GPS_HOUR = "GpsHour";
    constexpr const char* GPS_MINUTE = "GpsMinute";
    constexpr const char* GPS_SECOND = "GpsSecond";
    constexpr const char* GPS_VALIDITY_FLAGS = "GpsValidityFlags";
    constexpr const char* GPS_FIX_STATUS_FLAGS = "GpsFixStatusFlags";
    constexpr const char* GPS_ADDITIONAL_FLAGS = "GpsAdditionalFlags";
    constexpr const char* GPS_LONGITUDE = "GpsLongitude";
    constexpr const char* GPS_LATITUDE = "GpsLatitude";
    constexpr const char* MPU_ACCELERATION_X = "MpuAccelerationX";
    constexpr const char* MPU_ACCELERATION_Y = "MpuAccelerationY";
    constexpr const char* MPU_ACCELERATION_Z = "MpuAccelerationZ";
    constexpr const char* MPU_ROTATION_X = "MpuRotationX";
    constexpr const char* MPU_ROTATION_Y = "MpuRotationY";
    constexpr const char* MPU_ROTATION_Z = "MpuRotationZ";
    constexpr const char* MPU_TEMPERATURE = "MpuTemperature";
}

#endif // JSONDEFINES_H
