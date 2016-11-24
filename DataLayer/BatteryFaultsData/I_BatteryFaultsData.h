#pragma once

#include <QObject>
#include <QString>

class I_BatteryFaultsData : public QObject
{
    Q_OBJECT
public:
    virtual ~I_BatteryFaultsData() {}

    /* BatteryFaultsData Gets */
    virtual unsigned short getErrorFlag() const = 0;

    /* BatteryFaultsData status */
    virtual bool cellOverVoltage() const;
    virtual bool cellUnderVoltage() const;
    virtual bool cellOverTemperature() const;
    virtual bool measurementUntrusted() const;
    virtual bool cmuCommTimeout() const;
    virtual bool vehicleCommTimeout() const;
    virtual bool bmuIsInSetupMode() const;
    virtual bool cmuCanBusPowerStatus() const;
    virtual bool packIsolationTestFailure() const;
    virtual bool softwareOverCurrentMeasured() const;
    virtual bool canSupplyIsLow() const;
    virtual bool contactorIsStuck() const;
    virtual bool cmuDetectedExtraCellPresent() const;

    virtual bool operator==(const I_BatteryFaultsData& other) const;

    /* BatteryFaults Sets */
    virtual void setErrorFlag(const unsigned char& errorFlag) = 0;

signals:
    void errorFlagRecieved(const unsigned short errorFlag);
};
