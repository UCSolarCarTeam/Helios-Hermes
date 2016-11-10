#pragma once

#include <QObject>
#include "CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "DataLayer/CmuData/I_CmuData.h"
#include "DataLayer/CmuData/I_CmuUnit.h"

class CmuPopulator : public QObject
{
    Q_OBJECT
public:
    CmuPopulator(I_PacketDecoder& packetDecoder,
                 I_CmuData& cmuData);

public slots:
    void populateData(const CmuDataMessage);

private:
    QList<double> convertFloatListToDouble(QList<float> floatList);
    I_PacketDecoder& packetDecoder_;
    I_CmuData& cmuData;
};
