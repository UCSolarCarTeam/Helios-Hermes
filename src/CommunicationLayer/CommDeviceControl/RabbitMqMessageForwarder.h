#pragma once

#include <QThread>
#include <SimpleAmqpClient/SimpleAmqpClient.h>

#include "CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"

class I_Settings;

class RabbitMqMessageForwarder : public I_MessageForwarder
{
    Q_OBJECT
public:
    RabbitMqMessageForwarder(I_Settings& settings);
    virtual ~RabbitMqMessageForwarder();

public slots:
    void forwardData(QByteArray data);

private:
    void setupChannel();
    AmqpClient::Channel::ptr_t channel_;
    AmqpClient::Channel::OpenOpts openOpts_;
    QString exchangeName_;
    QString ipAddress_;
    quint16 port_;
};
