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

#include "BusinessLayer/JsonForwarder/VehicleJsonForwarder/VehicleJsonForwarder.h"
#include "BusinessLayer/JsonForwarder/JsonDefines.h"

#include "Tests/CommunicationLayer/CommDeviceControl/MockMessageForwarder.h"
#include "Tests/DataLayer/VehicleData/MockVehicleData.h"

using ::testing::Return;

class VehicleJsonForwarderTest : public ::testing::Test
{
protected:
    QScopedPointer<MockVehicleData> vehicleData_;
    QScopedPointer<MockMessageForwarder> messageForwarder_;
    QScopedPointer<VehicleJsonForwarder> vehicleJsonForwarder_;

    virtual void SetUp()
    {
        vehicleData_.reset(new MockVehicleData());
        messageForwarder_.reset(new MockMessageForwarder());
        vehicleJsonForwarder_.reset(new VehicleJsonForwarder(*vehicleData_,
                                                       *messageForwarder_));

        EXPECT_CALL(*vehicleData_, driverSetSpeedMetersPerSecond())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*vehicleData_, driverSetCurrent())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*vehicleData_, vehicleVelocityMetersPerSecond())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*vehicleData_, motorVelocityRpm())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*vehicleData_, ipmHeatSinkTemp())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*vehicleData_, dspBoardTemp())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*vehicleData_, receivedErrorCount())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*vehicleData_, transmittedErrorCount())
            .WillRepeatedly(Return(0));
    }
};

/****** JSON MATCHERS ******/

MATCHER_P2(JsonStringIs, key, value, "")
{
    QJsonObject jsonObj = QJsonDocument::fromJson(arg).object();
    QString actual = jsonObj[key].toString();
    QString expected = value;
    if (actual != expected)
    {
        qDebug() << "Actual is " << actual;
        qDebug() << "Expected is " << expected;
        return false;
    }
    return true;
}

/****** TESTS ******/

TEST_F(VehicleJsonForwarderTest, typeForwarded)
{
    EXPECT_CALL(*messageForwarder_,
                forwardData(JsonStringIs(JsonFormat::DATA_TYPE, JsonFormat::VEHICLE)))
        .Times(1);
    vehicleJsonForwarder_->forwardVehicleData(QJsonObject());
}

