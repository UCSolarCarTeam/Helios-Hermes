#include "MpptDataMessage.h"
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

unsigned char MpptDataMessage::mpptStatus() const
{
    return getUnsignedChar(messageData_, MPPT_STATUS);
}

unsigned short MpptDataMessage::arrayVoltage() const
{
    return getUnsignedShort(messageData_, ARRAY_VOLTAGE);
}

unsigned short MpptDataMessage::arrayCurrent() const
{
    return getUnsignedShort(messageData_, ARRAY_CURRENT);
}

unsigned short MpptDataMessage::batteryVoltage() const
{
    return getUnsignedShort(messageData_, BATTERY_VOLTAGE);
}

unsigned short MpptDataMessage::temperature() const
{
    return getUnsignedShort(messageData_, TEMPERATURE);
}

QString MpptDataMessage::toString() const
{
    QString messageString;
    messageString += QString::number(mpptStatus()) + ", ";
    messageString += QString::number(arrayVoltage()) + ", ";
    messageString += QString::number(arrayCurrent()) + ", ";
    messageString += QString::number(batteryVoltage()) + ", ";
    messageString += QString::number(temperature()) + ", ";
}

