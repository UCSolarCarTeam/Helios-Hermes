#pragma once

#include <QByteArray>
#include <QList>
#include <QString>

class CmuMessage
{
public:
   CmuMessage(const QByteArray& messageData);

   unsigned char cellNumber() const;
   QList<unsigned short> cellVoltages() const;
   unsigned short pcbTemperature() const;
   QList<unsigned short> cellTemperatures() const;

    QString toString() const;

private:
    const QByteArray messageData_;
};
