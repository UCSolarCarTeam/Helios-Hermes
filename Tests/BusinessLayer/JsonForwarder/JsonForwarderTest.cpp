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

#include <QTest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QScopedPointer>
#include <QDebug>

#include "BusinessLayer/JsonForwarder/JsonForwarder.h"
#include "BusinessLayer/JsonForwarder/JsonDefines.h"

#include "Tests/CommunicationLayer/CommDeviceControl/MockMessageForwarder.h"
#include "Tests/DataLayer/BatteryData/MockBatteryData.h"
#include "Tests/DataLayer/FaultsData/MockFaultsData.h"
#include "Tests/DataLayer/PowerData/MockPowerData.h"
#include "Tests/DataLayer/VehicleData/MockVehicleData.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::AllOf;
using ::testing::NiceMock;

namespace
{
    const int FORWARD_INTERVAL_MSEC = 5;
    const int FORWARD_ITERATIONS = 10;
}

class JsonForwarderTest : public ::testing::Test
{

protected:
    QScopedPointer<NiceMock<MockBatteryData> > batteryData_;
    QScopedPointer<NiceMock<MockFaultsData> > faultsData_;
    QScopedPointer<NiceMock<MockPowerData> > powerData_;
    QScopedPointer<NiceMock<MockVehicleData> > vehicleData_;
    QScopedPointer<NiceMock<MockMessageForwarder> > messageForwarder_;
    QScopedPointer<JsonForwarder> jsonForwarder_;

    virtual void SetUp()
    {
        batteryData_.reset(static_cast<NiceMock<MockBatteryData>*> (new MockBatteryData()));
        faultsData_.reset(static_cast<NiceMock<MockFaultsData>*> (new MockFaultsData()));
        powerData_.reset(static_cast<NiceMock<MockPowerData>*> (new MockPowerData()));
        vehicleData_.reset(static_cast<NiceMock<MockVehicleData>*> (new MockVehicleData()));
        messageForwarder_.reset(static_cast<NiceMock<MockMessageForwarder>*> (new MockMessageForwarder()));
        jsonForwarder_.reset(new JsonForwarder(*batteryData_,
                                               *faultsData_,
                                               *powerData_,
                                               *vehicleData_,
                                               *messageForwarder_));

        QList<double> emptyList = {0, 0, 0, 0, 0, 0, 0, 0};
        EXPECT_CALL(*batteryData_, mod0PcbTemperature())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*batteryData_, mod0CellTemperature())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*batteryData_, mod0CellVoltages())
            .WillRepeatedly(Return(emptyList));
        EXPECT_CALL(*batteryData_, mod1PcbTemperature())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*batteryData_, mod1CellTemperature())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*batteryData_, mod1CellVoltages())
            .WillRepeatedly(Return(emptyList));
        EXPECT_CALL(*batteryData_, mod2PcbTemperature())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*batteryData_, mod2CellTemperature())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*batteryData_, mod2CellVoltages())
            .WillRepeatedly(Return(emptyList));
        EXPECT_CALL(*batteryData_, mod3PcbTemperature())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*batteryData_, mod3CellTemperature())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*batteryData_, mod3CellVoltages())
            .WillRepeatedly(Return(emptyList));
        EXPECT_CALL(*batteryData_, batteryVoltage())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*batteryData_, batteryCurrent())
            .WillRepeatedly(Return(0));

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

MATCHER_P3(JsonNestedStringIs, key1, key2, value, "") {
    QJsonObject jsonObj = QJsonDocument::fromJson(arg).object();
    QString actual = jsonObj[key1].toObject()[key2].toString();
    QString expected = value;
    if(actual != expected)
    {
        qDebug() << "Actual is " << actual;
        qDebug() << "Expected is " << expected;
        return false;
    }
    return  true;
}

MATCHER_P3(JsonNestedStringArrayIs, key1, key2, value, "") {
    QJsonObject jsonObj = QJsonDocument::fromJson(arg).object();
    QJsonArray jsonArr = jsonObj[key1].toObject()[key2].toArray();
    for(int i = 0; i < value.size(); i++)
    {
        QString actual = jsonArr[i].toString();
        QString expected = value[i];    
        if(actual != expected)
        {
            qDebug() << "Actual is " << actual;
            qDebug() << "Expected is " << expected;
            return false;
        }
    }
    return true;
}

MATCHER_P3(JsonNestedBoolIs, key1, key2, value, "") {
    QJsonObject jsonObj = QJsonDocument::fromJson(arg).object();
    return jsonObj[key1].toObject()[key2].toBool() == value;
}

/****** TESTS ******/

