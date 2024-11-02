#ifndef BATTERYFAULTSDATA_H
#define BATTERYFAULTSDATA_H

#include <QObject>

class BatteryFaultsData : public QObject {
    Q_OBJECT
public:
    BatteryFaultsData();
    virtual ~BatteryFaultsData();

    bool internalCommunicationFault() const;
    bool internalConverversionFault() const;
    bool weakCellFault() const;
    bool lowCellVoltageFault() const;
    bool openWiringFault() const;
    bool currentSensorFault() const;
    bool packVoltageSensorFault() const;
    bool weakPackFault() const;
    bool voltageRedundancyFault() const;
    bool fanMonitorFault() const;
    bool thermistorFault() const;
    bool canbusCommunicationFault() const;
    bool alwaysOnSupplyFault() const;
    bool highVoltageIsolationFault() const;
    bool powerSupply12VFault() const;
    bool chargeLimitEnforcementFault() const;
    bool dischargeLimitEnforcementFault() const;
    bool chargerSafetyRelayFault() const;
    bool internalMemoryFault() const;
    bool internalThermistorFault() const;
    bool internalLogicFault() const;
    bool dclReducedDueToLowSoc() const;
    bool dclReducedDueToHighCellResistance() const;
    bool dclReducedDueToTemperature() const;
    bool dclReducedDueToLowCellVoltage() const;
    bool dclReducedDueToLowPackVoltage() const;
    bool dclAndCclReducedDueToVoltageFailsafe() const;
    bool dclAndCclReducedDueToCommunicationFailsafe() const;
    bool cclReducedDueToHighSoc() const;
    bool cclReducedDueToHighCellResistance() const;
    bool cclReducedDueToTemperature() const;
    bool cclReducedDueToHighCellVoltage() const;
    bool cclReducedDueToHighPackVoltage() const;
    bool cclReducedDueToChargerLatch() const;
    bool cclReducedDueToAlternateCurrentLimit() const;

    void setErrorFlags(const unsigned int& val);
    void setLimitFlags(const unsigned short& val);

private:
    bool internalCommunicationFault_ = 0;
    bool internalConverversionFault_ = 0;
    bool weakCellFault_ = 0;
    bool lowCellVoltageFault_ = 0;
    bool openWiringFault_ = 0;
    bool currentSensorFault_ = 0;
    bool packVoltageSensorFault_ = 0;
    bool weakPackFault_ = 0;
    bool voltageRedundancyFault_ = 0;
    bool fanMonitorFault_ = 0;
    bool thermistorFault_ = 0;
    bool canbusCommunicationFault_ = 0;
    bool alwaysOnSupplyFault_ = 0;
    bool highVoltageIsolationFault_ = 0;
    bool powerSupply12VFault_ = 0;
    bool chargeLimitEnforcementFault_ = 0;
    bool dischargeLimitEnforcementFault_ = 0;
    bool chargerSafetyRelayFault_ = 0;
    bool internalMemoryFault_ = 0;
    bool internalThermistorFault_ = 0;
    bool internalLogicFault_ = 0;

    bool dclReducedDueToLowSoc_ = 0;
    bool dclReducedDueToHighCellResistance_ = 0;
    bool dclReducedDueToTemperature_ = 0;
    bool dclReducedDueToLowCellVoltage_ = 0;
    bool dclReducedDueToLowPackVoltage_ = 0;
    bool dclAndCclReducedDueToVoltageFailsafe_ = 0;
    bool dclAndCclReducedDueToCommunicationFailsafe_ = 0;
    bool cclReducedDueToHighSoc_ = 0;
    bool cclReducedDueToHighCellResistance_ = 0;
    bool cclReducedDueToTemperature_ = 0;
    bool cclReducedDueToHighCellVoltage_ = 0;
    bool cclReducedDueToHighPackVoltage_ = 0;
    bool cclReducedDueToChargerLatch_ = 0;
    bool cclReducedDueToAlternateCurrentLimit_ = 0;
};

#endif // BATTERYFAULTSDATA_H
