#pragma once

#include <QByteArray>
#include <QList>
#include <QString>

class CmuMessage
{
public:
   CmuMessage(const QByteArray& messageData);

   unsigned char cmuNumber() const;
   QList<short> cellVoltages() const;
   unsigned short pcbTemperature() const;
   QList<unsigned short> cellTemperatures() const;

    QString toString() const;

private:
    const QByteArray messageData_;
};
