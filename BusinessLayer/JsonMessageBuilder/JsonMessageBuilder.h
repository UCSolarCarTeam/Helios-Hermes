#ifndef JSONMESSAGEBUILDER_H
#define JSONMESSAGEBUILDER_H

#include <QObject>
#include <QJsonObject>

#include "../../DataLayer/KeyMotorData/KeyMotorData.h"
#include "../../DataLayer/ProximitySensorsData/ProximitySensorsData.h"
#include "../../DataLayer/B3Data/B3Data.h"
#include "../../DataLayer/TelemetryData/TelemetryData.h"
#include "../../DataLayer/BatteryData/BatteryData.h"

class I_PacketChecksumChecker;

class JsonMessageBuilder : public QObject {
    Q_OBJECT
public:
    JsonMessageBuilder();
    JsonMessageBuilder(const I_PacketChecksumChecker& checksumChecker);
    virtual ~JsonMessageBuilder() {}

    QJsonObject buildKeyMotorMessage(const KeyMotorData& data);
    QJsonObject buildProximitySensorsMessage(const ProximitySensorsData& data);
    QJsonObject buildB3Message(const B3Data& data);
    QJsonObject buildTelemetryMessage(const TelemetryData& data);
    QJsonObject buildBatteryMessage(const BatteryData& data);
};

#endif // JSONMESSAGEBUILDER_H
