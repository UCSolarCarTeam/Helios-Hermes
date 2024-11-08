#ifndef JSONMESSAGEBUILDER_H
#define JSONMESSAGEBUILDER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>

#include "../../DataLayer/KeyMotorData/KeyMotorData.h"
#include "../../DataLayer/ProximitySensorsData/ProximitySensorsData.h"
#include "../../DataLayer/B3Data/B3Data.h"
#include "../../DataLayer/TelemetryData/TelemetryData.h"
#include "../../DataLayer/BatteryData/BatteryData.h"
#include "../../DataLayer/BatteryFaultsData/BatteryFaultsData.h"
#include "../../DataLayer/MbmsData/MbmsData.h"
#include "../../DataLayer/MpptData/MpptData.h"
#include "../../DataLayer/MotorDetailsData/MotorDetailsData.h"

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
    QJsonObject buildBatteryFaultsMessage(const BatteryFaultsData& data);
    QJsonObject buildMbmsMessage(const MbmsData& data);

    QJsonArray buildMpptMessage(const MpptData& data);
    QJsonArray buildMotorDetailsMessage(const MotorDetailsData& data);
};

#endif // JSONMESSAGEBUILDER_H
