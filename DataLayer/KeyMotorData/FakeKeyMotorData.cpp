#include "FakeKeyMotorData.h"

FakeKeyMotorData::FakeKeyMotorData()
{
}

FakeKeyMotorData::~FakeKeyMotorData()
{
}


/*Data "Gets"*/
unsigned char KeyMotorData::getM0Alive() const
{
    return 1;
}

float KeyMotorData::getM0SetCurrent() const
{
    return 2;
}

float KeyMotorData::getM0SetVelocity() const
{
    return 3;
}

float KeyMotorData::getM0BusCurrent() const
{
    return 4;
}

float KeyMotorData::getM0BusVoltage() const
{
    return 5;
}

float KeyMotorData::getM0VehicleVelocity() const
{
    return 6;
}

unsigned char KeyMotorData::getM1Alive() const
{
    return 1;
}

float KeyMotorData::getM1SetCurrent() const
{
    return 7;
}

float KeyMotorData::getM1SetVelocity() const
{
    return 8;
}

float KeyMotorData::getM1BusCurrent() const
{
    return 9;
}

float KeyMotorData::getM1BusVoltage() const
{
    return 10;
}

float KeyMotorData::getM1VehicleVelocity() const
{
    return 11;
}


/*KeyMotorData "Sets"*/
void FakeKeyMotorData::setM0Alive(const unsigned char& m0Alive) {}
void FakeKeyMotorData::setM0SetCurrent(const float& m0SetCurrent) {}
void FakeKeyMotorData::setM0SetVelocity(const float& m0SetVelocity) {}
void FakeKeyMotorData::setM0BusCurrent(const float& m0BusCurrent) {}
void FakeKeyMotorData::setM0BusVoltage(const float& m0BusVoltage) {}
void FakeKeyMotorData::setM0VehicleVelocity(const float& m0VehicleVelocity) {}
void FakeKeyMotorData::setM1Alive(const unsigned char& m1Alive) {}
void FakeKeyMotorData::setM1SetCurrent(const float& m1SetCurrent) {}
void FakeKeyMotorData::setM1SetVelocity(const float& m1SetVelocity) {}
void FakeKeyMotorData::setM1BusCurrent(const float& m1BusCurrent) {}
void FakeKeyMotorData::setM1BusVoltage(const float& m1BusVoltage) {}
void FakeKeyMotorData::setM1VehicleVelocity(const float& m1VehicleVelocity) {}
