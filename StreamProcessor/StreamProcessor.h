#ifndef STREAMPROCESSOR_H
#define STREAMPROCESSOR_H

#include "../SerialReciever/SerialReciever.h"
#include "../PacketFactory/PacketFactory.h"

#include <QObject>
#include <QByteArray>

class StreamProcessor : public QObject{
    Q_OBJECT
public:
    StreamProcessor(SerialReciever* serialReciever, PacketFactory* packetFactory);

public slots:
    void processData(const QByteArray& data);

private:
    QByteArray extractPacket();
    QByteArray decodePacket(QByteArray packet);
    bool isValidChecksum(QByteArray& decodedPacket);

    QByteArray buffer_;
    PacketFactory* packetFactory_;
};

#endif // STREAMPROCESSOR_H
