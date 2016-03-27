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
#include "JsonDefines.h" 

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
    batteryJsonObject[JsonFormat::DATA_TYPE] = JsonFormat::BATTERY;

    QJsonObject mod0 = QJsonObject();
    mod0[JsonFormat::PCB_TEMPERATURE] = QString::number(batteryData_.mod0PcbTemperature(), 'f', JsonFormat::DECIMAL_PRECISION);
    mod0[JsonFormat::CELL_TEMPERATURE] = QString::number(batteryData_.mod0CellTemperature(), 'f', JsonFormat::DECIMAL_PRECISION);
    QJsonArray mod0CellVoltages = { QString::number(batteryData_.mod0CellVoltages()[0], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod0CellVoltages()[1], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod0CellVoltages()[2], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod0CellVoltages()[3], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod0CellVoltages()[4], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod0CellVoltages()[5], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod0CellVoltages()[6], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod0CellVoltages()[7], 'f', JsonFormat::DECIMAL_PRECISION) };
    mod0[JsonFormat::CELL_VOLTAGES] = mod0CellVoltages;
    batteryJsonObject[JsonFormat::MOD_0] = mod0;

    QJsonObject mod1 = QJsonObject();
    mod1[JsonFormat::PCB_TEMPERATURE] = QString::number(batteryData_.mod1PcbTemperature(), 'f', JsonFormat::DECIMAL_PRECISION);
    mod1[JsonFormat::CELL_TEMPERATURE] = QString::number(batteryData_.mod1CellTemperature(), 'f', JsonFormat::DECIMAL_PRECISION);
    QJsonArray mod1CellVoltages = { QString::number(batteryData_.mod1CellVoltages()[0], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod1CellVoltages()[1], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod1CellVoltages()[2], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod1CellVoltages()[3], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod1CellVoltages()[4], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod1CellVoltages()[5], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod1CellVoltages()[6], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod1CellVoltages()[7], 'f', JsonFormat::DECIMAL_PRECISION) };
    mod1[JsonFormat::CELL_VOLTAGES] = mod1CellVoltages;
    batteryJsonObject[JsonFormat::MOD_1] = mod1;

    QJsonObject mod2 = QJsonObject();
    mod2[JsonFormat::PCB_TEMPERATURE] = QString::number(batteryData_.mod2PcbTemperature(), 'f', JsonFormat::DECIMAL_PRECISION);
    mod2[JsonFormat::CELL_TEMPERATURE] = QString::number(batteryData_.mod2CellTemperature(), 'f', JsonFormat::DECIMAL_PRECISION);
    QJsonArray mod2CellVoltages = { QString::number(batteryData_.mod2CellVoltages()[0], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod2CellVoltages()[1], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod2CellVoltages()[2], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod2CellVoltages()[3], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod2CellVoltages()[4], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod2CellVoltages()[5], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod2CellVoltages()[6], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod2CellVoltages()[7], 'f', JsonFormat::DECIMAL_PRECISION) };
    mod2[JsonFormat::CELL_VOLTAGES] = mod2CellVoltages;
    batteryJsonObject[JsonFormat::MOD_2] = mod2;

    QJsonObject mod3 = QJsonObject();
    mod3[JsonFormat::PCB_TEMPERATURE] = QString::number(batteryData_.mod3PcbTemperature(), 'f', JsonFormat::DECIMAL_PRECISION);
    mod3[JsonFormat::CELL_TEMPERATURE] = QString::number(batteryData_.mod3CellTemperature(), 'f', JsonFormat::DECIMAL_PRECISION);
    QJsonArray mod3CellVoltages = { QString::number(batteryData_.mod3CellVoltages()[0], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod3CellVoltages()[1], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod3CellVoltages()[2], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod3CellVoltages()[3], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod3CellVoltages()[4], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod3CellVoltages()[5], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod3CellVoltages()[6], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod3CellVoltages()[7], 'f', JsonFormat::DECIMAL_PRECISION) };
    mod3[JsonFormat::CELL_VOLTAGES] = mod3CellVoltages;
    batteryJsonObject[JsonFormat::MOD_3] = mod3;

    batteryJsonObject[JsonFormat::BATTERY_VOLTAGE] = QString::number(batteryData_.batteryVoltage(), 'f', JsonFormat::DECIMAL_PRECISION);
    batteryJsonObject[JsonFormat::BATTERY_CURRENT] = QString::number(batteryData_.batteryCurrent(), 'f', JsonFormat::DECIMAL_PRECISION);

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
