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

namespace
{
    const int FORWARD_INTERVAL = 10;
}

class JsonForwarderBatteryTest : public ::testing::Test
{

protected:
    MockBatteryData* batteryData_;
    MockFaultsData* faultsData_;
    MockPowerData* powerData_;
    MockVehicleData* vehicleData_;
    MockMessageForwarder* messageForwarder_;
    JsonForwarder* jsonForwarder_;

    virtual void SetUp()
    {

        batteryData_ = new MockBatteryData();
        faultsData_ = new MockFaultsData();
        powerData_ = new MockPowerData();
        vehicleData_ = new MockVehicleData();
        messageForwarder_ = new MockMessageForwarder();
        jsonForwarder_ = new JsonForwarder(*batteryData_,
                                           *faultsData_,
                                           *powerData_,
                                           *vehicleData_,
                                           *messageForwarder_);
    }

    virtual void TearDown()
    {
        delete batteryData_;
        delete faultsData_;
        delete powerData_;
        delete vehicleData_;
        delete messageForwarder_;
        delete jsonForwarder_;
    }
};

MATCHER_P2(JsonDoubleIs, key, value, "") {
    QJsonObject jsonObj = QJsonDocument::fromBinaryData(arg).object();
    return jsonObj[key].toDouble() == value;
}

MATCHER_P3(JsonNestedDoubleIs, key1, key2, value, "") {
    QJsonObject jsonObj = QJsonDocument::fromBinaryData(arg).object();
    return jsonObj[key1].toObject()[key2].toDouble() == value;
}

MATCHER_P3(JsonNestedDoubleArrayIs, key1, key2, value, "") {
    QJsonObject jsonObj = QJsonDocument::fromBinaryData(arg).object();
    QJsonArray jsonArr = jsonObj[key1].toObject()[key2].toArray();
    for(int i = 0; i < value.size(); i++)
    {
        if(jsonArr[i].toDouble() != value[i])
        {
            return false;
        }
    }
    return true;
}

MATCHER_P2(JsonStringIs, key, value, "") {
    QJsonObject jsonObj = QJsonDocument::fromBinaryData(arg).object();
    return jsonObj[key].toString() == value;
}

TEST_F(JsonForwarderBatteryTest, batteryDataForwarded)
{
    EXPECT_CALL(*messageForwarder_,
                forwardData(JsonStringIs("dataType", "Battery")))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL); //msec
    QTest::qWait(FORWARD_INTERVAL * 10); //msec
}

TEST_F(JsonForwarderBatteryTest, mod0DataForwarded)
{

    double mod0PcbTemperatureValue = 1.0;
    double mod0CellTemperatureValue = 2.0;
    QList<double> mod0CellVoltagesValue =  {3.1f, 3.2f, 3.3f, 3.4f, 3.5f, 3.6f, 3.7f, 3.8f};
    ON_CALL(*batteryData_, mod0PcbTemperature())
        .WillByDefault(Return(mod0PcbTemperatureValue));
    ON_CALL(*batteryData_, mod0CellTemperature())
        .WillByDefault(Return(mod0CellTemperatureValue));
    ON_CALL(*batteryData_, mod0CellVoltages())
        .WillByDefault(Return(mod0CellVoltagesValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedDoubleIs("mod0", "pcbTemperature", mod0PcbTemperatureValue),
                                  JsonNestedDoubleIs("mod0", "cellTemperature", mod0CellTemperatureValue),
                                  JsonNestedDoubleArrayIs("mod0", "cellVoltages", mod0CellVoltagesValue))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL); //msec
    QTest::qWait(FORWARD_INTERVAL * 10); //msec
}

