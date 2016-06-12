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

#include <QJsonDocument>
#include <QJsonObject>

#include "BusinessLayer/JsonForwarder/JsonDefines.h"
#include "CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"
#include "DataLayer/VehicleData/I_VehicleData.h"
#include "VehicleJsonForwarder.h"

VehicleJsonForwarder::VehicleJsonForwarder(I_VehicleData& vehicleData,
                                           I_MessageForwarder& messageForwarder)
: vehicleData_(vehicleData)
, messageForwarder_(messageForwarder)
{
}

void VehicleJsonForwarder::forwardVehicleData(const QJsonObject& baseJson)
{
    QJsonObject vehicleJson = baseJson;
    vehicleJson[JsonFormat::DATA_TYPE] = JsonFormat::VEHICLE;

    vehicleJson[JsonFormat::DRIVER_SET_SPEED_METERS_PER_SECOND] = QString::number(vehicleData_.driverSetSpeedMetersPerSecond(), 'f', JsonFormat::DECIMAL_PRECISION);
    vehicleJson[JsonFormat::DRIVER_SET_CURRENT] = QString::number(vehicleData_.driverSetCurrent(), 'f', JsonFormat::DECIMAL_PRECISION);
    vehicleJson[JsonFormat::VEHICLE_VELOCITY_METERS_PER_SECOND] = QString::number(vehicleData_.vehicleVelocityMetersPerSecond(), 'f', JsonFormat::DECIMAL_PRECISION);
    vehicleJson[JsonFormat::MOTOR_VELOCITY_RPM] = QString::number(vehicleData_.motorVelocityRpm(), 'f', JsonFormat::DECIMAL_PRECISION);
    vehicleJson[JsonFormat::IPM_HEAT_SINK_TEMP] = QString::number(vehicleData_.ipmHeatSinkTemp(), 'f', JsonFormat::DECIMAL_PRECISION);
    vehicleJson[JsonFormat::DSP_BOARD_TEMP] = QString::number(vehicleData_.dspBoardTemp(), 'f', JsonFormat::DECIMAL_PRECISION);
    vehicleJson[JsonFormat::RECEIVED_ERROR_COUNT] = QString::number(vehicleData_.receivedErrorCount(), 'f', JsonFormat::DECIMAL_PRECISION);
    vehicleJson[JsonFormat::TRANSMITTED_ERROR_COUNT] = QString::number(vehicleData_.transmittedErrorCount(), 'f', JsonFormat::DECIMAL_PRECISION);

    messageForwarder_.forwardData(QJsonDocument(vehicleJson).toJson(QJsonDocument::Compact));
}
