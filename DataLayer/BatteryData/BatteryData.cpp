#include "BatteryData.h"

namespace
{
    const unsigned char CONTACTOR0_ERROR_STATUS_OFFSET = 0x1;
    const unsigned char CONTACTOR1_ERROR_STATUS_OFFSET = 0x2;
    const unsigned char CONTACTOR0_STATUS_OFFSET = 0x4;
    const unsigned char CONTACTOR1_STATUS_OFFSET = 0x8;
    const unsigned char CONTACTOR_SUPPLY_OK_OFFSET = 0x10;
    const unsigned char CONTACTOR2_ERROR_STATUS_OFFSET = 0x20;
    const unsigned char CONTACTOR2_STATUS_OFFSET = 0x40;
}

BatteryData::BatteryData()
    : alive_(0)
    , packSocAmpHours_(0)
    , packSocPercentage_(0)
    , packBalanceSoc_(0)
    , packBalanceSocPercentage_(0)
    , chargingCellVoltageError_(0)
    , cellTemperatureMargin_(0)
    , dischargingCellVoltageError_(0)
    , totalPackCapacity_(0)
    , prechargeContactorDriverStatus_(0)
    , prechargeState_(BatteryData::PrechargeState::DEFAULT)
    , prechargeTimerElapsed_(0)
    , prechargeTimerCount_(0)
    , lowestCellVoltage_(0, 0)
    , highestCellVoltage_(0, 0)
    , lowestCellTemperature_(0, 0)
    , highestCellTemperature_(0, 0)
    , voltage_(0)
    , current_(0)
    , fan0Speed_(0)
    , fan1Speed_(0)
    , fanContactors12VCurrentConsumption_(0)
    , cmu12VCurrentConsumption_(0)
    , bmsCanLockedOut_(0)

{
    // initialize to 0
}

BatteryData::~BatteryData()
{
}

/*Data "Gets"*/
unsigned char BatteryData::getAlive() const
{
    return alive_;
}

float BatteryData::getPackSocAmpHours() const
{
    return packSocAmpHours_;
}

float BatteryData::getPackSocPercentage() const
{
    return packSocPercentage_;
}

float BatteryData::getPackBalanceSoc() const
{
    return packBalanceSoc_;
}

float BatteryData::getPackBalanceSocPercentage() const
{
    return packBalanceSocPercentage_;
}

unsigned short BatteryData::getChargingCellVoltageError() const
{
    return chargingCellVoltageError_;
}

unsigned short BatteryData::getCellTemperatureMargin() const
{
    return cellTemperatureMargin_;
}

unsigned short BatteryData::getDischargingCellVoltageError() const
{
    return dischargingCellVoltageError_;
}

unsigned short BatteryData::getTotalPackCapacity() const
{
    return totalPackCapacity_;
}

bool BatteryData::getContactor0ErrorStatus() const
{
    return static_cast<bool>(prechargeContactorDriverStatus_ & CONTACTOR0_ERROR_STATUS_OFFSET);
}

bool BatteryData::getContactor1ErrorStatus() const
{
    return static_cast<bool>(prechargeContactorDriverStatus_ & CONTACTOR1_ERROR_STATUS_OFFSET);
}

bool BatteryData::getContactor0Status() const
{
    return static_cast<bool>(prechargeContactorDriverStatus_ & CONTACTOR0_STATUS_OFFSET);
}

bool BatteryData::getContactor1Status() const
{
    return static_cast<bool>(prechargeContactorDriverStatus_ & CONTACTOR1_STATUS_OFFSET);
}

bool BatteryData::getContactorSupplyOk() const
{
    return static_cast<bool>(prechargeContactorDriverStatus_ & CONTACTOR_SUPPLY_OK_OFFSET);
}

bool BatteryData::getContactor2ErrorStatus() const
{
    return static_cast<bool>(prechargeContactorDriverStatus_ & CONTACTOR2_ERROR_STATUS_OFFSET);
}