TEST_F(JsonForwarderBatteryTest, mod1DataForwarded)
{
    double mod1PcbTemperatureValue = 11.0;
    double mod1CellTemperatureValue = 12.0;
    QList<double> mod1CellVoltagesValue = {13.1f, 13.2f, 13.3f, 13.4f, 13.5f, 13.6f, 13.7f, 13.8f};
    ON_CALL(*batteryData_, mod1PcbTemperature())
        .WillByDefault(Return(mod1PcbTemperatureValue));
    ON_CALL(*batteryData_, mod1CellTemperature())
        .WillByDefault(Return(mod1CellTemperatureValue));
    ON_CALL(*batteryData_, mod1CellVoltages())
        .WillByDefault(Return(mod1CellVoltagesValue));


    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedDoubleIs("mod1", "pcbTemperature", mod1PcbTemperatureValue),
                                  JsonNestedDoubleIs("mod1", "cellTemperature", mod1CellTemperatureValue),
                                  JsonNestedDoubleArrayIs("mod1", "cellVoltages", mod1CellVoltagesValue))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL); //msec
    QTest::qWait(FORWARD_INTERVAL * 10); //msec
}

TEST_F(JsonForwarderBatteryTest, mod2DataForwarded)
{
    double mod2PcbTemperatureValue = 21.0;
    double mod2CellTemperatureValue = 22.0;
    QList<double> mod2CellVoltagesValue = {23.1f, 23.2f, 23.3f, 23.4f, 23.5f, 23.6f, 23.7f, 23.8f};
    ON_CALL(*batteryData_, mod2PcbTemperature())
        .WillByDefault(Return(mod2PcbTemperatureValue));
    ON_CALL(*batteryData_, mod2CellTemperature())
        .WillByDefault(Return(mod2CellTemperatureValue));
    ON_CALL(*batteryData_, mod2CellVoltages())
        .WillByDefault(Return(mod2CellVoltagesValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedDoubleIs("mod2", "pcbTemperature", mod2PcbTemperatureValue),
                                  JsonNestedDoubleIs("mod2", "cellTemperature", mod2CellTemperatureValue),
                                  JsonNestedDoubleArrayIs("mod2", "cellVoltages", mod2CellVoltagesValue))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL); //msec
    QTest::qWait(FORWARD_INTERVAL * 10); //msec
}

TEST_F(JsonForwarderBatteryTest, mod3DataForwarded)
{
    double mod3PcbTemperatureValue = 31.0;
    double mod3CellTemperatureValue = 32.0;
    QList<double> mod3CellVoltagesValue = {33.1f, 33.2f, 33.3f, 33.4f, 33.5f, 33.6f, 33.7f, 33.8f};
    ON_CALL(*batteryData_, mod3PcbTemperature())
        .WillByDefault(Return(mod3PcbTemperatureValue));
    ON_CALL(*batteryData_, mod3CellTemperature())
        .WillByDefault(Return(mod3CellTemperatureValue));
    ON_CALL(*batteryData_, mod3CellVoltages())
        .WillByDefault(Return(mod3CellVoltagesValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonNestedDoubleIs("mod3", "pcbTemperature", mod3PcbTemperatureValue),
                                  JsonNestedDoubleIs("mod3", "cellTemperature", mod3CellTemperatureValue),
                                  JsonNestedDoubleArrayIs("mod3", "cellVoltages", mod3CellVoltagesValue))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL); //msec
    QTest::qWait(FORWARD_INTERVAL * 10); //msec
}

TEST_F(JsonForwarderBatteryTest, batteryBatteryDataForwarded)
{
    double batteryVoltageValue = 41.0;
    double batteryCurrentValue = 42.0;
    ON_CALL(*batteryData_, batteryVoltage())
        .WillByDefault(Return(batteryVoltageValue));
    ON_CALL(*batteryData_, batteryCurrent())
        .WillByDefault(Return(batteryCurrentValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonDoubleIs("batteryVoltage", batteryVoltageValue),
                                  JsonDoubleIs("batteryCurrent", batteryCurrentValue))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL); //msec
    QTest::qWait(FORWARD_INTERVAL * 10); //msec
}

