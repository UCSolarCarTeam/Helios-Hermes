/**
 *  Schulich Delta Hermes
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of Schulich Delta Hermes
 *
 *  Schulich Delta Hermes is free software:
 *  you can redistribute it and/or modify it under the terms
 *  of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  Schulich Delta Hermes is distributed
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General
 *  Public License along with Schulich Delta Hermes.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QScopedPointer>

#include "BusinessLayer/JsonForwarder/FaultsJsonForwarder/FaultsJsonForwarder.h"
#include "BusinessLayer/JsonForwarder/JsonDefines.h"

#include "Tests/CommunicationLayer/CommDeviceControl/MockMessageForwarder.h"
#include "Tests/DataLayer/FaultsData/MockFaultsData.h"

using ::testing::AllOf;
using ::testing::AtLeast;
using ::testing::Return;

class FaultsJsonForwarderTest : public ::testing::Test
{
protected:
    QScopedPointer<MockFaultsData> faultsData_;
    QScopedPointer<MockMessageForwarder> messageForwarder_;
    QScopedPointer<FaultsJsonForwarder> faultsJsonForwarder_;

    virtual void SetUp()
    {
        faultsData_.reset(new MockFaultsData());
        messageForwarder_.reset(new MockMessageForwarder());
        faultsJsonForwarder_.reset(new FaultsJsonForwarder(*faultsData_,
                                                           *messageForwarder_));

        EXPECT_CALL(*faultsData_, motorOneFaults())
            .WillRepeatedly(Return(MotorFaults(0)));
        EXPECT_CALL(*faultsData_, motorOneLimitFlags())
            .WillRepeatedly(Return(LimitFlags(0)));
        EXPECT_CALL(*faultsData_, motorTwoFaults())
            .WillRepeatedly(Return(MotorFaults(0)));
        EXPECT_CALL(*faultsData_, motorTwoLimitFlags())
            .WillRepeatedly(Return(LimitFlags(0)));
        EXPECT_CALL(*faultsData_, batteryFaults())
            .WillRepeatedly(Return(BatteryFaults(0)));
    }
};

/****** JSON MATCHERS ******/

MATCHER_P2(JsonStringIs, key, value, "")
{
    QJsonObject jsonObj = QJsonDocument::fromJson(arg).object();
    QString actual = jsonObj[key].toString();
    QString expected = value;
    if(actual != expected)
    {
        qDebug() << "Actual is " << actual;
        qDebug() << "Expected is " << expected;
        return false;
    }
    return true;
}

MATCHER_P3(JsonNestedBoolIs, key1, key2, value, "") {
    QJsonObject jsonObj = QJsonDocument::fromJson(arg).object();
    return jsonObj[key1].toObject()[key2].toBool() == value;
}

/****** TESTS ******/

TEST_F(FaultsJsonForwarderTest, faultsDataForwarded)
{
    EXPECT_CALL(*messageForwarder_,
                forwardData(JsonStringIs(JsonFormat::DATA_TYPE, JsonFormat::FAULTS)))
        .Times(AtLeast(1));
    faultsJsonForwarder_->forwardFaultsData(QJsonObject());
}

TEST_F(FaultsJsonForwarderTest, faultsTrueMotorOneFaultsDataForwarded)
{
    quint8 MOCK_MOTOR_FAULT_BITS = 0xff;
    MotorFaults faultsValue = MotorFaults(MOCK_MOTOR_FAULT_BITS);
    EXPECT_CALL(*faultsData_, motorOneFaults())
        .WillRepeatedly(Return(faultsValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedBoolIs(JsonFormat::MOTOR_ONE_FAULTS,
                                                   JsonFormat::HARDWARE_OVER_CURRENT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_FAULTS,
                                                   JsonFormat::SOFTWARE_OVER_CURRENT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_FAULTS,
                                                   JsonFormat::DC_BUS_OVER_VOLTAGE, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_FAULTS,
                                                   JsonFormat::BAD_MOTOR_POSITION_HALL_SEQUENCE, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_FAULTS,
                                                   JsonFormat::WATCHDOG_CAUSED_LAST_RESET, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_FAULTS,
                                                   JsonFormat::CONFIG_READ_ERROR, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_FAULTS,
                                                   JsonFormat::RAIL_UNDER_VOLTAGE_LOCK_OUT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_FAULTS,
                                                   JsonFormat::DESATURATION_FAULT, true))))
        .Times(AtLeast(1));
    faultsJsonForwarder_->forwardFaultsData(QJsonObject());
}

