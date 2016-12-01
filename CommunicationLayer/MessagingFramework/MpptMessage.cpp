#include "MpptMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
    const int MPPT_STATUS = 1;
    const int ARRAY_VOLTAGE = 2;
    const int ARRAY_CURRENT = 4;
    const int BATTERY_VOLTAGE = 6;
    const int TEMPERATURE = 8;
}

MpptMessage::MpptMessage(const QByteArray& messageData)
    : messageData_(messageData)
{

}

unsigned char MpptMessage::mpptStatus() const
{
    return getUnsignedChar(messageData_, MPPT_STATUS);
}

unsigned short MpptMessage::arrayVoltage() const
{
    return MessageDecodingHelpers::getUnsignedShort(messageData_, ARRAY_VOLTAGE);
}

unsigned short MpptMessage::arrayCurrent() const
{
    return MessageDecodingHelpers::getUnsignedShort(messageData_, ARRAY_CURRENT);
}

unsigned short MpptMessage::batteryVoltage() const
{
    return MessageDecodingHelpers::getUnsignedShort(messageData_, BATTERY_VOLTAGE);
}

unsigned short MpptMessage::temperature() const
{
    return MessageDecodingHelpers::getUnsignedShort(messageData_, TEMPERATURE);
}

QString MpptMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::Mppt) + ", ";
    messageString += QString::number(mpptStatus()) + ", ";
    messageString += QString::number(arrayVoltage()) + ", ";
    messageString += QString::number(arrayCurrent()) + ", ";
    messageString += QString::number(batteryVoltage()) + ", ";
    messageString += QString::number(temperature()) + ", ";
    return messageString;
}