TEST_F(VehicleJsonForwarderTest, driverSetSpeedMetersPerSecond)
{
    double driverSetSpeedMetersPerSecond = 0.12;
    QString driverSetSpeedMetersPerSecondString = QString::number(driverSetSpeedMetersPerSecond, 'f', JsonFormat::DECIMAL_PRECISION);
    EXPECT_CALL(*vehicleData_, driverSetSpeedMetersPerSecond())
        .WillRepeatedly(Return(driverSetSpeedMetersPerSecond));
    EXPECT_CALL(*messageForwarder_, forwardData(JsonStringIs(JsonFormat::DRIVER_SET_SPEED_METERS_PER_SECOND, driverSetSpeedMetersPerSecondString)));
    vehicleJsonForwarder_->forwardVehicleData(QJsonObject());
}
TEST_F(VehicleJsonForwarderTest, driverSetCurrent)
{
    double driverSetCurrent = 1.23;
    QString driverSetCurrentString = QString::number(driverSetCurrent, 'f', JsonFormat::DECIMAL_PRECISION);
    EXPECT_CALL(*vehicleData_, driverSetCurrent())
        .WillRepeatedly(Return(driverSetCurrent));
    EXPECT_CALL(*messageForwarder_, forwardData(JsonStringIs(JsonFormat::DRIVER_SET_CURRENT, driverSetCurrentString)));
    vehicleJsonForwarder_->forwardVehicleData(QJsonObject());
}
TEST_F(VehicleJsonForwarderTest, vehicleVelocityMetersPerSecond)
{
    double vehicleVelocityMetersPerSecond = 2.34;
    QString vehicleVelocityMetersPerSecondString = QString::number(vehicleVelocityMetersPerSecond, 'f', JsonFormat::DECIMAL_PRECISION);
    EXPECT_CALL(*vehicleData_, vehicleVelocityMetersPerSecond())
        .WillRepeatedly(Return(vehicleVelocityMetersPerSecond));
    EXPECT_CALL(*messageForwarder_, forwardData(JsonStringIs(JsonFormat::VEHICLE_VELOCITY_METERS_PER_SECOND, vehicleVelocityMetersPerSecondString)));
    vehicleJsonForwarder_->forwardVehicleData(QJsonObject());
}
TEST_F(VehicleJsonForwarderTest, motorVelocityRpm)
{
    double motorVelocityRpm = 3.45;
    QString motorVelocityRpmString = QString::number(motorVelocityRpm, 'f', JsonFormat::DECIMAL_PRECISION);
    EXPECT_CALL(*vehicleData_, motorVelocityRpm())
        .WillRepeatedly(Return(motorVelocityRpm));
    EXPECT_CALL(*messageForwarder_, forwardData(JsonStringIs(JsonFormat::MOTOR_VELOCITY_RPM, motorVelocityRpmString)));
    vehicleJsonForwarder_->forwardVehicleData(QJsonObject());
}
TEST_F(VehicleJsonForwarderTest, ipmHeatSinkTemp)
{
    double ipmHeatSinkTemp = 4.56;
    QString ipmHeatSinkTempString = QString::number(ipmHeatSinkTemp, 'f', JsonFormat::DECIMAL_PRECISION);
    EXPECT_CALL(*vehicleData_, ipmHeatSinkTemp())
        .WillRepeatedly(Return(ipmHeatSinkTemp));
    EXPECT_CALL(*messageForwarder_, forwardData(JsonStringIs(JsonFormat::IPM_HEAT_SINK_TEMP, ipmHeatSinkTempString)));
    vehicleJsonForwarder_->forwardVehicleData(QJsonObject());
}
TEST_F(VehicleJsonForwarderTest, dspBoardTemp)
{
    double dspBoardTemp = 5.67;
    QString dspBoardTempString = QString::number(dspBoardTemp, 'f', JsonFormat::DECIMAL_PRECISION);
    EXPECT_CALL(*vehicleData_, dspBoardTemp())
        .WillRepeatedly(Return(dspBoardTemp));
    EXPECT_CALL(*messageForwarder_, forwardData(JsonStringIs(JsonFormat::DSP_BOARD_TEMP, dspBoardTempString)));
    vehicleJsonForwarder_->forwardVehicleData(QJsonObject());
}
TEST_F(VehicleJsonForwarderTest, receivedErrorCount)
{
    double receivedErrorCount = 6.78;
    QString receivedErrorCountString = QString::number(receivedErrorCount, 'f', JsonFormat::DECIMAL_PRECISION);
    EXPECT_CALL(*vehicleData_, receivedErrorCount())
        .WillRepeatedly(Return(receivedErrorCount));
    EXPECT_CALL(*messageForwarder_, forwardData(JsonStringIs(JsonFormat::RECEIVED_ERROR_COUNT, receivedErrorCountString)));
    vehicleJsonForwarder_->forwardVehicleData(QJsonObject());
}
TEST_F(VehicleJsonForwarderTest, transmittedErrorCount)
{
    double transmittedErrorCount = 7.89;
    QString transmittedErrorCountString = QString::number(transmittedErrorCount, 'f', JsonFormat::DECIMAL_PRECISION);
    EXPECT_CALL(*vehicleData_, transmittedErrorCount())
        .WillRepeatedly(Return(transmittedErrorCount));
    EXPECT_CALL(*messageForwarder_, forwardData(JsonStringIs(JsonFormat::TRANSMITTED_ERROR_COUNT, transmittedErrorCountString)));
    vehicleJsonForwarder_->forwardVehicleData(QJsonObject());
}

TEST_F(VehicleJsonForwarderTest, baseJsonPreserved)
{
    QString fakeFieldKey = "Key";
    QString fakeFieldValue = "Value";
    QJsonObject fakeBaseJson = QJsonObject();
    fakeBaseJson[fakeFieldKey] = fakeFieldValue;

    EXPECT_CALL(*messageForwarder_,
                forwardData(JsonStringIs(fakeFieldKey, fakeFieldValue)))
        .Times(1);
    vehicleJsonForwarder_->forwardVehicleData(fakeBaseJson);
}
