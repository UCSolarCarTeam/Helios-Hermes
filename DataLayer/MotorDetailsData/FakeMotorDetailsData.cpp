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

// TODO fix this

#include "FakeMotorDetailsData.h"

FakeMotorDetailsData::FakeMotorDetailsData()
{
}

FakeMotorDetailsData::~FakeMotorDetailsData()
{
}

/*PowerData "Gets"*/
double FakeMotorDetailsData::driverSetSpeedMetersPerSecond() const
{   
   return 1;
}

double FakeMotorDetailsData::driverSetCurrent() const
{
   return 2;
}

double FakeMotorDetailsData::vehicleVelocityMetersPerSecond() const
{
   return 3;
}

double FakeMotorDetailsData::motorVelocityRpm() const
{
   return 4;
}

double FakeMotorDetailsData::ipmHeatSinkTemp() const
{
   return 5;
}
double FakeMotorDetailsData::dspBoardTemp() const
{
   return 6;
}

double FakeMotorDetailsData::receivedErrorCount() const
{
   return 7;
}
double FakeMotorDetailsData::transmittedErrorCount() const
{
   return 8;
}

/*PowerData "Sets"*/
void FakeMotorDetailsData::setDriverSetSpeedMetersPerSecond(double driverSetSpeedMetersPerSecond){}
void FakeMotorDetailsData::setDriverSetCurrent(double driverSetCurrent){}
void FakeMotorDetailsData::setVehicleVelocityMetersPerSecond(double vehicleVelocityMetersPerSecond){}
void FakeMotorDetailsData::setMotorVelocityRpm(double motorVelocityRpm){}
void FakeMotorDetailsData::setIpmHeatSinkTemp(double ipmHeatSinkTemp){}
void FakeMotorDetailsData::setDspBoardTemp(double dspBoardTemp){}
void FakeMotorDetailsData::setReceivedErrorCount(double receivedErrorCount){}
void FakeMotorDetailsData::setTransmittedErrorCount(double transmittedErrorCount){}