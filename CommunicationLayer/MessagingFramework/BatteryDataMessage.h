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

#include <QByteArray>
#include <QString>

class BatteryDataMessage
{
public:
    BatteryDataMessage(const QByteArray& messageData);

    bool alive() const;
    float packSocAmpHours() const;
    float packSocPercentage() const;
    float packBalanceSoc() const;
    float packBalanceSocPercentage() const;
    unsigned short chargingCellVoltageError() const;
    unsigned short cellTemperatureMargin() const;
    unsigned short dischargingCellVoltageError() const;
    unsigned short totalPackCapacity() const;
    bool prechargeContactorDriverStatus() const;
    bool prechargeState() const;
    bool prechargeTimerElapsed() const;
    unsigned short prechargeTimerCount() const;
    unsigned short lowestCellVoltage() const;
    bool lowestCellVoltageNumber() const;
    unsigned short highestCellVoltage() const;
    bool highestCellVoltageNumber() const;
    unsigned short lowestCellTemperature() const;
    bool lowestCellTemperatureNumber() const;
    unsigned short highestCellTemperature() const;
    bool highestCellTemperatureNumber() const;
    unsigned int voltage() const;
    unsigned int current() const;
    unsigned short fan0Speed() const;
    unsigned short fan1Speed() const;
    unsigned short fanContactors12VCurrentConsumption() const;
    unsigned short cmu12VCurrentConsumption() const;
    bool bmsCanLockedOut() const;

   
   QString toString() const;

private:
   const QByteArray messageData_;
};