TEST_F(FaultsJsonForwarderTest, faultsFalseMotorOneFaultsDataForwarded)
{
    quint8 MOCK_MOTOR_FAULT_BITS = 0x00;
    MotorFaults faultsValue = MotorFaults(MOCK_MOTOR_FAULT_BITS);
    EXPECT_CALL(*faultsData_, motorOneFaults())
        .WillRepeatedly(Return(faultsValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedBoolIs(JsonFormat::MOTOR_ONE_FAULTS,
                                                   JsonFormat::HARDWARE_OVER_CURRENT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_FAULTS,
                                                   JsonFormat::SOFTWARE_OVER_CURRENT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_FAULTS,
                                                   JsonFormat::DC_BUS_OVER_VOLTAGE, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_FAULTS,
                                                   JsonFormat::BAD_MOTOR_POSITION_HALL_SEQUENCE, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_FAULTS,
                                                   JsonFormat::WATCHDOG_CAUSED_LAST_RESET, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_FAULTS,
                                                   JsonFormat::CONFIG_READ_ERROR, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_FAULTS,
                                                   JsonFormat::RAIL_UNDER_VOLTAGE_LOCK_OUT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_FAULTS,
                                                   JsonFormat::DESATURATION_FAULT, false))))
        .Times(AtLeast(1));
    faultsJsonForwarder_->forwardFaultsData(QJsonObject());
}

TEST_F(FaultsJsonForwarderTest, faultsTrueMotorOneLimitsDataForwarded)
{
    quint8 MOCK_MOTOR_LIMIT_BITS = 0xff;
    LimitFlags limitsValue = LimitFlags(MOCK_MOTOR_LIMIT_BITS);
    EXPECT_CALL(*faultsData_, motorOneLimitFlags())
        .WillRepeatedly(Return(limitsValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedBoolIs(JsonFormat::MOTOR_ONE_LIMIT_FLAGS,
                                                   JsonFormat::OUTPUT_VOLTAGE_PWM_LIMIT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_LIMIT_FLAGS,
                                                   JsonFormat::MOTOR_CURRENT_LIMIT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_LIMIT_FLAGS,
                                                   JsonFormat::VELOCITY_LIMIT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_LIMIT_FLAGS,
                                                   JsonFormat::BUS_CURRENT_LIMIT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_LIMIT_FLAGS,
                                                   JsonFormat::BUS_VOLTAGE_UPPER_LIMIT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_LIMIT_FLAGS,
                                                   JsonFormat::BUS_VOLTAGE_LOWER_LIMIT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_LIMIT_FLAGS,
                                                   JsonFormat::IPM_OR_MOTOR_TELEMETRY_LIMIT, true))))
        .Times(AtLeast(1));
    faultsJsonForwarder_->forwardFaultsData(QJsonObject());
}

TEST_F(FaultsJsonForwarderTest, faultsFalseMotorOneLimitsDataForwarded)
{
    quint8 MOCK_MOTOR_LIMIT_BITS = 0x00;
    LimitFlags limitsValue = LimitFlags(MOCK_MOTOR_LIMIT_BITS);
    EXPECT_CALL(*faultsData_, motorOneLimitFlags())
        .WillRepeatedly(Return(limitsValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedBoolIs(JsonFormat::MOTOR_ONE_LIMIT_FLAGS,
                                                   JsonFormat::OUTPUT_VOLTAGE_PWM_LIMIT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_LIMIT_FLAGS,
                                                   JsonFormat::MOTOR_CURRENT_LIMIT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_LIMIT_FLAGS,
                                                   JsonFormat::VELOCITY_LIMIT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_LIMIT_FLAGS,
                                                   JsonFormat::BUS_CURRENT_LIMIT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_LIMIT_FLAGS,
                                                   JsonFormat::BUS_VOLTAGE_UPPER_LIMIT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_LIMIT_FLAGS,
                                                   JsonFormat::BUS_VOLTAGE_LOWER_LIMIT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_ONE_LIMIT_FLAGS,
                                                   JsonFormat::IPM_OR_MOTOR_TELEMETRY_LIMIT, false))))
        .Times(AtLeast(1));
    faultsJsonForwarder_->forwardFaultsData(QJsonObject());
}

