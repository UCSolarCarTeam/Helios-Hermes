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
#include <QDebug>
#include <QJsonObject>
#include <QDateTime>

#include "BusinessLayer/JsonForwarder/BatteryJsonForwarder/BatteryJsonForwarder.h"
#include "BusinessLayer/JsonForwarder/FaultsJsonForwarder/FaultsJsonForwarder.h"
#include "BusinessLayer/JsonForwarder/PowerJsonForwarder/PowerJsonForwarder.h"
#include "BusinessLayer/JsonForwarder/VehicleJsonForwarder/VehicleJsonForwarder.h"
#include "CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"
#include "InfrastructureLayer/Settings/I_Settings.h"
#include "JsonDefines.h"
#include "JsonForwarder.h"

namespace
{
    const QString MYSQL_DATE_FORMAT = "yyyy-MM-dd HH:mm:ss";
}

JsonForwarder::JsonForwarder(I_BatteryData& batteryData,
                             I_FaultsData& faultsData,
                             I_PowerData& powerData,
                             I_VehicleData& vehicleData,
                             I_MessageForwarder& messageForwarder,
                             I_Settings& settings)
: batteryJsonForwarder_(new BatteryJsonForwarder(batteryData, messageForwarder))
, faultsJsonForwarder_(new FaultsJsonForwarder(faultsData, messageForwarder))
, powerJsonForwarder_(new PowerJsonForwarder(powerData, messageForwarder))
, vehicleJsonForwarder_(new VehicleJsonForwarder(vehicleData, messageForwarder))
, readTimer_(new QTimer())
, dataToReadCount_(0)
, forwardPeriod_(settings.forwardPeriod())
, PACKET_TITLE_(settings.packetTitle())
{
    connect(readTimer_.data(), SIGNAL(timeout()), this, SLOT(forwardData()));
}

JsonForwarder::~JsonForwarder()
{}

void JsonForwarder::startForwardingData()
{
    readTimer_->setInterval(forwardPeriod_);
    readTimer_->start();
}

void JsonForwarder::forwardData()
{
    QJsonObject baseJson = QJsonObject();
    baseJson[JsonFormat::PACKET_TITLE] = PACKET_TITLE_;

    QString currentTime = QDateTime::currentDateTime().toUTC().toString(MYSQL_DATE_FORMAT);
    baseJson[JsonFormat::TIMESTAMP] = currentTime;

    switch (dataToReadCount_)
    {
    case 0:
        qDebug() << "JsonForwarder: Forwarding battery data";
        batteryJsonForwarder_->forwardBatteryData(baseJson);
        break;
    case 1:
        qDebug() << "JsonForwarder: Forwarding faults data";
        faultsJsonForwarder_->forwardFaultsData(baseJson);
        break;
    case 2:
        qDebug() << "JsonForwarder: Forwarding power data";
        powerJsonForwarder_->forwardPowerData(baseJson);
        break;
    case 3 :
        qDebug() << "JsonForwarder: Forwarding vehicle data";
        vehicleJsonForwarder_->forwardVehicleData(baseJson);
        break;
    }

    if (dataToReadCount_ >= 3)
    {
        dataToReadCount_ = 0;
    }
    else
    {
        dataToReadCount_++;
    }
}
