#pragma once

#include <QObject>

class I_MpptUnit : public QObject
{
    Q_OBJECT
public:
    virtual ~I_MpptUnit() {}

    /* MpptUnit Gets */
    virtual unsigned char getMpptStatus() const;
    virtual unsigned short getArrayVoltage() const;
    virtual unsigned short getArrayCurrent() const;
    virtual unsigned short getBatteryVoltage() const;
    virtual unsigned short getTemperature() const;

    /* MpptUnit Sets */;
    virtual void setArrayVoltage(const unsigned short& arrayVoltage);
    virtual void setArrayCurrent(const unsigned short& arrayCurrent);
    virtual void setBatteryVoltage(const unsigned short& batteryVoltage);
    virtual void setTemperature(const unsigned short& temperature);

signals:
    void arrayVoltageReceived(const unsigned short& arrayVoltage);
    void arrayCurrentReceived(const unsigned short& arrayCurrent);
    void batteryVoltageReceived(const unsigned short& batteryVoltage);
    void temperatureReceived(const unsigned short& temperature);
};
