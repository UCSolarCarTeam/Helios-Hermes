#include "JsonMessageBuilder.h"

#include "../JsonForwarder/JsonDefines.h"
#include "../../CommunicationLayer/PacketDecoder/PacketDecoder.h"
#include "../../CommunicationLayer/PacketChecksumChecker/I_PacketChecksumChecker.h"
#include "../../DataLayer/KeyMotorData/I_KeyMotorData.h"
#include "../../DataLayer/MotorDetailsData/I_MotorDetailsData.h"
#include "../../DataLayer/MotorDetailsData/I_MotorDetailsUnit.h"
#include "../../DataLayer/DriverControlsData/I_DriverControlsData.h"
#include "../../DataLayer/MotorFaultsData/I_MotorFaultsData.h"
#include "../../DataLayer/BatteryFaultsData/I_BatteryFaultsData.h"
#include "../../DataLayer/BatteryData/I_BatteryData.h"
#include "../../DataLayer/MpptData/I_MpptData.h"
#include "../../DataLayer/LightsData/I_LightsData.h"
#include "../../DataLayer/AuxBmsData/I_AuxBmsData.h"
#include "../../DataLayer/CcsData/I_CcsData.h"
#include "../../DataLayer/CcsData/CcsData.h"
#include "../../DataLayer/WiegandData/I_WiegandData.h"
#include "../../DataLayer/WiegandData/WiegandData.h"

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

QJsonObject JsonMessageBuilder::buildMbmsMessage(const MbmsData& data){
    QJsonObject json = QJsonObject();

    json[JsonFormat::COMMON_CONTACTOR_STATE] = data.commonContactorState();
    json[JsonFormat::MOTOR_CONTACTOR_STATE] = data.motorContactorState();
    json[JsonFormat::ARRAY_CONTACTOR_STATE] = data.arrayContactorState();
    json[JsonFormat::LV_CONTACTOR_STATE] = data.lvContactorState();
    json[JsonFormat::CHARGE_CONTACTOR_STATE] = data.chargeContactorState();
    json[JsonFormat::COMMON_CONTACTOR_ERROR] = data.commonContactorError();
    json[JsonFormat::MOTOR_CONTACTOR_ERROR] = data.motorContactorError();
    json[JsonFormat::ARRAY_CONTACTOR_ERROR] = data.arrayContactorError();
    json[JsonFormat::LV_CONTACTOR_ERROR] = data.lvContactorError();
    json[JsonFormat::CHARGE_CONTACTOR_ERROR] = data.chargeContactorError();
    json[JsonFormat::STROBE_BMS_LIGHT] = data.strobeBmsLight();
    json[JsonFormat::ALLOW_CHARGE] = data.allowCharge();
    json[JsonFormat::HIGH_VOLTAGE_ENABLE_STATE] = data.highVoltageEnableState();
    json[JsonFormat::ALLOW_DISCHARGE] = data.allowDischarge();
    json[JsonFormat::ORION_CAN_RECEIVED_RECENTLY] = data.orionCanReceivedRecently();
    json[JsonFormat::DISCHARGE_SHOULD_TRIP] = data.dischargeShouldTrip();
    json[JsonFormat::CHARGE_SHOULD_TRIP] = data.chargeShouldTrip();
    json[JsonFormat::AUXILLARY_BATTERY_VOLTAGE] = data.auxillaryBatteryVoltage();
    json[JsonFormat::MOTOR_VOLTAGE] = data.motorVoltage();
    json[JsonFormat::ARRAY_VOLTAGE] = data.arrayVoltage();
    json[JsonFormat::LV_VOLTAGE] = data.lvVoltage();
    json[JsonFormat::CHARGE_VOLTAGE] = data.chargeVoltage();
    json[JsonFormat::COMMON_CURRENT] = data.commonCurrent();
    json[JsonFormat::MOTOR_CURRENT] = data.motorCurrent();
    json[JsonFormat::ARRAY_CURRENT] = data.arrayCurrent();
    json[JsonFormat::LV_CURRENT] = data.lvCurrent();
    json[JsonFormat::CHARGE_CURRENT] = data.chargeCurrent();
    json[JsonFormat::HIGH_CELL_VOLTAGE_TRIP] = data.highCellVoltageTrip();
    json[JsonFormat::LOW_CELL_VOLTAGE_TRIP] = data.lowCellVoltageTrip();
    json[JsonFormat::HIGH_COMMON_CURRENT_TRIP] = data.highCommonCurrentTrip();
    json[JsonFormat::MOTOR_HIGH_TEMPERATURE_CURRENT_TRIP] = data.motorHighTemperatureCurrentTrip();
    json[JsonFormat::ARRAY_HIGH_TEMPERATURE_CURRENT_TRIP] = data.arrayHighTemperatureCurrentTrip();
    json[JsonFormat::LV_HIGH_TEMPERATURE_CURRENT_TRIP] = data.lvHighTemperatureCurrentTrip();
    json[JsonFormat::CHARGE_HIGH_TEMPERATURE_CURRENT_TRIP] = data.chargeHighTemperatureCurrentTrip();
    json[JsonFormat::PROTECTION_TRIP] = data.protectionTrip();
    json[JsonFormat::ORION_MESSAGE_TIMEOUT_TRIP] = data.orionMessageTimeoutTrip();
    json[JsonFormat::CONTACTOR_DISCONNECTED_UNEXPECTEDLY_TRIP] = data.contactorDisconnectedUnexpectedlyTrip();

    return json;
}

