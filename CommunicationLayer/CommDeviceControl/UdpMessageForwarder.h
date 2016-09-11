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

#pragma once

#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <QUdpSocket>
#include "CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"

class I_Settings;

class UdpMessageForwarder : public I_MessageForwarder
{
    Q_OBJECT
public:
    UdpMessageForwarder(I_Settings& settings);
    virtual ~UdpMessageForwarder();

public slots:
    void forwardData(QByteArray data);

private:
    AmqpClient::Channel::ptr_t channel_;
    QString routingKey_;
    QString exchangeName_;
};
