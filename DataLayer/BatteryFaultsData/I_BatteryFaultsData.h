#pragma once

#include <QObject>

class I_BatteryFaultsData : public QObject
{
    Q_OBJECT
public:
    virtual ~I_BatteryFaultsData() {}

    /* BatteryFaultsData Gets */
    virtual unsigned short getErrorFlag() const = 0;

    /* BatteryFaultsData status */
    virtual bool cellOverVoltage() const = 0;
    virtual bool cellUnderVoltage() const = 0;
    virtual bool cellOverTemperature() const = 0;
    virtual bool measurementUntrusted() const = 0;
    virtual bool cmuCommTimeout() const = 0;
    virtual bool vehicleCommTimeout() const = 0;
    virtual bool bmuIsInSetupMode() const = 0;
    virtual bool cmuCanBusPowerStatus() const = 0;
    virtual bool packIsolationTestFailure() const = 0;
    virtual bool softwareOverCurrentMeasured() const = 0;
    virtual bool canSupplyIsLow() const = 0;
    virtual bool contactorIsStuck() const = 0;
    virtual bool cmuDetectedExtraCellPresent() const = 0;

    virtual bool operator==(const I_BatteryFaultsData& other) const = 0;

    /* BatteryFaults Sets */
    virtual void setErrorFlag(const unsigned short& errorFlag) = 0;

signals:
    void errorFlagRecieved(const unsigned short errorFlag);
};
