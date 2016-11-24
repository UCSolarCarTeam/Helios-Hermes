#pragma once

#include <QString>
#include <QByteArray>

class BatteryFaultsMessage
{
public:
    BatteryFaults(unsigned char flags);

    unsigned char batteryFaultsFlags(const QByteArray& messageData) const;

    QString toString() const;

private:
   const QByteArray messageData_;
};
