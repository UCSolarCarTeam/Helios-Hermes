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

using ::testing::Return;
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
    unsigned char M0_ALIVE_VAL = true;
    float M0_SET_CURRENT_VAL = 1;
    float M0_SET_VELOCITY_VAL = 2;
    float M0_BUS_CURRENT_VAL = 3;
    float M0_BUS_VOLTAGE_VAL = 4;
    float M0_VEHICLE_VELOCITY_VAL = 5;
    unsigned char M1_ALIVE_VAL = false;
    float M1_SET_CURRENT_VAL = 6;
    float M1_SET_VELOCITY_VAL = 7;
    float M1_BUS_CURRENT_VAL = 8;
    float M1_BUS_VOLTAGE_VAL = 9;
    float M1_VEHICLE_VELOCITY_VAL = 10;

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