TEST_F(JsonForwarderTest, batteryDataTypeForwarded)
{
    EXPECT_CALL(*messageForwarder_,
                forwardData(JsonStringIs(JsonFormat::DATA_TYPE, JsonFormat::BATTERY)))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, batteryMod0DataForwarded)
{
    double mod0PcbTemperature = 1.0;
    QString mod0PcbTemperatureString = QString::number(mod0PcbTemperature, 'f', JsonFormat::DECIMAL_PRECISION);
    double mod0CellTemperature = 2.0;
    QString mod0CellTemperatureString = QString::number(mod0CellTemperature, 'f', JsonFormat::DECIMAL_PRECISION);
    QList<double> mod0CellVoltages =  {3.1f, 3.2f, 3.3f, 3.4f, 3.5f, 3.6f, 3.7f, 3.8f};
    QList<QString> mod0CellVoltagesString = QList<QString>(); //  {"3.10", "3.20", "3.30", "3.40", "3.50", "3.60", "3.70", "3.80"};
    foreach(double val, mod0CellVoltages)
    {
        mod0CellVoltagesString.append(QString::number(val, 'f', JsonFormat::DECIMAL_PRECISION));
    }

    EXPECT_CALL(*batteryData_, mod0PcbTemperature())
        .WillRepeatedly(Return(mod0PcbTemperature));
    EXPECT_CALL(*batteryData_, mod0CellTemperature())
        .WillRepeatedly(Return(mod0CellTemperature));
    EXPECT_CALL(*batteryData_, mod0CellVoltages())
        .WillRepeatedly(Return(mod0CellVoltages));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedStringIs(JsonFormat::MOD_0, 
                                                     JsonFormat::PCB_TEMPERATURE, 
                                                     mod0PcbTemperatureString),
                                  JsonNestedStringIs(JsonFormat::MOD_0, 
                                                     JsonFormat::CELL_TEMPERATURE, 
                                                     mod0CellTemperatureString),
                                  JsonNestedStringArrayIs(JsonFormat::MOD_0, 
                                                          JsonFormat::CELL_VOLTAGES, 
                                                          mod0CellVoltagesString))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, batteryMod1DataForwarded)
{
    double mod1PcbTemperature = 11.0;
    QString mod1PcbTemperatureString = QString::number(mod1PcbTemperature, 'f', JsonFormat::DECIMAL_PRECISION);
    double mod1CellTemperature = 12.0;
    QString mod1CellTemperatureString = QString::number(mod1CellTemperature, 'f', JsonFormat::DECIMAL_PRECISION);
    QList<double> mod1CellVoltages = {13.1f, 13.2f, 13.3f, 13.4f, 13.5f, 13.6f, 13.7f, 13.8f};
    QList<QString> mod1CellVoltagesString = QList<QString>(); // {"13.10", "13.20", "13.30", "13.40", "13.50", "13.60", "13.70", "13.80"};
    foreach(double val, mod1CellVoltages)
    {
        mod1CellVoltagesString.append(QString::number(val, 'f', JsonFormat::DECIMAL_PRECISION));
    }

    EXPECT_CALL(*batteryData_, mod1PcbTemperature())
        .WillRepeatedly(Return(mod1PcbTemperature));
    EXPECT_CALL(*batteryData_, mod1CellTemperature())
        .WillRepeatedly(Return(mod1CellTemperature));
    EXPECT_CALL(*batteryData_, mod1CellVoltages())
        .WillRepeatedly(Return(mod1CellVoltages));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedStringIs(JsonFormat::MOD_1, 
                                                     JsonFormat::PCB_TEMPERATURE, 
                                                     mod1PcbTemperatureString),
                                  JsonNestedStringIs(JsonFormat::MOD_1, 
                                                     JsonFormat::CELL_TEMPERATURE, 
                                                     mod1CellTemperatureString),
                                  JsonNestedStringArrayIs(JsonFormat::MOD_1, 
                                                          JsonFormat::CELL_VOLTAGES, 
                                                          mod1CellVoltagesString))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, batteryMod2DataForwarded)
{
    double mod2PcbTemperature = 21.0;
    QString mod2PcbTemperatureString = QString::number(mod2PcbTemperature, 'f', JsonFormat::DECIMAL_PRECISION);
    double mod2CellTemperature = 22.0;
    QString mod2CellTemperatureString = QString::number(mod2CellTemperature, 'f', JsonFormat::DECIMAL_PRECISION);
    QList<double> mod2CellVoltages = {23.1f, 23.2f, 23.3f, 23.4f, 23.5f, 23.6f, 23.7f, 23.8f};
    QList<QString> mod2CellVoltagesString = QList<QString>(); // {"23.10", "23.20", "23.30", "23.40", "23.50", "23.60", "23.70", "23.80"};
    foreach(double val, mod2CellVoltages)
    {
        mod2CellVoltagesString.append(QString::number(val, 'f', JsonFormat::DECIMAL_PRECISION));
    }

    EXPECT_CALL(*batteryData_, mod2PcbTemperature())
        .WillRepeatedly(Return(mod2PcbTemperature));
    EXPECT_CALL(*batteryData_, mod2CellTemperature())
        .WillRepeatedly(Return(mod2CellTemperature));
    EXPECT_CALL(*batteryData_, mod2CellVoltages())
        .WillRepeatedly(Return(mod2CellVoltages));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedStringIs(JsonFormat::MOD_2, 
                                                     JsonFormat::PCB_TEMPERATURE, 
                                                     mod2PcbTemperatureString),
                                  JsonNestedStringIs(JsonFormat::MOD_2, 
                                                     JsonFormat::CELL_TEMPERATURE, 
                                                     mod2CellTemperatureString),
                                  JsonNestedStringArrayIs(JsonFormat::MOD_2, 
                                                          JsonFormat::CELL_VOLTAGES, 
                                                          mod2CellVoltagesString))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, batteryMod3DataForwarded)
{
    double mod3PcbTemperature = 31.0;
    QString mod3PcbTemperatureString = QString::number(mod3PcbTemperature, 'f', JsonFormat::DECIMAL_PRECISION);
    double mod3CellTemperature = 32.0;
    QString mod3CellTemperatureString = QString::number(mod3CellTemperature, 'f', JsonFormat::DECIMAL_PRECISION);
    QList<double> mod3CellVoltages = {33.1f, 33.2f, 33.3f, 33.4f, 33.5f, 33.6f, 33.7f, 33.8f};
    QList<QString> mod3CellVoltagesString = QList<QString>(); // {"33.10", "33.20", "33.30", "33.40", "33.50", "33.60", "33.70", "33.80"};
    foreach(double val, mod3CellVoltages)
    {
         mod3CellVoltagesString.append(QString::number(val, 'f', JsonFormat::DECIMAL_PRECISION));
    }

    EXPECT_CALL(*batteryData_, mod3PcbTemperature())
        .WillRepeatedly(Return(mod3PcbTemperature));
    EXPECT_CALL(*batteryData_, mod3CellTemperature())
        .WillRepeatedly(Return(mod3CellTemperature));
    EXPECT_CALL(*batteryData_, mod3CellVoltages())
        .WillRepeatedly(Return(mod3CellVoltages));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedStringIs(JsonFormat::MOD_3, 
                                                     JsonFormat::PCB_TEMPERATURE, 
                                                     mod3PcbTemperatureString),
                                  JsonNestedStringIs(JsonFormat::MOD_3, 
                                                     JsonFormat::CELL_TEMPERATURE, 
                                                     mod3CellTemperatureString),
                                  JsonNestedStringArrayIs(JsonFormat::MOD_3, 
                                                          JsonFormat::CELL_VOLTAGES, 
                                                          mod3CellVoltagesString))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, batteryInternalDataForwarded)
{
    double batteryVoltage = 41.0;
    QString batteryVoltageString = QString::number(batteryVoltage, 'f', JsonFormat::DECIMAL_PRECISION);
    double batteryCurrent = 42.0;
    QString batteryCurrentString = QString::number(batteryCurrent, 'f', JsonFormat::DECIMAL_PRECISION);

    EXPECT_CALL(*batteryData_, batteryVoltage())
        .WillRepeatedly(Return(batteryVoltage));
    EXPECT_CALL(*batteryData_, batteryCurrent())
        .WillRepeatedly(Return(batteryCurrent));   

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonStringIs(JsonFormat::BATTERY_VOLTAGE, batteryVoltageString),
                                  JsonStringIs(JsonFormat::BATTERY_CURRENT, batteryCurrentString))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, faultsDataForwarded)
{
    EXPECT_CALL(*messageForwarder_,
                forwardData(JsonStringIs(JsonFormat::DATA_TYPE, JsonFormat::FAULTS)))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, faultsTrueMotorOneFaultsDataForwarded)
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
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, faultsFalseMotorOneFaultsDataForwarded)
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
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, faultsTrueMotorOneLimitsDataForwarded)
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
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, faultsFalseMotorOneLimitsDataForwarded)
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
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, faultsTrueMotorTwoFaultsDataForwarded)
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
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, faultsFalseMotorTwoFaultsDataForwarded)
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
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, faultsTrueMotorTwoLimitsDataForwarded)
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
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, faultsFalseMotorTwoLimitsDataForwarded)
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
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, faultsTrueBatteryFaultsDataForwarded)
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
                                                   JsonFormat::CMU_CAN_BUS_POWER_STATUS, true),
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
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, faultsFalseBatteryFaultsDataForwarded)
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
                                                   JsonFormat::CMU_CAN_BUS_POWER_STATUS, false),
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
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

