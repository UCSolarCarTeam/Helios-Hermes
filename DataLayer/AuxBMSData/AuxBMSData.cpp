#include "AuxBMSData.h"

namespace name
{

}

AuxBMSData::AuxBMSData()
    : prechargeState_(AuxBMSData::PrechargeState::IDLE)
    , auxVoltage_()
    , auxBmsAlive_(false)
    , strobeBmsLight_(false)
    , allowCharge_(false)
    , contactorError_(false)
{

}

AuxBMSData::~AuxBMSData()
{
}

/*Data "Gets"*/
AuxBMSData::PrechargeState AuxBMSData::getPrechargeState() const
{
    return prechargeState_;
}

unsigned char AuxBMSData::getAuxVoltage() const
{
    return auxVoltage_;
}

bool AuxBMSData::getAuxBmsAlive() const
{
    return auxBmsAlive_;
}

bool AuxBMSData::getStrobeBmsLight() const
{
    return strobeBmsLight_;
}

bool AuxBMSData::getAllowCharge() const
{
    return allowCharge_;
}

bool AuxBMSData::getContactorError() const
{
    return contactorError_;
}

/*AuxBMSData "Sets"*/
void AuxBMSData::setPrechargeState(const unsigned char& prechargeState)
{
    prechargeState_ = static_cast<PrechargeState>(prechargeState);
    emit prechargeStateReceived(prechargeState_);
}

void AuxBMSData::setAuxVoltage(const unsigned char& auxVoltage)
{
    auxVoltage_ = auxVoltage;
    emit auxVoltageReceived(auxVoltage_);
}

void AuxBMSData::setAuxBmsAlive(const bool& auxBmsAlive)
{
    auxBmsAlive_ = auxBmsAlive;
    emit auxBmsAliveReceived(auxBmsAlive_);
}

void AuxBMSData::setStrobeBmsLight(const bool& strobeBmsLight)
{
    strobeBmsLight_ = strobeBmsLight;
    emit strobeBmsLightRecieved(strobeBmsLight_);
}

void AuxBMSData::setAllowCharge(const bool& allowCharge)
{
    allowCharge_ = allowCharge;
    emit allowChargeRecieved(allowCharge_);
}

void AuxBMSData::setContactorError(const bool& contactorError)
{
    contactorError_ = contactorError;
    emit contactorErrorRecieved(contactorError_);
}
