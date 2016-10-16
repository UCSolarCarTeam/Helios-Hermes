#pragma once

#include <QByteArray>
#include <QString>

class DriverControlMessage
{
public:
    DriverControlsMessage(const QByteArray& messageData);

    unsigned char driverControlsBoardAlive() const;
    unsigned char lightsInputs() const;
    unsigned char musicInputs() const;
    unsigned short acceleration() const;
    unsigned short regenBraking() const;
    unsigned char driverInputs() const;

    QString toString() const;

private:
    const QByteArray messageData_;
}