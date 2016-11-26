#pragma once

#include "I_MotorFaultsData.h"

class MotorFaultsData : public I_MotorFaultsData
{
public:
    MotorFaultsData();
    virtual ~MotorFaultsData();

    QString toString() const;

    /* MotorFaults Gets */
    unsigned char getM0ErrorFlags() const;
    unsigned char getM1ErrorFlags() const;
    unsigned char getM0LimitFlags() const;
    unsigned char getM1LimitFlags() const;
    unsigned char getM0CanRxErrorCount() const;
    unsigned char getM0CanTxErrorCount() const;
    unsigned char getM1CanRxErrorCount() const;
    unsigned char getM1CanTxErrorCount() const;

    // Errors
    bool m0MotorOverSpeed() const;
    bool m0SoftwareOverCurrent() const;
    bool m0DcBusOverVoltage() const;
    bool m0BadMotorPositionHallSequence() const;
    bool m0WatchdogCausedLastReset() const;
    bool m0ConfigReadError() const;
    bool m0RailUnderVoltageLockOut() const;
    bool m0DesaturationFault() const;
    bool m1MotorOverSpeed() const;
    bool m1SoftwareOverCurrent() const;
    bool m1DcBusOverVoltage() const;
    bool m1BadMotorPositionHallSequence() const;
    bool m1WatchdogCausedLastReset() const;
    bool m1ConfigReadError() const;
    bool m1RailUnderVoltageLockOut() const;
    bool m1DesaturationFault() const;

    // Limits
    bool m0OutputVoltagePwmLimit() const;
    bool m0MotorCurrentLimit() const;
    bool m0VelocityLimit() const;
    bool m0BusCurrentLimit() const;
    bool m0BusVoltageUpperLimit() const;
    bool m0BusVoltageLowerLimit() const;
    bool m0IpmOrMotorTelemetryLimit() const;
    bool m1OutputVoltagePwmLimit() const;
    bool m1MotorCurrentLimit() const;
    bool m1VelocityLimit() const;
    bool m1BusCurrentLimit() const;
    bool m1BusVoltageUpperLimit() const;
    bool m1BusVoltageLowerLimit() const;
    bool m1IpmOrMotorTelemetryLimit() const;

    /* MotorFaults Sets */
    void setM0ErrorFlags(const unsigned char& m0ErrorFlags);
    void setM1ErrorFlags(const unsigned char& m1ErrorFlags);
    void setM0LimitFlags(const unsigned char& m0LimitFlags);
    void setM1LimitFlags(const unsigned char& m1LimitFlags);
    void setM0CanRxErrorCount(const unsigned char& m0CanRxErrorCount);
    void setM0CanTxErrorCount(const unsigned char& m0CanTxErrorCount);
    void setM1CanRxErrorCount(const unsigned char& m1CanRxErrorCount);
    void setM1CanTxErrorCount(const unsigned char& m1CanTxErrorCount);


private:
    unsigned char m0ErrorFlags_;
    unsigned char m1ErrorFlags_;
    unsigned char m0LimitFlags_;
    unsigned char m1LimitFlags_;
    unsigned char m0CanRxErrorCount_;
    unsigned char m0CanTxErrorCount_;
    unsigned char m1CanRxErrorCount_;
    unsigned char m1CanTxErrorCount_;
};
