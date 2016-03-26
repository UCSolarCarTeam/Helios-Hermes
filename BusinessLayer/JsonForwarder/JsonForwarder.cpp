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
#include <QTimer>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>

#include "DataLayer/BatteryData/I_BatteryData.h"
#include "DataLayer/FaultsData/I_FaultsData.h"
#include "DataLayer/PowerData/I_PowerData.h"
#include "DataLayer/VehicleData/I_VehicleData.h"
#include "CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"
#include "JsonForwarder.h"

JsonForwarder::JsonForwarder(I_BatteryData& batteryData,
                             I_FaultsData& faultsData,
                             I_PowerData& powerData,
                             I_VehicleData& vehicleData,
                             I_MessageForwarder& messageForwarder)
: batteryData_(batteryData)
, faultsData_(faultsData)
, powerData_(powerData)
, vehicleData_(vehicleData)
, messageForwarder_(messageForwarder)
, readTimer_(new QTimer())
, dataToRead_(BATTERY_DATA)
{
    connect(readTimer_.data(), SIGNAL(timeout()), this, SLOT(convertData()));
}

void JsonForwarder::start(int conversionFrequency)
{
    readTimer_->setInterval(conversionFrequency);
    readTimer_->start();
}

void JsonForwarder::convertData()
{
    switch(dataToRead_)
    {
        case BATTERY_DATA:
            convertBatteryData();
            dataToRead_ = FAULT_DATA;
            break;
        case FAULT_DATA:
            convertPowerData();
            dataToRead_ = POWER_DATA;
            break;
        case POWER_DATA:
            convertVehicleData();
            dataToRead_ = VEHICLE_DATA;
            break;
        case VEHICLE_DATA :
            convertPowerData();
            dataToRead_ = BATTERY_DATA;
            break;
    }
}

void JsonForwarder::convertBatteryData()
{
    QJsonObject batteryJsonObject = QJsonObject();
    batteryJsonObject["dataType"] = "Battery";

    QJsonObject mod0 = QJsonObject();
    mod0["pcbTemperature"] = batteryData_.mod0PcbTemperature();
    mod0["cellTemperature"] = batteryData_.mod0CellTemperature();
    QJsonArray mod0CellVoltages = { QString::number(batteryData_.mod0CellVoltages()[0], 'f', 2),
                                    QString::number(batteryData_.mod0CellVoltages()[1], 'f', 2),
                                    QString::number(batteryData_.mod0CellVoltages()[2], 'f', 2),
                                    QString::number(batteryData_.mod0CellVoltages()[3], 'f', 2),
                                    QString::number(batteryData_.mod0CellVoltages()[4], 'f', 2),
                                    QString::number(batteryData_.mod0CellVoltages()[5], 'f', 2),
                                    QString::number(batteryData_.mod0CellVoltages()[6], 'f', 2),
                                    QString::number(batteryData_.mod0CellVoltages()[7], 'f', 2) };
    mod0["cellVoltages"] = mod0CellVoltages;
    batteryJsonObject["mod0"] = mod0;

    QJsonObject mod1 = QJsonObject();
    mod1["pcbTemperature"] = QString::number(batteryData_.mod1PcbTemperature(), 'f', 2);
    mod1["cellTemperature"] = QString::number(batteryData_.mod1CellTemperature(), 'f', 2);
    QJsonArray mod1CellVoltages = { QString::number(batteryData_.mod1CellVoltages()[1], 'f', 2),
                                    QString::number(batteryData_.mod1CellVoltages()[1], 'f', 2),
                                    QString::number(batteryData_.mod1CellVoltages()[2], 'f', 2),
                                    QString::number(batteryData_.mod1CellVoltages()[3], 'f', 2),
                                    QString::number(batteryData_.mod1CellVoltages()[4], 'f', 2),
                                    QString::number(batteryData_.mod1CellVoltages()[5], 'f', 2),
                                    QString::number(batteryData_.mod1CellVoltages()[6], 'f', 2),
                                    QString::number(batteryData_.mod1CellVoltages()[7], 'f', 2) };
    mod1["cellVoltages"] = mod1CellVoltages;
    batteryJsonObject["mod1"] = mod1;

    QJsonObject mod2 = QJsonObject();
    mod2["pcbTemperature"] = QString::number(batteryData_.mod2PcbTemperature(), 'f', 2);
    mod2["cellTemperature"] = QString::number(batteryData_.mod2CellTemperature(), 'f', 2);
    QJsonArray mod2CellVoltages = { QString::number(batteryData_.mod2CellVoltages()[2], 'f', 2),
                                    QString::number(batteryData_.mod2CellVoltages()[1], 'f', 2),
                                    QString::number(batteryData_.mod2CellVoltages()[2], 'f', 2),
                                    QString::number(batteryData_.mod2CellVoltages()[3], 'f', 2),
                                    QString::number(batteryData_.mod2CellVoltages()[4], 'f', 2),
                                    QString::number(batteryData_.mod2CellVoltages()[5], 'f', 2),
                                    QString::number(batteryData_.mod2CellVoltages()[6], 'f', 2),
                                    QString::number(batteryData_.mod2CellVoltages()[7], 'f', 2) };
    mod2["cellVoltages"] = mod2CellVoltages;
    batteryJsonObject["mod2"] = mod2;

    QJsonObject mod3 = QJsonObject();
    mod3["pcbTemperature"] = QString::number(batteryData_.mod3PcbTemperature(), 'f', 2);
    mod3["cellTemperature"] = QString::number(batteryData_.mod3CellTemperature(), 'f', 2);
    QJsonArray mod3CellVoltages = { QString::number(batteryData_.mod3CellVoltages()[3], 'f', 2),
                                    QString::number(batteryData_.mod3CellVoltages()[1], 'f', 2),
                                    QString::number(batteryData_.mod3CellVoltages()[2], 'f', 2),
                                    QString::number(batteryData_.mod3CellVoltages()[3], 'f', 2),
                                    QString::number(batteryData_.mod3CellVoltages()[4], 'f', 2),
                                    QString::number(batteryData_.mod3CellVoltages()[5], 'f', 2),
                                    QString::number(batteryData_.mod3CellVoltages()[6], 'f', 2),
                                    QString::number(batteryData_.mod3CellVoltages()[7], 'f', 2) };
    mod3["cellVoltages"] = mod3CellVoltages;
    batteryJsonObject["mod3"] = mod3;

    batteryJsonObject["batteryVoltage"] = QString::number(batteryData_.batteryVoltage(), 'f', 2);
    batteryJsonObject["batteryCurrent"] = QString::number(batteryData_.batteryCurrent(), 'f', 2);

    qDebug() << "SENDING...";
    qDebug() << QJsonDocument(batteryJsonObject).toJson(QJsonDocument::Compact);
    qDebug() << "DONE!!!";
    messageForwarder_.forwardData(QJsonDocument(batteryJsonObject).toJson(QJsonDocument::Compact));
}

void JsonForwarder::convertFaultsData()
{
    // QJsonDocument faultJson;
    // messageForwarder_.forwardData(faultJson.toJson(QJsonDocument::Compact));
}

void JsonForwarder::convertPowerData()
{
    // QJsonDocument powerJson;
    // messageForwarder_.forwardData(powerJson.toJson(QJsonDocument::Compact));
}

void JsonForwarder::convertVehicleData()
{
    // QJsonDocument vehicleJson;
    // messageForwarder_.forwardData(vehicleJson.toJson(QJsonDocument::Compact));
}
