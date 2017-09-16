#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QTest>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QScopedPointer>

#include "BusinessLayer/JsonMessageBuilder/JsonMessageBuilder.h"
#include "BusinessLayer/JsonForwarder/JsonDefines.h"

#include "Tests/DataLayer/KeyMotorData/MockKeyMotorData.h"
#include "Tests/DataLayer/MotorDetailsData/MockMotorDetailsData.h"
#include "Tests/DataLayer/MotorDetailsData/MockMotorDetailsUnit.h"
#include "Tests/DataLayer/DriverControlsData/MockDriverControlsData.h"

using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::NiceMock;

class JsonMessageBuilderTest : public ::testing::Test
{
};

TEST(JsonMessageBuilderTest, keyMotor)
{
    JsonMessageBuilder jsonMessageBuilder_;

    QString EXPECTED_JSON_MSG = "\
                                [\
    {\
        \"Alive\":true,\
        \"SetCurrent\":1,\
        \"SetVelocity\":2,\
        \"BusCurrent\":3,\
        \"BusVoltage\":4,\
        \"VehicleVelocity\":5\
    },\
    {\
        \"Alive\":false,\
        \"SetCurrent\":6,\
        \"SetVelocity\":7,\
        \"BusCurrent\":8,\
        \"BusVoltage\":9,\
        \"VehicleVelocity\":10\
    }\
                                ]";

    QJsonDocument EXPECTED_JSON_DOC = QJsonDocument::fromJson(EXPECTED_JSON_MSG.toLatin1());
    QJsonArray EXPECTED_JSON_ARRAY = EXPECTED_JSON_DOC.array();

    NiceMock<MockKeyMotorData> mockKeyMotorData;
    const unsigned char M0_ALIVE_VAL = true;
    const float M0_SET_CURRENT_VAL = 1;
    const float M0_SET_VELOCITY_VAL = 2;
    const float M0_BUS_CURRENT_VAL = 3;
    const float M0_BUS_VOLTAGE_VAL = 4;
    const float M0_VEHICLE_VELOCITY_VAL = 5;
    const unsigned char M1_ALIVE_VAL = false;
    const float M1_SET_CURRENT_VAL = 6;
    const float M1_SET_VELOCITY_VAL = 7;
    const float M1_BUS_CURRENT_VAL = 8;
    const float M1_BUS_VOLTAGE_VAL = 9;
    const float M1_VEHICLE_VELOCITY_VAL = 10;

    ON_CALL(mockKeyMotorData, getM0Alive())
    .WillByDefault(Return(M0_ALIVE_VAL));
    ON_CALL(mockKeyMotorData, getM0SetCurrent())
    .WillByDefault(Return(M0_SET_CURRENT_VAL));
    ON_CALL(mockKeyMotorData, getM0SetVelocity())
    .WillByDefault(Return(M0_SET_VELOCITY_VAL));
    ON_CALL(mockKeyMotorData, getM0BusCurrent())
    .WillByDefault(Return(M0_BUS_CURRENT_VAL));
    ON_CALL(mockKeyMotorData, getM0BusVoltage())
    .WillByDefault(Return(M0_BUS_VOLTAGE_VAL));
    ON_CALL(mockKeyMotorData, getM0VehicleVelocity())
    .WillByDefault(Return(M0_VEHICLE_VELOCITY_VAL));

    ON_CALL(mockKeyMotorData, getM1Alive())
    .WillByDefault(Return(M1_ALIVE_VAL));
    ON_CALL(mockKeyMotorData, getM1SetCurrent())
    .WillByDefault(Return(M1_SET_CURRENT_VAL));
    ON_CALL(mockKeyMotorData, getM1SetVelocity())
    .WillByDefault(Return(M1_SET_VELOCITY_VAL));
    ON_CALL(mockKeyMotorData, getM1BusCurrent())
    .WillByDefault(Return(M1_BUS_CURRENT_VAL));
    ON_CALL(mockKeyMotorData, getM1BusVoltage())
    .WillByDefault(Return(M1_BUS_VOLTAGE_VAL));
    ON_CALL(mockKeyMotorData, getM1VehicleVelocity())
    .WillByDefault(Return(M1_VEHICLE_VELOCITY_VAL));

    QJsonArray ACTUAL_JSON_ARRAY =
        jsonMessageBuilder_.buildKeyMotorMessage(mockKeyMotorData);

    EXPECT_EQ(EXPECTED_JSON_ARRAY, ACTUAL_JSON_ARRAY);

    if (HasFailure())
    {
        qDebug() << "Actual is " << ACTUAL_JSON_ARRAY;
        qDebug() << "Expected is " << EXPECTED_JSON_ARRAY;
    }
}

