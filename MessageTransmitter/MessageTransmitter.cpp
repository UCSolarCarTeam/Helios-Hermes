#include "MessageTransmitter.h"
#include "../Config/ConfigManager.h"

#include <QTimer>

namespace {
    const int RETRY_PERIOD = 5000; // milliseconds
}

MessageTransmitter::MessageTransmitter() {
    localClient_ =  new QMqttClient();
    telemetryClient_ = new QMqttClient();

    setupLocalClient();
    setupTelemetryClient();
}

/** Transmit message to both local and telemetry MQTT services if connected */
void MessageTransmitter::transmitMessage(const QByteArray& message) {
    if(localClient_->state() == QMqttClient::Connected) {
        qDebug() << "Publishing to LOCAL MQTT Service";
        localClient_->publish(localTopic_, message);
    }

    if(telemetryClient_->state() == QMqttClient::Connected) {
        qDebug() << "Publishing to TELEMETRY MQTT Service";
        telemetryClient_->publish(telemetryTopic_, message);
    }
}

/** 
 * Setup Local MQTT client
 * requires hostname, port, and topic
 * will retry connecting every 5s if connection fails
 */
void MessageTransmitter::setupLocalClient() {
    ConfigManager& config = ConfigManager::instance();

    localClient_->setHostname(config.getLocalHostname());
    localClient_->setPort(config.getLocalPort());
    localTopic_ = config.getLocalTopic();

    QObject::connect(localClient_, &QMqttClient::connected, []() {
        qDebug() << "Connection to LOCAL MQTT Service Established";

    });

    QObject::connect(localClient_, &QMqttClient::disconnected, [this]() {
        qDebug() << "Connection to LOCAL MQTT Service Failed - retrying in 5s...";
        QTimer::singleShot(RETRY_PERIOD, [this]() {
            localClient_->connectToHost();
        });
    });

    localClient_->connectToHost();
}

/** 
 * Setup Telemetry MQTT client
 * requires hostname, port, username, password, and topic
 * will retry connecting every 5s if connection fails
 */
void MessageTransmitter::setupTelemetryClient() {
    ConfigManager& config = ConfigManager::instance();

    telemetryClient_->setHostname(config.getTelemetryHostname());
    telemetryClient_->setPort(config.getTelemetryPort());
    telemetryClient_->setUsername(config.getTelemetryUsername());
    telemetryClient_->setPassword(config.getTelemetryPassword());
    telemetryTopic_ = config.getTelemetryTopic();

    QObject::connect(telemetryClient_, &QMqttClient::connected, []() {
        qDebug() << "Connection to TELEMETRY MQTT Service Established";

    });

    QObject::connect(telemetryClient_, &QMqttClient::disconnected, [this]() {
        qDebug() << "Connection to TELEMETRY MQTT Service Failed - retrying in 5s...";
        QTimer::singleShot(RETRY_PERIOD, [this]() {
            telemetryClient_->connectToHost();
        });
    });

    telemetryClient_->connectToHost();
}