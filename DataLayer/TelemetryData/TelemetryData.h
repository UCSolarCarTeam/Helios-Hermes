#ifndef TELEMETRYDATA_H
#define TELEMETRYDATA_H

#include <QObject>

class TelemetryData : public QObject {
    Q_OBJECT
public:
    TelemetryData();
    virtual ~TelemetryData();

    unsigned short gpsYear() const;
    void setGpsYear(unsigned short newGpsYear);
    unsigned char gpsMonth() const;
    void setGpsMonth(unsigned char newGpsMonth);
    unsigned char gpsDay() const;
    void setGpsDay(unsigned char newGpsDay);
    unsigned char gpsHour() const;
    void setGpsHour(unsigned char newGpsHour);
    unsigned char gpsMinute() const;
    void setGpsMinute(unsigned char newGpsMinute);
    unsigned char gpsSecond() const;
    void setGpsSecond(unsigned char newGpsSecond);
    unsigned char gpsValidityFlags() const;
    void setGpsValidityFlags(unsigned char newGpsValidityFlags);
    unsigned char gpsFixStatusFlags() const;
    void setGpsFixStatusFlags(unsigned char newGpsFixStatusFlags);
    unsigned char gpsAdditionalFlags() const;
    void setGpsAdditionalFlags(unsigned char newGpsAdditionalFlags);
    int gpsLongitude() const;
    void setGpsLongitude(int newGpsLongitude);
    int gpsLatitude() const;
    void setGpsLatitude(int newGpsLatitude);
    unsigned short mpuAccelerationX() const;
    void setMpuAccelerationX(unsigned short newMpuAccelerationX);
    unsigned short mpuAccelerationY() const;
    void setMpuAccelerationY(unsigned short newMpuAccelerationY);
    unsigned short mpuAccelerationZ() const;
    void setMpuAccelerationZ(unsigned short newMpuAccelerationZ);
    unsigned short mpuRotationX() const;
    void setMpuRotationX(unsigned short newMpuRotationX);
    unsigned short mpuRotationY() const;
    void setMpuRotationY(unsigned short newMpuRotationY);
    unsigned short mpuRotationZ() const;
    void setMpuRotationZ(unsigned short newMpuRotationZ);
    unsigned short mpuTemperature() const;
    void setMpuTemperature(unsigned short newMpuTemperature);

private:
    unsigned short gpsYear_ = 0;
    unsigned char gpsMonth_ = 0;
    unsigned char gpsDay_ = 0;
    unsigned char gpsHour_ = 0;
    unsigned char gpsMinute_ = 0;
    unsigned char gpsSecond_ = 0;
    unsigned char gpsValidityFlags_ = 0;
    unsigned char gpsFixStatusFlags_ = 0;
    unsigned char gpsAdditionalFlags_ = 0;
    int gpsLongitude_ = 0;
    int gpsLatitude_ = 0;
    unsigned short mpuAccelerationX_ = 0;
    unsigned short mpuAccelerationY_ = 0;
    unsigned short mpuAccelerationZ_ = 0;
    unsigned short mpuRotationX_ = 0;
    unsigned short mpuRotationY_ = 0;
    unsigned short mpuRotationZ_ = 0;
    unsigned short mpuTemperature_ = 0;
};

#endif // TELEMETRYDATA_H
