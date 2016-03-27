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

#include "BusinessLayer/JsonForwarder/BatteryJsonForwarder/BatteryJsonForwarder.h"
#include "BusinessLayer/JsonForwarder/FaultsJsonForwarder/FaultsJsonForwarder.h"
#include "BusinessLayer/JsonForwarder/PowerJsonForwarder/PowerJsonForwarder.h"
#include "BusinessLayer/JsonForwarder/VehicleJsonForwarder/VehicleJsonForwarder.h"
#include "CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"
#include "JsonForwarder.h"
#include "JsonDefines.h"

class I_BatteryData;
class I_FaultsData;
class I_PowerData;
class I_VehicleData;
class I_MessageForwarder;

JsonForwarder::JsonForwarder(I_BatteryData& batteryData,
                             I_FaultsData& faultsData,
                             I_PowerData& powerData,
                             I_VehicleData& vehicleData,
                             I_MessageForwarder& messageForwarder)
: batteryJsonForwarder_(new BatteryJsonForwarder(batteryData, messageForwarder))
, faultsJsonForwarder_(new FaultsJsonForwarder(faultsData, messageForwarder))
, powerJsonForwarder_(new PowerJsonForwarder(powerData, messageForwarder))
, vehicleJsonForwarder_(new VehicleJsonForwarder(vehicleData, messageForwarder))
, readTimer_(new QTimer())
, dataToRead_(BATTERY_DATA)
{
    connect(readTimer_.data(), SIGNAL(timeout()), this, SLOT(forwardData()));
}

void JsonForwarder::start(int conversionFrequency)
{
    readTimer_->setInterval(conversionFrequency);
    readTimer_->start();
}

void JsonForwarder::forwardData()
{
    switch (dataToRead_)
    {
    case BATTERY_DATA:
        batteryJsonForwarder_->forwardBatteryData();
        dataToRead_ = FAULT_DATA;
        break;
    case FAULT_DATA:
        powerJsonForwarder_->forwardPowerData();
        dataToRead_ = POWER_DATA;
        break;
    case POWER_DATA:
        vehicleJsonForwarder_->forwardVehicleData();
        dataToRead_ = VEHICLE_DATA;
        break;
    case VEHICLE_DATA :
        powerJsonForwarder_->forwardPowerData();
        dataToRead_ = BATTERY_DATA;
        break;
    }
}
