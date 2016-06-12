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

#include "BusinessLayer/JsonForwarder/PowerJsonForwarder/PowerJsonForwarder.h"
#include "BusinessLayer/JsonForwarder/JsonDefines.h"

#include "Tests/CommunicationLayer/CommDeviceControl/MockMessageForwarder.h"
#include "Tests/DataLayer/PowerData/MockPowerData.h"

using ::testing::Return;

class PowerJsonForwarderTest : public ::testing::Test
{
protected:
    QScopedPointer<MockPowerData> powerData_;
    QScopedPointer<MockMessageForwarder> messageForwarder_;
    QScopedPointer<PowerJsonForwarder> powerJsonForwarder_;

    virtual void SetUp()
    {
        powerData_.reset(new MockPowerData());
        messageForwarder_.reset(new MockMessageForwarder());
        powerJsonForwarder_.reset(new PowerJsonForwarder(*powerData_,
                                                       *messageForwarder_));
        EXPECT_CALL(*powerData_, busCurrentA())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*powerData_, busVoltage())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*powerData_, motorVoltageReal())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*powerData_, motorCurrentReal())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*powerData_, backEmfImaginary())
            .WillRepeatedly(Return(0));
        EXPECT_CALL(*powerData_, dcBusAmpHours())
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

TEST_F(PowerJsonForwarderTest, typeForwarded)
{
    EXPECT_CALL(*messageForwarder_,
                forwardData(JsonStringIs(JsonFormat::DATA_TYPE, JsonFormat::POWER)))
        .Times(1);
    powerJsonForwarder_->forwardPowerData(QJsonObject());
}

TEST_F(PowerJsonForwarderTest, busCurrentAForwarded)
{
    double busCurrentA = 1.23;
    QString busCurrentAString = QString::number(busCurrentA, 'f', JsonFormat::DECIMAL_PRECISION);
    EXPECT_CALL(*powerData_, busCurrentA())
        .WillRepeatedly(Return(busCurrentA));
    EXPECT_CALL(*messageForwarder_, forwardData(JsonStringIs(JsonFormat::BUS_CURRENT_A, busCurrentAString)));
    powerJsonForwarder_->forwardPowerData(QJsonObject());
}

TEST_F(PowerJsonForwarderTest, busVoltageForwarded)
{
    double busVoltage = 2.34;
    QString busVoltageString = QString::number(busVoltage, 'f', JsonFormat::DECIMAL_PRECISION);
    EXPECT_CALL(*powerData_, busVoltage())
        .WillRepeatedly(Return(busVoltage));
    EXPECT_CALL(*messageForwarder_, forwardData(JsonStringIs(JsonFormat::BUS_VOLTAGE, busVoltageString)));
    powerJsonForwarder_->forwardPowerData(QJsonObject());
}

TEST_F(PowerJsonForwarderTest, motorVoltageRealForwarded)
{
    double motorVoltageReal = 3.45;
    QString motorVoltageRealString = QString::number(motorVoltageReal, 'f', JsonFormat::DECIMAL_PRECISION);
    EXPECT_CALL(*powerData_, motorVoltageReal())
        .WillRepeatedly(Return(motorVoltageReal));
    EXPECT_CALL(*messageForwarder_, forwardData(JsonStringIs(JsonFormat::MOTOR_VOLTAGE_REAL, motorVoltageRealString)));
    powerJsonForwarder_->forwardPowerData(QJsonObject());
}

TEST_F(PowerJsonForwarderTest, motorCurrentRealForwarded)
{
    double motorCurrentReal = 4.56;
    QString motorCurrentRealString = QString::number(motorCurrentReal, 'f', JsonFormat::DECIMAL_PRECISION);
    EXPECT_CALL(*powerData_, motorCurrentReal())
        .WillRepeatedly(Return(motorCurrentReal));
    EXPECT_CALL(*messageForwarder_, forwardData(JsonStringIs(JsonFormat::MOTOR_CURRENT_REAL, motorCurrentRealString)));
    powerJsonForwarder_->forwardPowerData(QJsonObject());
}

TEST_F(PowerJsonForwarderTest, backEmfImaginaryForwarded)
{
    double backEmfImaginary = 5.67;
    QString backEmfImaginaryString = QString::number(backEmfImaginary, 'f', JsonFormat::DECIMAL_PRECISION);
    EXPECT_CALL(*powerData_, backEmfImaginary())
        .WillRepeatedly(Return(backEmfImaginary));
    EXPECT_CALL(*messageForwarder_, forwardData(JsonStringIs(JsonFormat::BACK_EMF_IMAGINARY, backEmfImaginaryString)));
    powerJsonForwarder_->forwardPowerData(QJsonObject());
}

TEST_F(PowerJsonForwarderTest, dcBusAmpHoursForwarded)
{
    double dcBusAmpHours = 6.78;
    QString dcBusAmpHoursString = QString::number(dcBusAmpHours, 'f', JsonFormat::DECIMAL_PRECISION);
    EXPECT_CALL(*powerData_, dcBusAmpHours())
        .WillRepeatedly(Return(dcBusAmpHours));
    EXPECT_CALL(*messageForwarder_, forwardData(JsonStringIs(JsonFormat::DC_BUS_AMP_HOURS, dcBusAmpHoursString)));
    powerJsonForwarder_->forwardPowerData(QJsonObject());
}

TEST_F(PowerJsonForwarderTest, baseJsonPreserved)
{
    QString fakeFieldKey = "Key";
    QString fakeFieldValue = "Value";
    QJsonObject fakeBaseJson = QJsonObject();
    fakeBaseJson[fakeFieldKey] = fakeFieldValue;

    EXPECT_CALL(*messageForwarder_,
                forwardData(JsonStringIs(fakeFieldKey, fakeFieldValue)))
        .Times(1);
    powerJsonForwarder_->forwardPowerData(fakeBaseJson);
}
