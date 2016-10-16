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

#include "BatteryFaults.h"

namespace
{
   const unsigned char CELL_OVER_VOLTAGE_MASK = 0x0001;
   const unsigned char CELL_UNDER_VOLTAGE_MASK = 0x0002;
   const unsigned char CELL_OVER_TEMP_MASK = 0x0004;
   const unsigned char MEASUREMENT_UNTRUSTED_MASK = 0x0008;
   const unsigned char CMU_COMM_TIMEOUT_MASK = 0x0010;
   const unsigned char VEHICLE_COMM_TIMEOUT_MASK = 0x0020;
   const unsigned char BMU_IN_SETUP_MODE_MASK = 0x0040;
   const unsigned char CMU_CAN_BUS_POWER_STATUS_MASK = 0x0080;
   const unsigned char PACK_ISOLATION_TEST_FAILURE_MASK = 0x0100;
   const unsigned char SOFTWARE_OVER_CURRENT_MASK = 0x0200;
   const unsigned char CAN_SUPPLY_LOW_MASK = 0x0400;
   const unsigned char CONTACTOR_STUCK_MASK = 0x0800;
   const unsigned char CMU_DETECTED_EXTRA_CELL_MASK = 0x1000;
}

BatteryFaults::BatteryFaults(quint16 flags)
: flags_(flags)
{
}

bool BatteryFaults::cellOverVoltage() const
{
   return static_cast<bool>(flags_ & CELL_OVER_VOLTAGE_MASK);
}

bool BatteryFaults::cellUnderVoltage() const
{
   return static_cast<bool>(flags_ & CELL_UNDER_VOLTAGE_MASK);
}

bool BatteryFaults::cellOverTemperature() const
{
   return static_cast<bool>(flags_ & CELL_OVER_TEMP_MASK);
}

bool BatteryFaults::measurementUntrusted() const
{
   return static_cast<bool>(flags_ & MEASUREMENT_UNTRUSTED_MASK);
}

bool BatteryFaults::cmuCommTimeout() const
{
   return static_cast<bool>(flags_ & CMU_COMM_TIMEOUT_MASK);
}

bool BatteryFaults::vehicleCommTimeout() const
{
   return static_cast<bool>(flags_ & VEHICLE_COMM_TIMEOUT_MASK);
}

bool BatteryFaults::bmuIsInSetupMode() const
{
   return static_cast<bool>(flags_ & BMU_IN_SETUP_MODE_MASK);
}

bool BatteryFaults::cmuCanBusPowerStatus() const
{
   // Note: This fault flag actually means everything is okay.
   return !static_cast<bool>(flags_ & CMU_CAN_BUS_POWER_STATUS_MASK);
}

bool BatteryFaults::packIsolationTestFailure() const
{
   return static_cast<bool>(flags_ & PACK_ISOLATION_TEST_FAILURE_MASK);
}

bool BatteryFaults::softwareOverCurrentMeasured() const
{
   return static_cast<bool>(flags_ & SOFTWARE_OVER_CURRENT_MASK);
}

bool BatteryFaults::canSupplyIsLow() const
{
   return static_cast<bool>(flags_ & CAN_SUPPLY_LOW_MASK);
}

bool BatteryFaults::contactorIsStuck() const
{
   return static_cast<bool>(flags_ & CONTACTOR_STUCK_MASK);
}

bool BatteryFaults::cmuDetectedExtraCellPresent() const
{
   return static_cast<bool>(flags_ & CMU_DETECTED_EXTRA_CELL_MASK);
}

bool BatteryFaults::operator==(const BatteryFaults& other) const
{
   return flags_ == other.flags_;
}

QString BatteryFaults::toString() const
{
   return "0x" + QString::number(flags_, 16);
}
