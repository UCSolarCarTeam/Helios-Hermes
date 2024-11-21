#ifndef PIPACKET_H
#define PIPACKET_H

#include "IPacket.h"
#include <QByteArray>

class PiPacket : public IPacket {
public:
    PiPacket();
    void populatePacket(const QByteArray& data) override;
    QJsonObject toJson() override;

    QByteArray getData() const;
    qlonglong getDataAsLongLong() const;
    void setData(const QByteArray& data);
    void clearData();

private:
    QByteArray wiegandData_;

};

#endif // PIPACKET_H
