#include "OtherMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
    const int GPS_OFFSET = 1;
}

OtherMessage::OtherMessage(const QByteArray& messageData)
    : messageData_(messageData)
{
}

unsigned char OtherMessage::getGps() const
{
    return getUnsignedChar(messageData_, GPS_OFFSET);
}

QString OtherMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::Other) + ", ";
    return messageString;
}
