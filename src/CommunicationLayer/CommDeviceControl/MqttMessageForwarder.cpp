#include <QByteArray>
#include <QDebug>
#include <QHostAddress>
#include <QtCore5Compat/QTextCodec>
#include <QMqttClient>
#include <QMqttTopicFilter>
#include <QTimer>

#include "InfrastructureLayer/Settings/I_Settings.h"
#include "MqttMessageForwarder.h"


namespace
{
    quint32 TIMEOUT = 120;
    quint32 SLEEP_TIME = 2;
}

MqttMessageForwarder::MqttMessageForwarder(I_Settings& settings)
{
    topic_ = settings.exchangeName();
    ipAddress_ = settings.ipAddress();
    port_ = settings.port();

    setupClient();
    setupTelemetryClient();
}

MqttMessageForwarder::~MqttMessageForwarder()
{
}


void MqttMessageForwarder::setupClient()
{

    //TO IMPLEMENT
    //attempt to reconnect (optional)

    qDebug() << "Attempting to Setup MQTT Client";

    client_ = new QMqttClient(this);
    client_->setHostname(ipAddress_);
    client_->setPort(port_);

    QObject::connect(client_, &QMqttClient::connected, []() {
        qDebug() << "Connection to MQTT Service Established";

    });

    QObject::connect(client_, &QMqttClient::disconnected, [this]() {
        qDebug() << "Connection to MQTT Service Failed";
        QTimer::singleShot(5000, this, &MqttMessageForwarder::setupClient); // Retry after 5 seconds
    });


    client_->connectToHost();
}

void MqttMessageForwarder::setupTelemetryClient(){
    qDebug() << "Attempting to Setup TELEMETRY MQTT Client";

    telemtryClient_ = new QMqttClient(this);
    telemtryClient_->setHostname("localhost"); //Telemetry host
    telemtryClient_->setPort(6900); //port

    QObject::connect(client_, &QMqttClient::connected, []() {
        qDebug() << "Connection to AWS MQTT Service Established";

    });

    QObject::connect(telemtryClient_, &QMqttClient::disconnected, [this]() {
        qDebug() << "Connection to AWS MQTT Service Failed";
        QTimer::singleShot(5000, this, &MqttMessageForwarder::setupTelemetryClient); // Retry after 5 seconds
    });

    telemtryClient_->connectToHost();
}

void MqttMessageForwarder::forwardData(QByteArray data)
{
    //TO IMPLEMENT
    //failed to publish -> qCritical()
    //lost connection -> setupClient()

    qDebug() << "MqttMessageForwarder: Forwarding data to dashboard";
    //QByteArray messageData = "message sent";
    QMqttTopicName topicName(topic_);
    client_->publish(topicName, data);

    qDebug() << "MqttMessageForwarder: Forwarding data to AWS";
    QMqttTopicName telemetryTopic("skeeterAedes");
    telemtryClient_->publish(telemetryTopic, data);
}
