#pragma once

#include <QObject>

class I_KeyMotorData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_KeyMotorData() {}

    /*Data "Gets"*/
    virtual unsigned char getM0Alive() const = 0;
    virtual float getM0SetCurrent() const = 0;
    virtual float getM0SetVelocity() const = 0;
    virtual float getM0BusCurrent() const = 0;
    virtual float getM0BusVoltage() const = 0;
    virtual float getM0VehicleVelocity() const = 0;
    virtual unsigned char getM1Alive() const = 0;
    virtual float getM1SetCurrent() const = 0;
    virtual float getM1SetVelocity() const = 0;
    virtual float getM1BusCurrent() const = 0;
    virtual float getM1BusVoltage() const = 0;
    virtual float getM1VehicleVelocity() const = 0;


    /*KeyMotorData "Sets"*/
    virtual unsigned char setM0Alive(unsigned char& m0Alive) = 0;
    virtual float setM0SetCurrent(float& m0SetCurrent) = 0;
    virtual float setM0SetVelocity(float& m0SetVelocity) = 0;
    virtual float setM0BusCurrent(float& m0BusCurrent) = 0;
    virtual float setM0BusVoltage(float& m0BusVoltage) = 0;
    virtual float setM0VehicleVelocity(float& m0VehicleVelocity) = 0;
    virtual unsigned char setM1Alive(unsigned char& m1Alive) = 0;
    virtual float setM1SetCurrent(float& m1SetCurrent) = 0;
    virtual float setM1SetVelocity(float& m1SetVelocity) = 0;
    virtual float setM1BusCurrent(float& m1BusCurrent) = 0;
    virtual float setM1BusVoltage(float& m1BusVoltage) = 0;
    virtual float setM1VehicleVelocity(float& m1VehicleVelocity) = 0;

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
