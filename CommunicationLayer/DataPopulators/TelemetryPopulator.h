#ifndef TELEMETRYPOPULATOR_H
#define TELEMETRYPOPULATOR_H

#include <QObject>
#include "../../CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "../../DataLayer/TelemetryData/TelemetryData.h"

class TelemetryPopulator : public QObject {
    Q_OBJECT
public:
    TelemetryPopulator(I_PacketDecoder& packetDecoder, TelemetryData& data);

public slots:
    void populateData(const TelemetryMessage);

private:
    I_PacketDecoder& packetDecoder_;
    TelemetryData& data_;
};

#endif // TELEMETRYPOPULATOR_H
