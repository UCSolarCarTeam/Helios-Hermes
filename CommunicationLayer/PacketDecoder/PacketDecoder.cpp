#include <QDebug>

#include "PacketDecoder.h"

namespace {
    const int ID_INDEX = 0;

    const int KEY_MOTOR_ID = 1;
    const int KEY_MOTOR_LENGTH = 4;

    const std::array<int, 2> packetLength = {
        -69,
        KEY_MOTOR_LENGTH
    };
}

PacketDecoder::PacketDecoder(const I_PacketChecksumChecker& checksumChecker) {
    connect(&checksumChecker, SIGNAL(validDataReceived(QByteArray)), this, SLOT(handleValidData(QByteArray)));
}

PacketDecoder::~PacketDecoder(){}

void PacketDecoder::handleValidData(QByteArray message){
    qDebug() << "DECODING PACKET" << message;

    const unsigned char id = message.at(ID_INDEX);

    if(packetLength[id] != message.length()){
        qWarning() << "Packet is invalid: (INVALID LENGTH) Found Length " << message.length()
                 << "When it should be " << packetLength[id]
                 << "For packet ID: " << id;
        return;
    }

    switch(id){
        case KEY_MOTOR_ID:
            emit packetDecoded(KeyMotorMessage(message));
            return;
        default:
            qWarning() << "Unkown Packet ID:" << id;
    }

    // if message length = to namespace length definition
}
