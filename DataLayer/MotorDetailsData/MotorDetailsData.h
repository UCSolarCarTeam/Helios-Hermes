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
    unsigned char MotorDetailsData::getPackageID() const;
    float MotorDetailsData::getPhaseCCurrent() const;
    float MotorDetailsData::getPhaseBCurrent() const;
    float MotorDetailsData::getMotorVoltageReal() const;
    float MotorDetailsData::getMotorVoltageImaginary() const;
    float MotorDetailsData::getMotorCurrentReal() const;
    float MotorDetailsData::getMotorCurrentImaginary() const;
    float MotorDetailsData::getBackEmfReal() const;
    float MotorDetailsData::getBackEmfImaginary() const;
    float MotorDetailsData::getVoltageRailSuppply15V() const;
    float MotorDetailsData::getVoltageRailSupply33V() const;
    float MotorDetailsData::getVoltageRailSupply19V() const;
    float MotorDetailsData::getHeatSinkTemperature() const;
    float MotorDetailsData::getMotorTempterature() const;
    float MotorDetailsData::getDspBoardTemperature() const;
    float MotorDetailsData::getDcBusAmpHours() const;
    float MotorDetailsData::getOdometer() const;
    float MotorDetailsData::getSlipSpeed() const;

    /*MotorDetailsData "Sets"*/
    void MotorDetailsData::setPhaseCCurrent(const float& phaseCCurrent);
    void MotorDetailsData::setPhaseBCurrent(const float& phaseBCurrent);
    void MotorDetailsData::setMotorVoltageReal(const float& motorVoltageReal);
    void MotorDetailsData::setMotorVoltageImaginary(const float& motorVoltageImaginary);
    void MotorDetailsData::setMotorCurrentReal(const float& motorCurrentReal);
    void MotorDetailsData::setMotorCurrentImaginary(const float& motorCurrentImaginary);
    void MotorDetailsData::setBackEmfReal(const float& backEmfReal);
    void MotorDetailsData::setBackEmfImaginary(const float& backEmfImaginary);
    void MotorDetailsData::setVoltageRailSuppply15V(const float& voltageRailSuppply15V);
    void MotorDetailsData::setVoltageRailSupply33V(const float& voltageRailSupply33V);
    void MotorDetailsData::setVoltageRailSupply19V(const float& voltageRailSupply19V);
    void MotorDetailsData::setHeatSinkTemperature(const float& heatSinkTemperature);
    void MotorDetailsData::setMotorTempterature(const float& motorTempterature);
    void MotorDetailsData::setDspBoardTemperature(const float& dspBoardTemperature);
    void MotorDetailsData::setDcBusAmpHours(const float& dcBusAmpHours);
    void MotorDetailsData::setOdometer(const float& odometer);
    void MotorDetailsData::setSlipSpeed(const float& slipSpeed);

private:
    const unsigned char packageID_;
    
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
