#pragma once

#include <QMqttClient>
#include <QThread>
//#include <SimpleAmqpClient/SimpleAmqpClient.h>

//#include "CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"
#include "I_MessageForwarder.h"

class I_Settings;

class MqttMessageForwarder : public I_MessageForwarder
{
    Q_OBJECT
public:
    MqttMessageForwarder(I_Settings& settings);
    virtual ~MqttMessageForwarder();

public slots:
    void forwardData(QByteArray data);

private:
    void setupClient();
    void setupTelemetryClient();
    //AmqpClient::Channel::ptr_t channel_;
    //AmqpClient::Channel::OpenOpts openOpts_;
    QString topic_;
    QString ipAddress_;
    quint16 port_;
    QMqttClient* client_;
    QMqttTopicName clientTopic_;

    QMqttClient* telemtryClient_;
    QMqttTopicName telemetryTopic_;
};
