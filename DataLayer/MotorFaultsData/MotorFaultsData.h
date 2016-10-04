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

#include "I_MotorFaultsData.h"

class MotorFaultsData : public I_MotorFaultsData
{
public:
    MotorFaultsData();
    virtual ~MotorFaultsData();

    /* MotorFaults Gets */
    unsigned char getPackageID() const;
    unsigned char getM0ErrorFlags() const;
    unsigned char getM1ErrorFlags() const;
    unsigned char getM0LimitFlags() const;
    unsigned char getM1LimitFlags() const;
    unsigned char getM0CanRxErrorCount() const;
    unsigned char getM0CanTxErrorCount() const;
    unsigned char getM1CanRxErrorCount() const;
    unsigned char getM1CanTxErrorCount() const;

    /* MotorFaults Sets */
    void getM0ErrorFlags(const unsigned char&);
    void getM1ErrorFlags(const unsigned char&);
    void getM0LimitFlags(const unsigned char&);
    void getM1LimitFlags(const unsigned char&);
    void getM0CanRxErrorCount(const unsigned char&);
    void getM0CanTxErrorCount(const unsigned char&);
    void getM1CanRxErrorCount(const unsigned char&);
    void getM1CanTxErrorCount(const unsigned char&);


private:
    const unsigned char packageID_;
    
    unsigned char m0ErrorFlags_;
    unsigned char m1ErrorFlags_;
    unsigned char m0LimitFlags_;
    unsigned char m1LimitFlags_;
    unsigned char m0CanRxErrorCount_;
    unsigned char m0CanTxErrorCount_;
    unsigned char m1CanRxErrorCount_;
    unsigned char m1CanTxErrorCount_;
};