QJsonArray JsonMessageBuilder::buildMpptMessage(const MpptData& data){
    QJsonArray json = QJsonArray();

    for(int i = 0; i < data.getNumberOfUnits(); i++){
        QJsonObject unitJson = QJsonObject();
        const MpptUnit& unit = data.getMpptUnit(i);

        unitJson[JsonFormat::ALIVE] = unit.mpptStatus();
        unitJson[JsonFormat::ARRAY_VOLTAGE] = unit.arrayVoltage();
        unitJson[JsonFormat::ARRAY_CURRENT] = unit.arrayCurrent();
        unitJson[JsonFormat::BATTERY_VOLTAGE] = unit.batteryVoltage();
        unitJson[JsonFormat::TEMPERATURE] = unit.temperature();

        json.append(unitJson);
    }

    return json;
}

QJsonArray JsonMessageBuilder::buildMotorDetailsMessage(const MotorDetailsData& data){
    QJsonArray json = QJsonArray();

    for(int i = 0; i < data.getNumberOfUnits(); i++){
        QJsonObject motorJson = QJsonObject();
        const MotorDetailsUnit& motor = data.getMotorDetailsUnit(i);

        motorJson[JsonFormat::CONTROL_VALUE] = motor.controlValue();
        motorJson[JsonFormat::CONTROL_MODE] = motor.controlMode();
        motorJson[JsonFormat::MOTOR_MODE] = motor.motorMode();
        motorJson[JsonFormat::SOFTWARE_ENABLE] = motor.softwareEnable();
        motorJson[JsonFormat::DEBUG_MODE] = motor.debugMode();

        motorJson[JsonFormat::CURRENT_MOTOR_TORQUE] = motor.currentMotorTorque();
        motorJson[JsonFormat::CURRENT_RPM_VALUE] = motor.currentRpmValue();
        motorJson[JsonFormat::MOTOR_TEMPERATURE] = motor.motorTemperature();
        motorJson[JsonFormat::INVERTER_PEAK_CURRENT] = motor.inverterPeakCurrent();
        motorJson[JsonFormat::CURRENT_MOTOR_POWER] = motor.currentMotorPower();
        motorJson[JsonFormat::ABSOLUTE_ANGLE] = motor.AbsoluteAngle();

        motorJson[JsonFormat::MOTOR_ABOUT_TO_STALL] = motor.motorAboutToStall();
        motorJson[JsonFormat::DELAY_IN_READING_TEMP_SENSOR] = motor.delayInReadingTempSensor();
        motorJson[JsonFormat::DELAY_IN_READING_POS_SENSOR] = motor.delayInReadingPosSensor();
        motorJson[JsonFormat::INVERTER1_TEMP_VERY_HIGH] = motor.inverter1TempVeryHigh();
        motorJson[JsonFormat::INVERTER2_TEMP_VERY_HIGH] = motor.inverter2TempVeryHigh();
        motorJson[JsonFormat::INVERTER3_TEMP_VERY_HIGH] = motor.inverter3TempVeryHigh();
        motorJson[JsonFormat::INVERTER4_TEMP_VERY_HIGH] = motor.inverter4TempVeryHigh();
        motorJson[JsonFormat::INVERTER5_TEMP_VERY_HIGH] = motor.inverter5TempVeryHigh();

        motorJson[JsonFormat::INVERTER6_TEMP_VERY_HIGH] = motor.inverter6TempVeryHigh();
        motorJson[JsonFormat::CPU_TEMPERATURE_VERY_HIGH] = motor.cpuTemperatureVeryHigh();
        motorJson[JsonFormat::HALL_TEMPERATURE_VERY_HIGH] = motor.hallTemperatureVeryHigh();
        motorJson[JsonFormat::DCLINK_TEMPERATURE_VERY_HIGH] = motor.dclinkTemperatureVeryHigh();
        motorJson[JsonFormat::DELAY_IN_DCLINK_COMMUNICATION] = motor.delayInDclinkCommunication();
        motorJson[JsonFormat::INVERTER1_OVER_CURRENT] = motor.inverter1OverCurrent();
        motorJson[JsonFormat::INVERTER2_OVER_CURRENT] = motor.inverter2OverCurrent();
        motorJson[JsonFormat::INVERTER3_OVER_CURRENT] = motor.inverter3OverCurrent();

        motorJson[JsonFormat::INVERTER4_OVER_CURRENT] = motor.inverter4OverCurrent();
        motorJson[JsonFormat::INVERTER5_OVER_CURRENT] = motor.inverter5OverCurrent();
        motorJson[JsonFormat::INVERTER6_OVER_CURRENT] = motor.inverter6OverCurrent();
        motorJson[JsonFormat::DC_OVERVOLTAGE_WARNING] = motor.dcOvervoltageWarning();
        motorJson[JsonFormat::DC_UNDERVOLTAGE_WARNING] = motor.dcUndervoltageWarning();
        motorJson[JsonFormat::CAN_COMMS_TIMEOUT_WARNING] = motor.canCommsTimeout();
        motorJson[JsonFormat::INVERTER1_FAULT_WARNING] = motor.inverter1faultWarning();
        motorJson[JsonFormat::INVERTER2_FAULT_WARNING] = motor.inverter2faultWarning();

        motorJson[JsonFormat::INVERTER3_FAULT_WARNING] = motor.inverter3faultWarning();
        motorJson[JsonFormat::INVERTER4_FAULT_WARNING] = motor.inverter4faultWarning();
        motorJson[JsonFormat::INVERTER5_FAULT_WARNING] = motor.inverter5faultWarning();
        motorJson[JsonFormat::INVERTER6_FAULT_WARNING] = motor.inverter6faultWarning();
        motorJson[JsonFormat::CAN_SEND_WARNING] = motor.canSendWarning();
        motorJson[JsonFormat::LOST_FRAMES_ON_CAN_BUS_WARNING] = motor.lostFramesOnCanBusWarning();
        motorJson[JsonFormat::OVERSPEED_WARNING] = motor.overspeedWarning();
        motorJson[JsonFormat::CPU_OVERLOAD] = motor.cpuOverload();

        motorJson[JsonFormat::TORQUE_LIMITED] = motor.torqueLimited();
        motorJson[JsonFormat::START_AT_HIGH_RPM] = motor.startAtHighRpm();

        motorJson[JsonFormat::INIT_ERROR] = motor.initError();
        motorJson[JsonFormat::SETTINGS_NOT_FOUND] = motor.settingsNotFound();
        motorJson[JsonFormat::MOTOR_STALLED] = motor.motorStalled();
        motorJson[JsonFormat::CONTROLLER_DATA_READING_TIMEOUT] = motor.controllerDataReadingTimeout();
        motorJson[JsonFormat::INVALID_HALL_SENSOR_SEQUENCE] = motor.invalidHallSensorSequence();
        motorJson[JsonFormat::INVALID_HALL_SECTOR] = motor.invalidHallSector();
        motorJson[JsonFormat::ERROR_READING_TEMP_SENSOR] = motor.errorReadingTempSensor();
        motorJson[JsonFormat::POSITION_SENSOR_READING_ERROR] = motor.positionSensorReadingError();

        motorJson[JsonFormat::ERROR_READING_ENCODER] = motor.errorReadingEncoder();
        motorJson[JsonFormat::ZERO_POSITION_OFFSET_NOT_SET] = motor.zeroPositionOffsetNotSet();
        motorJson[JsonFormat::HW_ENABLE_NOT_SET] = motor.hwEnableNotSet();
        motorJson[JsonFormat::INVERTER1_TEMP_TOO_HIGH] = motor.inverter1TempTooHigh();
        motorJson[JsonFormat::INVERTER2_TEMP_TOO_HIGH] = motor.inverter2TempTooHigh();
        motorJson[JsonFormat::INVERTER3_TEMP_TOO_HIGH] = motor.inverter3TempTooHigh();
        motorJson[JsonFormat::INVERTER4_TEMP_TOO_HIGH] = motor.inverter4TempTooHigh();
        motorJson[JsonFormat::INVERTER5_TEMP_TOO_HIGH] = motor.inverter5TempTooHigh();

        motorJson[JsonFormat::INVERTER6_TEMP_TOO_HIGH] = motor.inverter6TempTooHigh();
        motorJson[JsonFormat::CPU_TEMPERATURE_TOO_HIGH] = motor.cpuTemperatureTooHigh();
        motorJson[JsonFormat::HALL_TEMP_TOO_HIGH] = motor.hallTemperatureTooHigh();
        motorJson[JsonFormat::DCLINK_TEMP_TOO_HIGH] = motor.dclinkTemperatureTooHigh();
        motorJson[JsonFormat::ERROR_IN_DCLINK_COMMUNICATION] = motor.errorInDclinkCommunication();
        motorJson[JsonFormat::INVERTER1_OVERCURRENT] = motor.inverter1Overcurrent();
        motorJson[JsonFormat::INVERTER2_OVERCURRENT] = motor.inverter2Overcurrent();
        motorJson[JsonFormat::INVERTER3_OVERCURRENT] = motor.inverter3Overcurrent();

        motorJson[JsonFormat::INVERTER4_OVERCURRENT] = motor.inverter4Overcurrent();
        motorJson[JsonFormat::INVERTER5_OVERCURRENT] = motor.inverter5Overcurrent();
        motorJson[JsonFormat::INVERTER6_OVERCURRENT] = motor.inverter6Overcurrent();
        motorJson[JsonFormat::DC_UNDERVOLTAGE_ERROR] = motor.dcUndervoltageError();
        motorJson[JsonFormat::DC_OVERVOLTAGE_ERROR] = motor.dcOvervoltageError();
        //motorJson[JsonFormat::DOUBLE_CAN_ID_ON_BUS] = motor.doubleCanIdOnBus(); FIX
        motorJson[JsonFormat::CAN_COMMS_TIMEOUT_ERROR] = motor.canCommsTimeoutError();
        motorJson[JsonFormat::INVERTER1_FAULT_ERROR] = motor.inverter1FaultError();
        motorJson[JsonFormat::INVERTER2_FAULT_ERROR] = motor.inverter2FaultError();
        motorJson[JsonFormat::INVERTER3_FAULT_ERROR] = motor.inverter3FaultError();
        motorJson[JsonFormat::INVERTER4_FAULT_ERROR] = motor.inverter4FaultError();
        motorJson[JsonFormat::INVERTER5_FAULT_ERROR] = motor.inverter5FaultError();
        motorJson[JsonFormat::INVERTER6_FAULT_ERROR] = motor.inverter6FaultError();
        motorJson[JsonFormat::CAN_SEND_ERROR] = motor.canSendError();
        motorJson[JsonFormat::LOST_FRAMES_ON_CAN_BUS_ERROR] = motor.lostFramesOnCanBusError();
        motorJson[JsonFormat::OVERSPEED_ERROR] = motor.overspeedError();

        motorJson[JsonFormat::CPU_OVERLOADED] = motor.cpuOverloaded();

        json.append(motorJson);
    }

    return json;
}

