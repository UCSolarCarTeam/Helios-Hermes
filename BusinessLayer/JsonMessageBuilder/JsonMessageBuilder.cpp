#include "JsonMessageBuilder.h"
#include "JsonForwarder/JsonDefines.h"
#include "DataLayer/KeyMotorData/I_KeyMotorData.h"
#include "DataLayer/MotorDetailsData/I_MotorDetailsData.h"
#include "DataLayer/MotorDetailsData/I_MotorDetailsUnit.h"
#include "DataLayer/DriverControlsData/I_DriverControlsData.h"
#include "DataLayer/MotorFaultsData/I_MotorFaultsData.h"

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
    QJsonObject driverControlsJson = QJsonObject();
    driverControlsJson[JsonFormat::ALIVE] = data.getDriverControlsBoardAlive();
    driverControlsJson[JsonFormat::HEADLIGHTS_OFF] = data.getHeadlightsOff();
    driverControlsJson[JsonFormat::HEADLIGHTS_LOW] = data.getHeadlightsLow();
    driverControlsJson[JsonFormat::HEADLIGHTS_HIGH] = data.getHeadlightsHigh();
    driverControlsJson[JsonFormat::SIGNAL_RIGHT] = data.getSignalRight();
    driverControlsJson[JsonFormat::SIGNAL_LEFT] = data.getSignalLeft();
    driverControlsJson[JsonFormat::HAZARD] = data.getHazard();
    driverControlsJson[JsonFormat::INTERIOR] = data.getInterior();
    driverControlsJson[JsonFormat::AUX] = data.getAux();
    driverControlsJson[JsonFormat::VOLUME_UP] = data.getVolumeUp();
    driverControlsJson[JsonFormat::VOLUME_DOWN] = data.getVolumeDown();
    driverControlsJson[JsonFormat::NEXT_SONG] = data.getNextSong();
    driverControlsJson[JsonFormat::PREV_SONG] = data.getPreviousSong();
    driverControlsJson[JsonFormat::BRAKES] = data.getBrakes();
    driverControlsJson[JsonFormat::FORWARD] = data.getForward();
    driverControlsJson[JsonFormat::REVERSE] = data.getReverse();
    driverControlsJson[JsonFormat::PUSH_TO_TALK] = data.getPushToTalk();
    driverControlsJson[JsonFormat::HORN] = data.getHorn();
    driverControlsJson[JsonFormat::RESET] = data.getReset();
    driverControlsJson[JsonFormat::ACCELERATION] = float(data.getAcceleration()) / 10000;
    driverControlsJson[JsonFormat::REGEN_BRAKING] = float(data.getRegenBraking()) / 10000;

    return driverControlsJson;
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
    m0LimitsFlagsJson[JsonFormat::IPM_OR_MOTOR_TEMPERATURE] = data.m0IpmOrMotorTelemetryLimit();
    motor0FaultsJson[JsonFormat::LIMITS_FLAGS] = m0LimitsFlagsJson;

    QJsonObject m1LimitsFlagsJson = QJsonObject();
    m1LimitsFlagsJson[JsonFormat::OUTPUT_VOLTAGE_PWM] = data.m1OutputVoltagePwmLimit();
    m1LimitsFlagsJson[JsonFormat::MOTOR_CURRENT] = data.m1MotorCurrentLimit();
    m1LimitsFlagsJson[JsonFormat::VELOCITY] = data.m1VelocityLimit();
    m1LimitsFlagsJson[JsonFormat::BUS_CURRENT] = data.m1BusCurrentLimit();
    m1LimitsFlagsJson[JsonFormat::BUS_VOLTAGE_UPPER] = data.m1BusVoltageUpperLimit();
    m1LimitsFlagsJson[JsonFormat::BUS_VOLTAGE_LOWER] = data.m1BusVoltageLowerLimit();
    m1LimitsFlagsJson[JsonFormat::IPM_OR_MOTOR_TEMPERATURE] = data.m1IpmOrMotorTelemetryLimit();
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
    Q_UNUSED(data);
    return QJsonArray();
}