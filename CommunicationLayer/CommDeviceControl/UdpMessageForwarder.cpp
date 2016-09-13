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
#include <QTextCodec>


#include "InfrastructureLayer/Settings/I_Settings.h"
#include "UdpMessageForwarder.h"


UdpMessageForwarder::UdpMessageForwarder(I_Settings& settings)
{
    exchangeName_ = settings.exchangeName();
    ipAddress_ = settings.ipAddress();
    udpPort_ = settings.udpPort();
    setupChannel();
}

UdpMessageForwarder::~UdpMessageForwarder()
{
}

void UdpMessageForwarder::setupChannel()
{
    channel_ = AmqpClient::Channel::Create(ipAddress_.toStdString(), udpPort_);
    channel_->DeclareExchange(exchangeName_.toStdString(), AmqpClient::Channel::EXCHANGE_TYPE_FANOUT);
}

void UdpMessageForwarder::forwardData(QByteArray data)
{
    qDebug() << "UdpMessageForwarder: Forwarding data";
    AmqpClient::BasicMessage::ptr_t mq_msg = AmqpClient::BasicMessage::Create(QTextCodec::codecForMib(106)->toUnicode(data).toStdString());
    try {
        channel_->BasicPublish(exchangeName_.toStdString(), "", mq_msg);
    } catch (AmqpClient::ChannelException& ex) {
        qWarning() << "UdpMessageForwarder: Failed to forward data";
    } catch (AmqpClient::ConnectionException& ex) {
        qWarning() << "UdpMessageForwarder: Connection to broker terminated";
        setupChannel();
    }
}