QJsonObject JsonMessageBuilder::buildLightsMessage(const I_LightsData& data)
{
    QJsonObject lightsJson = QJsonObject();
    lightsJson[JsonFormat::LIGHTS_ALIVE] = data.getAlive();
    lightsJson[JsonFormat::LIGHTS_LOW_BEAMS] = data.getLowBeams();
    lightsJson[JsonFormat::LIGHTS_HIGH_BEAMS] = data.getHighBeams();
    lightsJson[JsonFormat::LIGHTS_BRAKES] = data.getBrakes();
    lightsJson[JsonFormat::LIGHTS_LEFT_SIGNAL] = data.getLeftSignal();
    lightsJson[JsonFormat::LIGHTS_RIGHT_SIGNAL] = data.getRightSignal();
    lightsJson[JsonFormat::LIGHTS_BMS_STROBE_LIGHT] = data.getBmsStrobeLight();

    return lightsJson;
}

QJsonArray JsonMessageBuilder::buildMotorDetailsMessage(const I_MotorDetailsData& data)
{
    QJsonArray motorDetailsJson = QJsonArray();

    for (int i = 0; i < data.getNumberOfUnits(); i++)
    {
        QJsonObject motorDetailsJsonUnit = QJsonObject();
        const I_MotorDetailsUnit& motorDetailsUnit = data.getMotorDetailsUnit(i);

        motorDetailsJsonUnit[JsonFormat::PHASE_C_CURRENT] = motorDetailsUnit.getPhaseCCurrent();
        motorDetailsJsonUnit[JsonFormat::PHASE_B_CURRENT] = motorDetailsUnit.getPhaseBCurrent();
        motorDetailsJsonUnit[JsonFormat::MOTOR_VOLTAGE_REAL] = motorDetailsUnit.getMotorVoltageReal();
        motorDetailsJsonUnit[JsonFormat::MOTOR_VOLTAGE_IMAGINARY] = motorDetailsUnit.getMotorVoltageImaginary();
        motorDetailsJsonUnit[JsonFormat::MOTOR_CURRENT_REAL] = motorDetailsUnit.getMotorCurrentReal();
        motorDetailsJsonUnit[JsonFormat::MOTOR_CURRENT_IMAGINARY] = motorDetailsUnit.getMotorCurrentImaginary();
        motorDetailsJsonUnit[JsonFormat::BACK_EMF] = motorDetailsUnit.getBackEmf();
        motorDetailsJsonUnit[JsonFormat::VOLTAGE_RAIL_15V_SUPPLY] = motorDetailsUnit.getVoltageRailSuppply15V();
        motorDetailsJsonUnit[JsonFormat::VOLTAGE_RAIL_3V_SUPPLY] = motorDetailsUnit.getVoltageRailSupply33V();
        motorDetailsJsonUnit[JsonFormat::VOLTAGE_RAIL_1V_SUPPLY] = motorDetailsUnit.getVoltageRailSupply19V();
        motorDetailsJsonUnit[JsonFormat::HEAT_SINK_TEMP] = motorDetailsUnit.getHeatSinkTemperature();
        motorDetailsJsonUnit[JsonFormat::MOTOR_TEMP] = motorDetailsUnit.getMotorTemperature();
        motorDetailsJsonUnit[JsonFormat::DSP_BOARD_TEMP] = motorDetailsUnit.getDspBoardTemperature();
        motorDetailsJsonUnit[JsonFormat::DC_BUS_AMP_HOURS] = motorDetailsUnit.getDcBusAmpHours();
        motorDetailsJsonUnit[JsonFormat::ODOMETER_] = motorDetailsUnit.getOdometer();
        motorDetailsJsonUnit[JsonFormat::SLIP_SPEED] = motorDetailsUnit.getSlipSpeed();

        motorDetailsJson.append(motorDetailsJsonUnit);
    }

    return motorDetailsJson;
}

