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

#include "LightsData.h"

LightsData::LightsData()
    : packageID_(10)
    , lightStatus_(0);
{   
//    Initialize to 0
}

LightsData::~LightsData()
{
}

/* LightsData Gets */
unsigned char LightsData::getPackageID() const
{
    return packageID_;
}

unsigned char LightsData::getLightStatus() const 
{
    return lightStatus_;
}

/* LightsData Sets */
void LightsData::setLightStatus(const unsigned char& lightStatus)
{
    lightStatus_ = lightStatus;
    emit lightStatusReceived(lightStatus_);
}
