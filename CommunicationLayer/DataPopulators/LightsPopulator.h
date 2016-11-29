#pragma once

#include <QObject>
#include "CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "DataLayer/LightsData/I_LightsData.h"

class LightsPopulator : public QObject
{
    Q_OBJECT
public:
    LightsPopulator(I_PacketDecoder& packetDecoder, I_LightsData& lightsData);

public slots:
    void populateData(const LightsMessage&);

private:
    I_PacketDecoder& packetDecoder_;
    I_LightsData& lightsData_;
};
