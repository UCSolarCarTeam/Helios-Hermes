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
                             ProximitySensorsData& proximitySensorsData,
                             I_MessageForwarder& forwarder,
                             I_Settings& settings)
    : builder_(builder), keyMotorData_(keyMotorData), proximitySensorsData_(proximitySensorsData),
      forwarder_(forwarder), readTimer_(new QTimer()), forwardPeriod_(settings.forwardPeriod()),
      packetTitle_(settings.packetTitle()){
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

    forwarder_.forwardData(QJsonDocument(json).toJson(QJsonDocument::Compact));

}
