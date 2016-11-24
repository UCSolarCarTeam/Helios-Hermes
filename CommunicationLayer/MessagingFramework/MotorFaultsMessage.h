#pragma once

#include <QString>
#include <QByteArray>

class MotorFaults
{
public:
    MotorFaults(QByteArray& messageData);

    unsigned char M0ErrorFlags() const;
    unsigned char M1ErrorFlags() const;
    unsigned char M0LimitFlags() const;
    unsigned char M1LimitFlags() const;
    unsigned char M0CanRxErrorCount() const;
    unsigned char M0CanTxErrorCount() const;
    unsigned char M1CanRxErrorCount() const;
    unsigned char M1CanTxErrorCount() const;

    QString toString() const;

private:
    const QByteArray messageData_;
};
