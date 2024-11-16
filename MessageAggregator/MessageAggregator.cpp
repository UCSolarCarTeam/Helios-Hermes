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

    message["V2 packet"] = "Place holder";

    emit jsonPacketReady(QJsonDocument(message).toJson(QJsonDocument::Compact));
}

/** Begin transmission timer, fires every 0.5s by default */
void MessageAggregator::startTransmission() {
    ConfigManager& config = ConfigManager::instance();
    timer_.start(config.getForwardPeriod());
}
