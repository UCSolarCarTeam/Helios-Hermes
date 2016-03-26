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
    const int FORWARD_INTERVAL_MSEC = 10;
    const int FORWARD_ITERATIONS_MSEC = 10;
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
    }
};

/****** JSON MATCHERS ******/

MATCHER_P2(JsonStringIs, key, value, "")
{
  QJsonObject jsonObj = QJsonDocument::fromJson(arg).object();
  return jsonObj[key].toString() == value;
}

MATCHER_P3(JsonNestedStringIs, key1, key2, value, "") {
    QJsonObject jsonObj = QJsonDocument::fromJson(arg).object();
    return jsonObj[key1].toObject()[key2].toString() == value;
}

MATCHER_P3(JsonNestedStringArrayIs, key1, key2, value, "") {
    QJsonObject jsonObj = QJsonDocument::fromJson(arg).object();
    QJsonArray jsonArr = jsonObj[key1].toObject()[key2].toArray();
    for(int i = 0; i < value.size(); i++)
    {
        if(jsonArr[i].toString() != value[i])
        {
            qDebug() << "actual is " << jsonArr[i].toString();
            qDebug() << "expected is " << value[i];
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
                forwardData(JsonStringIs("dataType", "Battery")))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS_MSEC * 10);
}

TEST_F(JsonForwarderTest, batteryMod0DataForwarded)
{
    double mod0PcbTemperatureDouble_ = 1.0;
    QString mod0PcbTemperatureString = "1.00";
    double mod0CellTemperatureDouble = 2.0;
    QString mod0CellTemperatureString = "2.00";
    QList<double> mod0CellVoltagesDouble =  {3.1f, 3.2f, 3.3f, 3.4f, 3.5f, 3.6f, 3.7f, 3.8f};
    QList<QString> mod0CellVoltagesString =  {"3.10", "3.20", "3.30", "3.40", "3.50", "3.60", "3.70", "3.80"};

    EXPECT_CALL(*batteryData_, mod0PcbTemperature())
        .WillRepeatedly(Return(mod0PcbTemperatureDouble_));
    EXPECT_CALL(*batteryData_, mod0CellTemperature())
        .WillRepeatedly(Return(mod0CellTemperatureDouble));
    EXPECT_CALL(*batteryData_, mod0CellVoltages())
        .WillRepeatedly(Return(mod0CellVoltagesDouble));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedStringIs("mod0", "pcbTemperature", mod0PcbTemperatureString),
                                  JsonNestedStringIs("mod0", "cellTemperature", mod0CellTemperatureString),
                                  JsonNestedStringArrayIs("mod0", "cellVoltages", mod0CellVoltagesString))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS_MSEC * 10);
}

TEST_F(JsonForwarderTest, batteryMod1DataForwarded)
{
    double mod1PcbTemperatureDouble = 11.0;
    QString mod1PcbTemperatureString = "11.00";
    double mod1CellTemperatureDouble = 12.0;
    QString mod1CellTemperatureString = "12.00";
    QList<double> mod1CellVoltagesDouble = {13.1f, 13.2f, 13.3f, 13.4f, 13.5f, 13.6f, 13.7f, 13.8f};
    QList<QString> mod1CellVoltagesString = {"13.10", "13.20", "13.30", "13.40", "13.50", "13.60", "13.70", "13.80"};

    EXPECT_CALL(*batteryData_, mod1PcbTemperature())
        .WillRepeatedly(Return(mod1PcbTemperatureDouble));
    EXPECT_CALL(*batteryData_, mod1CellTemperature())
        .WillRepeatedly(Return(mod1CellTemperatureDouble));
    EXPECT_CALL(*batteryData_, mod1CellVoltages())
        .WillRepeatedly(Return(mod1CellVoltagesDouble));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedStringIs("mod1", "pcbTemperature", mod1PcbTemperatureString),
                                  JsonNestedStringIs("mod1", "cellTemperature", mod1CellTemperatureString),
                                  JsonNestedStringArrayIs("mod1", "cellVoltages", mod1CellVoltagesString))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS_MSEC * 10);
}

