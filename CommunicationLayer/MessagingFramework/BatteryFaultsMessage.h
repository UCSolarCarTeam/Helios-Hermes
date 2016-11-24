#pragma once

#include <QString>
#include <QByteArray>

class BatteryFaultsMessage
{
public:
    BatteryFaults(QByteArray& messageData);

    unsigned char batteryFaultsFlags() const;

    QString toString() const;

private:
   const QByteArray messageData_;
};
