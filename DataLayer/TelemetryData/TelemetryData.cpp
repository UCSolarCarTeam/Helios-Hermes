#include "TelemetryData.h"

TelemetryData::TelemetryData() {}

TelemetryData::~TelemetryData() {}

unsigned short TelemetryData::gpsYear() const
{
    return gpsYear_;
}

void TelemetryData::setGpsYear(unsigned short newGpsYear)
{
    gpsYear_ = newGpsYear;
}

unsigned char TelemetryData::gpsMonth() const
{
    return gpsMonth_;
}

void TelemetryData::setGpsMonth(unsigned char newGpsMonth)
{
    gpsMonth_ = newGpsMonth;
}

unsigned char TelemetryData::gpsDay() const
{
    return gpsDay_;
}

void TelemetryData::setGpsDay(unsigned char newGpsDay)
{
    gpsDay_ = newGpsDay;
}

unsigned char TelemetryData::gpsHour() const
{
    return gpsHour_;
}

void TelemetryData::setGpsHour(unsigned char newGpsHour)
{
    gpsHour_ = newGpsHour;
}

unsigned char TelemetryData::gpsMinute() const
{
    return gpsMinute_;
}

void TelemetryData::setGpsMinute(unsigned char newGpsMinute)
{
    gpsMinute_ = newGpsMinute;
}

unsigned char TelemetryData::gpsSecond() const
{
    return gpsSecond_;
}

void TelemetryData::setGpsSecond(unsigned char newGpsSecond)
{
    gpsSecond_ = newGpsSecond;
}

unsigned char TelemetryData::gpsValidityFlags() const
{
    return gpsValidityFlags_;
}

void TelemetryData::setGpsValidityFlags(unsigned char newGpsValidityFlags)
{
    gpsValidityFlags_ = newGpsValidityFlags;
}

unsigned char TelemetryData::gpsFixStatusFlags() const
{
    return gpsFixStatusFlags_;
}

void TelemetryData::setGpsFixStatusFlags(unsigned char newGpsFixStatusFlags)
{
    gpsFixStatusFlags_ = newGpsFixStatusFlags;
}

unsigned char TelemetryData::gpsAdditionalFlags() const
{
    return gpsAdditionalFlags_;
}

void TelemetryData::setGpsAdditionalFlags(unsigned char newGpsAdditionalFlags)
{
    gpsAdditionalFlags_ = newGpsAdditionalFlags;
}

int TelemetryData::gpsLongitude() const
{
    return gpsLongitude_;
}

void TelemetryData::setGpsLongitude(int newGpsLongitude)
{
    gpsLongitude_ = newGpsLongitude;
}

int TelemetryData::gpsLatitude() const
{
    return gpsLatitude_;
}

void TelemetryData::setGpsLatitude(int newGpsLatitude)
{
    gpsLatitude_ = newGpsLatitude;
}

unsigned short TelemetryData::mpuAccelerationX() const
{
    return mpuAccelerationX_;
}

void TelemetryData::setMpuAccelerationX(unsigned short newMpuAccelerationX)
{
    mpuAccelerationX_ = newMpuAccelerationX;
}

unsigned short TelemetryData::mpuAccelerationY() const
{
    return mpuAccelerationY_;
}

void TelemetryData::setMpuAccelerationY(unsigned short newMpuAccelerationY)
{
    mpuAccelerationY_ = newMpuAccelerationY;
}

unsigned short TelemetryData::mpuAccelerationZ() const
{
    return mpuAccelerationZ_;
}

void TelemetryData::setMpuAccelerationZ(unsigned short newMpuAccelerationZ)
{
    mpuAccelerationZ_ = newMpuAccelerationZ;
}

unsigned short TelemetryData::mpuRotationX() const
{
    return mpuRotationX_;
}

void TelemetryData::setMpuRotationX(unsigned short newMpuRotationX)
{
    mpuRotationX_ = newMpuRotationX;
}

unsigned short TelemetryData::mpuRotationY() const
{
    return mpuRotationY_;
}

void TelemetryData::setMpuRotationY(unsigned short newMpuRotationY)
{
    mpuRotationY_ = newMpuRotationY;
}

unsigned short TelemetryData::mpuRotationZ() const
{
    return mpuRotationZ_;
}

void TelemetryData::setMpuRotationZ(unsigned short newMpuRotationZ)
{
    mpuRotationZ_ = newMpuRotationZ;
}

unsigned short TelemetryData::mpuTemperature() const
{
    return mpuTemperature_;
}

void TelemetryData::setMpuTemperature(unsigned short newMpuTemperature)
{
    mpuTemperature_ = newMpuTemperature;
}