TEST_F(FaultsJsonForwarderTest, faultsTrueMotorTwoFaultsDataForwarded)
{
    quint8 MOCK_MOTOR_FAULT_BITS = 0xff;
    MotorFaults faultsValue = MotorFaults(MOCK_MOTOR_FAULT_BITS);
    EXPECT_CALL(*faultsData_, motorTwoFaults())
        .WillRepeatedly(Return(faultsValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedBoolIs(JsonFormat::MOTOR_TWO_FAULTS,
                                                   JsonFormat::HARDWARE_OVER_CURRENT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_FAULTS,
                                                   JsonFormat::SOFTWARE_OVER_CURRENT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_FAULTS,
                                                   JsonFormat::DC_BUS_OVER_VOLTAGE, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_FAULTS,
                                                   JsonFormat::BAD_MOTOR_POSITION_HALL_SEQUENCE, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_FAULTS,
                                                   JsonFormat::WATCHDOG_CAUSED_LAST_RESET, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_FAULTS,
                                                   JsonFormat::CONFIG_READ_ERROR, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_FAULTS,
                                                   JsonFormat::RAIL_UNDER_VOLTAGE_LOCK_OUT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_FAULTS,
                                                   JsonFormat::DESATURATION_FAULT, true))))
        .Times(AtLeast(1));
    faultsJsonForwarder_->forwardFaultsData(QJsonObject());
}

TEST_F(FaultsJsonForwarderTest, faultsFalseMotorTwoFaultsDataForwarded)
{
    quint8 MOCK_MOTOR_FAULT_BITS = 0x00;
    MotorFaults faultsValue = MotorFaults(MOCK_MOTOR_FAULT_BITS);
    EXPECT_CALL(*faultsData_, motorTwoFaults())
        .WillRepeatedly(Return(faultsValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedBoolIs(JsonFormat::MOTOR_TWO_FAULTS,
                                                   JsonFormat::HARDWARE_OVER_CURRENT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_FAULTS,
                                                   JsonFormat::SOFTWARE_OVER_CURRENT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_FAULTS,
                                                   JsonFormat::DC_BUS_OVER_VOLTAGE, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_FAULTS,
                                                   JsonFormat::BAD_MOTOR_POSITION_HALL_SEQUENCE, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_FAULTS,
                                                   JsonFormat::WATCHDOG_CAUSED_LAST_RESET, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_FAULTS,
                                                   JsonFormat::CONFIG_READ_ERROR, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_FAULTS,
                                                   JsonFormat::RAIL_UNDER_VOLTAGE_LOCK_OUT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_FAULTS,
                                                   JsonFormat::DESATURATION_FAULT, false))))
        .Times(AtLeast(1));
    faultsJsonForwarder_->forwardFaultsData(QJsonObject());
}

TEST_F(FaultsJsonForwarderTest, faultsTrueMotorTwoLimitsDataForwarded)
{
    quint8 MOCK_MOTOR_LIMIT_BITS = 0xff;
    LimitFlags limitsValue = LimitFlags(MOCK_MOTOR_LIMIT_BITS);
    EXPECT_CALL(*faultsData_, motorTwoLimitFlags())
        .WillRepeatedly(Return(limitsValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedBoolIs(JsonFormat::MOTOR_TWO_LIMIT_FLAGS,
                                                   JsonFormat::OUTPUT_VOLTAGE_PWM_LIMIT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_LIMIT_FLAGS,
                                                   JsonFormat::MOTOR_CURRENT_LIMIT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_LIMIT_FLAGS,
                                                   JsonFormat::VELOCITY_LIMIT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_LIMIT_FLAGS,
                                                   JsonFormat::BUS_CURRENT_LIMIT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_LIMIT_FLAGS,
                                                   JsonFormat::BUS_VOLTAGE_UPPER_LIMIT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_LIMIT_FLAGS,
                                                   JsonFormat::BUS_VOLTAGE_LOWER_LIMIT, true),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_LIMIT_FLAGS,
                                                   JsonFormat::IPM_OR_MOTOR_TELEMETRY_LIMIT, true))))
        .Times(AtLeast(1));
    faultsJsonForwarder_->forwardFaultsData(QJsonObject());
}