QJsonArray JsonMessageBuilder::buildMotorFaultsMessage(const I_MotorFaultsData& data)
{
    QJsonArray motorFaultsJson = QJsonArray();
    QJsonObject motor0FaultsJson = QJsonObject();
    QJsonObject motor1FaultsJson = QJsonObject();

    QJsonObject m0ErrorFlagsJson = QJsonObject();
    m0ErrorFlagsJson[JsonFormat::MOTOR_OVER_SPEED] = data.m0MotorOverSpeed();
    m0ErrorFlagsJson[JsonFormat::SOFTWARE_OVER_CURRENT] = data.m0SoftwareOverCurrent();
    m0ErrorFlagsJson[JsonFormat::DC_BUS_OVER_VOLTAGE] = data.m0DcBusOverVoltage();
    m0ErrorFlagsJson[JsonFormat::BAD_MOTOR_POSITION_HALL_SEQUENCE] = data.m0BadMotorPositionHallSequence();
    m0ErrorFlagsJson[JsonFormat::WATCHDOG_CAUSED_LAST_RESET] = data.m0WatchdogCausedLastReset();
    m0ErrorFlagsJson[JsonFormat::CONFIG_READ_ERROR] = data.m0ConfigReadError();
    m0ErrorFlagsJson[JsonFormat::RAIL_15V_UNDER_VOLTAGE_LOCK_OUT] = data.m0RailUnderVoltageLockOut();
    m0ErrorFlagsJson[JsonFormat::DESATURATION_FAULT] = data.m0DesaturationFault();
    motor0FaultsJson[JsonFormat::ERROR_FLAGS] = m0ErrorFlagsJson;

    QJsonObject m1ErrorFlagsJson = QJsonObject();
    m1ErrorFlagsJson[JsonFormat::MOTOR_OVER_SPEED] = data.m1MotorOverSpeed();
    m1ErrorFlagsJson[JsonFormat::SOFTWARE_OVER_CURRENT] = data.m1SoftwareOverCurrent();
    m1ErrorFlagsJson[JsonFormat::DC_BUS_OVER_VOLTAGE] = data.m1DcBusOverVoltage();
    m1ErrorFlagsJson[JsonFormat::BAD_MOTOR_POSITION_HALL_SEQUENCE] = data.m1BadMotorPositionHallSequence();
    m1ErrorFlagsJson[JsonFormat::WATCHDOG_CAUSED_LAST_RESET] = data.m1WatchdogCausedLastReset();
    m1ErrorFlagsJson[JsonFormat::CONFIG_READ_ERROR] = data.m1ConfigReadError();
    m1ErrorFlagsJson[JsonFormat::RAIL_15V_UNDER_VOLTAGE_LOCK_OUT] = data.m1RailUnderVoltageLockOut();
    m1ErrorFlagsJson[JsonFormat::DESATURATION_FAULT] = data.m1DesaturationFault();
    motor1FaultsJson[JsonFormat::ERROR_FLAGS] = m1ErrorFlagsJson;

    QJsonObject m0LimitsFlagsJson = QJsonObject();
    m0LimitsFlagsJson[JsonFormat::OUTPUT_VOLTAGE_PWM] = data.m0OutputVoltagePwmLimit();
    m0LimitsFlagsJson[JsonFormat::MOTOR_CURRENT] = data.m0MotorCurrentLimit();
    m0LimitsFlagsJson[JsonFormat::VELOCITY] = data.m0VelocityLimit();
    m0LimitsFlagsJson[JsonFormat::BUS_CURRENT] = data.m0BusCurrentLimit();
    m0LimitsFlagsJson[JsonFormat::BUS_VOLTAGE_UPPER] = data.m0BusVoltageUpperLimit();
    m0LimitsFlagsJson[JsonFormat::BUS_VOLTAGE_LOWER] = data.m0BusVoltageLowerLimit();
    m0LimitsFlagsJson[JsonFormat::IPM_OR_MOTOR_TEMPERATURE] = data.m0IpmOrMotorTemperatureLimit();
    motor0FaultsJson[JsonFormat::LIMITS_FLAGS] = m0LimitsFlagsJson;

    QJsonObject m1LimitsFlagsJson = QJsonObject();
    m1LimitsFlagsJson[JsonFormat::OUTPUT_VOLTAGE_PWM] = data.m1OutputVoltagePwmLimit();
    m1LimitsFlagsJson[JsonFormat::MOTOR_CURRENT] = data.m1MotorCurrentLimit();
    m1LimitsFlagsJson[JsonFormat::VELOCITY] = data.m1VelocityLimit();
    m1LimitsFlagsJson[JsonFormat::BUS_CURRENT] = data.m1BusCurrentLimit();
    m1LimitsFlagsJson[JsonFormat::BUS_VOLTAGE_UPPER] = data.m1BusVoltageUpperLimit();
    m1LimitsFlagsJson[JsonFormat::BUS_VOLTAGE_LOWER] = data.m1BusVoltageLowerLimit();
    m1LimitsFlagsJson[JsonFormat::IPM_OR_MOTOR_TEMPERATURE] = data.m1IpmOrMotorTemperatureLimit();
    motor1FaultsJson[JsonFormat::LIMITS_FLAGS] = m1LimitsFlagsJson;

    motor0FaultsJson[JsonFormat::RX_ERROR_COUNT] = data.getM0CanRxErrorCount();
    motor0FaultsJson[JsonFormat::TX_ERROR_COUNT] = data.getM0CanTxErrorCount();
    motor1FaultsJson[JsonFormat::RX_ERROR_COUNT] = data.getM1CanRxErrorCount();
    motor1FaultsJson[JsonFormat::TX_ERROR_COUNT] = data.getM1CanTxErrorCount();
    motorFaultsJson.append(motor0FaultsJson);
    motorFaultsJson.append(motor1FaultsJson);

    return motorFaultsJson;
}

