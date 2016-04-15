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

#include "I_CommDevice.h"
#include "InfrastructureLayer/Settings/I_Settings.h"
#include "UdpMessageForwarder.h"

UdpMessageForwarder::UdpMessageForwarder(const I_CommDevice& device, I_Settings& settings)
: device_(device)
, multicastAddress_(settings.ipAddress())
, multicastPort_(settings.udpPort())
{
    connect(&device_, SIGNAL(dataReceived(QByteArray)),
            this, SLOT(forwardData(QByteArray)));
}

UdpMessageForwarder::~UdpMessageForwarder()
{
}

void UdpMessageForwarder::forwardData(QByteArray data)
{
    qDebug() << "Forwarding data";
    const quint64 dataWritten = socket_.writeDatagram(data, multicastAddress_, multicastPort_);
    if (dataWritten != static_cast<quint64>(data.size()))
    {
        qWarning() << "Unable to forward data";
    }
}
