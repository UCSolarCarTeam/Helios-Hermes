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

class JsonForwarderBatteryTest : public ::testing::Test 
{

protected:
    MockBatteryData* batteryData_;
    MockFaultsData* faultsData_;
    MockPowerData* powerData_;
    MockVehicleData* vehicleData_;
    MockMessageForwarder* messageForwarder_;
    JsonForwarder* jsonForwarder_;
    const int FORWARD_INTERVAL = 10;
    
    double mod0_pcb_temperature_value_;
    double mod0_cell_temperature_value_;
    QList<double> mod0_cell_voltages_value_;
    double mod1_pcb_temperature_value_;
    double mod1_cell_temperature_value_;
    QList<double> mod1_cell_voltages_value_;
    double mod2_pcb_temperature_value_;
    double mod2_cell_temperature_value_;
    QList<double> mod2_cell_voltages_value_;
    double mod3_pcb_temperature_value_;
    double mod3_cell_temperature_value_;
    QList<double> mod3_cell_voltages_value_;
    double battery_voltage_value_;
    double battery_current_value_;


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
        mod0_pcb_temperature_value_ = 1.0;
        mod0_cell_temperature_value_ = 2.0;
        mod0_cell_voltages_value_ = {3.1f, 3.2f, 3.3f, 3.4f, 3.5f, 3.6f, 3.7f, 3.8f};

        mod1_pcb_temperature_value_ = 11.0;
        mod1_cell_temperature_value_ = 12.0;
        mod1_cell_voltages_value_ = {13.1f, 13.2f, 13.3f, 13.4f, 13.5f, 13.6f, 13.7f, 13.8f};
        
        mod2_pcb_temperature_value_ = 21.0;
        mod2_cell_temperature_value_ = 22.0;
        mod2_cell_voltages_value_ = {23.1f, 23.2f, 23.3f, 23.4f, 23.5f, 23.6f, 23.7f, 23.8f};
        
        mod3_pcb_temperature_value_ = 31.0;
        mod3_cell_temperature_value_ = 32.0;
        mod3_cell_voltages_value_ = {33.1f, 33.2f, 33.3f, 33.4f, 33.5f, 33.6f, 33.7f, 33.8f};
        
        battery_voltage_value_ = 41.0;
        battery_current_value_ = 42.0;

        ON_CALL(*batteryData_, mod0PcbTemperature())
            .WillByDefault(Return(mod0_pcb_temperature_value_));
        ON_CALL(*batteryData_, mod0CellTemperature())
            .WillByDefault(Return(mod0_cell_temperature_value_));
        ON_CALL(*batteryData_, mod0CellVoltages())
            .WillByDefault(Return(mod0_cell_voltages_value_));
        ON_CALL(*batteryData_, mod1PcbTemperature())
            .WillByDefault(Return(mod1_pcb_temperature_value_));
        ON_CALL(*batteryData_, mod1CellTemperature())
            .WillByDefault(Return(mod1_cell_temperature_value_));
        ON_CALL(*batteryData_, mod1CellVoltages())
            .WillByDefault(Return(mod1_cell_voltages_value_));
        ON_CALL(*batteryData_, mod2PcbTemperature())
            .WillByDefault(Return(mod2_pcb_temperature_value_));
        ON_CALL(*batteryData_, mod2CellTemperature())
            .WillByDefault(Return(mod2_cell_temperature_value_));
        ON_CALL(*batteryData_, mod2CellVoltages())
            .WillByDefault(Return(mod2_cell_voltages_value_));
        ON_CALL(*batteryData_, mod3PcbTemperature())
            .WillByDefault(Return(mod3_pcb_temperature_value_));
        ON_CALL(*batteryData_, mod3CellTemperature())
            .WillByDefault(Return(mod3_cell_temperature_value_));
        ON_CALL(*batteryData_, mod3CellVoltages())
            .WillByDefault(Return(mod3_cell_voltages_value_));
        ON_CALL(*batteryData_, batteryVoltage())
            .WillByDefault(Return(battery_voltage_value_));
        ON_CALL(*batteryData_, batteryCurrent())
            .WillByDefault(Return(battery_current_value_));
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

TEST_F(JsonForwarderBatteryTest, dataForwarded) 
{
    EXPECT_CALL(*messageForwarder_, forwardData(_))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL); //msec
    QTest::qWait(FORWARD_INTERVAL * 10); //msec
}

TEST_F(JsonForwarderBatteryTest, batteryDataForwarded) 
{
    EXPECT_CALL(*messageForwarder_, forwardData(_))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL);
    QTest::qWait(FORWARD_INTERVAL * 10);

}

TEST_F(JsonForwarderBatteryTest, faultDataForwarded) 
{

}

TEST_F(JsonForwarderBatteryTest, PowerDataForwarded) 
{

}

TEST_F(JsonForwarderBatteryTest, vehicleDataForwarded) 
{

}
 