bool BatteryData::getContactor2Status() const
{
    return static_cast<bool>(prechargeContactorDriverStatus_ & CONTACTOR2_STATUS_OFFSET);
}


BatteryData::PrechargeState BatteryData::getPrechargeState() const
{
    return prechargeState_;
}

unsigned char BatteryData::getPrechargeTimerElapsed() const
{
    return prechargeTimerElapsed_;
}

unsigned short BatteryData::getPrechargeTimerCount() const
{
    return prechargeTimerCount_;
}

QPair<unsigned char, unsigned short>& BatteryData::getLowestCellVoltage()
{
    return lowestCellVoltage_;
}

QPair<unsigned char, unsigned short>& BatteryData::getHighestCellVoltage()
{
    return highestCellVoltage_;
}

QPair<unsigned char, unsigned short>& BatteryData::getLowestCellTemperature()
{
    return lowestCellTemperature_;
}

QPair<unsigned char, unsigned short>& BatteryData::getHighestCellTemperature()
{
    return highestCellTemperature_;
}


unsigned int BatteryData::getVoltage() const
{
    return voltage_;
}

unsigned int BatteryData::getCurrent() const
{
    return current_;
}

unsigned short BatteryData::getFan0Speed() const
{
    return fan0Speed_;
}

unsigned short BatteryData::getFan1Speed() const
{
    return fan1Speed_;
}

unsigned short BatteryData::getFanContactors12VCurrentConsumption() const
{
    return fanContactors12VCurrentConsumption_;
}

unsigned short BatteryData::getCmu12VCurrentConsumption() const
{
    return cmu12VCurrentConsumption_;
}

unsigned char BatteryData::getBmsCanLockedOut() const
{
    return bmsCanLockedOut_;
}


/*BatteryData "Sets"*/
void BatteryData::setAlive(const unsigned char& alive)
{
    alive_ = alive;
    emit aliveReceived(alive_);
}

void BatteryData::setPackSocAmpHours(const float& packSocAmpHours)
{
    packSocAmpHours_ = packSocAmpHours;
    emit packSocAmpHoursReceived(packSocAmpHours_);
}

void BatteryData::setPackSocPercentage(const float& packSocPercentage)
{
    packSocPercentage_ = packSocPercentage;
    emit packSocPercentageReceived(packSocPercentage_);
}

void BatteryData::setPackBalanceSoc(const float& packBalanceSoc)
{
    packBalanceSoc_ = packBalanceSoc;
    emit packBalanceSocPercentageReceived(packBalanceSoc_);
}

void BatteryData::setPackBalanceSocPercentage(const float& packBalanceSocPercentage)
{
    packBalanceSocPercentage_ = packBalanceSocPercentage;
    emit packBalanceSocPercentageReceived(packBalanceSocPercentage_);
}

void BatteryData::setChargingCellVoltageError(const unsigned short& chargingCellVoltageError)
{
    chargingCellVoltageError_ = chargingCellVoltageError;
    emit chargingCellVoltageErrorReceived(chargingCellVoltageError_);
}

void BatteryData::setCellTemperatureMargin(const unsigned short& cellTemperatureMargin)
{
    cellTemperatureMargin_ = cellTemperatureMargin;
    emit cellTemperatureMarginReceived(cellTemperatureMargin_);
}

void BatteryData::setDischargingCellVoltageError(const unsigned short& dischargingCellVoltageError)
{
    dischargingCellVoltageError_ = dischargingCellVoltageError;
    emit dischargingCellVoltageErrorReceived(dischargingCellVoltageError_);
}
void BatteryData::setTotalPackCapacity(const unsigned short& totalPackCapacity)
{
    totalPackCapacity_ = totalPackCapacity;
    emit totalPackCapacityReceived(totalPackCapacity_);
}

