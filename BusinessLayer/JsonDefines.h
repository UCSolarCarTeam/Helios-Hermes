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

    constexpr const char* BATTERY = "Battery";
    constexpr const char* BMU_ALIVE = "BmuAlive";
    constexpr const char* DISCHARGE_RELAY_ENABLED = "DischargeRelayEnabled";
    constexpr const char* CHARGE_RELAY_ENABLED = "ChargeRelayEnabled";
    constexpr const char* CHARGER_SAFETY_ENABLED = "ChargerSafetyEnabled";
    constexpr const char* MALFUNCTION_INDICATOR_ACTIVE = "MalfunctionIndicatorActive";
    constexpr const char* MULTI_PURPOSE_INPUT_SIGNAL_STATUS = "MultiPurposeInputSignalStatus";
    constexpr const char* ALWAYS_ON_SIGNAL_STATUS = "AlwaysOnSignalStatus";
    constexpr const char* IS_READY_SIGNAL_STATUS = "IsReadySignalStatus";
    constexpr const char* IS_CHARGING_SIGNAL_STATUS = "IsChargingSignalStatus";
    constexpr const char* POPULATED_CELLS = "PopulatedCells";
    constexpr const char* INPUT_12V = "Input12V";
    constexpr const char* FAN_VOLTAGE = "FanVoltage";
    constexpr const char* PACK_CURRENT = "PackCurrent";
    constexpr const char* PACK_VOLTAGE = "PackVoltage";
    constexpr const char* PACK_STATE_OF_CHARGE = "PackStateOfCharge";
    constexpr const char* PACK_AMPHOURS = "PackAmphours";
    constexpr const char* PACK_DEPTH_OF_DISCHARGE = "PackDepthOfDischarge";
    constexpr const char* HIGH_TEMPERATURE = "HighTemperature";
    constexpr const char* HIGH_THERMISTOR_ID = "HighThermistorId";
    constexpr const char* LOW_TEMPERATURE = "LowTemperature";
    constexpr const char* LOW_THERMISTOR_ID = "LowThermistorId";
    constexpr const char* AVERAGE_TEMPERATURE = "AverageTemperature";
    constexpr const char* INTERNAL_TEMPERATURE = "InternalTemperature";
    constexpr const char* FAN_SPEED = "FanSpeed";
    constexpr const char* REQUESTED_FAN_SPEED = "RequestedFanSpeed";
    constexpr const char* LOW_CELL_VOLTAGE = "LowCellVoltage";
    constexpr const char* LOW_CELL_VOLTAGE_ID = "LowCellVoltageId";
    constexpr const char* HIGH_CELL_VOLTAGE = "HighCellVoltage";
    constexpr const char* HIGH_CELL_VOLTAGE_ID = "HighCellVoltageId";
    constexpr const char* AVERAGE_CELL_VOLTAGE = "AverageCellVoltage";

    constexpr const char* BATTERY_FAULTS = "BatteryFaults";
    constexpr const char* INTERNAL_COMMUNICATION_FAULT = "InternalCommunicationFault";
    constexpr const char* INTERNAL_CONVERSION_FAULT = "InternalConversionFault";
    constexpr const char* WEAK_CELL_FAULT = "WeakCellFault";
    constexpr const char* LOW_CELL_VOLTAGE_FAULT = "LowCellVoltageFault";
    constexpr const char* OPEN_WIRING_FAULT = "OpenWiringFault";
    constexpr const char* CURRENT_SENSOR_FAULT = "CurrentSensorFault";
    constexpr const char* PACK_VOLTAGE_SENSOR_FAULT = "PackVoltageSensorFault";
    constexpr const char* WEAK_PACK_FAULT = "WeakPackFault";
    constexpr const char* VOLTAGE_REDUNDANCY_FAULT = "VoltageRedundancyFault";
    constexpr const char* FAN_MONITOR_FAULT = "FanMonitorFault";
    constexpr const char* THERMISTOR_FAULT = "ThermistorFault";
    constexpr const char* CANBUS_COMMUNICATION_FAULT = "CanbusCommunicationFault";
    constexpr const char* ALWAYS_ON_SUPPLY_FAULT = "AlwaysOnSupplyFault";
    constexpr const char* HIGH_VOLTAGE_ISOLATION_FAULT = "HighVoltageIsolationFault";
    constexpr const char* POWER_SUPPLY_12V_FAULT = "PowerSupply12VFault";
    constexpr const char* CHARGE_LIMIT_ENFORCEMENT_FAULT = "ChargeLimitEnforcementFault";
    constexpr const char* DISCHARGE_LIMIT_ENFORCEMENT_FAULT = "DischargeLimitEnforcementFault";
    constexpr const char* CHARGER_SAFETY_RELAY_FAULT = "ChargerSafetyRelayFault";
    constexpr const char* INTERNAL_MEMORY_FAULT = "InternalMemoryFault";
    constexpr const char* INTERNAL_THERMISTOR_FAULT = "InternalThermistorFault";
    constexpr const char* INTERNAL_LOGIC_FAULT = "InternalLogicFault";
    constexpr const char* DCL_REDUCED_DUE_TO_LOW_SOC = "DclReducedDueToLowSoc";
    constexpr const char* DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE = "DclReducedDueToHighCellResistance";
    constexpr const char* DCL_REDUCED_DUE_TO_TEMPERATURE = "DclReducedDueToTemperature";
    constexpr const char* DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE = "DclReducedDueToLowCellVoltage";
    constexpr const char* DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE = "DclReducedDueToLowPackVoltage";
    constexpr const char* DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE = "DclAndCclReducedDueToVoltageFailsafe";
    constexpr const char* DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE = "DclAndCclReducedDueToCommunicationFailsafe";
    constexpr const char* CCL_REDUCED_DUE_TO_HIGH_SOC = "CclReducedDueToHighSoc";
    constexpr const char* CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE = "CclReducedDueToHighCellResistance";
    constexpr const char* CCL_REDUCED_DUE_TO_TEMPERATURE = "CclReducedDueToTemperature";
    constexpr const char* CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE = "CclReducedDueToHighCellVoltage";
    constexpr const char* CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE = "CclReducedDueToHighPackVoltage";
    constexpr const char* CCL_REDUCED_DUE_TO_CHARGER_LATCH = "CclReducedDueToChargerLatch";
    constexpr const char* CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT = "CclReducedDueToAlternateCurrentLimit";
}

#endif // JSONDEFINES_H
