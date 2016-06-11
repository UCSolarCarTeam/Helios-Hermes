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
#include <QJsonArray>
#include <QScopedPointer>

#include "BusinessLayer/JsonForwarder/BatteryJsonForwarder/BatteryJsonForwarder.h"
#include "BusinessLayer/JsonForwarder/JsonDefines.h"

#include "Tests/CommunicationLayer/CommDeviceControl/MockMessageForwarder.h"
#include "Tests/DataLayer/BatteryData/MockBatteryData.h"

using ::testing::AllOf;
using ::testing::Return;

class BatteryJsonForwarderTest : public ::testing::Test
{
protected:
    QScopedPointer<MockBatteryData> batteryData_;
    QScopedPointer<MockMessageForwarder> messageForwarder_;
    QScopedPointer<BatteryJsonForwarder> batteryJsonForwarder_;

    virtual void SetUp()
    {
        batteryData_.reset(new MockBatteryData());
        messageForwarder_.reset(new MockMessageForwarder());
        batteryJsonForwarder_.reset(new BatteryJsonForwarder(*batteryData_,
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

/****** TESTS ******/

TEST_F(BatteryJsonForwarderTest, typeForwarded)
{
    EXPECT_CALL(*messageForwarder_,
                forwardData(JsonStringIs(JsonFormat::DATA_TYPE, JsonFormat::BATTERY)))
        .Times(1);
    batteryJsonForwarder_->forwardBatteryData(QJsonObject());
}

TEST_F(BatteryJsonForwarderTest, mod0DataForwarded)
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
        .Times(1);
    batteryJsonForwarder_->forwardBatteryData(QJsonObject());
}

TEST_F(BatteryJsonForwarderTest, mod1DataForwarded)
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
        .Times(1);
    batteryJsonForwarder_->forwardBatteryData(QJsonObject());
}

TEST_F(BatteryJsonForwarderTest, mod2DataForwarded)
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
        .Times(1);
    batteryJsonForwarder_->forwardBatteryData(QJsonObject());
}

TEST_F(BatteryJsonForwarderTest, mod3DataForwarded)
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
        .Times(1);
    batteryJsonForwarder_->forwardBatteryData(QJsonObject());
}

TEST_F(BatteryJsonForwarderTest, batteryInternalDataForwarded)
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
        .Times(1);
    batteryJsonForwarder_->forwardBatteryData(QJsonObject());
}

TEST_F(BatteryJsonForwarderTest, baseJsonPreserved)
{
    QString fakeFieldKey = "Key";
    QString fakeFieldValue = "Value";
    QJsonObject fakeBaseJson = QJsonObject();
    fakeBaseJson[fakeFieldKey] = fakeFieldValue;

    EXPECT_CALL(*messageForwarder_,
                forwardData(JsonStringIs(fakeFieldKey, fakeFieldValue)))
        .Times(1);
    batteryJsonForwarder_->forwardBatteryData(fakeBaseJson);
}
