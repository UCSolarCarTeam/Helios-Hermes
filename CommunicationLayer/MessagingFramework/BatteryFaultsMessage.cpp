#include "BatteryFaultsMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

namespace
{
    const int ERROR_FLAGS = 1;
}

BatteryFaultsMessage::BatteryFaultsMessage(unsigned char flags)
: messageData_(messageData)
{
    // Initialize messageData
}

unsigned char BatteryFaultsMessage::batteryFaultsFlags(const QByteArray& messageData) const
{
    return getUnsignedChar(messageData_.at(ERROR_FLAGS));
}

QString BatteryFaultsMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::BatteryFaults) + ", ";
    messageString += QString::number(batteryFaultsFlags()) + ", ";
    return messageString;
}
