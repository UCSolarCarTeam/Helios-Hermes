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

#include "MpptData.h"

MpptData::MpptData()
: mpptStatus_(0)
, arrayVoltage_(0)
, arrayCurrent_(0)
, batteryVoltage_(0)
, temperature_(0)
{
    //  Initialize to 0
}

MpptData::~MpptData()
{
}

/* MpptData Gets */
unsigned char MpptData::getMpptStatus() const
{
    return mpptStatus_;
}

unsigned short MpptData::getRrayVoltage() const
{
    return arrayVoltage_;
}

unsigned short MpptData::getRrayCurrent() const
{
    return arrayCurrent_;
}

unsigned short MpptData::getBatteryVoltage() const
{
    return batteryVoltage_;
}

unsigned short MpptData::getTemperature() const
{
    return temperature_;
}


/* MpptData Sets */
void MpptData::setMpptStatus(const unsigned char& mpptStatus);
{
    mpptStatus_ = mpptStatus;
    emit mpptStatusReceived(mpptStatus_);
}

void MpptData::setArrayVoltage(const unsigned short& arrayVoltage);
{
    arrayVoltage_ = arrayVoltage;
    emit arrayVoltageReceived(arrayVoltage_);
}

void MpptData::setArrayCurrent(const unsigned short& arrayCurrent);
{
    arrayCurrent_ = arrayCurrent;
    emit arrayCurrentReceived(arrayCurrent_);
}

void MpptData::setBatteryVoltage(const unsigned short& batteryVoltage);
{
    batteryVoltage_ = batteryVoltage;
    emit batteryVoltageReceived(batteryVoltage_);
}

void MpptData::setTemperature(const unsigned short& temperature);
{
    temperature_ = temperature;
    emit temperatureReceived(temperature_);
}


