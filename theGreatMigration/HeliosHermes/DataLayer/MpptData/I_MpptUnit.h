#pragma once

#include <QObject>

class I_MpptUnit : public QObject
{
    Q_OBJECT
public:
    virtual ~I_MpptUnit() {}

    /* MpptUnit Gets */
    virtual unsigned char getMpptStatus() const = 0;
    virtual float getArrayVoltage() const = 0;
    virtual float getArrayCurrent() const = 0;
    virtual float getBatteryVoltage() const = 0;
    virtual float getTemperature() const = 0;

    /* MpptUnit Sets */;
    virtual void setMpptStatus(const unsigned char& mpptStatus) = 0;
    virtual void setArrayVoltage(const unsigned short& arrayVoltage) = 0;
    virtual void setArrayCurrent(const unsigned short& arrayCurrent) = 0;
    virtual void setBatteryVoltage(const unsigned short& batteryVoltage) = 0;
    virtual void setTemperature(const unsigned short& temperature) = 0;
};
