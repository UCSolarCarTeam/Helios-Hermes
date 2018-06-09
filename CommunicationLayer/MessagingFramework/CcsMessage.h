#pragma once

#include <QByteArray>
#include <QString>

class CcsMessage
{
public:
    CcsMessage(const QByteArray& messageData);
    bool ccsAlive() const;


private:
    const QByteArray messageData_;
};
