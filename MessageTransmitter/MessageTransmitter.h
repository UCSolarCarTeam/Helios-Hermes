#ifndef MESSAGETRANSMITTER_H
#define MESSAGETRANSMITTER_H

#include <QByteArray>
#include <QMqttClient>
#include <QObject>

class MessageTransmitter : public QObject {
    Q_OBJECT
public:
    MessageTransmitter();

    void setupLocalClient();
    void setupTelemetryClient();

public slots:
    void transmitMessage(const QByteArray& message);

private:
    QMqttClient* localClient_;
    QMqttClient* telemetryClient_;

    QString localTopic_;
    QString telemetryTopic_;
};

#endif // MESSAGETRANSMITTER_H
