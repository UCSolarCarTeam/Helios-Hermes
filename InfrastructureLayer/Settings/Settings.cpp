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

#include <QDebug>
#include <QSettings>

#include "Settings.h"

namespace
{
const QSettings::Format SETTINGS_FILE_FORMAT = QSettings::IniFormat;
}

Settings::Settings(QString filepath)
: settings_(filepath, SETTINGS_FILE_FORMAT)
{
}

QString Settings::serialPortName() const
{
    return settings_.value("SerialPort/portName").toString();
}

int Settings::baudrate() const
{
    return settings_.value("SerialPort/baudrate").toInt();
}

QString Settings::ipAddress() const
{
    return QString(settings_.value("UdpAddress/ipAddress").toString());
}

quint16 Settings::udpPort() const
{
    return (quint16)settings_.value("UdpAddress/port").toInt();
}

int Settings::forwardPeriod() const
{
    return settings_.value("forwardPeriod").toInt();
}

QString Settings::packetTitle() const
{
    return settings_.value("JsonFormat/packetTitle").toString();
}
