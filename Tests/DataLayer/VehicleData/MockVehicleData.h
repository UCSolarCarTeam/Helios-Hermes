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

#include "DataLayer/VehicleData/I_VehicleData.h"

class MockVehicleData : public I_VehicleData
{
public:

    /*VehicleData "Gets"*/
    MOCK_CONST_METHOD0(driverSetSpeedMetersPerSecond, double()); // double driverSetSpeedMetersPerSecond() const;
    MOCK_CONST_METHOD0(driverSetCurrent, double()); // double driverSetCurrent() const;
    MOCK_CONST_METHOD0(vehicleVelocityMetersPerSecond, double()); // double vehicleVelocityMetersPerSecond() const;
    MOCK_CONST_METHOD0(motorVelocityRpm, double()); // double motorVelocityRpm() const;
    MOCK_CONST_METHOD0(ipmHeatSinkTemp, double()); // double ipmHeatSinkTemp() const;
    MOCK_CONST_METHOD0(dspBoardTemp, double()); // double dspBoardTemp() const;
    MOCK_CONST_METHOD0(receivedErrorCount, double()); // double receivedErrorCount() const;
    MOCK_CONST_METHOD0(transmittedErrorCount, double()); // double transmittedErrorCount() const;

    /*VehicleData "Sets"*/
    MOCK_METHOD1(setDriverSetSpeedMetersPerSecond, void(double)); // void setDriverSetSpeedMetersPerSecond(double driverSetSpeedMetersPerSecond);
    MOCK_METHOD1(setDriverSetCurrent, void(double)); // void setDriverSetCurrent(double driverSetCurrent);
    MOCK_METHOD1(setVehicleVelocityMetersPerSecond, void(double)); // void setVehicleVelocityMetersPerSecond(double vehicleVelocityMetersPerSecond);
    MOCK_METHOD1(setMotorVelocityRpm, void(double)); // void setMotorVelocityRpm(double motorVelocityRpm);
    MOCK_METHOD1(setIpmHeatSinkTemp, void(double)); // void setIpmHeatSinkTemp(double ipmHeatSinkTemp);
    MOCK_METHOD1(setDspBoardTemp, void(double)); // void setDspBoardTemp(double dspBoardTemp);
    MOCK_METHOD1(setReceivedErrorCount, void(double)); // void setReceivedErrorCount(double receivedErrorCount);
    MOCK_METHOD1(setTransmittedErrorCount, void(double)); // void setTransmittedErrorCount(double transmittedErrorCount);
};

