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

namespace
{
    const int FORWARD_INTERVAL_MSEC = 5;
    const int FORWARD_ITERATIONS = 10;
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

/****** TESTS ******/

// TEST_F(JsonForwarderTest, dataForwarded)
// {
//     EXPECT_CALL(*messageForwarder_, forwardData(_))
//         .Times(AtLeast(1));
//     jsonForwarder_->startForwardingData(FORWARD_INTERVAL_MSEC);
//     QTest::qWait(FORWARD_INTERVAL_MSEC * FORWARD_ITERATIONS);
// }
