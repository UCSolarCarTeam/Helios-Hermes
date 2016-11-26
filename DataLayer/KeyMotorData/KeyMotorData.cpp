#include "KeyMotorData.h"

KeyMotorData::KeyMotorData()
    : m0Alive_(0)
    , m0SetCurrent_(0)
    , m0SetVelocity_(0)
    , m0BusCurrent_(0)
    , m0BusVoltage_(0)
    , m0VehicleVelocity_(0)
    , m1Alive_(0)
    , m1SetCurrent_(0)
    , m1SetVelocity_(0)
    , m1BusCurrent_(0)
    , m1BusVoltage_(0)
    , m1VehicleVelocity_(0)

{
    // initialize to 0
}

KeyMotorData::~KeyMotorData()
{
}

/*Data "Gets"*/
unsigned char KeyMotorData::getM0Alive() const
{
    return m0Alive_;
}

float KeyMotorData::getM0SetCurrent() const
{
    return m0SetCurrent_;
}

float KeyMotorData::getM0SetVelocity() const
{
    return m0SetVelocity_;
}

float KeyMotorData::getM0BusCurrent() const
{
    return m0BusCurrent_;
}

float KeyMotorData::getM0BusVoltage() const
{
    return m0BusVoltage_;
}

float KeyMotorData::getM0VehicleVelocity() const
{
    return m0VehicleVelocity_;
}

unsigned char KeyMotorData::getM1Alive() const
{
    return m1Alive_;
}

float KeyMotorData::getM1SetCurrent() const
{
    return m1SetCurrent_;
}

float KeyMotorData::getM1SetVelocity() const
{
    return m1SetVelocity_;
}

float KeyMotorData::getM1BusCurrent() const
{
    return m1BusCurrent_;
}

float KeyMotorData::getM1BusVoltage() const
{
    return m1BusVoltage_;
}

float KeyMotorData::getM1VehicleVelocity() const
{
    return m1VehicleVelocity_;
}


/*KeyMotorData "Sets"*/
void KeyMotorData::setM0Alive(const unsigned char& m0Alive)
{
    m0Alive_ = m0Alive;
    emit m0AliveReceived(m0Alive_);
}

void KeyMotorData::setM0SetCurrent(const float& m0SetCurrent)
{
    m0SetCurrent_ = m0SetCurrent;
    emit m0SetCurrentReceived(m0SetCurrent_);
}

void KeyMotorData::setM0SetVelocity(const float& m0SetVelocity)
{
    m0SetVelocity_ = m0SetVelocity;
    emit m0SetVelocityReceived(m0SetVelocity_);
}

void KeyMotorData::setM0BusCurrent(const float& m0BusCurrent)
{
    m0BusCurrent_ = m0BusCurrent;
    emit m0BusCurrentReceived(m0BusCurrent_);
}

void KeyMotorData::setM0BusVoltage(const float& m0BusVoltage)
{
    m0BusVoltage_ = m0BusVoltage;
    emit m0BusVoltageReceived(m0BusVoltage_);
}

void KeyMotorData::setM0VehicleVelocity(const float& m0VehicleVelocity)
{
    m0VehicleVelocity_ = m0VehicleVelocity;
    emit m0VehicleVelocityReceived(m0VehicleVelocity_);
}

void KeyMotorData::setM1Alive(const unsigned char& m1Alive)
{
    m1Alive_ = m1Alive;
    emit m1AliveReceived(m1Alive_);
}

void KeyMotorData::setM1SetCurrent(const float& m1SetCurrent)
{
    m1SetCurrent_ = m1SetCurrent;
    emit m1SetCurrentReceived(m1SetCurrent_);
}

void KeyMotorData::setM1SetVelocity(const float& m1SetVelocity)
{
    m1SetVelocity_ = m1SetVelocity;
    emit m1SetVelocityReceived(m1SetVelocity_);
}

void KeyMotorData::setM1BusCurrent(const float& m1BusCurrent)
{
    m1BusCurrent_ = m1BusCurrent;
    emit m1BusCurrentReceived(m1BusCurrent_);
}

void KeyMotorData::setM1BusVoltage(const float& m1BusVoltage)
{
    m1BusVoltage_ = m1BusVoltage;
    emit m1BusVoltageReceived(m1BusVoltage_);
}

void KeyMotorData::setM1VehicleVelocity(const float& m1VehicleVelocity)
{
    m1VehicleVelocity_ = m1VehicleVelocity;
    emit m1VehicleVelocityReceived(m1VehicleVelocity_);
}


