#include "OtherPopulator.h"

OtherPopulator::OtherPopulator(I_PacketDecoder& packetDecoder, I_OtherData& otherData)
: packetDecoder_(packetDecoder)
, otherData_(otherData)
{
    connect(&packetDecoder_, SIGNAL(packetDecoded(const OtherMessage)), this, SLOT(populateData(const OtherMessage)));
}

void OtherPopulator::populateData(const OtherMessage& message)
{
    otherData_.setGps(message.getGps());
}
