#include <QDebug>

#include "PacketDecoder.h"
#include "../PacketChecksumChecker/I_PacketChecksumChecker.h"
#include "../MessagingFramework/MessageDefines.h"

namespace
{
    const int INDEX_OF_PACKET_TYPE = 0;
}

PacketDecoder::PacketDecoder(const I_PacketChecksumChecker& checksumChecker)
{
    connect(&checksumChecker, SIGNAL(validDataReceived(QByteArray)),
            this, SLOT(handleValidData(QByteArray)));
}

PacketDecoder::~PacketDecoder()
{
}

void PacketDecoder::handleValidData(QByteArray messageData)
{
    MessageDefines::Type messageType =
        static_cast<MessageDefines::Type>(messageData.at(INDEX_OF_PACKET_TYPE));

    if (MessageDefines::getLengthForMessage(messageType) == messageData.size())
    {
        switch (messageType)
        {
            case MessageDefines::KeyMotor:
                emit packetDecoded(KeyMotorMessage(messageData));
                return;

            case MessageDefines::Motor0Details:
            case MessageDefines::Motor1Details:
                emit packetDecoded(MotorDetailsMessage(messageData));
                return;

            case MessageDefines::DriverControls:
                emit packetDecoded(DriverControlsMessage(messageData));
                return;

            case MessageDefines::MotorFaults:
                emit packetDecoded(MotorFaultsMessage(messageData));
                return;

            case MessageDefines::BatteryFaults:
                emit packetDecoded(BatteryFaultsMessage(messageData));
                return;

            case MessageDefines::Battery:
                emit packetDecoded(BatteryMessage(messageData));
                return;

            case MessageDefines::Cmu:
                emit packetDecoded(CmuMessage(messageData));
                return;

            case MessageDefines::Mppt:
                emit packetDecoded(MpptMessage(messageData));
                return;

            case MessageDefines::Lights:
                emit packetDecoded(LightsMessage(messageData));
                return;

            case MessageDefines::Other:
                emit packetDecoded(OtherMessage(messageData));
                return;

        }
    }
    else
    {
        qDebug() << "Message length is not correct for type" << static_cast<quint8>(messageType);
        qDebug() << "Actual" << messageData.size() << "Expected" << MessageDefines::getLengthForMessage(messageType);
    }
}
