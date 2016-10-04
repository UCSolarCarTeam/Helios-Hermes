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

#include "I_MpptData.h"

class MpptData : public I_MpptData
{
public:
    MpptData();
    virtual ~MpptData();

    /* MpptData Gets */
    unsigned char getPackageID() const;
    unsigned char getMpptStatus() const;
    unsigned short getArrayVoltage() const;
    unsigned short getArrayCurrent() const;
    unsigned short getBatteryVoltage() const;
    unsigned short getTemperature() const;

    /* MpptData Sets */
    void setMpptStatus(const unsigned char& mpptStatus);
    void setArrayVoltage(const unsigned short& arrayVoltage);
    void setArrayCurrent(const unsigned short& arrayCurrent);
    void setBatteryVoltage(const unsigned short& batteryVoltage);
    void setTemperature(const unsigned short& temperature);


private:
    const unsigned char packageID_;

    unsigned char mpptStatus_;
    unsigned short arrayVoltage_;
    unsigned short arrayCurrent_;
    unsigned short batteryVoltage_;
    unsigned short temperature_;
};
