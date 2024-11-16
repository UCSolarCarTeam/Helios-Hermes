#ifndef MESSAGETRANSMITTER_H
#define MESSAGETRANSMITTER_H

#include <QByteArray>
#include <QMqttClient>

class MessageTransmitter
{
public:
    MessageTransmitter();

    void transmitMessage(const QByteArray& message);

    void setupLocalClient();
    void setupTelemetryClient();

private:
    QMqttClient* localClient_;
    QMqttClient* telemetryClient_;

    QString localTopic_;
    QString telemetryTopic_;
};

#endif // MESSAGETRANSMITTER_H
