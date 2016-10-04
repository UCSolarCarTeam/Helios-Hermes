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

class I_MpptData : public QObject
{
    Q_OBJECT
public:
    virtual ~I_MpptData() {}

    /* MpptData Gets */
    virtual unsigned char getPackageID() const;
    virtual unsigned char getMpptStatus() const;
    virtual unsigned short getArrayVoltage() const;
    virtual unsigned short getArrayCurrent() const;
    virtual unsigned short getBatteryVoltage() const;
    virtual unsigned short getTemperature() const;

    /* MpptData Sets */;
    virtual void setMpptStatus(const unsigned char& mpptStatus);
    virtual void setArrayVoltage(const unsigned short& arrayVoltage);
    virtual void setArrayCurrent(const unsigned short& arrayCurrent);
    virtual void setBatteryVoltage(const unsigned short& batteryVoltage);
    virtual void setTemperature(const unsigned short& temperature);

signals:
    void mpptStatusReceived(const unsigned char& mpptStatus);
    void arrayVoltageReceived(const unsigned short& arrayVoltage);
    void arrayCurrentReceived(const unsigned short& arrayCurrent);
    void batteryVoltageReceived(const unsigned short& batteryVoltage);
    void temperatureReceived(const unsigned short& temperature);
};
