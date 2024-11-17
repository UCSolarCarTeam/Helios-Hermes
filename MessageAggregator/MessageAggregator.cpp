#include "MessageAggregator.h"
#include "../Config/ConfigManager.h"

#include <QJsonDocument>

MessageAggregator::MessageAggregator(MessageTransmitter* messageTransmitter, PacketFactory* packetFactory, QObject* parent) 
    : QObject(parent), messageTransmitter_(messageTransmitter), packetFactory_(packetFactory) {
    
    //Connects timer to createJsonMessage slot so that it fires every period of time defined in config.ini
    connect(&timer_, &QTimer::timeout, this, &MessageAggregator::createJsonMessage);

    //Connects jsonPacketReady signal to transmitMessage slot in MessageTransmitter
    connect(this, &MessageAggregator::jsonPacketReady, messageTransmitter_, &MessageTransmitter::transmitMessage);
}

/** Merges all packet json into one Json Message then emits signal to transmit */
void MessageAggregator::createJsonMessage() {
    qDebug() << "Creating JSON Message";

    QJsonObject message;

    message["Title"] = "Helios";
    message["Timestamp"] = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    message["KeyMotor"] = packetFactory_->getKeyMotorPacket().toJson();

    for(int i = 0; i < ConfigManager::instance().getNumberOfMotors(); i++) {
        message["MotorDetails" + QString::number(i)] = packetFactory_->getMotorDetailsPacket(i).toJson();
    }

    message["B3"] = packetFactory_->getB3Packet().toJson();
    message["Telemetry"] = packetFactory_->getTelemetryPacket().toJson();
    message["BatteryFaults"] = packetFactory_->getBatteryFaultsPacket().toJson();
    message["Battery"] = packetFactory_->getBatteryPacket().toJson();

    for(int i = 0; i < ConfigManager::instance().getNumberOfMppts(); i++) {
        message["Mppt" + QString::number(i)] = packetFactory_->getMpptPacket(i).toJson();
    }

    message["Mbms"] = packetFactory_->getMbmsPacket().toJson();
    message["ProximitySensors"] = packetFactory_->getProximitySensorsPacket().toJson();
    
    emit jsonPacketReady(QJsonDocument(message).toJson(QJsonDocument::Compact));
}

/** Begin transmission timer, fires every 0.5s by default */
void MessageAggregator::startTransmission() {
    ConfigManager& config = ConfigManager::instance();
    timer_.start(config.getForwardPeriod());
}
