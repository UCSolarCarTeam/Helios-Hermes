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

#include "DriverControlsData.h"
#include <QDebug>

DriverControlsData::DriverControlsData()
    : driverControlsBoardAlive_(0)
    , lightsInputs_(0)
    , musicInputs_(0)
    , acceleration_(0)
    , regenBraking_(0)
    , driverInputs_(0)
{
    // initialize to 0
}

DriverControlsData::~DriverControlsData()
{
}

/*Data "Gets"*/
unsigned char DriverControlsData::getDriverControlsBoardAlive() const 
{
    return driverControlsBoardAlive_;
}

unsigned char DriverControlsData::getLightsInputs() const 
{
    return lightsInputs_;
}

unsigned char DriverControlsData::getMusicInputs() const 
{
    return musicInputs_;
}

unsigned short DriverControlsData::getAcceleration() const 
{
    return acceleration_;
}

unsigned short DriverControlsData::getRegenBraking() const 
{
    return regenBraking_;
}

unsigned char DriverControlsData::getDriverInputs() const 
{
    return driverInputs_;
}


/*DriverControlsData "Sets"*/
void DriverControlsData::setDriverControlsBoardAlive(unsigned char& driverControlsBoardAlive)
{
    driverControlsBoardAlive_ = driverControlsBoardAlive;
    emit driverControlsBoardAliveReceived(driverControlsBoardAlive_);
}

void DriverControlsData::setLightsInputs(unsigned char& lightsInputs)
{
    lightsInputs_ = lightsInputs;
    emit lightsInputsReceived(lightsInputs_);
}

void DriverControlsData::setMusicInputs(unsigned char& musicInputs)
{
    musicInputs_ = musicInputs;
    emit musicInputsReceived(musicInputs_);
}

void DriverControlsData::setAcceleration(unsigned short& acceleration)
{
    acceleration_ = acceleration;
    emit accelerationReceived(acceleration_);
}

void DriverControlsData::setRegenBraking(unsigned short& regenBraking)
{
    regenBraking_ = regenBraking;
    emit regenBrakingReceived(regenBraking_);
}

void DriverControlsData::setDriverInputs(unsigned char& driverInputs)
{
    driverInputs_ = driverInputs;
    emit driverInputsReceived(driverInputs_);
}
