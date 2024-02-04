#include <QByteArray>
#include <QDebug>
#include <QHostAddress>
#include <QtCore5Compat/QTextCodec>
#include <QMqttClient>
#include <QMqttTopicFilter>

#include "InfrastructureLayer/Settings/I_Settings.h"
#include "RabbitMqMessageForwarder.h"


namespace
{
    quint32 TIMEOUT = 120;
    quint32 SLEEP_TIME = 2;
}

RabbitMqMessageForwarder::RabbitMqMessageForwarder(I_Settings& settings)
{
    exchangeName_ = settings.exchangeName();
    ipAddress_ = settings.ipAddress();
    port_ = settings.port();


    //Setting up openOpts
    // AmqpClient::Channel::OpenOpts::BasicAuth auth;
    // auth.password = "guest";
    // auth.username = "guest";
    // openOpts_.host = ipAddress_.toStdString();
    // openOpts_.port = port_;
    // openOpts_.auth = auth;
    // //Vhost and Frame max value are taken from default value in Channel
    // openOpts_.vhost = "/";
    // openOpts_.frame_max = 131072;
    setupChannel();
}

RabbitMqMessageForwarder::~RabbitMqMessageForwarder()
{
}


void RabbitMqMessageForwarder::setupChannel()
{
    qDebug() << "SETTING UP";

    client_ = new QMqttClient(this);
    client_->setHostname("127.0.0.1");
    client_->setPort(6969);

    QObject::connect(client_, &QMqttClient::connected, []() {
        qDebug() << "connected";

    });

    QObject::connect(client_, &QMqttClient::disconnected, []() {
        qDebug() << "disconnected";
    });


    client_->connectToHost();



    //client->disconnectFromHost();



    // quint32 i = 0;

    // do
    // {
    //     if (i++)
    //     {
    //         qInfo() << "RabbitMqMessageForwarder: Attempting to reconnect";
    //     }

    //     try
    //     {
    //         channel_ = AmqpClient::Channel::Open(openOpts_);
    //     }
    //     catch (std::exception&)
    //     {
    //         if (channel_ == NULL)
    //         {
    //             if (i == (TIMEOUT / SLEEP_TIME))
    //             {
    //                 qWarning() << "RabbitMqMessageForwarder timed out waiting for connection to broker";
    //                 throw;
    //             }

    //             qWarning() << "RabbitMqMessageForwarder: error creating channel";
    //             QThread::sleep(SLEEP_TIME);
    //         }
    //         else
    //         {
    //             throw;
    //         }
    //     }
    // }
    // while (channel_ == NULL);

    // channel_->DeclareExchange(exchangeName_.toStdString(), AmqpClient::Channel::EXCHANGE_TYPE_FANOUT);
}

void RabbitMqMessageForwarder::forwardData(QByteArray data)
{
    qDebug() << "RabbitMqMessageForwarder: Forwarding data";
    //QByteArray messageData = "message sent";
    QMqttTopicName topicName("test");
    client_->publish(topicName, data);

    // AmqpClient::BasicMessage::ptr_t mq_msg = AmqpClient::BasicMessage::Create(QTextCodec::codecForMib(106)->toUnicode(data).toStdString());

    // try
    // {
    //     channel_->BasicPublish(exchangeName_.toStdString(), "", mq_msg);
    // }
    // catch (AmqpClient::ChannelException& ex)
    // {
    //     qCritical() << "RabbitMqMessageForwarder: Failed to forward data";
    // }
    // catch (AmqpClient::ConnectionException& ex)
    // {
    //     qWarning() << "RabbitMqMessageForwarder: Connection to broker terminated";
    //     setupChannel();
    // }
}
