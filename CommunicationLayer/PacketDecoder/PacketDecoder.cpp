#include <QDebug>

#include "PacketDecoder.h"

namespace {
    const int ID_INDEX = 0;

    const int KEY_MOTOR_ID = 1;
    const int KEY_MOTOR_LENGTH = 4;

    const int MOTOR_DETAILS_0_ID = 2;
    const int MOTOR_DETAILS_0_LENGTH = 33;

    const int MOTOR_DETAILS_1_ID = 3;
    const int MOTOR_DETAILS_1_LENGTH = 33;

    const int B3_ID = 4;
    const int B3_LENGTH = 7;

    const int TELEMETRY_ID = 5;
    const int TELEMETRY_LENGTH = 33;

    const int BATTERY_FAULTS_ID = 6;
    const int BATTERY_FAULTS_LENGTH = 6;

    const int BATTERY_ID = 7;
    const int BATTERY_LENGTH = 48;

    const int MPPT_ID = 8;
    const int MPPT_LENGTH = 10;

    const int MBMS_ID = 9;
    const int MBMS_LENGTH = 26;

    const int PROXIMITY_SENSORS_ID = 10;
    const int PROXIMITY_SENSORS_LENGTH = 9;

    const std::array<int, 11> packetLength = {
        -69,
        KEY_MOTOR_LENGTH,
        MOTOR_DETAILS_0_LENGTH, 
        MOTOR_DETAILS_1_LENGTH,
        B3_LENGTH,
        TELEMETRY_LENGTH,
        BATTERY_FAULTS_LENGTH, 
        BATTERY_LENGTH, 
        MPPT_LENGTH, 
        MBMS_LENGTH,
        PROXIMITY_SENSORS_LENGTH
    };
}

PacketDecoder::PacketDecoder(const I_PacketChecksumChecker& checksumChecker) {
    connect(&checksumChecker, SIGNAL(validDataReceived(QByteArray)), this, SLOT(handleValidData(QByteArray)));
}

PacketDecoder::~PacketDecoder(){}

void PacketDecoder::handleValidData(QByteArray message){
    qDebug() << "DECODING PACKET" << message << " -- " << message.length();
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
        case MOTOR_DETAILS_0_ID:
            emit packetDecoded(MotorDetailsMessage(message, id));
            return;
        case MOTOR_DETAILS_1_ID:
            emit packetDecoded(MotorDetailsMessage(message, id));
            return;
        case B3_ID:
            emit packetDecoded(B3Message(message));
            return;
        case TELEMETRY_ID:
            emit packetDecoded(TelemetryMessage(message));
            return;
        case BATTERY_FAULTS_ID:
            emit packetDecoded(BatteryFaultsMessage(message));
            return;
        case BATTERY_ID:
            emit packetDecoded(BatteryMessage(message));
            return;
        case MPPT_ID:
            emit packetDecoded(MpptMessage(message));
            return;
        case MBMS_ID:
            emit packetDecoded(MbmsMessage(message));
            return;
        case PROXIMITY_SENSORS_ID:
            emit packetDecoded(ProximitySensorsMessage(message));
            return;
        default:
            qWarning() << "Unkown Packet ID:" << id;
    }
}
