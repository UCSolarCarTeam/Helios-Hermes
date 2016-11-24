#pragma once

#include "I_BatteryFaultsData.h"

class BatteryFaultsData : public I_BatteryFaultsData
{
public:
    BatteryFaultsData();
    virtual ~BatteryFaultsData();

    /* BatteryFaults Gets */
    unsigned short getErrorFlag() const;

    /* BatteryFaultsData status */
    bool cellOverVoltage() const;
    bool cellUnderVoltage() const;
    bool cellOverTemperature() const;
    bool measurementUntrusted() const;
    bool cmuCommTimeout() const;
    bool vehicleCommTimeout() const;
    bool bmuIsInSetupMode() const;
    bool cmuCanBusPowerStatus() const;
    bool packIsolationTestFailure() const;
    bool softwareOverCurrentMeasured() const;
    bool canSupplyIsLow() const;
    bool contactorIsStuck() const;
    bool cmuDetectedExtraCellPresent() const;

    bool operator==(const I_BatteryFaultsData& other) const;

    QString toString() const;

    /* BatteryFaults Sets */
    void setErrorFlag(const unsigned short&);


private:
    unsigned short errorFlag_;
};
