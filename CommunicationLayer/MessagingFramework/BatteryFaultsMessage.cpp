#include "BatteryFaultsMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
    const int ERROR_FLAGS = 1;
}

BatteryFaultsMessage::BatteryFaultsMessage(QByteArray& messageData)
    : messageData_(messageData)
{
    // Initialize messageData
}

unsigned char BatteryFaultsMessage::batteryFaultsFlags() const
{
    return getUnsignedChar(messageData_, ERROR_FLAGS);
}

QString BatteryFaultsMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::BatteryFaults) + ", ";
    messageString += QString::number(batteryFaultsFlags()) + ", ";
    return messageString;
}
