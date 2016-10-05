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

#include "I_DriverControlsData.h"

class DriverControlsData : public I_DriverControlsData
{
public:
    DriverControlsData();
    virtual ~DriverControlsData();

    /*Data "Gets"*/
    unsigned char getDriverControlsBoardAlive() const;
    unsigned char getLightsInputs() const;
    unsigned char getMusicInputs() const;
    unsigned short getAcceleration() const;
    unsigned short getRegenBraking() const;
    unsigned char getDriverInputs() const;

    /*DriverControlsData "Sets"*/
    void setDriverControlsBoardAlive(const unsigned char driverControlsBoardAlive);
    void setLightsInputs(const unsigned char lightsInputs);
    void setMusicInputs(const unsigned char musicInputs);
    void setAcceleration(const unsigned short acceleration);
    void setRegenBraking(const unsigned short regenBraking);
    void setDriverInputs(const unsigned char driverInputs);

private:
    unsigned char driverControlsBoardAlive_;
    unsigned char lightsInputs_;
    unsigned char musicInputs_;
    unsigned short acceleration_;
    unsigned short regenBraking_;
    unsigned char driverInputs_;
};
