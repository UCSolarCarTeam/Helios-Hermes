#pragma once

#include <QObject>
#include "CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "DataLayer/MotorFaultsData/I_MotorFaultsData.h"

class MotorFaultsData : public QObject
{
    Q_OBJECT
public:
    MotorFaultsData(I_PacketDecoder& packetDecoder,
                     I_MotorFaultsData& motorFaultsData);
public slots:
    void populateData(const MotorFaultsMessage);

private:
    I_PacketDecoder& packetDecoder_;
    I_MotorFaultsData& motorFaultsData_;
};
