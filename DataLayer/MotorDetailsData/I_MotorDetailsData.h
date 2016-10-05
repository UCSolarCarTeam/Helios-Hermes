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

class I_MotorDetailsData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_MotorDetailsData() {}

    /*MotorDetailsData "Gets"*/
    virtual float getPhaseCCurrent() const;
    virtual float getPhaseBCurrent() const;
    virtual float getMotorVoltageReal() const;
    virtual float getMotorVoltageImaginary() const;
    virtual float getMotorCurrentReal() const;
    virtual float getMotorCurrentImaginary() const;
    virtual float getBackEmfReal() const;
    virtual float getBackEmfImaginary() const;
    virtual float getVoltageRailSuppply15V() const;
    virtual float getVoltageRailSupply33V() const;
    virtual float getVoltageRailSupply19V() const;
    virtual float getHeatSinkTemperature() const;
    virtual float getMotorTempterature() const;
    virtual float getDspBoardTemperature() const;
    virtual float getDcBusAmpHours() const;
    virtual float getOdometer() const;
    virtual float getSlipSpeed() const;

    /*MotorDetailsData "Sets"*/
    virtual void setPhaseCCurrent(float& phaseCCurrent);
    virtual void setPhaseBCurrent(float& phaseBCurrent);
    virtual void setMotorVoltageReal(float& motorVoltageReal);
    virtual void setMotorVoltageImaginary(float& motorVoltageImaginary);
    virtual void setMotorCurrentReal(float& motorCurrentReal);
    virtual void setMotorCurrentImaginary(float& motorCurrentImaginary);
    virtual void setBackEmfReal(float& backEmfReal);
    virtual void setBackEmfImaginary(float& backEmfImaginary);
    virtual void setVoltageRailSuppply15V(float& voltageRailSuppply15V);
    virtual void setVoltageRailSupply33V(float& voltageRailSupply33V);
    virtual void setVoltageRailSupply19V(float& voltageRailSupply19V);
    virtual void setHeatSinkTemperature(float& heatSinkTemperature);
    virtual void setMotorTempterature(float& motorTempterature);
    virtual void setDspBoardTemperature(float& dspBoardTemperature);
    virtual void setDcBusAmpHours(float& dcBusAmpHours);
    virtual void setOdometer(float& odometer);
    virtual void setSlipSpeed(float& slipSpeed);

signals:
    void phaseCCurrentReceived(const float& phaseCCurrent);
    void phaseBCurrentReceived(const float& phaseBCurrent);
    void motorVoltageRealReceived(const float& motorVoltageReal);
    void motorVoltageImaginaryReceived(const float& motorVoltageImaginary);
    void motorCurrentRealReceived(const float& motorCurrentReal);
    void motorCurrentImaginaryReceived(const float& motorCurrentImaginary);
    void backEmfRealReceived(const float& backEmfReal);
    void backEmfImaginaryReceived(const float& backEmfImaginary);
    void voltageRailSuppply15VReceived(const float& voltageRailSuppply15V);
    void voltageRailSupply33VReceived(const float& voltageRailSupply33V);
    void voltageRailSupply19VReceived(const float& voltageRailSupply19V);
    void heatSinkTemperatureReceived(const float& heatSinkTemperature);
    void motorTempteratureReceived(const float& motorTempterature);
    void dspBoardTemperatureReceived(const float& dspBoardTemperature);
    void dcBusAmpHoursReceived(const float& dcBusAmpHours);
    void odometerReceived(const float& odometer);
    void slipSpeedReceived(const float& slipSpeed);
};

