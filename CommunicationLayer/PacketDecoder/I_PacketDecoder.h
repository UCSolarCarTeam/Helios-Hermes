#ifndef I_PACKETDECODER_H
#define I_PACKETDECODER_H

#include <QObject>

#include "../MessagingFramework/KeyMotorMessage.h"
#include "../MessagingFramework/ProximitySensorsMessage.h"
#include "../MessagingFramework/B3Message.h"

class I_PacketDecoder : public QObject{
    Q_OBJECT
public:
    virtual ~I_PacketDecoder(){}

signals:
    void packetDecoded(const KeyMotorMessage);
    void packetDecoded(const ProximitySensorsMessage);
    void packetDecoded(const B3Message);
};

#endif // I_PACKETDECODER_H
