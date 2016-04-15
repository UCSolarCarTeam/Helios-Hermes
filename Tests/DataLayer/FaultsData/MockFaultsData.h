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

#include "DataLayer/FaultsData/I_FaultsData.h"

class MockFaultsData : public I_FaultsData
{
public:

   /* FaultData Gets */
   MOCK_CONST_METHOD0(motorOneFaults, MotorFaults()); // MotorFaults motorOneFaults() const;
   MOCK_CONST_METHOD0(motorOneLimitFlags, LimitFlags()); // LimitFlags motorOneLimitFlags() const;
   MOCK_CONST_METHOD0(motorTwoFaults, MotorFaults()); // MotorFaults motorTwoFaults() const;
   MOCK_CONST_METHOD0(motorTwoLimitFlags, LimitFlags()); // LimitFlags motorTwoLimitFlags() const;
   MOCK_CONST_METHOD0(batteryFaults, BatteryFaults()); // BatteryFaults batteryFaults() const;

   /* FaultData Sets */
   MOCK_METHOD1(setMotorOneFaults, void(MotorFaults)); // void setMotorOneFaults(MotorFaults motorFaults);
   MOCK_METHOD1(setMotorOneLimitFlags, void(LimitFlags)); // void setMotorOneLimitFlags(LimitFlags limitFlags);
   MOCK_METHOD1(setMotorTwoFaults, void(MotorFaults)); // void setMotorTwoFaults(MotorFaults motorFaults);
   MOCK_METHOD1(setMotorTwoLimitFlags, void(LimitFlags)); // void setMotorTwoLimitFlags(LimitFlags limitFlags);
   MOCK_METHOD1(setBatteryFaults, void(BatteryFaults)); // void setBatteryFaults(BatteryFaults batteryFaults);
};

