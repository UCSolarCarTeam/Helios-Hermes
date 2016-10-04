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

#include "MotorDetailsData.h"

MotorDetailsData::MotorDetailsData(unsigned char motorNumber)
: phaseCCurrent_(0)
, phaseBCurrent_(0)
, motorVoltageReal_(0)
, motorVoltageImaginary_(0)
, motorCurrentReal_(0)
, motorCurrentImaginary_(0)
, backEmfReal_(0)
, backEmfImaginary_(0)
, voltageRailSuppply15V_(0)
, voltageRailSupply33V_(0)
, voltageRailSupply19V_(0)
, heatSinkTemperature_(0)
, motorTempterature_(0)
, dspBoardTemperature_(0)
, dcBusAmpHours_(0)
, odometer_(0)
, slipSpeed_(0)
{
    // initialize to 0
    switch (motorNumber) {
        case 0:
            packageID_ = 2;
            break;
        case 1:
            packageID_ = 3;
            break;
        default:
            throw "Invalid motor number"
    }
}

MotorDetailsData::~MotorDetailsData()
{
}

/* MotorDetailsData Gets*/
unsigned char MotorDetailsData::getPackageID() const
{
    return packageID_;
}

float MotorDetailsData::getPhaseCCurrent() const
{
    return phaseCCurrent_;
}

float MotorDetailsData::getPhaseBCurrent() const
{
    return phaseBCurrent_;
}

float MotorDetailsData::getMotorVoltageReal() const
{
    return motorVoltageReal_;
}

float MotorDetailsData::getMotorVoltageImaginary() const
{
    return motorVoltageImaginary_;
}

float MotorDetailsData::getMotorCurrentReal() const
{
    return motorCurrentReal_;
}

float MotorDetailsData::getMotorCurrentImaginary() const
{
    return motorCurrentImaginary_;
}

float MotorDetailsData::getBackEmfReal() const
{
    return backEmfReal_;
}

float MotorDetailsData::getBackEmfImaginary() const
{
    return backEmfImaginary_;
}

float MotorDetailsData::getVoltageRailSuppply15V() const
{
    return voltageRailSuppply15V_;
}

float MotorDetailsData::getVoltageRailSupply33V() const
{
    return voltageRailSupply33V_;
}

float MotorDetailsData::getVoltageRailSupply19V() const
{
    return voltageRailSupply19V_;
}

float MotorDetailsData::getHeatSinkTemperature() const
{
    return heatSinkTemperature_;
}

float MotorDetailsData::getMotorTempterature() const
{
    return motorTempterature_;
}

float MotorDetailsData::getDspBoardTemperature() const
{
    return dspBoardTemperature_;
}

float MotorDetailsData::getDcBusAmpHours() const
{
    return dcBusAmpHours_;
}

float MotorDetailsData::getOdometer() const
{
    return odometer_;
}

float MotorDetailsData::getSlipSpeed() const
{
    return slipSpeed_;
}


/* MotorDetailsData Sets*/

void MotorDetailsData::setPhaseCCurrent(float& phaseCCurrent)
{
    phaseCCurrent_ = phaseCCurrent;
    emit phaseCCurrentReceived(phaseCCurrent_);
}

void MotorDetailsData::setPhaseBCurrent(float& phaseBCurrent)
{
    phaseBCurrent_ = phaseBCurrent;
    emit phaseBCurrentReceived(phaseBCurrent_);
}

void MotorDetailsData::setMotorVoltageReal(float& motorVoltageReal)
{
    motorVoltageReal_ = motorVoltageReal;
    emit motorVoltageRealReceived(motorVoltageReal_);
}

void MotorDetailsData::setMotorVoltageImaginary(float& motorVoltageImaginary)
{
    motorVoltageImaginary_ = motorVoltageImaginary;
    emit motorVoltageImaginaryReceived(motorVoltageImaginary_);
}

void MotorDetailsData::setMotorCurrentReal(float& motorCurrentReal)
{
    motorCurrentReal_ = motorCurrentReal;
    emit motorCurrentRealReceived(motorCurrentReal_);
}

void MotorDetailsData::setMotorCurrentImaginary(float& motorCurrentImaginary)
{
    motorCurrentImaginary_ = motorCurrentImaginary;
    emit motorCurrentImaginaryReceived(motorCurrentImaginary_);
}

void MotorDetailsData::setBackEmfReal(float& backEmfReal)
{
    backEmfReal_ = backEmfReal;
    emit backEmfRealReceived(backEmfReal_);
}

void MotorDetailsData::setBackEmfImaginary(float& backEmfImaginary)
{
    backEmfImaginary_ = backEmfImaginary;
    emit backEmfImaginaryReceived(backEmfImaginary_);
}

void MotorDetailsData::setVoltageRailSuppply15V(float& voltageRailSuppply15V)
{
    voltageRailSuppply15V_ = voltageRailSuppply15V;
    emit voltageRailSuppply15VReceived(voltageRailSuppply15V_);
}

void MotorDetailsData::setVoltageRailSupply33V(float& voltageRailSupply33V)
{
    voltageRailSupply33V_ = voltageRailSupply33V;
    emit voltageRailSupply33VReceived(voltageRailSupply33V_);
}

void MotorDetailsData::setVoltageRailSupply19V(float& voltageRailSupply19V)
{
    voltageRailSupply19V_ = voltageRailSupply19V;
    emit voltageRailSupply19VReceived(voltageRailSupply19V_);
}

void MotorDetailsData::setHeatSinkTemperature(float& heatSinkTemperature)
{
    heatSinkTemperature_ = heatSinkTemperature;
    emit heatSinkTemperatureReceived(heatSinkTemperature_);
}

void MotorDetailsData::setMotorTempterature(float& motorTempterature)
{
    motorTempterature_ = motorTempterature;
    emit motorTempteratureReceived(motorTempterature_);
}

void MotorDetailsData::setDspBoardTemperature(float& dspBoardTemperature)
{
    dspBoardTemperature_ = dspBoardTemperature;
    emit dspBoardTemperatureReceived(dspBoardTemperature_);
}

void MotorDetailsData::setDcBusAmpHours(float& dcBusAmpHours)
{
    dcBusAmpHours_ = dcBusAmpHours;
    emit dcBusAmpHoursReceived(dcBusAmpHours_);
}

void MotorDetailsData::setOdometer(float& odometer)
{
    odometer_ = odometer;
    emit odometerReceived(odometer_);
}

void MotorDetailsData::setSlipSpeed(float& slipSpeed)
{
    slipSpeed_ = slipSpeed;
    emit slipSpeedReceived(slipSpeed_);
}
