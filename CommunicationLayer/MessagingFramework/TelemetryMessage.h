#ifndef TELEMETRYMESSAGE_H
#define TELEMETRYMESSAGE_H

#include <QByteArray>

class TelemetryMessage {
public:
    TelemetryMessage(const QByteArray& message);

    unsigned short gpsYear() const;
    unsigned char gpsMonth() const;
    unsigned char gpsDay() const;
    unsigned char gpsHour() const;
    unsigned char gpsMinute() const;
    unsigned char gpsSecond() const;
    unsigned char gpsValidityFlags() const;
    unsigned char gpsFixStatusFlags() const;
    unsigned char gpsAdditionalFlags() const;
    int gpsLongitude() const; /** VERIFY */
    int gpsLatitude() const; /** VERIFY */
    unsigned short mpuAccelerationX() const;
    unsigned short mpuAccelerationY() const;
    unsigned short mpuAccelerationZ() const;
    unsigned short mpuRotationX() const;
    unsigned short mpuRotationY() const;
    unsigned short mpuRotationZ() const;
    unsigned short mpuTemperature() const;

private:
    const QByteArray message_;
};

#endif // TELEMETRYMESSAGE_H
