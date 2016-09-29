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

#include "MotorFaultsData.h"

MotorFaultsData::MotorFaultsData()
    : packageID_(0)
{
    // Initialize to 0
    // TODO complete
}
MotorFaultsData::~MotorFaultsData()
{
}

/* BatteryFaults Gets */
unsigned char MotorFaultsData::getPackageID() const {
    return packageID_;
}

unsigned char MotorFaultsData::getM0ErrorFlags() const {
    return m0ErrorFlags_;
}

unsigned char MotorFaultsData::getM1ErrorFlags() const {
    return m1ErrorFlags_;
}

unsigned char MotorFaultsData::getM0LimitFlags() const {
    return m0LimitFlags_;
}

unsigned char MotorFaultsData::getM1LimitFlags() const {
    return m1LimitFlags_;
}

unsigned char MotorFaultsData::getM0CanRxErrorCount() const {
    return m0CanRxErrorCount_;
}

unsigned char MotorFaultsData::getM0CanTxErrorCount() const {
    return m0CanTxErrorCount_;
}

unsigned char MotorFaultsData::getM1CanRxErrorCount() const {
    return m1CanRxErrorCount_;
}

unsigned char MotorFaultsData::getM1CanTxErrorCount() const {
    return m1CanTxErrorCount_;
}


/* BatteryFaults Sets */
void MotorFaultsData::setPackageID(const unsigned char& packageID) {
    packageID_ = packageID;
    emit packageIDReceived(packageID_);
}

// TODO finish
