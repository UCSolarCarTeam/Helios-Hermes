/**
 *  Schulich Delta Hermes
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of Schulich Delta Hermes
 *
 *  Schulich Delta Hermes is free software:
 *  you can redistribute it and/or modify it under the terms
 *  of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  Schulich Delta Hermes is distributed
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General
 *  Public License along with Schulich Delta Hermes.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#include <QByteArray>
#include <QDebug>
#include <QHostAddress>


#include "InfrastructureLayer/Settings/I_Settings.h"
#include "UdpMessageForwarder.h"


UdpMessageForwarder::UdpMessageForwarder(I_Settings& settings)
{
    // TODO deal with exceptional situations

    // Create rabbitMQ channel
    channel = Channel::Create(settings.ipAddress(), settings.udpPort());

    // declare rabbitMQ Queue
    channel->DeclareQueue(QUEUE_NAME, false, false, false, false); // TODO determine if arguments must be changed

    // bind rabbitMQ Queue
    channel->BindQueue(QUEUE_NAME, EXCHANGE_NAME, ROUTING_KEY);
}

UdpMessageForwarder::~UdpMessageForwarder()
{

}

void UdpMessageForwarder::forwardData(QByteArray data)
{
    //  ------------ Old Implementation TODO remove -------------------
    // qDebug() << "UdpMessageForwarder: Forwarding data";
    // const quint64 dataWritten = socket_.writeDatagram(data, ipAddress_, port_);
    // if (dataWritten != static_cast<quint64>(data.size()))
    // {
    //     qWarning() << "UdpMessageForwader: Unable to forward data";
    // }
    //
    // ------------------------------------------------------------------

    // TODO populate message with data
    // Using:
    // static ptr_t AmqpClient::BasicMessage::Create	(	amqp_bytes_t_& body, amqp_basic_properties_t_*	properties);
    #define FAKE_MESSAGE "placeholder_message"
    BasicMessage::ptr_t mq_msg = BasicMessage::Create(FAKE_MESSAGE);

    channel->BasicPublish(mq_msg);
}
