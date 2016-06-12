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
#include "DataLayer/PowerData/I_PowerData.h"
#include "PowerJsonForwarder.h"

PowerJsonForwarder::PowerJsonForwarder(I_PowerData& powerData,
                                       I_MessageForwarder& messageForwarder)
: powerData_(powerData)
, messageForwarder_(messageForwarder)
{
}

void PowerJsonForwarder::forwardPowerData(const QJsonObject& baseJson)
{
    QJsonObject powerJson = baseJson;
    powerJson[JsonFormat::DATA_TYPE] = JsonFormat::POWER;

    powerJson[JsonFormat::BUS_CURRENT_A] = QString::number(powerData_.busCurrentA(), 'f', JsonFormat::DECIMAL_PRECISION);
    powerJson[JsonFormat::BUS_VOLTAGE] = QString::number(powerData_.busVoltage(), 'f', JsonFormat::DECIMAL_PRECISION);
    powerJson[JsonFormat::MOTOR_VOLTAGE_REAL] = QString::number(powerData_.motorVoltageReal(), 'f', JsonFormat::DECIMAL_PRECISION);
    powerJson[JsonFormat::MOTOR_CURRENT_REAL] = QString::number(powerData_.motorCurrentReal(), 'f', JsonFormat::DECIMAL_PRECISION);
    powerJson[JsonFormat::BACK_EMF_IMAGINARY] = QString::number(powerData_.backEmfImaginary(), 'f', JsonFormat::DECIMAL_PRECISION);
    powerJson[JsonFormat::DC_BUS_AMP_HOURS] = QString::number(powerData_.dcBusAmpHours(), 'f', JsonFormat::DECIMAL_PRECISION);

    messageForwarder_.forwardData(QJsonDocument(powerJson).toJson(QJsonDocument::Compact));
}
