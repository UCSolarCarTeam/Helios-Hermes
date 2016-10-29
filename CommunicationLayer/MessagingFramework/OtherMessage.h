#pragma once

#include <QByteArray>
#include <QString>

class OtherMessage
{
public:
    OtherMessage(const QByteArray& messageData);

    QString toString() const;

private:
    QByteArray messageData_;    
}