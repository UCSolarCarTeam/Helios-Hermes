#pragma once

#include <QObject>
#include "../../CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "../../DataLayer/KeyMotorData/I_KeyMotorData.h"

class KeyMotorPopulator : public QObject
{
    Q_OBJECT
public:
    KeyMotorPopulator(I_PacketDecoder& packetDecoder, I_KeyMotorData& keyMotorData);

public slots:
    void populateData(const KeyMotorMessage);

private:
    I_PacketDecoder& packetDecoder_;
    I_KeyMotorData& keyMotorData_;
};
