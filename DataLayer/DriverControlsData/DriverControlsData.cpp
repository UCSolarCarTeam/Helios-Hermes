#include "DriverControlsData.h"

DriverControlsData::DriverControlsData()
    : driverControlsBoardAlive_(0)
    , lightsInputs_(0)
    , musicInputs_(0)
    , acceleration_(0)
    , regenBraking_(0)
    , driverInputs_(0)
{
    // initialize to 0
}

DriverControlsData::~DriverControlsData()
{
}

/*Data "Gets"*/
unsigned char DriverControlsData::getDriverControlsBoardAlive() const 
{
    return driverControlsBoardAlive_;
}

unsigned char DriverControlsData::getLightsInputs() const 
{
    return lightsInputs_;
}

unsigned char DriverControlsData::getMusicInputs() const 
{
    return musicInputs_;
}

unsigned short DriverControlsData::getAcceleration() const 
{
    return acceleration_;
}

unsigned short DriverControlsData::getRegenBraking() const 
{
    return regenBraking_;
}

unsigned char DriverControlsData::getDriverInputs() const 
{
    return driverInputs_;
}


/*DriverControlsData "Sets"*/
void DriverControlsData::setDriverControlsBoardAlive(const unsigned char& driverControlsBoardAlive)
{
    driverControlsBoardAlive_ = driverControlsBoardAlive;
    emit driverControlsBoardAliveReceived(driverControlsBoardAlive_);
}

void DriverControlsData::setLightsInputs(const unsigned char& lightsInputs)
{
    lightsInputs_ = lightsInputs;
    emit lightsInputsReceived(lightsInputs_);
}

void DriverControlsData::setMusicInputs(const unsigned char& musicInputs)
{
    musicInputs_ = musicInputs;
    emit musicInputsReceived(musicInputs_);
}

void DriverControlsData::setAcceleration(const unsigned short& acceleration)
{
    acceleration_ = acceleration;
    emit accelerationReceived(acceleration_);
}

void DriverControlsData::setRegenBraking(const unsigned short& regenBraking)
{
    regenBraking_ = regenBraking;
    emit regenBrakingReceived(regenBraking_);
}

void DriverControlsData::setDriverInputs(const unsigned char& driverInputs)
{
    driverInputs_ = driverInputs;
    emit driverInputsReceived(driverInputs_);
}
