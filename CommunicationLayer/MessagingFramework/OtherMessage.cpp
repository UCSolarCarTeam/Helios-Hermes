#include "OtherMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace {
    const int GPS = 1;
}

OtherMessage::OtherMessage(const QByteArray& messageData)
    : messageData_(messageData)
{
}

unsigned char OtherMessage::getGps() const {
    return getUnsignedChar(messageData_, GPS);
}

QString OtherMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::Other) + ", ";
    return messageString;
}
