#include "MpptUnit.h"

namespace {
    const int CENTI_TO_ONES = 100;
    const int MILLI_TO_ONES = 1000;
}

MpptUnit::MpptUnit() {}

MpptUnit::~MpptUnit() {}

unsigned char MpptUnit::mpptStatus() const
{
    return mpptStatus_;
}

void MpptUnit::setMpptStatus(const unsigned char newMpptStatus)
{
    mpptStatus_ = newMpptStatus;
}

float MpptUnit::arrayVoltage() const
{
    return arrayVoltage_;
}

void MpptUnit::setArrayVoltage(const unsigned short newArrayVoltage)
{
    arrayVoltage_ =  static_cast<float>(newArrayVoltage) / CENTI_TO_ONES;
}

float MpptUnit::arrayCurrent() const
{
    return arrayCurrent_;
}

void MpptUnit::setArrayCurrent(const unsigned short newArrayCurrent)
{
    arrayCurrent_ = static_cast<float>(newArrayCurrent) / MILLI_TO_ONES;
}

float MpptUnit::batteryVoltage() const
{
    return batteryVoltage_;
}

void MpptUnit::setBatteryVoltage(const unsigned short newBatteryVoltage)
{
    batteryVoltage_ = static_cast<float>(newBatteryVoltage) / CENTI_TO_ONES;
}

float MpptUnit::temperature() const
{
    return temperature_;
}

void MpptUnit::setTemperature(const unsigned short newTemperature)
{
    temperature_ = static_cast<float>(newTemperature) / CENTI_TO_ONES;
}
