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
class I_FaultsData;
class I_PowerData;
class I_VehicleData;

class DataContainer
{
public:
   DataContainer();
   ~DataContainer();

   I_PowerData& powerData();
   I_VehicleData& vehicleData();
   I_BatteryData& batteryData();
   I_FaultsData& faultsData();

private:
   QScopedPointer<I_VehicleData> vehicleData_;
   QScopedPointer<I_PowerData> powerData_;
   QScopedPointer<I_BatteryData> batteryData_;
   QScopedPointer<I_FaultsData> faultsData_;
};
