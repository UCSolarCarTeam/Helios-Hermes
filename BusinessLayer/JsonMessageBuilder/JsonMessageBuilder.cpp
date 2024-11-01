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
