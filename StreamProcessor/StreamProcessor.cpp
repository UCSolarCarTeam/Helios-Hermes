#include "StreamProcessor.h"

#include <QDebug>

namespace {
    const char FRAMING_BYTE = 0x00;

    const int MIN_PACKET_LENGTH = 4; //TODO: set to smallest packet
}

/** 
 * Takes in serialReciever to connect signal and slot for data recieved 
 * and packetFactory to store all packet data in a single instance 
 */
StreamProcessor::StreamProcessor(SerialReciever* SerialReciever, PacketFactory* packetFactory) : packetFactory_(packetFactory) {
    buffer_.resize(1);
    buffer_.fill(FRAMING_BYTE);
    QObject::connect(SerialReciever, &SerialReciever::dataRecieved, this, &StreamProcessor::processData);
}

/** 
 * Processes data recieved from serial port
 * Fired every time data is recieved from serial port
 * 
 * Data is processed in the following steps:
 * 1. Append data to buffer
 * 2. Extract packet from buffer
 * 3. Decode packet
 * 4. Check checksum
 * 5. Identify and verify size then send to packet factory
 */
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

    //decode packet
    QByteArray decodedPacket = decodePacket(bytePacket);

    if(decodedPacket.isNull()) {
        qDebug() << "Packet is too small - figure it out: " << bytePacket;
        return;
    };

    //checksum
    if(!isValidChecksum(decodedPacket)) return;

    

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

/** 
 * Decodes the byte packet to insert 0x00s into there proper position 
 * 
 * Packets recieved have been encoded using bytestuffing. This function unstuffs
 * the packet.
 * 
 * First byte of packet points to the index of where the next 0x00 should be.
 * Then that byte points to the next encoded zero and so on until the 
 * end of packet is reached.
 * */
QByteArray StreamProcessor::decodePacket(QByteArray packet) {

    QByteArray decodedPacket;
    const int length = packet.size();
    int indexOfZero = 0;

    if(length < MIN_PACKET_LENGTH) return NULL;

    while(indexOfZero < length) {
        const int indexOfNextZero = static_cast<unsigned char>(packet.at(indexOfZero)) + indexOfZero;

        // appends between current zero and next zero
        for (int i = indexOfZero + 1; i < indexOfNextZero && i < length; ++i) {
            decodedPacket.append(packet.at(i));
        }

        // replaces encoded value with 0x00
        if(indexOfNextZero < 0xFF && indexOfNextZero < length){
            decodedPacket.append(char(0x00));
        }

        indexOfZero = indexOfNextZero;
    }

    return decodedPacket;
}

/** Checks if Checksum (last 2 bytes at this stage) is valid and drops those bytes from the packet */
bool StreamProcessor::isValidChecksum(QByteArray& decodedPacket){
    const int endOfPacketIndex = decodedPacket.size() - 1;

    //extract last 2 bytes in checksum and flip
    const quint16 checksum = (static_cast<quint16>(decodedPacket.at(endOfPacketIndex - 1)) & 0xFF) |
                        (static_cast<quint16>(decodedPacket.at(endOfPacketIndex)) << 8);

    //remove checksum bytes from packet
    decodedPacket.chop(sizeof(checksum));

    const quint16 calculatedChecksum = qChecksum(QByteArrayView(decodedPacket));

    if(calculatedChecksum == checksum){
        qDebug() << "Checksum Passed";
        return true;
    }

    qDebug() << "Calculated =" << QByteArray::number(calculatedChecksum, 16) 
             << "retrieved =" << QByteArray::number(checksum, 16);
    qDebug() << "Error decoding data, checksum doesn't match. Data is: " << decodedPacket;

    return false;
}
