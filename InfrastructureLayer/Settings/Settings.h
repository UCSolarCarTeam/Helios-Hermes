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
    quint16 port() const;
    int forwardPeriod() const;
    QString packetTitle() const;
    QString exchangeName() const;
    int numberOfMotors() const;
    int numberOfMppts() const;

private:
    QSettings settings_;
};
