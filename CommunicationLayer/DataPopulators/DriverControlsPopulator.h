#pragma once

#include <QObject>
#include "CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "DataLayer/DriverControlsData/I_DriverControlsData.h"

class DriverControlsPopulator : public QObject
{
    Q_OBJECT
public:
    DriverControlsPopulator(I_PacketDecoder& packetDecoder, I_DriverControlsData& driverControlsData);

public slots:
    void populateData(const DriverControlsMessage);

private:
    I_PacketDecoder& packetDecoder_;
    I_DriverControlsData& driverControlsData_;
}