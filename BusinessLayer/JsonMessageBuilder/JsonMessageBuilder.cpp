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
