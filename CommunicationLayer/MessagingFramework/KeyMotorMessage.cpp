#include "KeyMotorMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
    const int M_0_ALIVE = ''
    const int M_0_SET_CURRENT = ''
    const int M_0_SET_VELOCITY = ''
    const int M_0_BUS_CURRENT = ''
    const int M_0_BUS_VOLTAGE = ''
    const int M_0_VEHICLE_VELOCITY = ''
    const int M_1_ALIVE = ''
    const int M_1_SET_CURRENT = ''
    const int M_1_SET_VELOCITY = ''
    const int M_1_BUS_CURRENT = ''
    const int M_1_BUS_VOLTAGE = ''
    const int M_1_VEHICLE_VELOCITY = ''
}

KeyMotorMessage::KeyMotorMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

bool KeyMotorMessage::m0Alive() const
{
    return static_cast<bool>(messageData_.at(M_0_ALIVE));
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

QString KeyMotorMessage::toString() const
{
    QString messageString;
    messageString += QString::number(m0Alive()) + ", ";
    messageString += QString::number(m0SetCurrent()) + ", ";
    messageString += QString::number(m0SetVelocity()) + ", ";
    messageString += QString::number(m0BusCurrent()) + ", ";
    messageString += QString::number(m0BusVoltage()) + ", ";
    messageString += QString::number(m0VehicleVelocity()) + ", ";
    messageString += QString::number(m1Alive()) + ", ";
    messageString += QString::number(m1SetCurrent()) + ", ";
    messageString += QString::number(m1SetVelocity()) + ", ";
    messageString += QString::number(m1BusCurrent()) + ", ";
    messageString += QString::number(m1BusVoltage()) + ", ";
    messageString += QString::number(m1VehicleVelocity()) + ", ";
    return messageString;
}
