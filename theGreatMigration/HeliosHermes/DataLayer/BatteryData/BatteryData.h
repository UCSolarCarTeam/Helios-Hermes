#pragma once

#include "I_BatteryData.h"

#include <QPair>

class BatteryData : public I_BatteryData
{
public:

    BatteryData();
    virtual ~BatteryData();

    /*Data "Gets"*/
    bool getAlive() const;
    unsigned char getBmsRelayStatus() const; // will return the complete set of bitflags
    unsigned char getPopulatedCells() const;
    float get12VInputVoltage() const;
    float getFanVoltage() const;
    float getPackCurrent() const;
    float getPackVoltage() const;
    float getPackStateOfCharge() const;
    float getPackAmphours() const;
    float getPackDepthOfDischarge() const;
    unsigned char getHighTemperature() const;
    unsigned char getHighThermistorId() const;
    unsigned char getLowTemperature() const;
    unsigned char getLowThermistorId() const;
    unsigned char getAverageTemperature() const;
    unsigned char getInternalTemperature() const;
    unsigned char getFanSpeed() const;
    unsigned char getRequestedFanSpeed() const;
    unsigned short getLowCellVoltage() const;
    unsigned char getLowCellVoltageId() const;
    unsigned short getHighCellVoltage() const;
    unsigned char getHighCellVoltageId() const;
    unsigned short getAverageCellVoltage() const;

    /* BMS relay status getter */
    bool bmsDischargeRelayEnabled() const;
    bool bmsChargeRelayEnabled() const;
    bool bmsChargerSafetyEnabled() const;
    bool bmsMalfunctionIndicatorActive() const;
    bool bmsGetMultiPurposeInputSignalStatus() const;
    bool bmsGetAlwaysOnSignalStatus() const;
    bool bmsGetIsReadySignalStatus() const;
    bool bmsGetIsChargingSignalStatus() const;

    /*BatteryData "Sets"*/
    void setAlive(const bool&);
    void setBmsRelayStatus(const unsigned char&);
    void setPopulatedCells(const unsigned char&);
    void set12VInputVoltage(const float&);
    void setFanVoltage(const float&);
    void setPackCurrent(const float&);
    void setPackVoltage(const float&);
    void setPackStateOfCharge(const float&);
    void setPackAmphours(const float&);
    void setPackDepthOfDischarge(const float&);
    void setHighTemperature(const unsigned char&);
    void setHighThermistorId(const unsigned char&);
    void setLowTemperature(const unsigned char&);
    void setLowThermistorId(const unsigned char&);
    void setAverageTemperature(const unsigned char&);
    void setInternalTemperature(const unsigned char&);
    void setFanSpeed(const unsigned char&);
    void setRequestedFanSpeed(const unsigned char&);
    void setLowCellVoltage(const unsigned short&);
    void setLowCellVoltageId(const unsigned char&);
    void setHighCellVoltage(const unsigned short&);
    void setHighCellVoltageId(const unsigned char&);
    void setAverageCellVoltage(const unsigned short&);

private:
    bool alive_;
    unsigned char bmsRelayStatus_;
    unsigned char populatedCells_;
    float inputVoltage12_;
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
    unsigned short lowCellVoltage_;
    unsigned char lowCellVoltageId_;
    unsigned short highCellVoltage_;
    unsigned char highCellVoltageId_;
    unsigned short averageCellVoltage_;

    inline bool bmsRelayStatusFlagPresent(const unsigned char statusMask) const;
};
