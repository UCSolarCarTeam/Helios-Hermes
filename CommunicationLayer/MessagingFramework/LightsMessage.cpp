#include "LightsMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
    const int LIGHT_STATUS = 1;
}

LightsMessage::LightsMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

unsigned char LightsMessage::lightStatus() const
{
    return getUnsignedChar(messageData_, LIGHT_STATUS);
}

QString LightsMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::Lights) + ", ";
    messageString += QString::number(lightStatus()) + ", ";
    return messageString;
}
