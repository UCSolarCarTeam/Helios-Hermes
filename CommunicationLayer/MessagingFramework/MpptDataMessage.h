#pragma once

#include <QByteArray>
#include <QString>

class MpptDataMessage
{
public:
    MpptDataMessage(const QByteArray& messageData);

    unsigned char mpptStatus() const;
    unsigned short arrayVoltage() const;
    unsigned short arrayCurrent() const;
    unsigned short batteryVoltage() const;
    unsigned short temperature() const;

    QString toString() const;

private:
    const QByteArray messageData_;
}