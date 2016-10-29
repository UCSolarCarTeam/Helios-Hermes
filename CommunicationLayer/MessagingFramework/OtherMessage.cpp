#include "OtherMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

OtherMessage::OtherMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

QString OtherMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::OtherData) + ", ";
    return messageString;
}
