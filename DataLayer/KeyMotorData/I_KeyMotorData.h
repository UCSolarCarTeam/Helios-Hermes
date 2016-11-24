#pragma once

#include <QObject>

class I_KeyMotorData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_KeyMotorData() {}

    /*Data "Gets"*/
    virtual unsigned char KeyMotorData::getM0Alive() const = 0;
    virtual float KeyMotorData::getM0SetCurrent() const = 0;
    virtual float KeyMotorData::getM0SetVelocity() const = 0;
    virtual float KeyMotorData::getM0BusCurrent() const = 0;
    virtual float KeyMotorData::getM0BusVoltage() const = 0;
    virtual float KeyMotorData::getM0VehicleVelocity() const = 0;
    virtual unsigned char KeyMotorData::getM1Alive() const = 0;
    virtual float KeyMotorData::getM1SetCurrent() const = 0;
    virtual float KeyMotorData::getM1SetVelocity() const = 0;
    virtual float KeyMotorData::getM1BusCurrent() const = 0;
    virtual float KeyMotorData::getM1BusVoltage() const = 0;
    virtual float KeyMotorData::getM1VehicleVelocity() const = 0;


    /*KeyMotorData "Sets"*/
    virtual unsigned char KeyMotorData::setM0Alive(unsigned char& m0Alive);
    virtual float KeyMotorData::setM0SetCurrent(float& m0SetCurrent);
    virtual float KeyMotorData::setM0SetVelocity(float& m0SetVelocity);
    virtual float KeyMotorData::setM0BusCurrent(float& m0BusCurrent);
    virtual float KeyMotorData::setM0BusVoltage(float& m0BusVoltage);
    virtual float KeyMotorData::setM0VehicleVelocity(float& m0VehicleVelocity);
    virtual unsigned char KeyMotorData::setM1Alive(unsigned char& m1Alive);
    virtual float KeyMotorData::setM1SetCurrent(float& m1SetCurrent);
    virtual float KeyMotorData::setM1SetVelocity(float& m1SetVelocity);
    virtual float KeyMotorData::setM1BusCurrent(float& m1BusCurrent);
    virtual float KeyMotorData::setM1BusVoltage(float& m1BusVoltage);
    virtual float KeyMotorData::setM1VehicleVelocity(float& m1VehicleVelocity);

signals:

    void m0AliveReceived(unsigned char m0Alive);
    void m0SetCurrentReceived(float m0SetCurrent);
    void m0SetVelocityReceived(float m0SetVelocity);
    void m0BusCurrentReceived(float m0BusCurrent);
    void m0BusVoltageReceived(float m0BusVoltage);
    void m0VehicleVelocityReceived(float m0VehicleVelocity);
    void m1AliveReceived(unsigned char m1Alive);
    void m1SetCurrentReceived(float m1SetCurrent);
    void m1SetVelocityReceived(float m1SetVelocity);
    void m1BusCurrentReceived(float m1BusCurrent);
    void m1BusVoltageReceived(float m1BusVoltage);
    void m1VehicleVelocityReceived(float m1VehicleVelocity);
};