/*
TEST_F(JsonForwarderTest, powerDataForwarded)
{
    double busCurrentAValue = 1.0f;
    double busVoltageValue = -2.0f;
    double motorVoltageRealValue = 3.0f;
    double motorCurrentRealValue = -4.0f;
    double backEmfImaginaryValue = 5.0f;
    double dcBusAmpHoursValue = -6.0f;

    EXPECT_CALL(*powerData_, busCurrentA())
        .WillRepeatedly(Return(busCurrentAValue));
    EXPECT_CALL(*powerData_, busVoltage())
        .WillRepeatedly(Return(busVoltageValue));
    EXPECT_CALL(*powerData_, motorVoltageReal())
        .WillRepeatedly(Return(motorVoltageRealValue));
    EXPECT_CALL(*powerData_, motorCurrentReal())
        .WillRepeatedly(Return(motorCurrentRealValue));
    EXPECT_CALL(*powerData_, backEmfImaginary())
        .WillRepeatedly(Return(backEmfImaginaryValue));
    EXPECT_CALL(*powerData_, dcBusAmpHours())
        .WillRepeatedly(Return(dcBusAmpHoursValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonStringIs(JsonFormat::DATA_TYPE, "Power"),
                                  JsonIs("busCurrentA", busCurrentAValue),
                                  JsonIs("busVoltage", busVoltageValue),
                                  JsonIs("motorVoltageReal", motorVoltageRealValue),
                                  JsonIs("motorCurrentReal", motorCurrentRealValue),
                                  JsonIs("backEmfImaginary", backEmfImaginaryValue),
                                  JsonIs("dcBusAmpHours", dcBusAmpHoursValue))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}

TEST_F(JsonForwarderTest, vehicleDataForwarded)
{
    double driverSetSpeedMetersPerSecondValue = 1.1f;
    double driverSetCurrentValue = -2.2f;
    double vehicleVelocityMetersPerSecondValue = 3.3f;
    double motorVelocityRpmValue = -4.4f;
    double ipmHeatSinkTempValue = 5.5f;
    double dspBoardTempValue = -6.6f;
    double receivedErrorCountValue = 8.8f;
    double transmittedErrorCountValue = -9.9f;

    EXPECT_CALL(*vehicleData_, driverSetSpeedMetersPerSecond())
        .WillRepeatedly(Return(driverSetSpeedMetersPerSecondValue));
    EXPECT_CALL(*vehicleData_, driverSetCurrent())
        .WillRepeatedly(Return(driverSetCurrentValue));
    EXPECT_CALL(*vehicleData_, vehicleVelocityMetersPerSecond())
        .WillRepeatedly(Return(vehicleVelocityMetersPerSecondValue));
    EXPECT_CALL(*vehicleData_, motorVelocityRpm())
        .WillRepeatedly(Return(motorVelocityRpmValue));
    EXPECT_CALL(*vehicleData_, ipmHeatSinkTemp())
        .WillRepeatedly(Return(ipmHeatSinkTempValue));
    EXPECT_CALL(*vehicleData_, dspBoardTemp())
        .WillRepeatedly(Return(dspBoardTempValue));
    EXPECT_CALL(*vehicleData_, receivedErrorCount())
        .WillRepeatedly(Return(receivedErrorCountValue));
    EXPECT_CALL(*vehicleData_, transmittedErrorCount())
        .WillRepeatedly(Return(transmittedErrorCountValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonStringIs(JsonFormat::DATA_TYPE, "Vehicle"),
                                  JsonIs("driverSetSpeedMetersPerSecond", driverSetSpeedMetersPerSecondValue),
                                  JsonIs("driverSetCurrent", driverSetCurrentValue),
                                  JsonIs("vehicleVelocityMetersPerSecond", vehicleVelocityMetersPerSecondValue),
                                  JsonIs("motorVelocityRpm", motorVelocityRpmValue),
                                  JsonIs("ipmHeatSinkTemp", ipmHeatSinkTempValue),
                                  JsonIs("dspBoardTemp", dspBoardTempValue),
                                  JsonIs("receivedErrorCount", receivedErrorCountValue),
                                  JsonIs("transmittedErrorCount", transmittedErrorCountValue))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
}
*/
