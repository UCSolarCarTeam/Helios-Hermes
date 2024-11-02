#ifndef JSONFORWARDER_H
#define JSONFORWARDER_H

#include <QObject>
#include <QTimer>

#include "../../DataLayer/KeyMotorData/KeyMotorData.h"
#include "../../DataLayer/B3Data/B3Data.h"
#include "../../DataLayer/ProximitySensorsData/ProximitySensorsData.h"
#include "../../DataLayer/TelemetryData/TelemetryData.h"
#include "../JsonMessageBuilder/JsonMessageBuilder.h"
#include "../../DataLayer/BatteryData/BatteryData.h"
#include "../../DataLayer/BatteryFaultsData/BatteryFaultsData.h"
#include "../../DataLayer/MbmsData/MbmsData.h"
#include "../../DataLayer/MpptData/MpptData.h"

class I_MessageForwarder;
class I_Settings;

class JsonForwarder : public QObject{
    Q_OBJECT
public:
    JsonForwarder(JsonMessageBuilder& builder,
                  KeyMotorData& keyMotorData,
                  B3Data& b3Data,
                  TelemetryData& telemetryData,
                  BatteryFaultsData& batteryFaultsData,
                  BatteryData& batteryData,
                  MpptData& mpptData,
                  MbmsData& mbmsData,
                  ProximitySensorsData& proximitySensorsData,
                  I_MessageForwarder& forwarder,
                  I_Settings& settings);
    virtual ~JsonForwarder();

    void startForwardingData();
    void forwardData(QDateTime& currentTime);

private slots:
    void handleTimeout();

private:
    JsonMessageBuilder& builder_;
    KeyMotorData& keyMotorData_;
    B3Data& b3Data_;
    TelemetryData& telemetryData_;
    BatteryFaultsData& batteryFaultsData_;
    BatteryData& batteryData_;
    MpptData& mpptData_;
    MbmsData& mbmsData_;
    ProximitySensorsData& proximitySensorsData_;
    I_MessageForwarder& forwarder_;
    QScopedPointer<QTimer> readTimer_;
    int forwardPeriod_;
    const QString packetTitle_;
};

#endif // JSONFORWARDER_H