TEST(JsonMessageBuilderTest, motorDetails)
{
    JsonMessageBuilder jsonMessageBuilder_;

    // *INDENT-OFF*
    QString EXPECTED_JSON_MSG = "\
    [{ \
        \"PhaseCCurrent\": 1, \
        \"PhaseBCurrent\": 2, \
        \"MotorVoltageReal\": 3, \
        \"MotorVoltageImaginary\": 4, \
        \"MotorCurrentReal\": 5, \
        \"MotorCurrentImaginary\": 6, \
        \"BackEmfReal\": 7, \
        \"BackEmfImaginary\": 8, \
        \"VoltageRail15VSupply\": 9, \
        \"VoltageRail3VSupply\": 10, \
        \"VoltageRail1VSupply\": 11, \
        \"HeatSinkTemp\": 12, \
        \"MotorTemp\": 13, \
        \"DspBoardTemp\": 14, \
        \"DcBusAmpHours\": 15, \
        \"Odometer\": 16, \
        \"SlipSpeed\": 17 \
    }, { \
        \"PhaseCCurrent\": 18, \
        \"PhaseBCurrent\": 19, \
        \"MotorVoltageReal\": 20, \
        \"MotorVoltageImaginary\": 21, \
        \"MotorCurrentReal\": 22, \
        \"MotorCurrentImaginary\": 23, \
        \"BackEmfReal\": 24, \
        \"BackEmfImaginary\": 25, \
        \"VoltageRail15VSupply\": 26, \
        \"VoltageRail3VSupply\": 27, \
        \"VoltageRail1VSupply\": 28, \
        \"HeatSinkTemp\": 29, \
        \"MotorTemp\": 30, \
        \"DspBoardTemp\": 31, \
        \"DcBusAmpHours\": 32, \
        \"Odometer\": 33, \
        \"SlipSpeed\": 34 \
    }]";
    // *INDENT-ON*

    QJsonDocument EXPECTED_JSON_DOC = QJsonDocument::fromJson(EXPECTED_JSON_MSG.toLatin1());
    QJsonArray EXPECTED_JSON_ARRAY = EXPECTED_JSON_DOC.array();

    NiceMock<MockMotorDetailsData> mockMotorDetailsData;    
    NiceMock<MockMotorDetailsUnit> mockMotorDetailsUnit_0;
    NiceMock<MockMotorDetailsUnit> mockMotorDetailsUnit_1;

    ON_CALL(mockMotorDetailsData, getNumberOfUnits())
    .WillByDefault(Return(2));
    ON_CALL(mockMotorDetailsData, getMotorDetailsUnit(0))
    .WillByDefault(ReturnRef(mockMotorDetailsUnit_0));
    ON_CALL(mockMotorDetailsData, getMotorDetailsUnit(1))
    .WillByDefault(ReturnRef(mockMotorDetailsUnit_1));

    const float M0_PHASE_C_CURRENT = 1;
    const float M0_PHASE_B_CURRENT = 2;
    const float M0_MOTOR_VOLTAGE_REAL = 3;
    const float M0_MOTOR_VOLTAGE_IMAGINARY = 4;
    const float M0_MOTOR_CURRENT_REAL = 5;
    const float M0_MOTOR_CURRENT_IMAGINARY = 6;
    const float M0_BACK_EMF_REAL = 7;
    const float M0_BACK_EMF_IMAGINARY = 8;
    const float M0_VOLTAGE_RAIL_15V_SUPPLY = 9;
    const float M0_VOLTAGE_RAIL_3V_SUPPLY = 10;
    const float M0_VOLTAGE_RAIL_1V_SUPPLY = 11;
    const float M0_HEAT_SINK_TEMP = 12;
    const float M0_MOTOR_TEMP_ = 13;
    const float M0_DSP_BOARD_TEMP = 14;
    const float M0_DC_BUS_AMPHOURS = 15;
    const float M0_ODOMETER = 16;
    const float M0_SLIP_SPEED = 17;

    const float M1_PHASE_C_CURRENT = 18;
    const float M1_PHASE_B_CURRENT = 19;
    const float M1_MOTOR_VOLTAGE_REAL = 20;
    const float M1_MOTOR_VOLTAGE_IMAGINARY = 21;
    const float M1_MOTOR_CURRENT_REAL = 22;
    const float M1_MOTOR_CURRENT_IMAGINARY = 23;
    const float M1_BACK_EMF_REAL = 24;
    const float M1_BACK_EMF_IMAGINARY = 25;
    const float M1_VOLTAGE_RAIL_15V_SUPPLY = 26;
    const float M1_VOLTAGE_RAIL_3V_SUPPLY = 27;
    const float M1_VOLTAGE_RAIL_1V_SUPPLY = 28;
    const float M1_HEAT_SINK_TEMP = 29;
    const float M1_MOTOR_TEMP = 30;
    const float M1_DSP_BOARD_TEMP = 31;
    const float M1_DC_BUS_AMPHOURS = 32;
    const float M1_ODOMETER = 33;
    const float M1_SLIP_SPEED = 34;

    ON_CALL(mockMotorDetailsUnit_0, getMotorNumber())
    .WillByDefault(Return(0));
    ON_CALL(mockMotorDetailsUnit_0, getPhaseCCurrent())
    .WillByDefault(Return(M0_PHASE_C_CURRENT));
    ON_CALL(mockMotorDetailsUnit_0, getPhaseBCurrent())
    .WillByDefault(Return(M0_PHASE_B_CURRENT));
    ON_CALL(mockMotorDetailsUnit_0, getMotorVoltageReal())
    .WillByDefault(Return(M0_MOTOR_VOLTAGE_REAL));
    ON_CALL(mockMotorDetailsUnit_0, getMotorVoltageImaginary())
    .WillByDefault(Return(M0_MOTOR_VOLTAGE_IMAGINARY));
    ON_CALL(mockMotorDetailsUnit_0, getMotorCurrentReal())
    .WillByDefault(Return(M0_MOTOR_CURRENT_REAL));
    ON_CALL(mockMotorDetailsUnit_0, getMotorCurrentImaginary())
    .WillByDefault(Return(M0_MOTOR_CURRENT_IMAGINARY));
    ON_CALL(mockMotorDetailsUnit_0, getBackEmfReal())
    .WillByDefault(Return(M0_BACK_EMF_REAL));
    ON_CALL(mockMotorDetailsUnit_0, getBackEmfImaginary())
    .WillByDefault(Return(M0_BACK_EMF_IMAGINARY));
    ON_CALL(mockMotorDetailsUnit_0, getVoltageRailSuppply15V())
    .WillByDefault(Return(M0_VOLTAGE_RAIL_15V_SUPPLY));
    ON_CALL(mockMotorDetailsUnit_0, getVoltageRailSupply33V())
    .WillByDefault(Return(M0_VOLTAGE_RAIL_3V_SUPPLY));
    ON_CALL(mockMotorDetailsUnit_0, getVoltageRailSupply19V())
    .WillByDefault(Return(M0_VOLTAGE_RAIL_1V_SUPPLY));
    ON_CALL(mockMotorDetailsUnit_0, getHeatSinkTemperature())
    .WillByDefault(Return(M0_HEAT_SINK_TEMP));
    ON_CALL(mockMotorDetailsUnit_0, getMotorTempterature())
    .WillByDefault(Return(M0_MOTOR_TEMP_));
    ON_CALL(mockMotorDetailsUnit_0, getDspBoardTemperature())
    .WillByDefault(Return(M0_DSP_BOARD_TEMP));
    ON_CALL(mockMotorDetailsUnit_0, getDcBusAmpHours())
    .WillByDefault(Return(M0_DC_BUS_AMPHOURS));
    ON_CALL(mockMotorDetailsUnit_0, getOdometer())
    .WillByDefault(Return(M0_ODOMETER));
    ON_CALL(mockMotorDetailsUnit_0, getSlipSpeed())
    .WillByDefault(Return(M0_SLIP_SPEED));

    ON_CALL(mockMotorDetailsUnit_1, getMotorNumber())
    .WillByDefault(Return(1));
    ON_CALL(mockMotorDetailsUnit_1, getPhaseCCurrent())
    .WillByDefault(Return(M1_PHASE_C_CURRENT));
    ON_CALL(mockMotorDetailsUnit_1, getPhaseBCurrent())
    .WillByDefault(Return(M1_PHASE_B_CURRENT));
    ON_CALL(mockMotorDetailsUnit_1, getMotorVoltageReal())
    .WillByDefault(Return(M1_MOTOR_VOLTAGE_REAL));
    ON_CALL(mockMotorDetailsUnit_1, getMotorVoltageImaginary())
    .WillByDefault(Return(M1_MOTOR_VOLTAGE_IMAGINARY));
    ON_CALL(mockMotorDetailsUnit_1, getMotorCurrentReal())
    .WillByDefault(Return(M1_MOTOR_CURRENT_REAL));
    ON_CALL(mockMotorDetailsUnit_1, getMotorCurrentImaginary())
    .WillByDefault(Return(M1_MOTOR_CURRENT_IMAGINARY));
    ON_CALL(mockMotorDetailsUnit_1, getBackEmfReal())
    .WillByDefault(Return(M1_BACK_EMF_REAL));
    ON_CALL(mockMotorDetailsUnit_1, getBackEmfImaginary())
    .WillByDefault(Return(M1_BACK_EMF_IMAGINARY));
    ON_CALL(mockMotorDetailsUnit_1, getVoltageRailSuppply15V())
    .WillByDefault(Return(M1_VOLTAGE_RAIL_15V_SUPPLY));
    ON_CALL(mockMotorDetailsUnit_1, getVoltageRailSupply33V())
    .WillByDefault(Return(M1_VOLTAGE_RAIL_3V_SUPPLY));
    ON_CALL(mockMotorDetailsUnit_1, getVoltageRailSupply19V())
    .WillByDefault(Return(M1_VOLTAGE_RAIL_1V_SUPPLY));
    ON_CALL(mockMotorDetailsUnit_1, getHeatSinkTemperature())
    .WillByDefault(Return(M1_HEAT_SINK_TEMP));
    ON_CALL(mockMotorDetailsUnit_1, getMotorTempterature())
    .WillByDefault(Return(M1_MOTOR_TEMP));
    ON_CALL(mockMotorDetailsUnit_1, getDspBoardTemperature())
    .WillByDefault(Return(M1_DSP_BOARD_TEMP));
    ON_CALL(mockMotorDetailsUnit_1, getDcBusAmpHours())
    .WillByDefault(Return(M1_DC_BUS_AMPHOURS));
    ON_CALL(mockMotorDetailsUnit_1, getOdometer())
    .WillByDefault(Return(M1_ODOMETER));
    ON_CALL(mockMotorDetailsUnit_1, getSlipSpeed())
    .WillByDefault(Return(M1_SLIP_SPEED));
    
    QJsonArray ACTUAL_JSON_ARRAY =
        jsonMessageBuilder_.buildMotorDetailsMessage(mockMotorDetailsData);

    EXPECT_EQ(EXPECTED_JSON_ARRAY, ACTUAL_JSON_ARRAY);

    if (HasFailure())
    {
        qDebug() << "Actual is " << ACTUAL_JSON_ARRAY;
        qDebug() << "Expected is " << EXPECTED_JSON_ARRAY;
    }
}