void BatteryData::setPrechargeContactorDriverStatus(const unsigned char& prechargeContactorDriverStatus)
{
    prechargeContactorDriverStatus_ = prechargeContactorDriverStatus;
    emit prechargeContactorDriverStatusReceived(prechargeContactorDriverStatus_);
}

void BatteryData::setPrechargeState(const unsigned char& prechargeState)
{
    prechargeState_ = static_cast<BatteryData::PrechargeState>(prechargeState);
    emit prechargeStateReceived(prechargeState_);
}

void BatteryData::setPrechargeTimerElapsed(const unsigned char& prechargeTimerElapsed)
{
    prechargeTimerElapsed_ = prechargeTimerElapsed;
    emit prechargeTimerElapsedReceived(prechargeTimerElapsed_);
}

void BatteryData::setPrechargeTimerCount(const unsigned short& prechargeTimerCount)
{
    prechargeTimerCount_ = prechargeTimerCount;
    emit prechargeTimerCountReceived(prechargeTimerCount_);
}

void BatteryData::setLowestCellVoltage(const unsigned char& lowestCellVoltageNumber, const unsigned short& lowestCellVoltage)
{
    lowestCellVoltage_.first = lowestCellVoltageNumber;
    lowestCellVoltage_.second = lowestCellVoltage;
    emit lowestCellVoltageReceived(lowestCellVoltage_);
}

void BatteryData::setHighestCellVoltage(const unsigned char& highestCellVoltageNumber, const unsigned short& highestCellVoltage)
{
    highestCellVoltage_.first = highestCellVoltageNumber;
    highestCellVoltage_.second = highestCellVoltage;
    emit highestCellVoltageReceived(highestCellVoltage_);
}

void BatteryData::setLowestCellTemperature(const unsigned char& lowestCellTemperatureNumber, const unsigned short& lowestCellTemperature)
{
    lowestCellTemperature_.first = lowestCellTemperatureNumber;
    lowestCellTemperature_.second = lowestCellTemperature;
    emit lowestCellTemperatureReceived(lowestCellTemperature_);
}

void BatteryData::setHighestCellTemperature(const unsigned char& highestCellTemperatureNumber, const unsigned short& highestCellTemperature)
{
    highestCellTemperature_.first = highestCellTemperatureNumber;
    highestCellTemperature_.second = highestCellTemperature;
    emit highestCellTemperatureReceived(highestCellTemperature_);
}

void BatteryData::setVoltage(const unsigned int& voltage)
{
    voltage_ = voltage;
    emit voltageReceived(voltage_);
}

void BatteryData::setCurrent(const unsigned int& current)
{
    current_ = current;
    emit currentReceived(current_);
}

void BatteryData::setFan0Speed(const unsigned short& fan0Speed)
{
    fan0Speed_ = fan0Speed;
    emit fan0SpeedReceived(fan0Speed_);
}

void BatteryData::setFan1Speed(const unsigned short& fan1Speed)
{
    fan1Speed_ = fan1Speed;
    emit fan1SpeedReceived(fan1Speed_);
}

void BatteryData::setFanContactors12VCurrentConsumption(const unsigned short& fanContactors12VCurrentConsumption)
{
    fanContactors12VCurrentConsumption_ = fanContactors12VCurrentConsumption;
    emit fanContactors12VCurrentConsumptionReceived(fanContactors12VCurrentConsumption_);
}

void BatteryData::setCmu12VCurrentConsumption(const unsigned short& cmu12VCurrentConsumption)
{
    cmu12VCurrentConsumption_ = cmu12VCurrentConsumption;
    emit cmu12VCurrentConsumptionReceived(cmu12VCurrentConsumption_);
}

void BatteryData::setBmsCanLockedOut(const unsigned char& bmsCanLockedOut)
{
    bmsCanLockedOut_ = bmsCanLockedOut;
    emit bmsCanLockedOutReceived(bmsCanLockedOut_);
}
