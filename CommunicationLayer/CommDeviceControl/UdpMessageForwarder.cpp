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
    routingKey_ = settings.routingKey();
    exchangeName_ = settings.exchangeName();
    channel_ = Channel::Create(settings.ipAddress().toStdString(), (int)settings.udpPort());
    channel_->DeclareExchange(exchangeName_.toStdString(), Channel::EXCHANGE_TYPE_FANOUT);
}

UdpMessageForwarder::~UdpMessageForwarder()
{
}

void UdpMessageForwarder::forwardData(QByteArray data)
{
    BasicMessage::ptr_t mq_msg = BasicMessage::Create(QTextCodec::codecForMib(106)->toUnicode(data).toStdString());
    channel_->BasicPublish(exchangeName_.toStdString(), routingKey_.toStdString(), mq_msg);
}
