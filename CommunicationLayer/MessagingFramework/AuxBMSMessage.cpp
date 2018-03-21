#include "AuxBMSMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
    const int PRECHARGE_STATE_OFFSET = 1;
    const int AUX_VOLTAGE_OFFSET = 2;
    const int AUX_BMS_ALIVE_OFFSET = 3;
    const int STROBE_BMS_LIGHT_OFFSET = 4;
    const int ALLOW_CHARGE_OFFSET = 5;
    const int CONTACTOR_ERROR_OFFSET = 6;
}

AuxBMSMessage::AuxBMSMessage(const QByteArray &messageData)
    : messageData_(messageData)
{
}

unsigned char AuxBMSMessage::prechargeState() const
{
    return getUnsignedChar(messageData_, PRECHARGE_STATE_OFFSET);
}
unsigned char AuxBMSMessage::auxVoltage() const
{
    return getUnsignedChar(messageData_, AUX_VOLTAGE_OFFSET);
}

bool AuxBMSMessage::auxBmsAlive() const
{
    return static_cast<bool>(messageData_.at(AUX_BMS_ALIVE_OFFSET));
}

bool AuxBMSMessage::strobeBmsLight() const
{
    return static_cast<bool>(messageData_.at(STROBE_BMS_LIGHT_OFFSET));
}

bool AuxBMSMessage::allowCharge() const
{
    return static_cast<bool>(messageData_.at(ALLOW_CHARGE_OFFSET));
}

bool AuxBMSMessage::contactorError() const
{
    return static_cast<bool>(messageData_.at(CONTACTOR_ERROR_OFFSET));
}

QString AuxBMSMessage::toString() const
{
    QString messageString;
    messageString += QString::number(MessageDefines::AUX_BMS) + ", ";
    messageString += QString::number(prechargeState()) + ", ";
    messageString += QString::number(auxVoltage()) + ", ";
    messageString += QString::number(auxBmsAlive()) + ", ";
    messageString += QString::number(strobeBmsLight()) + ", ";
    messageString += QString::number(allowCharge()) + ", ";
    messageString += QString::number(contactorError()) + ", ";
    return messageString;
}
