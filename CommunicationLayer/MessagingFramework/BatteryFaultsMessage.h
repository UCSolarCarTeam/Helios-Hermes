#ifndef BATTERYFAULTSMESSAGE_H
#define BATTERYFAULTSMESSAGE_H

#include <QByteArray>

class BatteryFaultsMessage {
public:
    BatteryFaultsMessage(const QByteArray& message);

    unsigned int errorFlags() const;
    unsigned short limitFlags() const;

private:
    const QByteArray message_;
};

#endif // BATTERYFAULTSMESSAGE_H
