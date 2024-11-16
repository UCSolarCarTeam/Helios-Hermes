#include "StreamProcessor.h"

#include <QDebug>

namespace {
    const char FRAMING_BYTE = 0x00;
}

StreamProcessor::StreamProcessor(SerialReciever* SerialReciever) {
    buffer_.resize(1);
    buffer_.fill(FRAMING_BYTE);
    QObject::connect(SerialReciever, &SerialReciever::dataRecieved, this, &StreamProcessor::processData);
}

void StreamProcessor::processData(const QByteArray& data) {
    qDebug() << "Starting data processing";

    //append to data string
    buffer_.append(data);

    //disect at 0x00
    QByteArray bytePacket = extractPacket();

    if(bytePacket.isNull()) {
        qDebug() << "Failed to Extract Packet from buffer: " << buffer_;
        return;
    };

    qDebug() << "Made it this far: " << bytePacket;
    //decode

    //checksum

    //identify and verify size then send to packet factory
}

/** Extract bytes between FRAMING_BYTES (this is a packet) */
QByteArray StreamProcessor::extractPacket() {
    while (true) {
        //Find start of packet at the framing byte
        int startOfPacketIndex = buffer_.indexOf(FRAMING_BYTE);

        if(startOfPacketIndex == -1) return NULL;

        buffer_ = buffer_.mid(startOfPacketIndex);

        //Find end of packet (next occurance of framing byte)
        int endOfPacketIndex = buffer_.indexOf(FRAMING_BYTE, 1);

        if(endOfPacketIndex == -1) return NULL;

        //extract packet and remove from buffer
        QByteArray packet = buffer_.mid(1, endOfPacketIndex - 1);
        buffer_.remove(0, endOfPacketIndex);

        return packet;
    }
}