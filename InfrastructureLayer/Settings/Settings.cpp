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
    return QString(settings_.value("RabbitMq/ipAddress").toString());
}

quint16 Settings::port() const
{
    return (quint16)settings_.value("RabbitMq/port").toInt();
}

int Settings::forwardPeriod() const
{
    return settings_.value("forwardPeriod").toInt();
}

QString Settings::packetTitle() const
{
    return settings_.value("JsonFormat/packetTitle").toString();
}

QString Settings::exchangeName() const
{
    return QString(settings_.value("RabbitMq/exchangeName").toString());
}

int Settings::numberOfCmus() const
{
    return settings_.value("UnitNumbers/numberOfCmus").toInt();
}

int Settings::numberOfMotors() const
{
    return settings_.value("UnitNumbers/numberOfMotors").toInt();
}

int Settings::numberOfMppts() const
{
    return settings_.value("UnitNumbers/numberOfMppts").toInt();
}
