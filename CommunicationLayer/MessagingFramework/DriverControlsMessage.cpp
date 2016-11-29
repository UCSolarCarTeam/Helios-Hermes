#include "DriverControlsMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
    const int DRIVER_CONTROLS_BOARD_ALIVE = 1;
    const int LIGHTS_INPUTS = 2;
    const int MUSIC_INPUTS = 3;
    const int ACCELERATION = 4;
    const int REGEN_BRAKING = 6;
    const int DRIVER_INPUTS = 8;
}

DriverControlsMessage::DriverControlsMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

unsigned char DriverControlsMessage::driverControlsBoardAlive() const
{
    return static_cast<bool>(messageData_.at(DRIVER_CONTROLS_BOARD_ALIVE));
}

unsigned char DriverControlsMessage::lightsInputs() const
{
    return getUnsignedChar(messageData_, LIGHTS_INPUTS);
}

unsigned char DriverControlsMessage::musicInputs() const
{
    return getUnsignedChar(messageData_, MUSIC_INPUTS);
}

unsigned short DriverControlsMessage::acceleration() const
{
    return getUnsignedShort(messageData_, ACCELERATION);
}

unsigned short DriverControlsMessage::regenBraking() const
{
    return getUnsignedShort(messageData_, REGEN_BRAKING);
}

unsigned char DriverControlsMessage::driverInputs() const
{
    return getUnsignedChar(messageData_, DRIVER_INPUTS);
}   

QString DriverControlsMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::DriverControls) + ", ";
    messageString += QString::number(driverControlsBoardAlive()) + ", ";
    messageString += QString::number(lightsInputs()) + ", ";
    messageString += QString::number(musicInputs()) + ", ";
    messageString += QString::number(acceleration()) + ", ";
    messageString += QString::number(regenBraking()) + ", ";
    messageString += QString::number(driverInputs()) + ", ";
    return messageString;
}

