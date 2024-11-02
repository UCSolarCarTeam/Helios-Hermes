#include "JsonForwarder.h"

#include "../../InfrastructureLayer/Settings/I_Settings.h"
#include "../JsonDefines.h"
#include "../../CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"

#include <QJsonDocument>

namespace {
    const QString DATE_FORMAT = "yyyy-MM-dd HH:mm:ss";
}

JsonForwarder::JsonForwarder(JsonMessageBuilder& builder,
                             KeyMotorData& keyMotorData,
                             B3Data& b3Data,
                             TelemetryData& telemetryData,
                             BatteryFaultsData& batteryFaultsData,
                             BatteryData& batteryData,
                             MpptData& mpptData,
                             MbmsData& mbmsData,
                             ProximitySensorsData& proximitySensorsData,
                             I_MessageForwarder& forwarder,
                             I_Settings& settings)
    : builder_(builder), keyMotorData_(keyMotorData), b3Data_(b3Data), telemetryData_(telemetryData), batteryFaultsData_(batteryFaultsData),
      batteryData_(batteryData), mpptData_(mpptData), mbmsData_(mbmsData), proximitySensorsData_(proximitySensorsData), forwarder_(forwarder), 
      readTimer_(new QTimer()), forwardPeriod_(settings.forwardPeriod()), packetTitle_(settings.packetTitle()){
    connect(readTimer_.data(), SIGNAL(timeout()), this, SLOT(handleTimeout()));
}

JsonForwarder::~JsonForwarder() {}

void JsonForwarder::startForwardingData() {
    readTimer_->setInterval(forwardPeriod_);
    readTimer_->start();
}

void JsonForwarder::handleTimeout(){
    qWarning() << "Json Forwarder: Timeout Occured";
    QDateTime currentTime = QDateTime::currentDateTime();
    forwardData(currentTime);
}

void JsonForwarder::forwardData(QDateTime& currentTime) {
    QJsonObject json = QJsonObject();

    json[JsonFormat::PACKET_TITLE] = packetTitle_;
    json[JsonFormat::TIMESTAMP] = currentTime.toUTC().toString(DATE_FORMAT);

    json[JsonFormat::KEY_MOTOR] = builder_.buildKeyMotorMessage(keyMotorData_);
    json[JsonFormat::PROXIMITY_SENSORS] = builder_.buildProximitySensorsMessage(proximitySensorsData_);
    json[JsonFormat::B3] = builder_.buildB3Message(b3Data_);
    json[JsonFormat::TELEMETRY] = builder_.buildTelemetryMessage(telemetryData_);
    json[JsonFormat::BATTERY] = builder_.buildBatteryMessage(batteryData_);
    json[JsonFormat::BATTERY_FAULTS] = builder_.buildBatteryFaultsMessage(batteryFaultsData_);
    json[JsonFormat::MBMS] = builder_.buildMbmsMessage(mbmsData_);
    json[JsonFormat::MPPT] = builder_.buildMpptMessage(mpptData_);

    forwarder_.forwardData(QJsonDocument(json).toJson(QJsonDocument::Compact));

}
