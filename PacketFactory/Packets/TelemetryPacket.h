#ifndef TELEMETRYPACKET_H
#define TELEMETRYPACKET_H

#include "IPacket.h"

class TelemetryPacket : public IPacket {
public:
    TelemetryPacket();
    void populatePacket(const QByteArray& data) override;
    QJsonObject toJson() override;

private:
    //assign packet fields here
};

#endif // TELEMETRYPACKET_H
