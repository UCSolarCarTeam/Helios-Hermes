#pragma once

#include "I_KeyMotorData.h"

class FakeKeyMotorData : public I_KeyMotorData
{
public:
    FakeKeyMotorData();
    virtual ~FakeKeyMotorData();

    /*Data "Gets"*/
    unsigned char KeyMotorData::getM0Alive() const;
    float KeyMotorData::getM0SetCurrent() const;
    float KeyMotorData::getM0SetVelocity() const;
    float KeyMotorData::getM0BusCurrent() const;
    float KeyMotorData::getM0BusVoltage() const;
    float KeyMotorData::getM0VehicleVelocity() const;
    unsigned char KeyMotorData::getM1Alive() const;
    float KeyMotorData::getM1SetCurrent() const;
    float KeyMotorData::getM1SetVelocity() const;
    float KeyMotorData::getM1BusCurrent() const;
    float KeyMotorData::getM1BusVoltage() const;
    float KeyMotorData::getM1VehicleVelocity() const;

    /*KeyMotorData "Sets"*/
    void KeyMotorData::setM0Alive(const unsigned char& m0Alive);
    void KeyMotorData::setM0SetCurrent(const float& m0SetCurrent);
    void KeyMotorData::setM0SetVelocity(const float& m0SetVelocity);
    void KeyMotorData::setM0BusCurrent(const float& m0BusCurrent);
    void KeyMotorData::setM0BusVoltage(const float& m0BusVoltage);
    void KeyMotorData::setM0VehicleVelocity(const float& m0VehicleVelocity);
    void KeyMotorData::setM1Alive(const unsigned char& m1Alive);
    void KeyMotorData::setM1SetCurrent(const float& m1SetCurrent);
    void KeyMotorData::setM1SetVelocity(const float& m1SetVelocity);
    void KeyMotorData::setM1BusCurrent(const float& m1BusCurrent);
    void KeyMotorData::setM1BusVoltage(const float& m1BusVoltage);
    void KeyMotorData::setM1VehicleVelocity(const float& m1VehicleVelocity);
}