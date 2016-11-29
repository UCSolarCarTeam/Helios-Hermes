#pragma once

#include <QByteArray>
#include <QString>

class OtherMessage
{
public:
    OtherMessage(const QByteArray& messageData);

    unsigned char getGps() const;

    QString toString() const;

private:
    QByteArray messageData_;    
};
