#ifndef KEYMOTORPOPULATOR_H
#define KEYMOTORPOPULATOR_H

#include <QObject>
#include "../../CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "../../DataLayer/KeyMotorData/KeyMotorData.h"

class KeyMotorPopulator : public QObject {
    Q_OBJECT
public:
    KeyMotorPopulator(I_PacketDecoder& packetDecoder, KeyMotorData& data);

public slots:
    void populatorData(const KeyMotorMessage);

private:
    I_PacketDecoder& packetDecoder_;
    KeyMotorData& data_;
};

#endif // KEYMOTORPOPULATOR_H
