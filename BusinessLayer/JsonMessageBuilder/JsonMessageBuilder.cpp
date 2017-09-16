#include "JsonMessageBuilder.h"
#include "JsonForwarder/JsonDefines.h"
#include "DataLayer/KeyMotorData/I_KeyMotorData.h"
#include "DataLayer/MotorDetailsData/I_MotorDetailsData.h"
#include "DataLayer/MotorDetailsData/I_MotorDetailsUnit.h"

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
    QJsonArray motorDetailsJson = QJsonArray();

    data.getNumberOfUnits();
    for(int i = 0; i < data.getNumberOfUnits(); i++)
    {
        QJsonObject motorDetailsJsonUnit = QJsonObject();
        const I_MotorDetailsUnit& motorDetailsUnit = data.getMotorDetailsUnit(i);

        motorDetailsJsonUnit[JsonFormat::PHASE_C_CURRENT] = motorDetailsUnit.getPhaseCCurrent();
        motorDetailsJsonUnit[JsonFormat::PHASE_B_CURRENT] = motorDetailsUnit.getPhaseBCurrent();
        motorDetailsJsonUnit[JsonFormat::MOTOR_VOLTAGE_REAL] = motorDetailsUnit.getMotorVoltageReal();
        motorDetailsJsonUnit[JsonFormat::MOTOR_VOLTAGE_IMAGINARY] = motorDetailsUnit.getMotorVoltageImaginary();
        motorDetailsJsonUnit[JsonFormat::MOTOR_CURRENT_REAL] = motorDetailsUnit.getMotorCurrentReal();
        motorDetailsJsonUnit[JsonFormat::MOTOR_CURRENT_IMAGINARY] = motorDetailsUnit.getMotorCurrentImaginary();
        motorDetailsJsonUnit[JsonFormat::BACK_EMF_REAL] = motorDetailsUnit.getBackEmfReal();
        motorDetailsJsonUnit[JsonFormat::BACK_EMF_IMAGINARY] = motorDetailsUnit.getBackEmfImaginary();
        motorDetailsJsonUnit[JsonFormat::VOLTAGE_RAIL_15V_SUPPLY] = motorDetailsUnit.getVoltageRailSuppply15V();
        motorDetailsJsonUnit[JsonFormat::VOLTAGE_RAIL_3V_SUPPLY] = motorDetailsUnit.getVoltageRailSupply33V();
        motorDetailsJsonUnit[JsonFormat::VOLTAGE_RAIL_1V_SUPPLY] = motorDetailsUnit.getVoltageRailSupply19V();
        motorDetailsJsonUnit[JsonFormat::HEAT_SINK_TEMP] = motorDetailsUnit.getHeatSinkTemperature();
        motorDetailsJsonUnit[JsonFormat::MOTOR_TEMP] = motorDetailsUnit.getMotorTempterature();
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
    Q_UNUSED(data);
    return QJsonArray();
}

QJsonArray JsonMessageBuilder::buildMpptMessage(const I_MpptData& data)
{
    Q_UNUSED(data);
    return QJsonArray();
}