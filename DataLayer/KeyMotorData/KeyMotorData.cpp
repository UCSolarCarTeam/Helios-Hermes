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

#include "KeyMotorData.h"
#include <QDebug>

KeyMotorData::KeyMotorData()
    : packageID_(1)
    , m0Alive_(0)
    , m0SetCurrent_(0)
    , m0SetVelocity_(0)
    , m0BusCurrent_(0)
    , m0BusVoltage_(0)
    , m0VehicleVelocity_(0)
    , m1Alive_(0)
    , m1SetCurrent_(0)
    , m1SetVelocity_(0)
    , m1BusCurrent_(0)
    , m1BusVoltage_(0)
    , m1VehicleVelocity_(0)

{
    // initialize to 0
}

KeyMotorData::~KeyMotorData()
{
}

/*Data "Gets"*/
unsigned char KeyMotorData::getPackageID()
{
    return packageID_;
}

unsigned char KeyMotorData::getM0Alive() 
{
    return m0Alive_;
}

float KeyMotorData::getM0SetCurrent() 
{
    return m0SetCurrent_;
}

float KeyMotorData::getM0SetVelocity() 
{
    return m0SetVelocity_;
}

float KeyMotorData::getM0BusCurrent() 
{
    return m0BusCurrent_;
}

float KeyMotorData::getM0BusVoltage() 
{
    return m0BusVoltage_;
}

float KeyMotorData::getM0VehicleVelocity() 
{
    return m0VehicleVelocity_;
}

unsigned char KeyMotorData::getM1Alive() 
{
    return m1Alive_;
}

float KeyMotorData::getM1SetCurrent() 
{
    return m1SetCurrent_;
}

float KeyMotorData::getM1SetVelocity() 
{
    return m1SetVelocity_;
}

float KeyMotorData::getM1BusCurrent() 
{
    return m1BusCurrent_;
}

float KeyMotorData::getM1BusVoltage() 
{
    return m1BusVoltage_;
}

float KeyMotorData::getM1VehicleVelocity() 
{
    return m1VehicleVelocity_;
}


/*KeyMotorData "Sets"*/
void KeyMotorData::setM0Alive(unsigned char& m0Alive)
{
    m0Alive_ = m0Alive;
    emit m0AliveReceived(m0Alive_);
}

void KeyMotorData::setM0SetCurrent(float& m0SetCurrent)
{
    m0SetCurrent_ = m0SetCurrent;
    emit m0SetCurrentReceived(m0SetCurrent_);
}

void KeyMotorData::setM0SetVelocity(float& m0SetVelocity)
{
    m0SetVelocity_ = m0SetVelocity;
    emit m0SetVelocityReceived(m0SetVelocity_);
}

void KeyMotorData::setM0BusCurrent(float& m0BusCurrent)
{
    m0BusCurrent_ = m0BusCurrent;
    emit m0BusCurrentReceived(m0BusCurrent_);
}

void KeyMotorData::setM0BusVoltage(float& m0BusVoltage)
{
    m0BusVoltage_ = m0BusVoltage;
    emit m0BusVoltageReceived(m0BusVoltage_);
}

void KeyMotorData::setM0VehicleVelocity(float& m0VehicleVelocity)
{
    m0VehicleVelocity_ = m0VehicleVelocity;
    emit m0VehicleVelocityReceived(m0VehicleVelocity_);
}

void KeyMotorData::setM1Alive(unsigned char& m1Alive)
{
    m1Alive_ = m1Alive;
    emit m1AliveReceived(m1Alive_);
}

void KeyMotorData::setM1SetCurrent(float& m1SetCurrent)
{
    m1SetCurrent_ = m1SetCurrent;
    emit m1SetCurrentReceived(m1SetCurrent_);
}

void KeyMotorData::setM1SetVelocity(float& m1SetVelocity)
{
    m1SetVelocity_ = m1SetVelocity;
    emit m1SetVelocityReceived(m1SetVelocity_);
}

void KeyMotorData::setM1BusCurrent(float& m1BusCurrent)
{
    m1BusCurrent_ = m1BusCurrent;
    emit m1BusCurrentReceived(m1BusCurrent_);
}

void KeyMotorData::setM1BusVoltage(float& m1BusVoltage)
{
    m1BusVoltage_ = m1BusVoltage;
    emit m1BusVoltageReceived(m1BusVoltage_);
}

void KeyMotorData::setM1VehicleVelocity(float& m1VehicleVelocity)
{
    m1VehicleVelocity_ = m1VehicleVelocity;
    emit m1VehicleVelocityReceived(m1VehicleVelocity_);
}


