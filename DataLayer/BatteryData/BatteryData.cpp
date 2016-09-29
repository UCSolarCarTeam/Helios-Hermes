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

#include "BatteryData.h"
#include <QDebug>

BatteryData::BatteryData()
    : packageID_(-1)
    , alive_(-1)
    , packSocAmpHours_(-1)
    , packSocPercentage_(-1)
    , packBalanceSoc_(-1)
    , packBalanceSocPercentage_(-1)
    , chargingCellVoltageError_(-1)
    , cellTemperatureMargin_(-1)
    , dischargingCellVoltageError_(-1)
    , totalPackCapacity_(-1)
    , prechargeContactorDriverStatus_(-1)
    , prechargeState_(-1)
    , prechargeTimerElapsed_(-1)
    , prechargeTimerCount_(-1)
    , lowestCellVoltage_(-1)
    , lowestCellVoltageNumber_(-1)
    , highestCellVoltage_(-1)
    , highestCellVoltageNumber_(-1)
    , lowestCellTemperature_(-1)
    , lowestCellTemperatureNumber_(-1)
    , highestCellTemperature_(-1)
    , highestCellTemperatureNumber_(-1)
    , voltage_(-1)
    , current_(-1)
    , fan0Speed_(-1)
    , fan1Speed_(-1)
    , fanContactors12VCurrentConsumption_(-1)
    , cmu12VCurrentConsumption_(-1)
    , bmsCanLockedOut_(-1)

{
    // initialize to -1
}

BatteryData::~BatteryData()
{
}

/*Data "Gets"*/
unsigned char BatteryData::getPackageID() const {
    return packageID_;
}

unsigned char BatteryData::getAlive() const {
    return alive_;
}

float BatteryData::getPackSocAmpHours() const {
    return packSocAmpHours_;
}

float BatteryData::getPackSocPercentage() const {
    return packSocPercentage_;
}

float BatteryData::getPackBalanceSoc() const {
    return packBalanceSoc_;
}

float BatteryData::getPackBalanceSocPercentage() const {
    return packBalanceSocPercentage_;
}

unsigned short BatteryData::getChargingCellVoltageError() const {
    return chargingCellVoltageError_;
}

unsigned short BatteryData::getCellTemperatureMargin() const {
    return cellTemperatureMargin_;
}

unsigned short BatteryData::getDischargingCellVoltageError() const {
    return dischargingCellVoltageError_;
}

unsigned short BatteryData::getTotalPackCapacity() const {
    return totalPackCapacity_;
}

unsigned char BatteryData::getPrechargeContactorDriverStatus() const {
    return prechargeContactorDriverStatus_;
}

unsigned char BatteryData::getPrechargeState() const {
    return prechargeState_;
}

unsigned char BatteryData::getPrechargeTimerElapsed() const {
    return prechargeTimerElapsed_;
}

unsigned short BatteryData::getPrechargeTimerCount() const {
    return prechargeTimerCount_;
}

unsigned short BatteryData::getLowestCellVoltage() const {
    return lowestCellVoltage_;
}

unsigned char BatteryData::getLowestCellVoltageNumber() const {
    return lowestCellVoltageNumber_;
}

unsigned short BatteryData::getHighestCellVoltage() const {
    return highestCellVoltage_;
}

unsigned char BatteryData::getHighestCellVoltageNumber() const {
    return highestCellVoltageNumber_;
}

unsigned short BatteryData::getLowestCellTemperature() const {
    return lowestCellTemperature_;
}

unsigned char BatteryData::getLowestCellTemperatureNumber() const {
    return lowestCellTemperatureNumber_;
}

unsigned short BatteryData::getHighestCellTemperature() const {
    return highestCellTemperature_;
}

unsigned char BatteryData::getHighestCellTemperatureNumber() const {
    return highestCellTemperatureNumber_;
}

unsigned int BatteryData::getVoltage() const {
    return voltage_;
}

unsigned int BatteryData::getCurrent() const {
    return current_;
}

unsigned short BatteryData::getFan0Speed() const {
    return fan0Speed_;
}

unsigned short BatteryData::getFan1Speed() const {
    return fan1Speed_;
}

unsigned short BatteryData::getFanContactors12VCurrentConsumption() const {
    return fanContactors12VCurrentConsumption_;
}

unsigned short BatteryData::getCmu12VCurrentConsumption() const {
    return cmu12VCurrentConsumption_;
}

unsigned char BatteryData::getBmsCanLockedOut() const {
    return bmsCanLockedOut_;
}


/*BatteryData "Sets"*/
void BatteryData::setPackageID(const unsigned char& packageID) {
    packageID_ = packageID;
    emit packageIDReceived(packageID_);
}

void BatteryData::setAlive(const unsigned char& alive) {
    alive_ = alive;
    emit aliveReceived(alive_);
}

void BatteryData::setPackSocAmpHours(const float& packSocAmpHours) {
    packSocAmpHours_ = packSocAmpHours;
    emit packSocAmpHoursReceived(packSocAmpHours_);
}

void BatteryData::setPackSocPercentage(const float& packSocPercentage) {
    packSocPercentage_ = packSocPercentage;
    emit packSocPercentageReceived(packSocPercentage_);
}

void BatteryData::setPackBalanceSoc(const float& packBalanceSoc) {
    packBalanceSoc_ = packBalanceSoc;
    emit packBalanceSocPercentageReceived(packBalanceSoc_);
}

