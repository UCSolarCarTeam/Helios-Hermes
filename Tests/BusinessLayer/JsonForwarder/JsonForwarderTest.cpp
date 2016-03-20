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
    const int FORWARD_INTERVAL_MSEC = 10;
    const int FORWARD_ITERATIONS_MSEC = 10;
}

class JsonForwarderTest : public ::testing::Test
{

protected:
    QScopedPointer<MockBatteryData> batteryData_;
    QScopedPointer<MockFaultsData> faultsData_;
    QScopedPointer<MockPowerData> powerData_;
    QScopedPointer<MockVehicleData> vehicleData_;
    QScopedPointer<MockMessageForwarder> messageForwarder_;
    QScopedPointer<JsonForwarder> jsonForwarder_;

    virtual void SetUp()
    {

        batteryData_.reset(new MockBatteryData());
        faultsData_.reset(new MockFaultsData());
        powerData_.reset(new MockPowerData());
        vehicleData_.reset(new MockVehicleData());
        messageForwarder_.reset(new MockMessageForwarder());
        jsonForwarder_.reset(new JsonForwarder(*batteryData_,
                                               *faultsData_,
                                               *powerData_,
                                               *vehicleData_,
                                               *messageForwarder_));
    }
};

/****** JSON MATCHERS ******/

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

MATCHER_P3(JsonNestedBoolIs, key1, key2, value, "") {
    QJsonObject jsonObj = QJsonDocument::fromBinaryData(arg).object();
    return jsonObj[key1].toObject()[key2].toBool() == value;    
}


/****** TESTS ******/

TEST_F(JsonForwarderTest, batteryDataForwarded)
{
    double mod0PcbTemperatureValue = 1.0;
    double mod0CellTemperatureValue = 2.0;
    QList<double> mod0CellVoltagesValue =  {3.1f, 3.2f, 3.3f, 3.4f, 3.5f, 3.6f, 3.7f, 3.8f};
    double mod1PcbTemperatureValue = 11.0;
    double mod1CellTemperatureValue = 12.0;
    QList<double> mod1CellVoltagesValue = {13.1f, 13.2f, 13.3f, 13.4f, 13.5f, 13.6f, 13.7f, 13.8f};
    double mod2PcbTemperatureValue = 21.0;
    double mod2CellTemperatureValue = 22.0;
    QList<double> mod2CellVoltagesValue = {23.1f, 23.2f, 23.3f, 23.4f, 23.5f, 23.6f, 23.7f, 23.8f};
    double mod3PcbTemperatureValue = 31.0;
    double mod3CellTemperatureValue = 32.0;
    QList<double> mod3CellVoltagesValue = {33.1f, 33.2f, 33.3f, 33.4f, 33.5f, 33.6f, 33.7f, 33.8f};
    double batteryVoltageValue = 41.0;
    double batteryCurrentValue = 42.0;

    ON_CALL(*batteryData_, mod0PcbTemperature())
        .WillByDefault(Return(mod0PcbTemperatureValue));
    ON_CALL(*batteryData_, mod0CellTemperature())
        .WillByDefault(Return(mod0CellTemperatureValue));
    ON_CALL(*batteryData_, mod0CellVoltages())
        .WillByDefault(Return(mod0CellVoltagesValue));
    ON_CALL(*batteryData_, mod1PcbTemperature())
        .WillByDefault(Return(mod1PcbTemperatureValue));
    ON_CALL(*batteryData_, mod1CellTemperature())
        .WillByDefault(Return(mod1CellTemperatureValue));
    ON_CALL(*batteryData_, mod1CellVoltages())
        .WillByDefault(Return(mod1CellVoltagesValue));
    ON_CALL(*batteryData_, mod2PcbTemperature())
        .WillByDefault(Return(mod2PcbTemperatureValue));
    ON_CALL(*batteryData_, mod2CellTemperature())
        .WillByDefault(Return(mod2CellTemperatureValue));
    ON_CALL(*batteryData_, mod2CellVoltages())
        .WillByDefault(Return(mod2CellVoltagesValue));
    ON_CALL(*batteryData_, mod3PcbTemperature())
        .WillByDefault(Return(mod3PcbTemperatureValue));
    ON_CALL(*batteryData_, mod3CellTemperature())
        .WillByDefault(Return(mod3CellTemperatureValue));
    ON_CALL(*batteryData_, mod3CellVoltages())
        .WillByDefault(Return(mod3CellVoltagesValue));
    ON_CALL(*batteryData_, batteryVoltage())
        .WillByDefault(Return(batteryVoltageValue));
    ON_CALL(*batteryData_, batteryCurrent())
        .WillByDefault(Return(batteryCurrentValue));

    EXPECT_CALL(*messageForwarder_,
                forwardData(AllOf(JsonStringIs("dataType", "Vehicle"),
                                  JsonNestedDoubleIs("mod0", "pcbTemperature", mod0PcbTemperatureValue),
                                  JsonNestedDoubleIs("mod0", "cellTemperature", mod0CellTemperatureValue),
                                  JsonNestedDoubleArrayIs("mod0", "cellVoltages", mod0CellVoltagesValue),
                                  JsonNestedDoubleIs("mod1", "pcbTemperature", mod1PcbTemperatureValue),
                                  JsonNestedDoubleIs("mod1", "cellTemperature", mod1CellTemperatureValue),
                                  JsonNestedDoubleArrayIs("mod1", "cellVoltages", mod1CellVoltagesValue),
                                  JsonNestedDoubleIs("mod2", "pcbTemperature", mod2PcbTemperatureValue),
                                  JsonNestedDoubleIs("mod2", "cellTemperature", mod2CellTemperatureValue),
                                  JsonNestedDoubleArrayIs("mod2", "cellVoltages", mod2CellVoltagesValue),
                                  JsonNestedDoubleIs("mod3", "pcbTemperature", mod3PcbTemperatureValue),
                                  JsonNestedDoubleIs("mod3", "cellTemperature", mod3CellTemperatureValue),
                                  JsonNestedDoubleArrayIs("mod3", "cellVoltages", mod3CellVoltagesValue),
                                  JsonDoubleIs("batteryVoltage", batteryVoltageValue),
                                  JsonDoubleIs("batteryCurrent", batteryCurrentValue))))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL_MSEC);
    QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS_MSEC);
}

