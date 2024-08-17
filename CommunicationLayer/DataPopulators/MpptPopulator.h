#pragma once

#include <QObject>
#include "../../CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "../../DataLayer/MpptData/I_MpptData.h"

class MpptPopulator : public QObject
{
    Q_OBJECT
public:
    MpptPopulator(I_PacketDecoder& packetDecoder, I_MpptData& mpptData);

public slots:
    void populateData(const MpptMessage);

private:
    I_PacketDecoder& packetDecoder_;
    I_MpptData& mpptData_;
};
