#pragma once

#include <QObject>
#include "CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "DataLayer/AuxBMSData/I_AuxBMSData.h"

class AuxBMSPopulator : public QObject
{
    Q_OBJECT
public:
    AuxBMSPopulator(I_PacketDecoder& packetDecoder,
                    I_AuxBMSData& auxBmsData);
public slots:
    void populateData(const AuxBMSMessage);

private:
    I_PacketDecoder& packetDecoder_;
    I_AuxBMSData& auxBmsData_;
};
