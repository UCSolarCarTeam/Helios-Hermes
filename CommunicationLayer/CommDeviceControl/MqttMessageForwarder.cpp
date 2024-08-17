#include <QByteArray>
#include <QDebug>
#include <QHostAddress>
#include <QtCore5Compat/QTextCodec>
#include <QMqttClient>
#include <QMqttTopicFilter>

#include "../../InfrastructureLayer/Settings/I_Settings.h"
#include "MqttMessageForwarder.h"


namespace
{
    quint32 TIMEOUT = 120;
    quint32 SLEEP_TIME = 2;
}

RabbitMqMessageForwarder::RabbitMqMessageForwarder(I_Settings& settings)
{
    topic_ = settings.exchangeName();
    ipAddress_ = settings.ipAddress();
    port_ = settings.port();

    setupClient();
}

RabbitMqMessageForwarder::~RabbitMqMessageForwarder()
{
}


void RabbitMqMessageForwarder::setupClient()
{

    //TO IMPLEMENT
    //attempt to reconnect (optional)

    qDebug() << "Attempting to Setup MQTT Client";


    client_ = new QMqttClient(this);
    client_->setHostname(ipAddress_);
    client_->setPort(port_);

    QObject::connect(client_, &QMqttClient::connected, []() {
        qDebug() << "Connected to MQTT Service Established";

    });

    QObject::connect(client_, &QMqttClient::disconnected, []() {
        qDebug() << "Connection to MQTT Service Failed";
        throw;
    });


    client_->connectToHost();
}

void RabbitMqMessageForwarder::forwardData(QByteArray data)
{
    //TO IMPLEMENT
    //failed to publish -> qCritical()
    //lost connection -> setupClient()

    qDebug() << "MqttMessageForwarder: Forwarding data";
    //QByteArray messageData = "message sent";
    QMqttTopicName topicName(topic_);
    client_->publish(topicName, data);
}
