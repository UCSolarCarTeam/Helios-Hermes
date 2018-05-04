#include "MpptUnit.h"

MpptUnit::MpptUnit()
    : mpptStatus_(0)
    , arrayVoltage_(0)
    , arrayCurrent_(0)
    , batteryVoltage_(0)
    , temperature_(0)
{
    //  Initialize to 0
}

MpptUnit::~MpptUnit()
{
}

/* MpptUnit Gets */
unsigned char MpptUnit::getMpptStatus() const
{
    return mpptStatus_;
}

unsigned short MpptUnit::getArrayVoltage() const
{
    return arrayVoltage_;
}

unsigned short MpptUnit::getArrayCurrent() const
{
    return arrayCurrent_;
}

unsigned short MpptUnit::getBatteryVoltage() const
{
    return batteryVoltage_;
}

unsigned short MpptUnit::getTemperature() const
{
    return temperature_;
}


/* MpptUnit Sets */
void MpptUnit::setMpptStatus(const unsigned char& mpptStatus)
{
    mpptStatus_ = mpptStatus;
    emit mpptStatusReceived(mpptStatus_);
}

void MpptUnit::setArrayVoltage(const unsigned short& arrayVoltage)
{
    arrayVoltage_ = (arrayVoltage * 100);
    emit arrayVoltageReceived(arrayVoltage_);
}

void MpptUnit::setArrayCurrent(const unsigned short& arrayCurrent)
{
    arrayCurrent_ = (arrayCurrent * 1000);
    emit arrayCurrentReceived(arrayCurrent_);
}

void MpptUnit::setBatteryVoltage(const unsigned short& batteryVoltage)
{
    batteryVoltage_ = (batteryVoltage * 100);
    emit batteryVoltageReceived(batteryVoltage_);
}

void MpptUnit::setTemperature(const unsigned short& temperature)
{
    temperature_ = (temperature * 100);
    emit temperatureReceived(temperature_);
}


