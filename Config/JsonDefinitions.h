#ifndef JSONDEFINITIONS_H
#define JSONDEFINITIONS_H

namespace JsonDefinitions {

    /**
     * Key motor keys
     */
    constexpr const char* KEY_MOTOR = "KeyMotor";
    constexpr const char* MOTOR_SETPOINT = "MotorSetpoint";
    constexpr const char* CONTROL_MODE = "ControlMode";
    constexpr const char* MOTOR_MODE = "MotorMode";
    constexpr const char* SOFTWARE_ENABLE = "SoftwareEnable";
    constexpr const char* DEBUG_MODE= "DebugMode";

    /**
     * Motor details keys
     */
    constexpr const char* MOTOR_DETAILS = "MotorDetails";
    constexpr const char* CONTROL_VALUE = "ControlValue";
    constexpr const char* CURRENT_MOTOR_TORQUE = "CurrentMotorTorque";
    constexpr const char* CURRENT_RPM_VALUE = "CurrentRpmValue";
    constexpr const char* MOTOR_TEMPERATURE = "MotorTemperature";
    constexpr const char* INVERTER_PEAK_CURRENT = "InverterPeakCurrent";
    constexpr const char* CURRENT_MOTOR_POWER = "CurrentMotorPower";
    constexpr const char* ABSOLUTE_ANGLE = "AbsoluteAngle";
    constexpr const char* MOTOR_ABOUT_TO_STALL = "MotorAboutToStall";
    constexpr const char* DELAY_IN_READING_TEMP_SENSOR = "DelayInReadingTempSensor";
    constexpr const char* DELAY_IN_READING_POS_SENSOR = "DelayInReadingPosSensor";
    constexpr const char* INVERTER1_TEMP_VERY_HIGH = "Inverter1TempVeryHigh";
    constexpr const char* INVERTER2_TEMP_VERY_HIGH = "Inverter2TempVeryHigh";
    constexpr const char* INVERTER3_TEMP_VERY_HIGH = "Inverter3TempVeryHigh";
    constexpr const char* INVERTER4_TEMP_VERY_HIGH = "Inverter4TempVeryHigh";
    constexpr const char* INVERTER5_TEMP_VERY_HIGH = "Inverter5TempVeryHigh";
    constexpr const char* INVERTER6_TEMP_VERY_HIGH = "Inverter6TempVeryHigh";
    constexpr const char* CPU_TEMPERATURE_VERY_HIGH = "CpuTemperatureVeryHigh";
    constexpr const char* HALL_TEMPERATURE_VERY_HIGH = "HallTemperatureVeryHigh";
    constexpr const char* DCLINK_TEMPERATURE_VERY_HIGH = "DclinkTemperatureVeryHigh";
    constexpr const char* DELAY_IN_DCLINK_COMMUNICATION = "DelayInDclinkCommunication";
    constexpr const char* INVERTER1_OVER_CURRENT_WARNING = "Inverter1OverCurrentWarning";
    constexpr const char* INVERTER2_OVER_CURRENT_WARNING = "Inverter2OverCurrentWarning";
    constexpr const char* INVERTER3_OVER_CURRENT_WARNING = "Inverter3OverCurrentWarning";
    constexpr const char* INVERTER4_OVER_CURRENT_WARNING = "Inverter4OverCurrentWarning";
    constexpr const char* INVERTER5_OVER_CURRENT_WARNING = "Inverter5OverCurrentWarning";
    constexpr const char* INVERTER6_OVER_CURRENT_WARNING = "Inverter6OverCurrentWarning";
    constexpr const char* DC_OVERVOLTAGE_WARNING = "DcOvervoltageWarning";
    constexpr const char* DC_UNDERVOLTAGE_WARNING = "DcUndervoltageWarning";
    constexpr const char* CAN_COMMS_TIMEOUT_WARNING = "CanCommsTimeoutWarning";
    constexpr const char* INVERTER1_FAULT_WARNING = "Inverter1FaultWarning";
    constexpr const char* INVERTER2_FAULT_WARNING = "Inverter2FaultWarning";
    constexpr const char* INVERTER3_FAULT_WARNING = "Inverter3FaultWarning";
    constexpr const char* INVERTER4_FAULT_WARNING = "Inverter4FaultWarning";
    constexpr const char* INVERTER5_FAULT_WARNING = "Inverter5FaultWarning";
    constexpr const char* INVERTER6_FAULT_WARNING = "Inverter6FaultWarning";
    constexpr const char* CAN_SEND_WARNING = "CanSendWarning";
    constexpr const char* LOST_FRAMES_ON_CAN_BUS_WARNING = "LostFramesOnCanBusWarning";
    constexpr const char* OVERSPEED_WARNING = "OverspeedWarning";
    constexpr const char* CPU_OVERLOAD = "CpuOverload";
    constexpr const char* TORQUE_LIMITED = "TorqueLimited";
    constexpr const char* START_AT_HIGH_RPM = "StartAtHighRpm";
    constexpr const char* INIT_ERROR = "InitError";
    constexpr const char* SETTINGS_NOT_FOUND = "SettingsNotFound";
    constexpr const char* MOTOR_STALLED = "MotorStalled";
    constexpr const char* CONTROLLER_DATA_READING_TIMEOUT = "ControllerDataReadingTimeout";
    constexpr const char* INVALID_HALL_SENSOR_SEQUENCE = "InvalidHallSensorSequence";
    constexpr const char* INVALID_HALL_SECTOR = "InvalidHallSector";
    constexpr const char* ERROR_READING_TEMP_SENSOR = "ErrorReadingTempSensor";
    constexpr const char* POSITION_SENSOR_READING_ERROR = "PositionSensorReadingError";
    constexpr const char* ERROR_READING_ENCODER = "ErrorReadingEncoder";
    constexpr const char* ZERO_POSITION_OFFSET_NOT_SET = "ZeroPositionOffsetNotSet";
    constexpr const char* HW_ENABLE_NOT_SET = "HwEnableNotSet";
    constexpr const char* INVERTER1_TEMP_TOO_HIGH = "Inverter1TempTooHigh";
    constexpr const char* INVERTER2_TEMP_TOO_HIGH = "Inverter2TempTooHigh";
    constexpr const char* INVERTER3_TEMP_TOO_HIGH = "Inverter3TempTooHigh";
    constexpr const char* INVERTER4_TEMP_TOO_HIGH = "Inverter4TempTooHigh";
    constexpr const char* INVERTER5_TEMP_TOO_HIGH = "Inverter5TempTooHigh";
    constexpr const char* INVERTER6_TEMP_TOO_HIGH = "Inverter6TempTooHigh";
    constexpr const char* CPU_TEMP_TOO_HIGH = "CpuTempTooHigh";
    constexpr const char* CPU_TEMPERATURE_TOO_HIGH = "CpuTempTooHigh";
    constexpr const char* HALL_TEMP_TOO_HIGH = "HallTempTooHigh";
    constexpr const char* DCLINK_TEMP_TOO_HIGH = "DclinkTempTooHigh";
    constexpr const char* ERROR_IN_DCLINK_COMMUNICATION = "ErrorInDclinkCommunication";
    constexpr const char* INVERTER1_OVERCURRENT_ERROR = "Inverter1OvercurrentError";
    constexpr const char* INVERTER2_OVERCURRENT_ERROR = "Inverter2OvercurrentError";
    constexpr const char* INVERTER3_OVERCURRENT_ERROR = "Inverter3OvercurrentError";
    constexpr const char* INVERTER4_OVERCURRENT_ERROR = "Inverter4OvercurrentError";
    constexpr const char* INVERTER5_OVERCURRENT_ERROR = "Inverter5OvercurrentError";
    constexpr const char* INVERTER6_OVERCURRENT_ERROR = "Inverter6OvercurrentError";
    constexpr const char* DC_OVERVOLTAGE_ERROR = "DcOvervoltageError";
    constexpr const char* DC_UNDERVOLTAGE_ERROR = "DcUndervoltageError";
    constexpr const char* DOUBLE_CAN_ID_ON_BUS = "DoubleCanIdOnBus";
    constexpr const char* CAN_COMMS_TIMEOUT_ERROR = "CanCommsTimeoutError";
    constexpr const char* INVERTER1_FAULT_ERROR = "Inverter1FaultError";
    constexpr const char* INVERTER2_FAULT_ERROR = "Inverter2FaultError";
    constexpr const char* INVERTER3_FAULT_ERROR = "Inverter3FaultError";
    constexpr const char* INVERTER4_FAULT_ERROR = "Inverter4FaultError";
    constexpr const char* INVERTER5_FAULT_ERROR = "Inverter5FaultError";
    constexpr const char* INVERTER6_FAULT_ERROR = "Inverter6FaultError";
    constexpr const char* CAN_SEND_ERROR = "CanSendError";
    constexpr const char* LOST_FRAMES_ON_CAN_BUS_ERROR = "LostFramesOnCanBusError";
    constexpr const char* OVERSPEED_ERROR = "OverspeedError";
    constexpr const char* CPU_OVERLOADED = "CpuOverload";

