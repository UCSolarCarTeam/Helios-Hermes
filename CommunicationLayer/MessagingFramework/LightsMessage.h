#pragma once

#include <QByteArray>
#include <QString>

class LightsMessage
{
public:
    LightsMessage(const QByteArray& messageData);

    bool alive() const;
    unsigned char lightStatus() const;

    QString toString() const;

private:
    const QByteArray messageData_;
};
