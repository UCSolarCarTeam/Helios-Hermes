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

#include "I_MotorDetailsData.h"

class MotorDetailsData : public I_MotorDetailsData
{
public:
    MotorDetailsData();
    virtual ~MotorDetailsData();

    /*MotorDetailsData "Gets"*/
    float getPhaseCCurrent() const;
    float getPhaseBCurrent() const;
    float getMotorVoltageReal() const;
    float getMotorVoltageImaginary() const;
    float getMotorCurrentReal() const;
    float getMotorCurrentImaginary() const;
    float getBackEmfReal() const;
    float getBackEmfImaginary() const;
    float getVoltageRailSuppply15V() const;
    float getVoltageRailSupply33V() const;
    float getVoltageRailSupply19V() const;
    float getHeatSinkTemperature() const;
    float getMotorTempterature() const;
    float getDspBoardTemperature() const;
    float getDcBusAmpHours() const;
    float getOdometer() const;
    float getSlipSpeed() const;

    /*MotorDetailsData "Sets"*/
    void setPhaseCCurrent(const float& phaseCCurrent);
    void setPhaseBCurrent(const float& phaseBCurrent);
    void setMotorVoltageReal(const float& motorVoltageReal);
    void setMotorVoltageImaginary(const float& motorVoltageImaginary);
    void setMotorCurrentReal(const float& motorCurrentReal);
    void setMotorCurrentImaginary(const float& motorCurrentImaginary);
    void setBackEmfReal(const float& backEmfReal);
    void setBackEmfImaginary(const float& backEmfImaginary);
    void setVoltageRailSuppply15V(const float& voltageRailSuppply15V);
    void setVoltageRailSupply33V(const float& voltageRailSupply33V);
    void setVoltageRailSupply19V(const float& voltageRailSupply19V);
    void setHeatSinkTemperature(const float& heatSinkTemperature);
    void setMotorTempterature(const float& motorTempterature);
    void setDspBoardTemperature(const float& dspBoardTemperature);
    void setDcBusAmpHours(const float& dcBusAmpHours);
    void setOdometer(const float& odometer);
    void setSlipSpeed(const float& slipSpeed);

private:
    float phaseCCurrent_;
    float phaseBCurrent_;
    float motorVoltageReal_;
    float motorVoltageImaginary_;
    float motorCurrentReal_;
    float motorCurrentImaginary_;
    float backEmfReal_;
    float backEmfImaginary_;
    float voltageRailSuppply15V_;
    float voltageRailSupply33V_;
    float voltageRailSupply19V_;
    float heatSinkTemperature_;
    float motorTempterature_;
    float dspBoardTemperature_;
    float dcBusAmpHours_;
    float odometer_;
    float slipSpeed_;
};