    /**
     * B3 keys
     */
    constexpr const char* B3 = "B3";
    constexpr const char* RIGHT_SIGNAL_IN = "RightSignalIn";
    constexpr const char* LEFT_SIGNAL_IN = "LeftSignalIn";
    constexpr const char* HAZARD_LIGHTS_IN = "HazardLightsIn";
    constexpr const char* HEADLIGHTS_SWITCH_IN = "HeadightsSwitchIn";
    constexpr const char* FORWARD_SWITCH_IN = "ForwardSwitchIn";
    constexpr const char* HORN_SWITCH_IN = "HornSwitchIn";
    constexpr const char* FORWARD_IN = "ForwardIn";
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
    constexpr const char* DAYTIME_RUNNING_LIGHT_SIGNAL_OUT = "DaytimeRunningLightSignalOut";
    constexpr const char* HEADLIGHT_SIGNAL_OUT = "HeadlightSignalOut";
    constexpr const char* BRAKE_LIGHT_SIGNAL_OUT = "BrakeLightSignalOut";
    constexpr const char* HORN_SIGNAL_OUT = "HornSignalOut";

    /**
     * Proximity sensor keys
     */
    constexpr const char* PROXIMITY_SENSORS = "ProximitySensors";
    constexpr const char* PROXIMITY_SENSOR_1 = "ProximitySensor1";
    constexpr const char* PROXIMITY_SENSOR_2 = "ProximitySensor2";
    constexpr const char* PROXIMITY_SENSOR_3 = "ProximitySensor3";
    constexpr const char* PROXIMITY_SENSOR_4 = "ProximitySensor4";
}

#endif // JSONDEFINITIONS_H
