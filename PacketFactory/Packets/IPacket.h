#ifndef IPACKET_H
#define IPACKET_H

#include <QJsonObject>
#include <QByteArray>

class IPacket {
    public:
        virtual ~IPacket() {}
        virtual void populatePacket(const QByteArray& data) = 0;
        virtual QJsonObject toJson() = 0;
};

#endif // IPACKET_H