TEST_F(FaultsJsonForwarderTest, faultsFalseMotorTwoLimitsDataForwarded)
{
    quint8 MOCK_MOTOR_LIMIT_BITS = 0x00;
    LimitFlags limitsValue = LimitFlags(MOCK_MOTOR_LIMIT_BITS);
    EXPECT_CALL(*faultsData_, motorTwoLimitFlags())
        .WillRepeatedly(Return(limitsValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedBoolIs(JsonFormat::MOTOR_TWO_LIMIT_FLAGS,
                                                   JsonFormat::OUTPUT_VOLTAGE_PWM_LIMIT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_LIMIT_FLAGS,
                                                   JsonFormat::MOTOR_CURRENT_LIMIT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_LIMIT_FLAGS,
                                                   JsonFormat::VELOCITY_LIMIT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_LIMIT_FLAGS,
                                                   JsonFormat::BUS_CURRENT_LIMIT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_LIMIT_FLAGS,
                                                   JsonFormat::BUS_VOLTAGE_UPPER_LIMIT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_LIMIT_FLAGS,
                                                   JsonFormat::BUS_VOLTAGE_LOWER_LIMIT, false),
                                  JsonNestedBoolIs(JsonFormat::MOTOR_TWO_LIMIT_FLAGS,
                                                   JsonFormat::IPM_OR_MOTOR_TELEMETRY_LIMIT, false))))
        .Times(AtLeast(1));
    faultsJsonForwarder_->forwardFaultsData(QJsonObject());
}

TEST_F(FaultsJsonForwarderTest, faultsTrueBatteryFaultsDataForwarded)
{
    quint16 MOCK_BATTERY_FAULT_BITS = 0xffff;

    BatteryFaults batteryFaultsValue = BatteryFaults(MOCK_BATTERY_FAULT_BITS);
    EXPECT_CALL(*faultsData_, batteryFaults())
        .WillRepeatedly(Return(batteryFaultsValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::CELL_OVER_VOLTAGE, true),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::CELL_UNDER_VOLTAGE, true),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::CELL_OVER_TEMPERATURE, true),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::MEASUREMENT_UNTRUSTED, true),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::CMU_COMM_TIMEOUT, true),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::VEHICLE_COMM_TIMEOUT, true),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::BMU_IS_IN_SETUP_MODE, true),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::CMU_CAN_BUS_POWER_STATUS, !true), // note in BatteryFaults.cpp
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::PACK_ISOLATION_TEST_FAILURE, true),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::SOFTWARE_OVER_CURRENT_MEASURED, true),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::CAN_SUPPLY_IS_LOW, true),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::CONTACTOR_IS_STUCK, true),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::CMU_DETECTED_EXTRA_CELL_PRESENT, true))))
        .Times(AtLeast(1));
    faultsJsonForwarder_->forwardFaultsData(QJsonObject());
}

TEST_F(FaultsJsonForwarderTest, faultsFalseBatteryFaultsDataForwarded)
{
    quint16 MOCK_BATTERY_FAULT_BITS = 0x0000;
    BatteryFaults batteryFaultsValue = BatteryFaults(MOCK_BATTERY_FAULT_BITS);
    EXPECT_CALL(*faultsData_, batteryFaults())
        .WillRepeatedly(Return(batteryFaultsValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::CELL_OVER_VOLTAGE, false),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::CELL_UNDER_VOLTAGE, false),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::CELL_OVER_TEMPERATURE, false),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::MEASUREMENT_UNTRUSTED, false),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::CMU_COMM_TIMEOUT, false),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::VEHICLE_COMM_TIMEOUT, false),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::BMU_IS_IN_SETUP_MODE, false),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::CMU_CAN_BUS_POWER_STATUS, true), // note in BatteryFaults.cpp
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::PACK_ISOLATION_TEST_FAILURE, false),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::SOFTWARE_OVER_CURRENT_MEASURED, false),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::CAN_SUPPLY_IS_LOW, false),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::CONTACTOR_IS_STUCK, false),
                                  JsonNestedBoolIs(JsonFormat::BATTERY_FAULTS,
                                                   JsonFormat::CMU_DETECTED_EXTRA_CELL_PRESENT, false))))
        .Times(AtLeast(1));
    faultsJsonForwarder_->forwardFaultsData(QJsonObject());
}

TEST_F(FaultsJsonForwarderTest, baseJsonPreserved)
{
    QString fakeFieldKey = "Key";
    QString fakeFieldValue = "Value";
    QJsonObject fakeBaseJson = QJsonObject();
    fakeBaseJson[fakeFieldKey] = fakeFieldValue;

    EXPECT_CALL(*messageForwarder_,
                forwardData(JsonStringIs(fakeFieldKey, fakeFieldValue)))
        .Times(1);
    faultsJsonForwarder_->forwardFaultsData(fakeBaseJson);    
}

