#include "CmuPopulator.h"

CmuPopulator::CmuPopulator(I_PacketDecoder& packetDecoder, I_CmuData& cmuData)
: packetDecoder_(packetDecoder), cmuData_(cmuData)
{
    connect(&packetDecoder_ SIGNAL(packetDecoded(const CmuMessage)), this, SLOT(populateData(const CmuMessage)));
}

void CmuPopulator::populateData(const CmuMessage message)
{
    I_CmuUnit* cmuUnit = cmuData_.getCmuUnit(message.cmuNumber());
    QList<unsigned short> cellVoltages = message.cellVoltages();
    QList<unsigned short> cellTemperatures = message.cellTemperatures();
    cmuUnit->setCell0Voltage(cellVoltage.pop_front());
    cmuUnit->setCell1Voltage(cellVoltage.pop_front());
    cmuUnit->setCell2Voltage(cellVoltage.pop_front());
    cmuUnit->setCell3Voltage(cellVoltage.pop_front());
    cmuUnit->setCell4Voltage(cellVoltage.pop_front());
    cmuUnit->setCell5Voltage(cellVoltage.pop_front());
    cmuUnit->setCell6Voltage(cellVoltage.pop_front());
    cmuUnit->setCell7Voltage(cellVoltage.pop_front());
    cmuUnit->setPcbTemp(message.pcbTemperature());
    cmuUnit->setCellTemp0(cellTemperature.pop_front());
    cmuUnit->setCellTemp1(cellTemperature.pop_front());
    cmuUnit->setCellTemp2(cellTemperature.pop_front());
    cmuUnit->setCellTemp3(cellTemperature.pop_front());
    cmuUnit->setCellTemp4(cellTemperature.pop_front());
    cmuUnit->setCellTemp5(cellTemperature.pop_front());
    cmuUnit->setCellTemp6(cellTemperature.pop_front());
    cmuUnit->setCellTemp7(cellTemperature.pop_front());
    cmuUnit->setCellTemp8(cellTemperature.pop_front());
    cmuUnit->setCellTemp9(cellTemperature.pop_front());
    cmuUnit->setCellTemp10(cellTemperature.pop_front());
    cmuUnit->setCellTemp11(cellTemperature.pop_front());
    cmuUnit->setCellTemp12(cellTemperature.pop_front());
    cmuUnit->setCellTemp13(cellTemperature.pop_front());
    cmuUnit->setCellTemp14(cellTemperature.pop_front());
}
