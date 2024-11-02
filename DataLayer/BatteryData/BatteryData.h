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
    unsigned char bmuAlive_ = 0;

    bool dischargeRelayEnabled_ = 0;
    bool chargeRelayEnabled_ = 0;
    bool chargerSafetyEnabled_ = 0;
    bool malfunctionIndicatorActive_ = 0;
    bool multiPurposeInputSignalStatus_ = 0;
    bool alwaysOnSignalStatus_ = 0;
    bool isReadySignalStatus_ = 0;
    bool isChargingSignalStatus_ = 0;

    unsigned char populatedCells_ = 0;
    float input12V_ = 0;
    float fanVoltage_ = 0;
    float packCurrent_ = 0;
    float packVoltage_ = 0;
    float packStateOfCharge_ = 0;
    float packAmphours_ = 0;
    float packDepthOfDischarge_ = 0;
    unsigned char highTemperature_ = 0;
    unsigned char highThermistorId_ = 0;
    unsigned char lowTemperature_ = 0;
    unsigned char lowThermistorId_ = 0;
    unsigned char averageTemperature_ = 0;
    unsigned char internalTemperature_ = 0;
    unsigned char fanSpeed_ = 0;
    unsigned char requestedFanSpeed_ = 0;
    short int lowCellVoltage_ = 0;
    unsigned char lowCellVoltageId_ = 0;
    short int highCellVoltage_ = 0;
    unsigned char highCellVoltageId_ = 0;
    short int averageCellVoltage_ = 0;
};

#endif // BATTERYDATA_H