TEST_F(JsonForwarderTest, batteryMod2DataForwarded)
{
    double mod2PcbTemperatureDouble = 21.0;
    QString mod2PcbTemperatureString = "21.00";
    double mod2CellTemperatureDouble = 22.0;
    QString mod2CellTemperatureString = "22.00";
    QList<double> mod2CellVoltagesDouble = {23.1f, 23.2f, 23.3f, 23.4f, 23.5f, 23.6f, 23.7f, 23.8f};
    QList<QString> mod2CellVoltagesString = {"23.10", "23.20", "23.30", "23.40", "23.50", "23.60", "23.70", "23.80"};

    EXPECT_CALL(*batteryData_, mod2PcbTemperature())
        .WillRepeatedly(Return(mod2PcbTemperatureDouble));
    EXPECT_CALL(*batteryData_, mod2CellTemperature())
        .WillRepeatedly(Return(mod2CellTemperatureDouble));
    EXPECT_CALL(*batteryData_, mod2CellVoltages())
        .WillRepeatedly(Return(mod2CellVoltagesDouble));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedStringIs("mod2", "pcbTemperature", mod2PcbTemperatureString),
                                  JsonNestedStringIs("mod2", "cellTemperature", mod2CellTemperatureString),
                                  JsonNestedStringArrayIs("mod2", "cellVoltages", mod2CellVoltagesString))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS_MSEC * 10);
}

TEST_F(JsonForwarderTest, batteryMod3DataForwarded)
{
    double mod3PcbTemperatureDouble = 31.0;
    QString mod3PcbTemperatureString = "31.00";
    double mod3CellTemperatureDouble = 32.0;
    QString mod3CellTemperatureString = "32.00";
    QList<double> mod3CellVoltagesDouble = {33.1f, 33.2f, 33.3f, 33.4f, 33.5f, 33.6f, 33.7f, 33.8f};
    QList<QString> mod3CellVoltagesString = {"33.10", "33.20", "33.30", "33.40", "33.50", "33.60", "33.70", "33.80"};
    
    EXPECT_CALL(*batteryData_, mod3PcbTemperature())
        .WillRepeatedly(Return(mod3PcbTemperatureDouble));
    EXPECT_CALL(*batteryData_, mod3CellTemperature())
        .WillRepeatedly(Return(mod3CellTemperatureDouble));
    EXPECT_CALL(*batteryData_, mod3CellVoltages())
        .WillRepeatedly(Return(mod3CellVoltagesDouble));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedStringIs("mod3", "pcbTemperature", mod3PcbTemperatureString),
                                  JsonNestedStringIs("mod3", "cellTemperature", mod3CellTemperatureString),
                                  JsonNestedStringArrayIs("mod3", "cellVoltages", mod3CellVoltagesString))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS_MSEC * 10);
}

TEST_F(JsonForwarderTest, batteryInternalDataForwarded)
{
    double batteryVoltageDouble = 41.0;
    QString batteryVoltageString = "41.00";
    double batteryCurrentDouble = 42.0;
    QString batteryCurrentString = "42.00";

    EXPECT_CALL(*batteryData_, batteryVoltage())
        .WillRepeatedly(Return(batteryVoltageDouble));
    EXPECT_CALL(*batteryData_, batteryCurrent())
        .WillRepeatedly(Return(batteryCurrentDouble));   

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonStringIs("batteryVoltage", batteryVoltageString),
                                  JsonStringIs("batteryCurrent", batteryCurrentString))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS_MSEC * 10);
}

