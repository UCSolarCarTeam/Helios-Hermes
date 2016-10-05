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

#pragma once

#include "I_KeyMotorData.h"

class KeyMotorData : public I_KeyMotorData
{
public:
    KeyMotorData();
    virtual ~KeyMotorData();

    /*Data "Gets"*/
    unsigned char KeyMotorData::getM0Alive() const;
    float KeyMotorData::getM0SetCurrent() const;
    float KeyMotorData::getM0SetVelocity() const;
    float KeyMotorData::getM0BusCurrent() const;
    float KeyMotorData::getM0BusVoltage() const;
    float KeyMotorData::getM0VehicleVelocity() const;
    unsigned char KeyMotorData::getM1Alive() const;
    float KeyMotorData::getM1SetCurrent() const;
    float KeyMotorData::getM1SetVelocity() const;
    float KeyMotorData::getM1BusCurrent() const;
    float KeyMotorData::getM1BusVoltage() const;
    float KeyMotorData::getM1VehicleVelocity() const;

    /*KeyMotorData "Sets"*/
    void KeyMotorData::setM0Alive(const unsigned char& m0Alive);
    void KeyMotorData::setM0SetCurrent(const float& m0SetCurrent);
    void KeyMotorData::setM0SetVelocity(const float& m0SetVelocity);
    void KeyMotorData::setM0BusCurrent(const float& m0BusCurrent);
    void KeyMotorData::setM0BusVoltage(const float& m0BusVoltage);
    void KeyMotorData::setM0VehicleVelocity(const float& m0VehicleVelocity);
    void KeyMotorData::setM1Alive(const unsigned char& m1Alive);
    void KeyMotorData::setM1SetCurrent(const float& m1SetCurrent);
    void KeyMotorData::setM1SetVelocity(const float& m1SetVelocity);
    void KeyMotorData::setM1BusCurrent(const float& m1BusCurrent);
    void KeyMotorData::setM1BusVoltage(const float& m1BusVoltage);
    void KeyMotorData::setM1VehicleVelocity(const float& m1VehicleVelocity);

private:
    unsigned char m0Alive_;
    float m0SetCurrent_;
    float m0SetVelocity_;
    float m0BusCurrent_;
    float m0BusVoltage_;
    float m0VehicleVelocity_;
    unsigned char m1Alive_;
    float m1SetCurrent_;
    float m1SetVelocity_;
    float m1BusCurrent_;
    float m1BusVoltage_;
    float m1VehicleVelocity_;
};
