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

#include <QObject>

class I_BatteryData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_BatteryData() {}

    /*Data "Gets"*/
    virtual unsigned char getAlive() const = 0;
    virtual float getPackSocAmpHours() const = 0;
    virtual float getPackSocPercentage() const = 0;
    virtual float getPackBalanceSoc() const = 0;
    virtual float getPackBalanceSocPercentage() const = 0;
    virtual unsigned short getChargingCellVoltageError() const = 0;
    virtual unsigned short getCellTemperatureMargin() const = 0;
    virtual unsigned short getDischargingCellVoltageError() const = 0;
    virtual unsigned short getTotalPackCapacity() const = 0;
    virtual unsigned char getPrechargeContactorDriverStatus() const = 0;
    virtual unsigned char getPrechargeState() const = 0;
    virtual unsigned char getPrechargeTimerElapsed() const = 0;
    virtual unsigned short getPrechargeTimerCount() const = 0;
    virtual unsigned short getLowestCellVoltage() const = 0;
    virtual unsigned char getLowestCellVoltageNumber() const = 0;
    virtual unsigned short getHighestCellVoltage() const = 0;
    virtual unsigned char getHighestCellVoltageNumber() const = 0;
    virtual unsigned short getLowestCellTemperature() const = 0;
    virtual unsigned char getLowestCellTemperatureNumber() const = 0;
    virtual unsigned short getHighestCellTemperature() const = 0;
    virtual unsigned char getHighestCellTemperatureNumber() const = 0;
    virtual unsigned int getVoltage() const = 0;
    virtual unsigned int getCurrent() const = 0;
    virtual unsigned short getFan0Speed() const = 0;
    virtual unsigned short getFan1Speed() const = 0;
    virtual unsigned short getFanContactors12VCurrentConsumption() const = 0;
    virtual unsigned short getCmu12VCurrentConsumption() const = 0;
    virtual unsigned char getBmsCanLockedOut() const = 0;

    /*BatteryData "Sets"*/
    virtual void setAlive(const unsigned char&) = 0;
    virtual void setPackSocAmpHours(const float&) = 0;
    virtual void setPackSocPercentage(const float&) = 0;
    virtual void setPackBalanceSoc(const float&) = 0;
    virtual void setPackBalanceSocPercentage(const float&) = 0;
    virtual void setChargingCellVoltageError(const unsigned short&) = 0;
    virtual void setCellTemperatureMargin(const unsigned short&) = 0;
    virtual void setDischargingCellVoltageError(const unsigned short&) = 0;
    virtual void setTotalPackCapacity(const unsigned short&) = 0;
    virtual void setPrechargeContactorDriverStatus(const unsigned char&) = 0;
    virtual void setPrechargeState(const unsigned char&) = 0;
    virtual void setPrechargeTimerElapsed(const unsigned char&) = 0;
    virtual void setPrechargeTimerCount(const unsigned short&) = 0;
    virtual void setLowestCellVoltage(const unsigned short&) = 0;
    virtual void setLowestCellVoltageNumber(const unsigned char&) = 0;
    virtual void setHighestCellVoltage(const unsigned short&) = 0;
    virtual void setHighestCellVoltageNumber(const unsigned char&) = 0;
    virtual void setLowestCellTemperature(const unsigned short&) = 0;
    virtual void setLowestCellTemperatureNumber(const unsigned char&) = 0;
    virtual void setHighestCellTemperature(const unsigned short&) = 0;
    virtual void setHighestCellTemperatureNumber(const unsigned char&) = 0;
    virtual void setVoltage(const unsigned int&) = 0;
    virtual void setCurrent(const unsigned int&) = 0;
    virtual void setFan0Speed(const unsigned short&) = 0;
    virtual void setFan1Speed(const unsigned short&) = 0;
    virtual void setFanContactors12VCurrentConsumption(const unsigned short&) = 0;
    virtual void setCmu12VCurrentConsumption(const unsigned short&) = 0;
    virtual void setBmsCanLockedOut(const unsigned char&) = 0;

signals:
    void aliveReceived(const unsigned char& alive);
    void packSocAmpHoursReceived(const float& packSocAmpHours);
    void packSocPercentageReceived(const float& packSocPercentage);
    void packBalanceSocReceived(const float& packBalanceSoc);
    void packBalanceSocPercentageReceived(const float& packBalanceSocPercentage);
    void chargingCellVoltageErrorReceived(const unsigned short& chargingCellVoltageError);
    void cellTemperatureMarginReceived(const unsigned short& cellTemperatureMargin);
    void dischargingCellVoltageErrorReceived(const unsigned short& dischargingCellVoltageError);
    void totalPackCapacityReceived(const unsigned short& totalPackCapacity);
    void prechargeContactorDriverStatusReceived(const unsigned char& prechargeContactorDriverStatus);
    void prechargeStateReceived(const unsigned char& prechargeState);
    void prechargeTimerElapsedReceived(const unsigned char& prechargeTimerElapsed);
    void prechargeTimerCountReceived(const unsigned short& prechargeTimerCount);
    void lowestCellVoltageReceived(const unsigned short& lowestCellVoltage);
    void lowestCellVoltageNumberReceived(const unsigned char& lowestCellVoltageNumber);
    void highestCellVoltageReceived(const unsigned short& highestCellVoltage);
    void highestCellVoltageNumberReceived(const unsigned char& highestCellVoltageNumber);
    void lowestCellTemperatureReceived(const unsigned short& lowestCellTemperature);
    void lowestCellTemperatureNumberReceived(const unsigned char& lowestCellTemperatureNumber);
    void highestCellTemperatureReceived(const unsigned short& highestCellTemperature);
    void highestCellTemperatureNumberReceived(const unsigned char& highestCellTemperatureNumber);
    void voltageReceived(const unsigned int& voltage);
    void currentReceived(const unsigned int& current);
    void fan0SpeedReceived(const unsigned short& fan0Speed);
    void fan1SpeedReceived(const unsigned short& fan1Speed);
    void fanContactors12VCurrentConsumptionReceived(const unsigned short& fanContactors12VCurrentConsumption);
    void cmu12VCurrentConsumptionReceived(const unsigned short& cmu12VCurrentConsumption);
    void bmsCanLockedOutReceived(const unsigned char& bmsCanLockedOut);
};