QJsonArray JsonMessageBuilder::buildMpptMessage(const I_MpptData& data)
{
    QJsonArray mpptJson = QJsonArray();

    for (int i = 0; i < data.getNumberOfUnits(); i++)
    {
        QJsonObject mpptJsonUnit = QJsonObject();
        const I_MpptUnit& mpptUnit = data.getMpptUnit(i);

        if (mpptUnit.getMpptStatus())
        {
            mpptJsonUnit[JsonFormat::ALIVE] = true;
        }
        else
        {
            mpptJsonUnit[JsonFormat::ALIVE] = false;
        }

        mpptJsonUnit[JsonFormat::ARRAY_VOLTAGE] = mpptUnit.getArrayVoltage();
        mpptJsonUnit[JsonFormat::ARRAY_CURRENT] = mpptUnit.getArrayCurrent();
        mpptJsonUnit[JsonFormat::BATTERY_VOLTAGE] = mpptUnit.getBatteryVoltage();
        mpptJsonUnit[JsonFormat::TEMPERATURE] = mpptUnit.getTemperature();

        mpptJson.append(mpptJsonUnit);
    }

    return mpptJson;
}

QJsonObject JsonMessageBuilder::buildWiegandMessage(const I_WiegandData& data) {
    QJsonObject wiegandJson;  // Create a JSON object to hold the message
    // qDebug() << "Building Wiegand message";

    int wiegandId = data.getWiegandId(); // Ensure this method exists in I_WiegandData

    wiegandJson["wiegandId"] = wiegandId;

    return wiegandJson; // Return the constructed JSON object
}
