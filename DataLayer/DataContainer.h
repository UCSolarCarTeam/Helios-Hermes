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

#include <QScopedPointer>

class I_BatteryData;
class I_BatteryFaultsData;
class I_CmuData;
class I_DriverControlsData;
class I_KeyMotorData;
class I_LightsData;
class I_MotorDetailsData;
class I_MotorFaultsData;
class I_MpptData;

class DataContainer
{
public:
    DataContainer();
    ~DataContainer();

    I_BatteryData& batteryData();
    I_BatteryFaultsData& batteryFaultsData();
    I_CmuData& cmuData();
    I_DriverControlsData& driverControlsData();
    I_KeyMotorData& keyMotorData();
    I_LightsData& lightsData();
    I_MotorDetailsData& motorDetailsData();
    I_MotorFaultsData& motorFaultsData();
    I_MpptData& mpptData();

private:
    QScopedPointer<I_BatteryData> batteryData_;
    QScopedPointer<I_BatteryFaultsData> batteryFaultsData_;
    QScopedPointer<I_CmuData> cmuData_;
    QScopedPointer<I_DriverControlsData> driverControlsData_;
    QScopedPointer<I_KeyMotorData> keyMotorData_;
    QScopedPointer<I_LightsData> lightsData_;
    QScopedPointer<I_MotorDetailsData> motorDetailsData_;
    QScopedPointer<I_MotorFaultsData> motorFaultsData_;
    QScopedPointer<I_MpptData> mpptData_;
};
