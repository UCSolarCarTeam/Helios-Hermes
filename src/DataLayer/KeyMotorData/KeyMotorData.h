#pragma once

#include "I_KeyMotorData.h"

class KeyMotorData : public I_KeyMotorData
{
public:
    KeyMotorData();
    virtual ~KeyMotorData();

    /*Data "Gets"*/
    unsigned char getM0Alive() const;
    float getM0SetCurrent() const;
    float getM0SetVelocity() const;
    float getM0BusCurrent() const;
    float getM0BusVoltage() const;
    float getM0VehicleVelocity() const;
    unsigned char getM1Alive() const;
    float getM1SetCurrent() const;
    float getM1SetVelocity() const;
    float getM1BusCurrent() const;
    float getM1BusVoltage() const;
    float getM1VehicleVelocity() const;

    /*KeyMotorData "Sets"*/
    void setM0Alive(const unsigned char& m0Alive);
    void setM0SetCurrent(const float& m0SetCurrent);
    void setM0SetVelocity(const float& m0SetVelocity);
    void setM0BusCurrent(const float& m0BusCurrent);
    void setM0BusVoltage(const float& m0BusVoltage);
    void setM0VehicleVelocity(const float& m0VehicleVelocity);
    void setM1Alive(const unsigned char& m1Alive);
    void setM1SetCurrent(const float& m1SetCurrent);
    void setM1SetVelocity(const float& m1SetVelocity);
    void setM1BusCurrent(const float& m1BusCurrent);
    void setM1BusVoltage(const float& m1BusVoltage);
    void setM1VehicleVelocity(const float& m1VehicleVelocity);

private:
    unsigned char m0Alive_;
    float m0SetCurrent_;
    float m0SetVelocity_;
    float m0BusCurrent_;
    float m0BusVoltage_;
    float m0VehicleVelocity_;
    unsigned char m1Alive_;
    float m1SetCurrent_;
    float m1SetVelocity_;
    float m1BusCurrent_;
    float m1BusVoltage_;
    float m1VehicleVelocity_;
};
