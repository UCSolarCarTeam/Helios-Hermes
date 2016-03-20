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

class JsonForwarderVehicleTest : public ::testing::Test 
{

protected:
    MockBatteryData* batteryData_;
    MockFaultsData* faultsData_;
    MockPowerData* powerData_;
    MockVehicleData* vehicleData_;
    MockMessageForwarder* messageForwarder_;
    JsonForwarder* jsonForwarder_;
    const int FORWARD_INTERVAL = 10;
    

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

TEST_F(JsonForwarderVehicleTest, dataForwarded) 
{
    EXPECT_CALL(*messageForwarder_, forwardData(_))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL); //msec
    QTest::qWait(FORWARD_INTERVAL * 10); //msec
}

TEST_F(JsonForwarderVehicleTest, batteryDataForwarded) 
{
    EXPECT_CALL(*messageForwarder_, forwardData(_))
        .Times(AtLeast(1));
    jsonForwarder_->start(FORWARD_INTERVAL);
    QTest::qWait(FORWARD_INTERVAL * 10);

}

TEST_F(JsonForwarderVehicleTest, faultDataForwarded) 
{

}

TEST_F(JsonForwarderVehicleTest, PowerDataForwarded) 
{

}

TEST_F(JsonForwarderVehicleTest, vehicleDataForwarded) 
{

}
