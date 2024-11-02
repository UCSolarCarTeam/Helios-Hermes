#ifndef BATTERYDATA_H
#define BATTERYDATA_H

#include <QObject>

class BatteryData : public QObject {
    Q_OBJECT
public:
    BatteryData();
    virtual ~BatteryData();


    unsigned char bmuAlive() const;
    void setBmuAlive(unsigned char newBmuAlive);
    bool dischargeRelayEnabled() const;
    bool chargeRelayEnabled() const;
    bool chargerSafetyEnabled() const;
    bool malfunctionIndicatorActive() const;
    bool multiPurposeInputSignalStatus() const;
    bool alwaysOnSignalStatus() const;
    bool isReadySignalStatus() const;
    bool isChargingSignalStatus() const;
    unsigned char populatedCells() const;
    void setPopulatedCells(unsigned char newPopulatedCells);
    float input12V() const;
    void setInput12V(float newInput12V);
    float fanVoltage() const;
    void setFanVoltage(float newFanVoltage);
    float packCurrent() const;
    void setPackCurrent(float newPackCurrent);
    float packVoltage() const;
    void setPackVoltage(float newPackVoltage);
    float packStateOfCharge() const;
    void setPackStateOfCharge(float newPackStateOfCharge);
    float packAmphours() const;
    void setPackAmphours(float newPackAmphours);
    float packDepthOfDischarge() const;
    void setPackDepthOfDischarge(float newPackDepthOfDischarge);
    unsigned char highTemperature() const;
    void setHighTemperature(unsigned char newHighTemperature);
    unsigned char highThermistorId() const;
    void setHighThermistorId(unsigned char newHighThermistorId);
    unsigned char lowTemperature() const;
    void setLowTemperature(unsigned char newLowTemperature);
    unsigned char lowThermistorId() const;
    void setLowThermistorId(unsigned char newLowThermistorId);
    unsigned char averageTemperature() const;
    void setAverageTemperature(unsigned char newAverageTemperature);
    unsigned char internalTemperature() const;
    void setInternalTemperature(unsigned char newInternalTemperature);
    unsigned char fanSpeed() const;
    void setFanSpeed(unsigned char newFanSpeed);
    unsigned char requestedFanSpeed() const;
    void setRequestedFanSpeed(unsigned char newRequestedFanSpeed);
    short lowCellVoltage() const;
    void setLowCellVoltage(short newLowCellVoltage);
    unsigned char lowCellVoltageId() const;
    void setLowCellVoltageId(unsigned char newLowCellVoltageId);
    short highCellVoltage() const;
    void setHighCellVoltage(short newHighCellVoltage);
    unsigned char highCellVoltageId() const;
    void setHighCellVoltageId(unsigned char newHighCellVoltageId);
    short averageCellVoltage() const;
    void setAverageCellVoltage(short newAverageCellVoltage);
    void setBmsRelayStatus(unsigned char val);

private:
    unsigned char bmuAlive_;

    bool dischargeRelayEnabled_;
    bool chargeRelayEnabled_;
    bool chargerSafetyEnabled_;
    bool malfunctionIndicatorActive_;
    bool multiPurposeInputSignalStatus_;
    bool alwaysOnSignalStatus_;
    bool isReadySignalStatus_;
    bool isChargingSignalStatus_;

    unsigned char populatedCells_;
    float input12V_;
    float fanVoltage_;
    float packCurrent_;
    float packVoltage_;
    float packStateOfCharge_;
    float packAmphours_;
    float packDepthOfDischarge_;
    unsigned char highTemperature_;
    unsigned char highThermistorId_;
    unsigned char lowTemperature_;
    unsigned char lowThermistorId_;
    unsigned char averageTemperature_;
    unsigned char internalTemperature_;
    unsigned char fanSpeed_;
    unsigned char requestedFanSpeed_;
    short int lowCellVoltage_;
    unsigned char lowCellVoltageId_;
    short int highCellVoltage_;
    unsigned char highCellVoltageId_;
    short int averageCellVoltage_;
};

#endif // BATTERYDATA_H
