#include "JsonMessageBuilder.h"
#include "JsonForwarder/JsonDefines.h"
#include "DataLayer/KeyMotorData/KeyMotorData.h"

JsonMessageBuilder::JsonMessageBuilder()
{
}

QJsonObject JsonMessageBuilder::buildBatteryMessage(const I_BatteryData& data)
{
    Q_UNUSED(data);
    return QJsonObject();
}

QJsonObject JsonMessageBuilder::buildBatteryFaultsMessage(const I_BatteryFaultsData& data)
{
    Q_UNUSED(data);
    return QJsonObject();
}

QJsonObject JsonMessageBuilder::buildDriverControlsMessage(const I_DriverControlsData& data)
{
    Q_UNUSED(data);
    return QJsonObject();
}

QJsonArray JsonMessageBuilder::buildKeyMotorMessage(const I_KeyMotorData& data)
{

    QJsonObject keyMotor0Json = QJsonObject();
    keyMotor0Json[JsonFormat::ALIVE] = false;

    if (data.getM0Alive() != 0)
    {
        keyMotor0Json[JsonFormat::ALIVE] = true;

    }

    keyMotor0Json[JsonFormat::SET_CURRENT] = data.getM0SetCurrent();
    keyMotor0Json[JsonFormat::SET_VELOCITY] = data.getM0SetVelocity();
    keyMotor0Json[JsonFormat::BUS_CURRENT] = data.getM0BusCurrent();
    keyMotor0Json[JsonFormat::BUS_VOLTAGE] = data.getM0BusVoltage();
    keyMotor0Json[JsonFormat::VEHICLE_VELOCITY] = data.getM0VehicleVelocity();

    QJsonObject keyMotor1Json = QJsonObject();
    keyMotor1Json[JsonFormat::ALIVE] = false;

    if (data.getM1Alive() != 0)
    {
        keyMotor1Json[JsonFormat::ALIVE] = true;

    }

    keyMotor1Json[JsonFormat::SET_CURRENT] = data.getM1SetCurrent();
    keyMotor1Json[JsonFormat::SET_VELOCITY] = data.getM1SetVelocity();
    keyMotor1Json[JsonFormat::BUS_CURRENT] = data.getM1BusCurrent();
    keyMotor1Json[JsonFormat::BUS_VOLTAGE] = data.getM1BusVoltage();
    keyMotor1Json[JsonFormat::VEHICLE_VELOCITY] = data.getM1VehicleVelocity();

    QJsonArray keyMotorJson =
    {
        keyMotor0Json,
        keyMotor1Json
    };
    return keyMotorJson;
}

QJsonObject JsonMessageBuilder::buildLightsMessage(const I_LightsData& data)
{
    Q_UNUSED(data);
    return QJsonObject();
}

QJsonArray JsonMessageBuilder::buildMotorDetailsMessage(const I_MotorDetailsData& data)
{
    Q_UNUSED(data);
    return QJsonArray();
}

QJsonArray JsonMessageBuilder::buildMotorFaultsMessage(const I_MotorFaultsData& data)
{
    Q_UNUSED(data);
    return QJsonArray();
}

QJsonArray JsonMessageBuilder::buildMpptMessage(const I_MpptData& data)
{
    Q_UNUSED(data);
    return QJsonArray();
}