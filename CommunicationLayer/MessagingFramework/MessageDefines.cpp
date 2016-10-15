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

#include "MessageDefines.h"

namespace
{
    const int BATTERY_DATA_LENGTH = 63;
    const int BATTERY_FAULTS_DATA_LENGTH = 6;
    const int CMU_DATA_LENGTH = 53;
    const int DRIVER_CONTROLS_DATA_LENGTH = 13;
    const int KEY_MOTOR_DATA_LENGTH = 46;
    const int LIGHTS_DATA_LENGTH = 5;
    const int MOTOR_DETAILS_DATA_LENGTH = 72;
    const int MOTOR_FAULTS_DATA_LENGTH = 12;
    const int MPPT_DATA_LENGTH = 13;
    const int OTHER_DATA_LENGTH = 20;
}

int MessageDefines::getLengthForMessage(MessageDefines::Type type)
{
   switch (type)
   {
    case BatteryData:
        return BATTERY_DATA_LENGTH;
    case BatteryFaultsData:
        return BATTERY_FAULTS_DATA_LENGTH;
    case CmuData:
        return CMU_DATA_LENGTH;
    case DriverControlsData:
        return DRIVER_CONTROLS_DATA_LENGTH;
    case KeyMotorData:
        return KEY_MOTOR_DATA_LENGTH;
    case LightsData:
        return LIGHTS_DATA_LENGTH;
    case MotorDetailsData:
        return MOTOR_DETAILS_DATA_LENGTH;
    case MotorFaultsData:
        return MOTOR_FAULTS_DATA_LENGTH;
    case MpptData:
        return MPPT_DATA_LENGTH;
    case OtherData:
        return OTHER_DATA_LENGTH;
    default:
        return 0;
   }

}
