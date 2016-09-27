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

#include "DataContainer.h"
#include "BatteryData/BatteryData.h"
#include "BatteryFaultsData/BatteryFaultsData.h"
#include "CmuData/CmuData.h"
#include "DriverControlsData/DriverControlsData.h"
#include "KeyMotorData/KeyMotorData.h"
#include "LightsData/LightsData.h"
#include "MotorDetailsData/MotorDetailsData.h"
#include "MotorFaultsData/MotorFaultsData.h"
#include "MpptData/MpptData.h"

DataContainer::DataContainer()
: batteryData_(new BatteryData())
, batteryFaultsData_(new BatteryFaultsData())
, cmuData_(new CmuData())
, driverControlsData_(new DriverControlsData())
, keyMotorData_(new KeyMotorData())
, lightsData_(new LightsData())
, motorDetailsData_(new MotorDetailsData())
, motorFaultsData_(new MotorFaultsData())
, mpptData_(new MpptData())
{
}

DataContainer::~DataContainer()
{
}

capsiswrong& DataContainer::replaceMe()
{
   return replaceMe;
}