void BatteryData::setPackBalanceSocPercentage(const float& packBalanceSocPercentage) {
    packBalanceSocPercentage_ = packBalanceSocPercentage;
    emit packBalanceSocPercentageReceived(packBalanceSocPercentage_);
}

void BatteryData::setChargingCellVoltageError(const unsigned short& chargingCellVoltageError) {
    chargingCellVoltageError_ = chargingCellVoltageError;
    emit chargingCellVoltageErrorReceived(chargingCellVoltageError_);
}

void BatteryData::setCellTemperatureMargin(const unsigned short& cellTemperatureMargin) {
    cellTemperatureMargin_ = cellTemperatureMargin;
    emit cellTemperatureMarginReceived(cellTemperatureMargin_);
}

void BatteryData::setDischargingCellVoltageError(const unsigned short& dischargingCellVoltageError) {
    dischargingCellVoltageError_ = dischargingCellVoltageError;
    emit dischargingCellVoltageErrorReceived(dischargingCellVoltageError_);
}
void BatteryData::setTotalPackCapacity(const unsigned short& totalPackCapacity) {
    totalPackCapacity_ = totalPackCapacity;
    emit totalPackCapacityReceived(totalPackCapacity_);
}

void BatteryData::setPrechargeContactorDriverStatus(const unsigned char& prechargeContactorDriverStatus) {
    prechargeContactorDriverStatus_ = prechargeContactorDriverStatus;
    emit prechargeContactorDriverStatusReceived(prechargeContactorDriverStatus_);
}

void BatteryData::setPrechargeState(const unsigned char& prechargeState) {
    prechargeState_ = prechargeState;
    emit prechargeStateReceived(prechargeState_);
}

void BatteryData::setPrechargeTimerElapsed(const unsigned char& prechargeTimerElapsed) {
    prechargeTimerElapsed_ = prechargeTimerElapsed;
    emit prechargeTimerElapsedReceived(prechargeTimerElapsed_);
}

void BatteryData::setPrechargeTimerCount(const unsigned short& prechargeTimerCount) {
    prechargeTimerCount_ = prechargeTimerCount;
    emit prechargeTimerCountReceived(prechargeTimerCount_);
}

void BatteryData::setLowestCellVoltage(const unsigned short& lowestCellVoltage) {
    lowestCellVoltage_ = lowestCellVoltage;
    emit lowestCellVoltageReceived(lowestCellVoltage_);
}

void BatteryData::setLowestCellVoltageNumber(const unsigned char& lowestCellVoltageNumber) {
    lowestCellVoltageNumber_ = lowestCellVoltageNumber;
    emit lowestCellVoltageNumberReceived(lowestCellVoltageNumber_);
}

void BatteryData::setHighestCellVoltage(const unsigned short& highestCellVoltage) {
    highestCellVoltage_ = highestCellVoltage;
    emit highestCellVoltageReceived(highestCellVoltage_);
}

void BatteryData::setHighestCellVoltageNumber(const unsigned char& highestCellVoltageNumber) {
    highestCellVoltageNumber_ = highestCellVoltageNumber;
    emit highestCellVoltageNumberReceived(highestCellVoltageNumber_);
}

void BatteryData::setLowestCellTemperature(const unsigned short& lowestCellTemperature) {
    lowestCellTemperature_ = lowestCellTemperature;
    emit lowestCellTemperatureReceived(lowestCellTemperature_);
}

void BatteryData::setLowestCellTemperatureNumber(const unsigned char& lowestCellTemperatureNumber) {
    lowestCellTemperatureNumber_ = lowestCellTemperatureNumber;
    emit lowestCellTemperatureNumberReceived(lowestCellTemperatureNumber_);
}

void BatteryData::setHighestCellTemperature(const unsigned short& highestCellTemperature) {
    highestCellTemperature_ = highestCellTemperature;
    emit highestCellTemperatureReceived(highestCellTemperature_);
}

void BatteryData::setHighestCellTemperatureNumber(const unsigned char& highestCellTemperatureNumber) {
    highestCellTemperatureNumber_ = highestCellTemperatureNumber;
    emit highestCellTemperatureNumberReceived(highestCellTemperatureNumber_);
}

void BatteryData::setVoltage(const unsigned int& voltage) {
    voltage_ = voltage;
    emit voltageReceived(voltage_);
}

void BatteryData::setCurrent(const unsigned int& current) {
    current_ = current;
    emit currentReceived(current_);
}

void BatteryData::setFan0Speed(const unsigned short& fan0Speed) {
    fan0Speed_ = fan0Speed;
    emit fan0SpeedReceived(fan0Speed_);
}

void BatteryData::setFan1Speed(const unsigned short& fan1Speed) {
    fan1Speed_ = fan1Speed;
    emit fan1SpeedReceived(fan1Speed_);
}

void BatteryData::setFanContactors12VCurrentConsumption(const unsigned short& fanContactors12VCurrentConsumption) {
    fanContactors12VCurrentConsumption_ = fanContactors12VCurrentConsumption;
    emit fanContactors12VCurrentConsumptionReceived(fanContactors12VCurrentConsumption_);
}

void BatteryData::setCmu12VCurrentConsumption(const unsigned short& cmu12VCurrentConsumption) {
    cmu12VCurrentConsumption_ cmu12VCurrentConsumption;
    emit cmu12VCurrentConsumptionReceived(cmu12VCurrentConsumption_);
}

void BatteryData::setBmsCanLockedOut(const unsigned char& bmsCanLockedOut) {
    bmsCanLockedOut_ = bmsCanLockedOut;
    emit bmsCanLockedOutReceived(bmsCanLockedOut_);
}
