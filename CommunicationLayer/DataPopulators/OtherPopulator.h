#pragma once

#include <QObject>
#include "CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "DataLayer/OtherData/I_OtherData.h"

class OtherPopulator : public QObject
{
    Q_OBJECT
public:
    OtherPopulator(I_PacketDecoder& packetDecoder, I_OtherData& otherData);

public slots:
    void populateData(const OtherMessage);

private:
    I_PacketDecoder& packetDecoder_;
    I_OtherData& otherData_;
};
