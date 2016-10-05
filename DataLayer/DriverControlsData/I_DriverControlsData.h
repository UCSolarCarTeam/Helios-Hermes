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

class I_BatteryData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_BatteryData() {}

    /*Data "Gets"*/
    virtual unsigned char getDriverControlsBoardAlive() const = 0;
    virtual unsigned char getLightsInputs() const = 0;
    virtual unsigned char getMusicInputs() const = 0;
    virtual unsigned short getAcceleration() const = 0;
    virtual unsigned short getRegenBraking() const = 0;
    virtual unsigned char getDriverInputs() const = 0;

    /*BatteryData "Sets"*/
    virtual void setSetDriverControlsBoardAlive(const unsigned char& getDriverControlsBoardAlive) = 0;
    virtual void setSetLightsInputs(const unsigned char& getLightsInputs) = 0;
    virtual void setSetMusicInputs(const unsigned char& getMusicInputs) = 0;
    virtual void setSetAcceleration(const unsigned short& getAcceleration) = 0;
    virtual void setSetRegenBraking(const unsigned short& getRegenBraking) = 0;
    virtual void setSetDriverInputs(const unsigned char& getDriverInputs) = 0;

signals:
    void driverControlsBoardAliveReceived(unsigned char getDriverControlsBoardAlive);
    void lightsInputsReceived(unsigned char getLightsInputs);
    void musicInputsReceived(unsigned char getMusicInputs);
    void accelerationReceived(unsigned short getAcceleration);
    void regenBrakingReceived(unsigned short getRegenBraking);
    void driverInputsReceived(unsigned char getDriverInputs);
};
