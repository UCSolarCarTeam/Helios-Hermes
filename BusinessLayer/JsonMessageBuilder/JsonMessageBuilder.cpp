#include "JsonMessageBuilder.h"

#include "../JsonDefines.h"

JsonMessageBuilder::JsonMessageBuilder() {}

QJsonObject JsonMessageBuilder::buildKeyMotorMessage(const KeyMotorData& data){
    QJsonObject json = QJsonObject();

    json[JsonFormat::MOTOR_SETPOINT] = data.getMotorSetpoint();
    json[JsonFormat::CONTROL_MODE] = data.getControlMode();
    json[JsonFormat::MOTOR_MODE] = data.getMotorMode();
    json[JsonFormat::SOFTWARE_ENABLE] = data.getSoftwareEnable();
    json[JsonFormat::DEBUG_MODE] = data.getDebugMode();

    return json;
}

QJsonObject JsonMessageBuilder::buildProximitySensorsMessage(const ProximitySensorsData& data){
    QJsonObject json = QJsonObject();

    json[JsonFormat::PROXIMITY_SENSOR_1] = data.getProximitySensor1();
    json[JsonFormat::PROXIMITY_SENSOR_2] = data.getProximitySensor2();
    json[JsonFormat::PROXIMITY_SENSOR_3] = data.getProximitySensor3();
    json[JsonFormat::PROXIMITY_SENSOR_4] = data.getProximitySensor4();

    return json;
}

QJsonObject JsonMessageBuilder::buildB3Message(const B3Data& data){
    QJsonObject json = QJsonObject();

    json[JsonFormat::RIGHT_SIGNAL_IN] = data.rightSignalIn();
    json[JsonFormat::LEFT_SIGNAL_IN] = data.leftSignalIn();
    json[JsonFormat::HAZARD_LIGHTS] = data.hazardLights();
    json[JsonFormat::HEADLIGHTS_SWITCH] = data.headlightsSwitch();
    json[JsonFormat::FORWARD] = data.forward();
    json[JsonFormat::HORN_SWITCH] = data.hornSwitch();
    json[JsonFormat::FORWARD_SWITCH] = data.forwardSwitch();

    json[JsonFormat::NEUTRAL] = data.neutral();
    json[JsonFormat::REVERSE] = data.reverse();
    json[JsonFormat::BRAKE_SWITCH] = data.brakeSwitch();
    json[JsonFormat::HANDBRAKE_SWITCH] = data.handBrakeSwitch();
    json[JsonFormat::MOTOR_RESET] = data.motorReset();
    json[JsonFormat::RACE_MODE] = data.raceMode();
    json[JsonFormat::LAP] = data.lap();
    json[JsonFormat::ZOOM_ZOOM] = data.zoomZoom();

    json[JsonFormat::ACCELERATION] = data.acceleration();
    json[JsonFormat::REGEN_BRAKING] = data.regenBraking();

    json[JsonFormat::RIGHT_SIGNAL_OUT] = data.rightSignalOut();
    json[JsonFormat::LEFT_SIGNAL_OUT] = data.leftSignalOut();
    json[JsonFormat::DAYTIME_RUNNING_LIGHT_SIGNAL] = data.daytimeRunningLightSignal();
    json[JsonFormat::HEADLIGHT_SIGNAL] = data.headlightSignal();
    json[JsonFormat::BRAKE_LIGHT_SIGNAL] = data.brakeLightSignal();
    json[JsonFormat::HORN_SIGNAL] = data.hornSignal();

    return json;
}

