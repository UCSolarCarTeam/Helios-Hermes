#include "FakeBatteryData.h"

FakeBatteryData::FakeBatteryData()
{
}

FakeBatteryData::~FakeBatteryData()
{
}

/*Data "Gets"*/
unsigned char FakeBatteryData::getAlive() const
{
    return 1;
}

float FakeBatteryData::getPackSocAmpHours() const
{
    return 2;
}

float FakeBatteryData::getPackSocPercentage() const
{
    return 3;
}

float FakeBatteryData::getPackBalanceSoc() const
{
    return 4;
}

float FakeBatteryData::getPackBalanceSocPercentage() const
{
    return 5;
}

unsigned short FakeBatteryData::getChargingCellVoltageError() const
{
    return 6;
}

unsigned short FakeBatteryData::getCellTemperatureMargin() const
{
    return 7;
}

unsigned short FakeBatteryData::getDischargingCellVoltageError() const
{
    return 8;
}

unsigned short FakeBatteryData::getTotalPackCapacity() const
{
    return 9;
}

bool FakeBatteryData::getContactor0ErrorStatus() const
{
    return true;
}

bool FakeBatteryData::getContactor1ErrorStatus() const
{
    return true;
}

bool FakeBatteryData::getContactor0Status() const
{
    return true;
}

bool FakeBatteryData::getContactor1Status() const
{
    return true;
}

bool FakeBatteryData::getContactorSupplyOk() const
{
    return true;
}

bool FakeBatteryData::getContactor2ErrorStatus() const
{
    return true;
}

bool FakeBatteryData::getContactor2Status() const
{
    return true;
}


PrechargeState FakeBatteryData::getPrechargeState() const
{
    return PrechargeState::ERROR;
}

unsigned char FakeBatteryData::getPrechargeTimerElapsed() const
{
    return 12;
}

unsigned short FakeBatteryData::getPrechargeTimerCount() const
{
    return 13;
}

QPair<unsigned char, unsigned short>& FakeBatteryData::getLowestCellVoltage() const
{
    return QPair<unsigned char, unsigned short>(0, 0);
}

QPair<unsigned char, unsigned short>& FakeBatteryData::getHighestCellVoltage() const
{
    return QPair<unsigned char, unsigned short>(0, 0);
}

QPair<unsigned char, unsigned short>& FakeBatteryData::getLowestCellTemperature() const
{
    return QPair<unsigned char, unsigned short>(0, 0);
}

QPair<unsigned char, unsigned short>& FakeBatteryData::getHighestCellTemperature() const
{
    return QPair<unsigned char, unsigned short>(0, 0);
}


unsigned int FakeBatteryData::getVoltage() const
{
    return 22;
}

unsigned int FakeBatteryData::getCurrent() const
{
    return 23;
}

unsigned short FakeBatteryData::getFan0Speed() const
{
    return 24;
}

unsigned short FakeBatteryData::getFan1Speed() const
{
    return 25;
}

unsigned short FakeBatteryData::getFanContactors12VCurrentConsumption() const
{
    return 26;
}

unsigned short FakeBatteryData::getCmu12VCurrentConsumption() const
{
    return 27;
}

unsigned char FakeBatteryData::getBmsCanLockedOut() const
{
    return 1;
}

/*BatteryData "Sets"*/
void FakeBatteryData::setAlive(const unsigned char& alive) {}
void FakeBatteryData::setPackSocAmpHours(const float& packSocAmpHours) {}
void FakeBatteryData::setPackSocPercentage(const float& packSocPercentage) {}
void FakeBatteryData::setPackBalanceSoc(const float& packBalanceSoc) {}
void FakeBatteryData::setPackBalanceSocPercentage(const float& packBalanceSocPercentage) {}
void FakeBatteryData::setChargingCellVoltageError(const unsigned short& chargingCellVoltageError) {}
void FakeBatteryData::setCellTemperatureMargin(const unsigned short& cellTemperatureMargin) {}
void FakeBatteryData::setDischargingCellVoltageError(const unsigned short& dischargingCellVoltageError) {}
void FakeBatteryData::setTotalPackCapacity(const unsigned short& totalPackCapacity) {}
void FakeBatteryData::setPrechargeContactorDriverStatus(const unsigned char& prechargeContactorDriverStatus) {}
void FakeBatteryData::setPrechargeState(const unsigned char& prechargeState) {}
void FakeBatteryData::setPrechargeTimerElapsed(const unsigned char& prechargeTimerElapsed) {}
void FakeBatteryData::setPrechargeTimerCount(const unsigned short& prechargeTimerCount) {}
void FakeBatteryData::setLowestCellVoltage(const unsigned short lowestCellVoltage&, const unsigned char& lowestCellVoltageNumber) {}
void FakeBatteryData::setHighestCellVoltage(const unsigned short highestCellVoltage&, const unsigned char& highestCellVoltageNumber) {}
void FakeBatteryData::setLowestCellTemperature(const unsigned short lowestCellTemperature&, const unsigned char& lowestCellTemperatureNumber) {}
void FakeBatteryData::setHighestCellTemperature(const unsigned short highestCellTemperature&, const unsigned char& highestCellTemperatureNumber) {}
void FakeBatteryData::setVoltage(const unsigned int& voltage) {}
void FakeBatteryData::setCurrent(const unsigned int& current) {}
void FakeBatteryData::setFan0Speed(const unsigned short& fan0Speed) {}
void FakeBatteryData::setFan1Speed(const unsigned short& fan1Speed) {}
void FakeBatteryData::setFanContactors12VCurrentConsumption(const unsigned short& fanContactors12VCurrentConsumption) {}
void FakeBatteryData::setCmu12VCurrentConsumption(const unsigned short& cmu12VCurrentConsumption) {}
void FakeBatteryData::setBmsCanLockedOut(const unsigned char& bmsCanLockedOut) {}
