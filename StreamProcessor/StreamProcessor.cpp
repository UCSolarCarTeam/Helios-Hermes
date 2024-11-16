#include "StreamProcessor.h"

#include <QDebug>

StreamProcessor::StreamProcessor(SerialReciever* SerialReciever) {
    QObject::connect(SerialReciever, &SerialReciever::dataRecieved, this, &StreamProcessor::processData);
}

void StreamProcessor::processData(const QByteArray& data) {
    qDebug() << "Starting data processing";

    //append to data string

    //disect at 0x00

    //decode

    //checksum

    //identify and verify size then send to packet factory
}
