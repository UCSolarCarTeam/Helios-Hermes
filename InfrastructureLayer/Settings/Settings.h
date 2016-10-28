#pragma once

#include <QSettings>

#include "I_Settings.h"

class Settings : public I_Settings
{
public:
    Settings(QString filepath);
    virtual ~Settings() {}
    QString serialPortName() const;
    int baudrate() const;
    QString ipAddress() const;
    quint16 udpPort() const;
    int forwardPeriod() const;
    QString packetTitle() const;
    QString exchangeName() const;

private:
    QSettings settings_;
};