QJsonObject JsonMessageBuilder::buildTelemetryMessage(const TelemetryData& data){
    QJsonObject json = QJsonObject();

    json[JsonFormat::GPS_YEAR] = data.gpsYear();
    json[JsonFormat::GPS_MONTH] = data.gpsMonth();
    json[JsonFormat::GPS_DAY] = data.gpsDay();
    json[JsonFormat::GPS_HOUR] = data.gpsHour();
    json[JsonFormat::GPS_MINUTE] = data.gpsMinute();
    json[JsonFormat::GPS_SECOND] = data.gpsSecond();
    json[JsonFormat::GPS_VALIDITY_FLAGS] = data.gpsValidityFlags();
    json[JsonFormat::GPS_FIX_STATUS_FLAGS] = data.gpsFixStatusFlags();
    json[JsonFormat::GPS_ADDITIONAL_FLAGS] = data.gpsAdditionalFlags();
    json[JsonFormat::GPS_LONGITUDE] = data.gpsLongitude();
    json[JsonFormat::GPS_LATITUDE] = data.gpsLatitude();
    json[JsonFormat::MPU_ACCELERATION_X] = data.mpuAccelerationX();
    json[JsonFormat::MPU_ACCELERATION_Y] = data.mpuAccelerationY();
    json[JsonFormat::MPU_ACCELERATION_Z] = data.mpuAccelerationZ();
    json[JsonFormat::MPU_ROTATION_X] = data.mpuRotationX();
    json[JsonFormat::MPU_ROTATION_Y] = data.mpuRotationY();
    json[JsonFormat::MPU_ROTATION_Z] = data.mpuRotationZ();
    json[JsonFormat::MPU_TEMPERATURE] = data.mpuTemperature();

    return json;
}

QJsonObject JsonMessageBuilder::buildBatteryMessage(const BatteryData& data){
    QJsonObject json = QJsonObject();

    json[JsonFormat::BMU_ALIVE] = data.bmuAlive();

    json[JsonFormat::DISCHARGE_RELAY_ENABLED] = data.dischargeRelayEnabled();
    json[JsonFormat::CHARGE_RELAY_ENABLED] = data.chargeRelayEnabled();
    json[JsonFormat::CHARGER_SAFETY_ENABLED] = data.chargerSafetyEnabled();
    json[JsonFormat::MALFUNCTION_INDICATOR_ACTIVE] = data.malfunctionIndicatorActive();
    json[JsonFormat::MULTI_PURPOSE_INPUT_SIGNAL_STATUS] = data.multiPurposeInputSignalStatus();
    json[JsonFormat::ALWAYS_ON_SIGNAL_STATUS] = data.alwaysOnSignalStatus();
    json[JsonFormat::IS_READY_SIGNAL_STATUS] = data.isReadySignalStatus();
    json[JsonFormat::IS_CHARGING_SIGNAL_STATUS] = data.isChargingSignalStatus();

    json[JsonFormat::POPULATED_CELLS] = data.populatedCells();
    json[JsonFormat::INPUT_12V] = data.input12V();
    json[JsonFormat::FAN_VOLTAGE] = data.fanVoltage();
    json[JsonFormat::PACK_CURRENT] = data.packCurrent();
    json[JsonFormat::PACK_VOLTAGE] = data.packVoltage();
    json[JsonFormat::PACK_STATE_OF_CHARGE] = data.packStateOfCharge();
    json[JsonFormat::PACK_AMPHOURS] = data.packAmphours();
    json[JsonFormat::PACK_DEPTH_OF_DISCHARGE] = data.packDepthOfDischarge();
    json[JsonFormat::HIGH_TEMPERATURE] = data.highTemperature();
    json[JsonFormat::HIGH_THERMISTOR_ID] = data.highThermistorId();
    json[JsonFormat::LOW_TEMPERATURE] = data.lowTemperature();
    json[JsonFormat::LOW_THERMISTOR_ID] = data.lowThermistorId();
    json[JsonFormat::AVERAGE_TEMPERATURE] = data.averageTemperature();
    json[JsonFormat::INTERNAL_TEMPERATURE] = data.internalTemperature();
    json[JsonFormat::FAN_SPEED] = data.fanSpeed();
    json[JsonFormat::REQUESTED_FAN_SPEED] = data.requestedFanSpeed();
    json[JsonFormat::LOW_CELL_VOLTAGE] = data.lowCellVoltage();
    json[JsonFormat::LOW_CELL_VOLTAGE_ID] = data.lowCellVoltageId();
    json[JsonFormat::HIGH_CELL_VOLTAGE] = data.highCellVoltage();
    json[JsonFormat::HIGH_CELL_VOLTAGE_ID] = data.highCellVoltageId();
    json[JsonFormat::AVERAGE_CELL_VOLTAGE] = data.averageCellVoltage();
   
    return json;
}

