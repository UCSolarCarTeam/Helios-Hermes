#ifndef PROXIMITYSENSORSMESSAGE_H
#define PROXIMITYSENSORSMESSAGE_H

#include <QByteArray>

class ProximitySensorsMessage {
public:
    ProximitySensorsMessage(const QByteArray& message);

    unsigned short proximitySensor1() const;
    unsigned short proximitySensor2() const;
    unsigned short proximitySensor3() const;
    unsigned short proximitySensor4() const;

private:
    const QByteArray message_;
};

#endif // PROXIMITYSENSORSMESSAGE_H
