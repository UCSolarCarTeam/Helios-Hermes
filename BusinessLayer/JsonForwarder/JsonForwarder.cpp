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
#include <QJsonDocument>


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
, dataToRead_()
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
            convertFaultsData();
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
            dataToRead_ = POWER_DATA;
            break;
    }
}

void JsonForwarder::convertBatteryData()
{
    QJsonDocument batteryJson;
    messageForwarder_.forwardData(batteryJson.toJson(QJsonDocument::Compact));

}

void JsonForwarder::convertFaultsData()
{
    QJsonDocument faultJson;
    messageForwarder_.forwardData(faultJson.toJson(QJsonDocument::Compact));

}

void JsonForwarder::convertPowerData()
{
    QJsonDocument powerJson;
    messageForwarder_.forwardData(powerJson.toJson(QJsonDocument::Compact));

}

void JsonForwarder::convertVehicleData()
{
    QJsonDocument vehicleJson;
    messageForwarder_.forwardData(vehicleJson.toJson(QJsonDocument::Compact));
}