/*
TEST_F(JsonForwarderTest, faultsDataForwarded)
{
    quint8 mockMotorFaultPattern = 0xaa; // 0xaa == 1010 1010 in binary
    quint8 mockLimitFlagPattern = 0xaa; // 0xaa == 1010 1010 in binary
    quint16 mockBatteryFaultPattern = 0xaaaa; // 0xaaaa == 1010 1010 1010 1010 in binary

    MotorFaults motorOneFaultsValue = MotorFaults(mockMotorFaultPattern);
    LimitFlags motorOneLimitFlagsValue = LimitFlags(mockLimitFlagPattern);
    MotorFaults motorTwoFaultsValue = MotorFaults(mockMotorFaultPattern);
    LimitFlags motorTwoLimitFlagsValue = LimitFlags(mockLimitFlagPattern);
    BatteryFaults batteryFaultsValue = BatteryFaults(mockBatteryFaultPattern);
    EXPECT_CALL(*faultsData_, motorOneFaults())
        .WillRepeatedly(Return(motorOneFaultsValue));
    EXPECT_CALL(*faultsData_, motorOneLimitFlags())
        .WillRepeatedly(Return(motorOneLimitFlagsValue));
    EXPECT_CALL(*faultsData_, motorTwoFaults())
        .WillRepeatedly(Return(motorTwoFaultsValue));
    EXPECT_CALL(*faultsData_, motorTwoLimitFlags())
        .WillRepeatedly(Return(motorTwoLimitFlagsValue));
    EXPECT_CALL(*faultsData_, batteryFaults())
        .WillRepeatedly(Return(batteryFaultsValue));


    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonStringIs("dataType", "Faults"),
                                  JsonNestedBoolIs("motorOneFaults", "hardwareOverCurrent", false),
                                  JsonNestedBoolIs("motorOneFaults", "softwareOverCurrent", true),
                                  JsonNestedBoolIs("motorOneFaults", "dcBusOverVoltage", false),
                                  JsonNestedBoolIs("motorOneFaults", "badMotorPositionHallSequence", true),
                                  JsonNestedBoolIs("motorOneFaults", "watchdogCausedLastReset", false),
                                  JsonNestedBoolIs("motorOneFaults", "configReadError", true),
                                  JsonNestedBoolIs("motorOneFaults", "railUnderVoltageLockOut", false),
                                  JsonNestedBoolIs("motorOneFaults", "desaturationFault", true),
                                  JsonNestedBoolIs("motorOneLimitFlags", "outputVoltagePwmLimit", false),
                                  JsonNestedBoolIs("motorOneLimitFlags", "motorCurrentLimit", true),
                                  JsonNestedBoolIs("motorOneLimitFlags", "velocityLimit", false),
                                  JsonNestedBoolIs("motorOneLimitFlags", "busCurrentLimit", true),
                                  JsonNestedBoolIs("motorOneLimitFlags", "busVoltageUpperLimit", false),
                                  JsonNestedBoolIs("motorOneLimitFlags", "busVoltageLowerLimit", true),
                                  JsonNestedBoolIs("motorOneLimitFlags", "ipmOrMotorTelemetryLimit", false),
                                  JsonNestedBoolIs("motorTwoFaults", "hardwareOverCurrent", false),
                                  JsonNestedBoolIs("motorTwoFaults", "softwareOverCurrent", true),
                                  JsonNestedBoolIs("motorTwoFaults", "dcBusOverVoltage", false),
                                  JsonNestedBoolIs("motorTwoFaults", "badMotorPositionHallSequence", true),
                                  JsonNestedBoolIs("motorTwoFaults", "watchdogCausedLastReset", false),
                                  JsonNestedBoolIs("motorTwoFaults", "configReadError", true),
                                  JsonNestedBoolIs("motorTwoFaults", "railUnderVoltageLockOut", false),
                                  JsonNestedBoolIs("motorTwoFaults", "desaturationFault", true),
                                  JsonNestedBoolIs("motorTwoLimitFlags", "outputVoltagePwmLimit", false),
                                  JsonNestedBoolIs("motorTwoLimitFlags", "motorCurrentLimit", true),
                                  JsonNestedBoolIs("motorTwoLimitFlags", "velocityLimit", false),
                                  JsonNestedBoolIs("motorTwoLimitFlags", "busCurrentLimit", true),
                                  JsonNestedBoolIs("motorTwoLimitFlags", "busVoltageUpperLimit", false),
                                  JsonNestedBoolIs("motorTwoLimitFlags", "busVoltageLowerLimit", true),
                                  JsonNestedBoolIs("motorTwoLimitFlags", "ipmOrMotorTelemetryLimit", false),
                                  JsonNestedBoolIs("batteryFaults", "cellOverVoltage", false),
                                  JsonNestedBoolIs("batteryFaults", "cellUnderVoltage", true),
                                  JsonNestedBoolIs("batteryFaults", "cellOverTemperature", false),
                                  JsonNestedBoolIs("batteryFaults", "measurementUntrusted", true),
                                  JsonNestedBoolIs("batteryFaults", "cmuCommTimeout", false),
                                  JsonNestedBoolIs("batteryFaults", "vehicleCommTimeout", true),
                                  JsonNestedBoolIs("batteryFaults", "bmuIsInSetupMode", false),
                                  JsonNestedBoolIs("batteryFaults", "cmuCanBusPowerStatus", true),
                                  JsonNestedBoolIs("batteryFaults", "packIsolationTestFailure", false),
                                  JsonNestedBoolIs("batteryFaults", "softwareOverCurrentMeasured", true),
                                  JsonNestedBoolIs("batteryFaults", "canSupplyIsLow", false),
                                  JsonNestedBoolIs("batteryFaults", "contactorIsStuck", true),
                                  JsonNestedBoolIs("batteryFaults", "cmuDetectedExtraCellPresent", false))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS_MSEC);
}

TEST_F(JsonForwarderTest, invertedFaultsDataForwarded)
{
    quint8 mockInvertedMotorFaultPattern = 0x55; // 0x55 == 0101 0101 in binary
    quint8 mockInvertedLimitFlagPattern = 0x55; // 0x55 == 0101 0101 in binary
    quint16 mockInvertedBatteryFaultPattern = 0x5555; // 0x5555 == 0101 0101 0101 0101 in binary

    MotorFaults motorOneFaultsValue = MotorFaults(mockInvertedMotorFaultPattern);
    LimitFlags motorOneLimitFlagsValue = LimitFlags(mockInvertedLimitFlagPattern);
    MotorFaults motorTwoFaultsValue = MotorFaults(mockInvertedMotorFaultPattern);
    LimitFlags motorTwoLimitFlagsValue = LimitFlags(mockInvertedLimitFlagPattern);
    BatteryFaults batteryFaultsValue = BatteryFaults(mockInvertedBatteryFaultPattern);
    EXPECT_CALL(*faultsData_, motorOneFaults())
        .WillRepeatedly(Return(motorOneFaultsValue));
    EXPECT_CALL(*faultsData_, motorOneLimitFlags())
        .WillRepeatedly(Return(motorOneLimitFlagsValue));
    EXPECT_CALL(*faultsData_, motorTwoFaults())
        .WillRepeatedly(Return(motorTwoFaultsValue));
    EXPECT_CALL(*faultsData_, motorTwoLimitFlags())
        .WillRepeatedly(Return(motorTwoLimitFlagsValue));
    EXPECT_CALL(*faultsData_, batteryFaults())
        .WillRepeatedly(Return(batteryFaultsValue));


    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonStringIs("dataType", "Faults"),
                                  JsonNestedBoolIs("motorOneFaults", "hardwareOverCurrent", true),
                                  JsonNestedBoolIs("motorOneFaults", "softwareOverCurrent", false),
                                  JsonNestedBoolIs("motorOneFaults", "dcBusOverVoltage", true),
                                  JsonNestedBoolIs("motorOneFaults", "badMotorPositionHallSequence", false),
                                  JsonNestedBoolIs("motorOneFaults", "watchdogCausedLastReset", true),
                                  JsonNestedBoolIs("motorOneFaults", "configReadError", false),
                                  JsonNestedBoolIs("motorOneFaults", "railUnderVoltageLockOut", true),
                                  JsonNestedBoolIs("motorOneFaults", "desaturationFault", false),
                                  JsonNestedBoolIs("motorOneLimitFlags", "outputVoltagePwmLimit", true),
                                  JsonNestedBoolIs("motorOneLimitFlags", "motorCurrentLimit", false),
                                  JsonNestedBoolIs("motorOneLimitFlags", "velocityLimit", true),
                                  JsonNestedBoolIs("motorOneLimitFlags", "busCurrentLimit", false),
                                  JsonNestedBoolIs("motorOneLimitFlags", "busVoltageUpperLimit", true),
                                  JsonNestedBoolIs("motorOneLimitFlags", "busVoltageLowerLimit", false),
                                  JsonNestedBoolIs("motorOneLimitFlags", "ipmOrMotorTelemetryLimit", true),
                                  JsonNestedBoolIs("motorTwoFaults", "hardwareOverCurrent", true),
                                  JsonNestedBoolIs("motorTwoFaults", "softwareOverCurrent", false),
                                  JsonNestedBoolIs("motorTwoFaults", "dcBusOverVoltage", true),
                                  JsonNestedBoolIs("motorTwoFaults", "badMotorPositionHallSequence", false),
                                  JsonNestedBoolIs("motorTwoFaults", "watchdogCausedLastReset", true),
                                  JsonNestedBoolIs("motorTwoFaults", "configReadError", false),
                                  JsonNestedBoolIs("motorTwoFaults", "railUnderVoltageLockOut", true),
                                  JsonNestedBoolIs("motorTwoFaults", "desaturationFault", false),
                                  JsonNestedBoolIs("motorTwoLimitFlags", "outputVoltagePwmLimit", true),
                                  JsonNestedBoolIs("motorTwoLimitFlags", "motorCurrentLimit", false),
                                  JsonNestedBoolIs("motorTwoLimitFlags", "velocityLimit", true),
                                  JsonNestedBoolIs("motorTwoLimitFlags", "busCurrentLimit", false),
                                  JsonNestedBoolIs("motorTwoLimitFlags", "busVoltageUpperLimit", true),
                                  JsonNestedBoolIs("motorTwoLimitFlags", "busVoltageLowerLimit", false),
                                  JsonNestedBoolIs("motorTwoLimitFlags", "ipmOrMotorTelemetryLimit", true),
                                  JsonNestedBoolIs("batteryFaults", "cellOverVoltage", true),
                                  JsonNestedBoolIs("batteryFaults", "cellUnderVoltage", false),
                                  JsonNestedBoolIs("batteryFaults", "cellOverTemperature", true),
                                  JsonNestedBoolIs("batteryFaults", "measurementUntrusted", false),
                                  JsonNestedBoolIs("batteryFaults", "cmuCommTimeout", true),
                                  JsonNestedBoolIs("batteryFaults", "vehicleCommTimeout", false),
                                  JsonNestedBoolIs("batteryFaults", "bmuIsInSetupMode", true),
                                  JsonNestedBoolIs("batteryFaults", "cmuCanBusPowerStatus", false),
                                  JsonNestedBoolIs("batteryFaults", "packIsolationTestFailure", true),
                                  JsonNestedBoolIs("batteryFaults", "softwareOverCurrentMeasured", false),
                                  JsonNestedBoolIs("batteryFaults", "canSupplyIsLow", true),
                                  JsonNestedBoolIs("batteryFaults", "contactorIsStuck", false),
                                  JsonNestedBoolIs("batteryFaults", "cmuDetectedExtraCellPresent", true))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS_MSEC);
}

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
                forwardData(AllOf(JsonStringIs("dataType", "Power"),
                                  JsonDoubleIs("busCurrentA", busCurrentAValue),
                                  JsonDoubleIs("busVoltage", busVoltageValue),
                                  JsonDoubleIs("motorVoltageReal", motorVoltageRealValue),
                                  JsonDoubleIs("motorCurrentReal", motorCurrentRealValue),
                                  JsonDoubleIs("backEmfImaginary", backEmfImaginaryValue),
                                  JsonDoubleIs("dcBusAmpHours", dcBusAmpHoursValue))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS_MSEC);
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
                forwardData(AllOf(JsonStringIs("dataType", "Vehicle"),
                                  JsonDoubleIs("driverSetSpeedMetersPerSecond", driverSetSpeedMetersPerSecondValue),
                                  JsonDoubleIs("driverSetCurrent", driverSetCurrentValue),
                                  JsonDoubleIs("vehicleVelocityMetersPerSecond", vehicleVelocityMetersPerSecondValue),
                                  JsonDoubleIs("motorVelocityRpm", motorVelocityRpmValue),
                                  JsonDoubleIs("ipmHeatSinkTemp", ipmHeatSinkTempValue),
                                  JsonDoubleIs("dspBoardTemp", dspBoardTempValue),
                                  JsonDoubleIs("receivedErrorCount", receivedErrorCountValue),
                                  JsonDoubleIs("transmittedErrorCount", transmittedErrorCountValue))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS_MSEC);
}
*/
