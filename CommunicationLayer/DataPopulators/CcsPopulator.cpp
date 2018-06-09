#include "CcsPopulator.h"

CcsPopulator::CcsPopulator(I_PacketDecoder& packetDecoder, I_CcsData& ccsData)
    : packetDecoder_(packetDecoder)
    , ccsData_(ccsData)
{
    connect(&packetDecoder_, SIGNAL(packetDecoded(const CcsMessage)), this, SLOT(populateData(const CcsMessage)));
}

void CcsPopulator::populateData(const CcsMessage message)
{
    ccsData_.setCcsAlive(message.ccsAlive());
}