TEST_F(JsonForwarderTest, faultsDataForwarded)
{
    EXPECT_CALL(*messageForwarder_,
                forwardData(JsonStringIs("dataType", "Faults")))
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
    
    ON_CALL(*powerData_, busCurrentA())
        .WillByDefault(Return(busCurrentAValue));
    ON_CALL(*powerData_, busVoltage())
        .WillByDefault(Return(busVoltageValue));
    ON_CALL(*powerData_, motorVoltageReal())
        .WillByDefault(Return(motorVoltageRealValue));
    ON_CALL(*powerData_, motorCurrentReal())
        .WillByDefault(Return(motorCurrentRealValue));
    ON_CALL(*powerData_, backEmfImaginary())
        .WillByDefault(Return(backEmfImaginaryValue));
    ON_CALL(*powerData_, dcBusAmpHours())
        .WillByDefault(Return(dcBusAmpHoursValue));

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

    ON_CALL(*vehicleData_, driverSetSpeedMetersPerSecond())
        .WillByDefault(Return(driverSetSpeedMetersPerSecondValue)); 
    ON_CALL(*vehicleData_, driverSetCurrent())
        .WillByDefault(Return(driverSetCurrentValue)); 
    ON_CALL(*vehicleData_, vehicleVelocityMetersPerSecond())
        .WillByDefault(Return(vehicleVelocityMetersPerSecondValue)); 
    ON_CALL(*vehicleData_, motorVelocityRpm())
        .WillByDefault(Return(motorVelocityRpmValue)); 
    ON_CALL(*vehicleData_, ipmHeatSinkTemp())
        .WillByDefault(Return(ipmHeatSinkTempValue)); 
    ON_CALL(*vehicleData_, dspBoardTemp())
        .WillByDefault(Return(dspBoardTempValue)); 
    ON_CALL(*vehicleData_, receivedErrorCount())
        .WillByDefault(Return(receivedErrorCountValue)); 
    ON_CALL(*vehicleData_, transmittedErrorCount())
        .WillByDefault(Return(transmittedErrorCountValue)); 

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
