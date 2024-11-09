#include <QByteArray>
#include <QDebug>
#include <QHostAddress>
#include <QtCore5Compat/QTextCodec>
#include <QMqttClient>
#include <QMqttTopicFilter>
#include <QTimer>

//#include "InfrastructureLayer/Settings/I_Settings.h"
#include "../../InfrastructureLayer/Settings/I_Settings.h"
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

    qDebug() << "Attempting to Setup LOCAL MQTT Client";

    client_ = new QMqttClient(this);
    client_->setHostname(ipAddress_);
    client_->setPort(port_);
    clientTopic_.setName("hermesExchange");

    QObject::connect(client_, &QMqttClient::connected, []() {
        qDebug() << "Connection to LOCAL MQTT Service Established";

    });

    QObject::connect(client_, &QMqttClient::disconnected, [this]() {
        qDebug() << "Connection to LOCAL MQTT Service Failed - retrying in 5s...";
        QTimer::singleShot(5000, this, &MqttMessageForwarder::setupClient); // Retry after 5 seconds
    });


    client_->connectToHost();
}

void MqttMessageForwarder::setupTelemetryClient(){
    qDebug() << "Attempting to Setup TELEMETRY MQTT Client";

    telemtryClient_ = new QMqttClient(this);

    telemtryClient_->setHostname("aedes.calgarysolarcar.ca"); //Telemetry host
    telemtryClient_->setPort(1883); //port
    telemtryClient_->setUsername("username"); //change me
    telemtryClient_->setPassword("password"); //change me
    telemetryTopic_.setName("test topic");

    QObject::connect(telemtryClient_, &QMqttClient::connected, []() {
        qDebug() << "Connection to TELEMETRY MQTT Service Established";
    });

    QObject::connect(telemtryClient_, &QMqttClient::disconnected, [this]() {
        qDebug() << "Connection to TELEMETRY MQTT Service Failed - retrying in 5s...";
        QTimer::singleShot(5000, this, &MqttMessageForwarder::setupTelemetryClient); // Retry after 5 seconds
    });

    //TODO - Error handling for failed auth

    telemtryClient_->connectToHost();
}

void MqttMessageForwarder::forwardData(QByteArray data)
{

    if(client_->state() == QMqttClient::Connected){
        qDebug() << "MqttMessageForwarder: Forwarding data to dashboard";
        client_->publish(clientTopic_, data);
    }

    if(telemtryClient_->state() == QMqttClient::Connected){
        qDebug() << "MqttMessageForwarder: Forwarding data to AWS";
        telemtryClient_->publish(telemetryTopic_, data);
    }
}
