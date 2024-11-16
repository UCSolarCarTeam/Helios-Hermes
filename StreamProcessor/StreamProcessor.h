#ifndef STREAMPROCESSOR_H
#define STREAMPROCESSOR_H

#include "../SerialReciever/SerialReciever.h"

#include <QObject>
#include <QByteArray>

class StreamProcessor : public QObject{
    Q_OBJECT
public:
    StreamProcessor(SerialReciever* serialReciever);

public slots:
    void processData(const QByteArray& data);

private:
    QByteArray extractPacket();
    QByteArray decodePacket(QByteArray packet);
    bool isValidChecksum(QByteArray& decodedPacket);

    QByteArray buffer_;
};

#endif // STREAMPROCESSOR_H