QJsonObject JsonMessageBuilder::buildBatteryFaultsMessage(const BatteryFaultsData& data){
    QJsonObject json = QJsonObject();

    json[JsonFormat::INTERNAL_COMMUNICATION_FAULT] = data.internalCommunicationFault();
    json[JsonFormat::INTERNAL_CONVERSION_FAULT] = data.internalConverversionFault();
    json[JsonFormat::WEAK_CELL_FAULT] = data.weakCellFault();
    json[JsonFormat::LOW_CELL_VOLTAGE_FAULT] = data.lowCellVoltageFault();
    json[JsonFormat::OPEN_WIRING_FAULT] = data.openWiringFault();
    json[JsonFormat::CURRENT_SENSOR_FAULT] = data.currentSensorFault();
    json[JsonFormat::PACK_VOLTAGE_SENSOR_FAULT] = data.packVoltageSensorFault();
    json[JsonFormat::WEAK_PACK_FAULT] = data.weakPackFault();
    json[JsonFormat::VOLTAGE_REDUNDANCY_FAULT] = data.voltageRedundancyFault();
    json[JsonFormat::FAN_MONITOR_FAULT] = data.fanMonitorFault();
    json[JsonFormat::THERMISTOR_FAULT] = data.thermistorFault();
    json[JsonFormat::CANBUS_COMMUNICATION_FAULT] = data.canbusCommunicationFault();
    json[JsonFormat::ALWAYS_ON_SUPPLY_FAULT] = data.alwaysOnSupplyFault();
    json[JsonFormat::HIGH_VOLTAGE_ISOLATION_FAULT] = data.highVoltageIsolationFault();
    json[JsonFormat::POWER_SUPPLY_12V_FAULT] = data.powerSupply12VFault();
    json[JsonFormat::CHARGE_LIMIT_ENFORCEMENT_FAULT] = data.chargeLimitEnforcementFault();
    json[JsonFormat::DISCHARGE_LIMIT_ENFORCEMENT_FAULT] = data.dischargeLimitEnforcementFault();
    json[JsonFormat::CHARGER_SAFETY_RELAY_FAULT] = data.chargerSafetyRelayFault();
    json[JsonFormat::INTERNAL_MEMORY_FAULT] = data.internalMemoryFault();
    json[JsonFormat::INTERNAL_THERMISTOR_FAULT] = data.internalThermistorFault();
    json[JsonFormat::INTERNAL_LOGIC_FAULT] = data.internalLogicFault();

    json[JsonFormat::DCL_REDUCED_DUE_TO_LOW_SOC] = data.dclReducedDueToLowSoc();
    json[JsonFormat::DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE] = data.dclReducedDueToHighCellResistance();
    json[JsonFormat::DCL_REDUCED_DUE_TO_TEMPERATURE] = data.dclReducedDueToTemperature();
    json[JsonFormat::DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE] = data.dclReducedDueToLowCellVoltage();
    json[JsonFormat::DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE] = data.dclReducedDueToLowPackVoltage();
    json[JsonFormat::DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE] = data.dclAndCclReducedDueToVoltageFailsafe();
    json[JsonFormat::DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE] = data.dclAndCclReducedDueToCommunicationFailsafe();
    json[JsonFormat::CCL_REDUCED_DUE_TO_HIGH_SOC] = data.cclReducedDueToHighSoc();
    json[JsonFormat::CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE] = data.cclReducedDueToHighCellResistance();
    json[JsonFormat::CCL_REDUCED_DUE_TO_TEMPERATURE] = data.cclReducedDueToTemperature();
    json[JsonFormat::CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE] = data.cclReducedDueToHighCellVoltage();
    json[JsonFormat::CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE] = data.cclReducedDueToHighPackVoltage();
    json[JsonFormat::CCL_REDUCED_DUE_TO_CHARGER_LATCH] = data.cclReducedDueToChargerLatch();
    json[JsonFormat::CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT] = data.cclReducedDueToAlternateCurrentLimit();
    
    return json;
}