TEST(JsonMessageBuilderTest, driverControls)
{
    JsonMessageBuilder jsonMessageBuilder_;

    QString EXPECTED_JSON_MSG = "\
    { \
        \"Alive\": false, \
        \"HeadlightsOff\": true, \
        \"HeadlightsLow\": false, \
        \"HeadlightsHigh\": true, \
        \"SignalRight\": false, \
        \"SignalLeft\": true, \
        \"Hazard\": false, \
        \"Interior\": true, \
        \"Aux\": true, \
        \"VolumeUp\": false, \
        \"VolumeDown\": true, \
        \"NextSong\": false, \
        \"PrevSong\": true, \
        \"Acceleration\": 0.1, \
        \"RegenBraking\": 0.2, \
        \"Brakes\": true, \
        \"Forward\": false, \
        \"Reverse\": true, \
        \"PushToTalk\": false, \
        \"Horn\": true, \
        \"Reset\": false \
    }";

    QJsonDocument EXPECTED_JSON_DOC = QJsonDocument::fromJson(EXPECTED_JSON_MSG.toLatin1());
    QJsonObject EXPECTED_JSON = EXPECTED_JSON_DOC.object();

    NiceMock<MockDriverControlsData> mockDriverControlsData;
    const bool ALIVE = false;
    const bool HEADLIGHTS_OFF = true;
    const bool HEADLIGHTS_LOW = false;
    const bool HEADLIGHTS_HIGH = true;
    const bool SIGNAL_RIGHT = false;
    const bool SIGNAL_LEFT = true;
    const bool HAZARD = false;
    const bool INTERIOR = true;
    const bool AUX = true;
    const bool VOLUME_UP = false;
    const bool VOLUME_DOWN = true;
    const bool NEXT_SONG = false;
    const bool PREV_SONG = true;
    const bool BRAKES = true;
    const bool FORWARD = false;
    const bool REVERSE = true;
    const bool PUSH_TO_TALK = false;
    const bool HORN = true;
    const bool RESET = false;
    const unsigned short ACCELERATION = 1000;
    const unsigned short REGEN_BRAKING = 2000;

    ON_CALL(mockDriverControlsData, getDriverControlsBoardAlive())
    .WillByDefault(Return(ALIVE));
    ON_CALL(mockDriverControlsData, getHeadlightsOff())
    .WillByDefault(Return(HEADLIGHTS_OFF));
    ON_CALL(mockDriverControlsData, getHeadlightsLow())
    .WillByDefault(Return(HEADLIGHTS_LOW));
    ON_CALL(mockDriverControlsData, getHeadlightsHigh())
    .WillByDefault(Return(HEADLIGHTS_HIGH));
    ON_CALL(mockDriverControlsData, getSignalRight())
    .WillByDefault(Return(SIGNAL_RIGHT));
    ON_CALL(mockDriverControlsData, getSignalLeft())
    .WillByDefault(Return(SIGNAL_LEFT));
    ON_CALL(mockDriverControlsData, getHazard())
    .WillByDefault(Return(HAZARD));
    ON_CALL(mockDriverControlsData, getInterior())
    .WillByDefault(Return(INTERIOR));
    ON_CALL(mockDriverControlsData, getAux())
    .WillByDefault(Return(AUX));
    ON_CALL(mockDriverControlsData, getVolumeUp())
    .WillByDefault(Return(VOLUME_UP));
    ON_CALL(mockDriverControlsData, getVolumeDown())
    .WillByDefault(Return(VOLUME_DOWN));
    ON_CALL(mockDriverControlsData, getNextSong())
    .WillByDefault(Return(NEXT_SONG));
    ON_CALL(mockDriverControlsData, getPreviousSong())
    .WillByDefault(Return(PREV_SONG));
    ON_CALL(mockDriverControlsData, getBrakes())
    .WillByDefault(Return(BRAKES));
    ON_CALL(mockDriverControlsData, getForward())
    .WillByDefault(Return(FORWARD));
    ON_CALL(mockDriverControlsData, getReverse())
    .WillByDefault(Return(REVERSE));
    ON_CALL(mockDriverControlsData, getPushToTalk())
    .WillByDefault(Return(PUSH_TO_TALK));
    ON_CALL(mockDriverControlsData, getHorn())
    .WillByDefault(Return(HORN));
    ON_CALL(mockDriverControlsData, getReset())
    .WillByDefault(Return(RESET));
    ON_CALL(mockDriverControlsData, getAcceleration())
    .WillByDefault(Return(ACCELERATION));
    ON_CALL(mockDriverControlsData, getRegenBraking())
    .WillByDefault(Return(REGEN_BRAKING));

    QJsonObject ACTUAL_JSON =
        jsonMessageBuilder_.buildDriverControlsMessage(mockDriverControlsData);

    EXPECT_EQ(EXPECTED_JSON, ACTUAL_JSON);

    if (HasFailure())
    {
        qDebug() << "Actual is " << ACTUAL_JSON;
        qDebug() << "Expected is " << EXPECTED_JSON;
    }
}