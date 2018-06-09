#pragma once

#include <QObject>
#include "CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "DataLayer/CcsData/I_CcsData.h"

class CcsPopulator : public QObject
{
    Q_OBJECT
public:
    CcsPopulator(I_PacketDecoder& packetDecoder,
                    I_CcsData& ccsData);
public slots:
    void populateData(const CcsMessage);

private:
    I_PacketDecoder& packetDecoder_;
    I_CcsData& ccsData_;
};
