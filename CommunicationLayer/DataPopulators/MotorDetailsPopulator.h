#pragma once

#include <QObject>
#include "CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "DataLayer/MotorDetailsData/I_MotorDetailsData.h"

class MotorDetailsPopulator : public QObject
{
    Q_OBJECT
public:
    MotorDetailsPopulator(I_PacketDecoder& packetDecoder, I_MotorDetailsData& motorDetailsData);

public slots:
    void populateData(const MotorDetailsMessage);

private:
    I_PacketDecoder& packetDecoder_;
    I_MotorDetailsData& motorDetailsData_;
}