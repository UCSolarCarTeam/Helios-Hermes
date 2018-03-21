#pragma once

#include <QByteArray>
#include <QString>

class AuxBMSMessage
{
public:
    AuxBMSMessage(const QByteArray& messageData);

    unsigned char prechargeState() const;
    unsigned char auxVoltage() const;
    bool auxBmsAlive() const;
    bool strobeBmsLight() const;
    bool allowCharge() const;
    bool contactorError() const;

    QString toString() const;

private:
    const QByteArray messageData_;
};
