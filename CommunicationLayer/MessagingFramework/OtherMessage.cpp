#include "OtherMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

OtherMessage::OtherMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

QString OtherMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::Other) + ", ";
    return messageString;
}
