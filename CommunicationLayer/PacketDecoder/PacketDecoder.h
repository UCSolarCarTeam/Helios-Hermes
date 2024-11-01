#ifndef PACKETDECODER_H
#define PACKETDECODER_H

#include <QObject>

#include "I_PacketDecoder.h"
#include "../PacketChecksumChecker/I_PacketChecksumChecker.h"

class PacketDecoder : public I_PacketDecoder {
    Q_OBJECT
public:
    explicit PacketDecoder(const I_PacketChecksumChecker& checksumChecker);
    virtual ~PacketDecoder();

private slots:
    void handleValidData(QByteArray message);
};

#endif // PACKETDECODER_H
