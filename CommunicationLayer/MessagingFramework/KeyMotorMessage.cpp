#include "KeyMotorData.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"
// TODO make sure messageDefines has right ID's

using namespace MessageDecodingHelpers;

namespace
{
    const int M_0_ALIVE = 1;
    const int M_0_SET_CURRENT = 2;
    const int M_0_SET_VELOCITY = 6;
    const int M_0_BUS_CURRENT = 10;
    const int M_0_BUS_VOLTAGE = 14;
    const int M_0_VEHICLE_VELOCITY = 18;
    const int M_1_ALIVE = 22;
    const int M_1_SET_CURRENT = 23;
    const int M_1_SET_VELOCITY = 27;
    const int M_1_BUS_CURRENT = 31;
    const int M_1_BUS_VOLTAGE = 35;
    const int M_1_VEHICLE_VELOCITY = 39;
}

KeyMotorMessage::KeyMotorMessage(const QByteArray& messageData)
: messageData_(messageData);
{
}

bool KeyMotorMessage::m0Alive() const
{
    return static_cast<bool>(messageData_.at(M_0_ALIVE);
}

float KeyMotorMessage::m0SetCurrent() const
{
    return getFloat(messageData_, M_0_SET_CURRENT);
}

float KeyMotorMessage::m0SetVelocity() const
{
    return getFloat(messageData_, M_0_SET_VELOCITY);
}

float KeyMotorMessage::m0BusCurrent() const
{
    return getFloat(messageData_, M_0_BUS_CURRENT);
}

float KeyMotorMessage::m0BusVoltage() const
{
    return getFloat(messageData_, M_0_BUS_VOLTAGE);
}

float KeyMotorMessage::m0VehicleVelocity() const
{
    return getFloat(messageData_, M_0_VEHICLE_VELOCITY);
}

bool KeyMotorMessage::m1Alive() const
{
    return static_cast<bool>(messageData_.at(M_1_ALIVE));
}

float KeyMotorMessage::m1SetCurrent() const
{
    return getFloat(messageData_, M_1_SET_CURRENT);
}

float KeyMotorMessage::m1SetVelocity() const
{
    return getFloat(messageData_, M_1_SET_VELOCITY);
}

float KeyMotorMessage::m1BusCurrent() const
{
    return getFloat(messageData_, M_1_BUS_CURRENT);
}

float KeyMotorMessage::m1BusVoltage() const
{
    return getFloat(messageData_, M_1_BUS_VOLTAGE);
}

float KeyMotorMessage::m1VehicleVelocity() const
{
    return getFloat(messageData_, M_1_VEHICLE_VELOCITY);
}
