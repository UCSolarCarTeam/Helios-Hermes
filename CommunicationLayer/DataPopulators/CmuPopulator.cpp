#include "CmuPopulator.h"

CmuPopulator::CmuPopulator(I_PacketDecoder& packetDecoder, I_CmuData& cmuData)
: packetDecoder_(packetDecoder)
, cmuData_(cmuData)
{
    connect(&packetDecoder_, SIGNAL(packetDecoded(const CmuMessage)), this, SLOT(populateData(const CmuMessage)));
}

void CmuPopulator::populateData(const CmuMessage message)
{
    I_CmuUnit* cmuUnit = cmuData_.getCmuUnit(message.cmuNumber());
    QList<unsigned short> cellVoltages = message.cellVoltages();
    QList<unsigned short> cellTemperatures = message.cellTemperatures();
    for (int i = 0; i < cellVoltages.size(); i++)
    {
        cmuUnit->setCellVoltage(i, cellVoltages.pop_front());
    }
    cmuUnit->setPcbTemp(message.pcbTemperature());
    for (int i = 0; i < cellTemperatures.size(); i++)
    {
        cmuUnit->setCellTemp(i, cellTemperatures.pop_front());
    }
}
