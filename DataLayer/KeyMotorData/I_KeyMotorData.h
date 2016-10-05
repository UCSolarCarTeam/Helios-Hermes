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

#include <QObject>

class I_KeyMotorData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_KeyMotorData() {}

    /*Data "Gets"*/
    virtual unsigned char KeyMotorData::getM0Alive() const = 0;
    virtual float KeyMotorData::getM0SetCurrent() const = 0;
    virtual float KeyMotorData::getM0SetVelocity() const = 0;
    virtual float KeyMotorData::getM0BusCurrent() const = 0;
    virtual float KeyMotorData::getM0BusVoltage() const = 0;
    virtual float KeyMotorData::getM0VehicleVelocity() const = 0;
    virtual unsigned char KeyMotorData::getM1Alive() const = 0;
    virtual float KeyMotorData::getM1SetCurrent() const = 0;
    virtual float KeyMotorData::getM1SetVelocity() const = 0;
    virtual float KeyMotorData::getM1BusCurrent() const = 0;
    virtual float KeyMotorData::getM1BusVoltage() const = 0;
    virtual float KeyMotorData::getM1VehicleVelocity() const = 0;


    /*KeyMotorData "Sets"*/
    virtual unsigned char KeyMotorData::setM0Alive(unsigned char& m0Alive);
    virtual float KeyMotorData::setM0SetCurrent(float& m0SetCurrent);
    virtual float KeyMotorData::setM0SetVelocity(float& m0SetVelocity);
    virtual float KeyMotorData::setM0BusCurrent(float& m0BusCurrent);
    virtual float KeyMotorData::setM0BusVoltage(float& m0BusVoltage);
    virtual float KeyMotorData::setM0VehicleVelocity(float& m0VehicleVelocity);
    virtual unsigned char KeyMotorData::setM1Alive(unsigned char& m1Alive);
    virtual float KeyMotorData::setM1SetCurrent(float& m1SetCurrent);
    virtual float KeyMotorData::setM1SetVelocity(float& m1SetVelocity);
    virtual float KeyMotorData::setM1BusCurrent(float& m1BusCurrent);
    virtual float KeyMotorData::setM1BusVoltage(float& m1BusVoltage);
    virtual float KeyMotorData::setM1VehicleVelocity(float& m1VehicleVelocity);

signals:

    void m0AliveReceived(unsigned char m0Alive);
    void m0SetCurrentReceived(float m0SetCurrent);
    void m0SetVelocityReceived(float m0SetVelocity);
    void m0BusCurrentReceived(float m0BusCurrent);
    void m0BusVoltageReceived(float m0BusVoltage);
    void m0VehicleVelocityReceived(float m0VehicleVelocity);
    void m1AliveReceived(unsigned char m1Alive);
    void m1SetCurrentReceived(float m1SetCurrent);
    void m1SetVelocityReceived(float m1SetVelocity);
    void m1BusCurrentReceived(float m1BusCurrent);
    void m1BusVoltageReceived(float m1BusVoltage);
    void m1VehicleVelocityReceived(float m1VehicleVelocity);
};
