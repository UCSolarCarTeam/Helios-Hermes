#pragma once

#include <QObject>
#include <QString>

class I_MotorFaultsData : public QObject
{
    Q_OBJECT
public:
    virtual ~I_MotorFaultsData() {}

    QString toString() const;

    /* MotorFaults Gets */
    virtual unsigned char getM0ErrorFlags() const;
    virtual unsigned char getM1ErrorFlags() const;
    virtual unsigned char getM0LimitFlags() const;
    virtual unsigned char getM1LimitFlags() const;
    virtual unsigned char getM0CanRxErrorCount() const;
    virtual unsigned char getM0CanTxErrorCount() const;
    virtual unsigned char getM1CanRxErrorCount() const;
    virtual unsigned char getM1CanTxErrorCount() const;

    // Errors
    virtual bool m0MotorOverSpeed() const;
    virtual bool m0SoftwareOverCurrent() const;
    virtual bool m0DcBusOverVoltage() const;
    virtual bool m0BadMotorPositionHallSequence() const;
    virtual bool m0WatchdogCausedLastReset() const;
    virtual bool m0ConfigReadError() const;
    virtual bool m0RailUnderVoltageLockOut() const;
    virtual bool m0DesaturationFault() const;
    virtual bool m1MotorOverSpeed() const;
    virtual bool m1SoftwareOverCurrent() const;
    virtual bool m1DcBusOverVoltage() const;
    virtual bool m1BadMotorPositionHallSequence() const;
    virtual bool m1WatchdogCausedLastReset() const;
    virtual bool m1ConfigReadError() const;
    virtual bool m1RailUnderVoltageLockOut() const;
    virtual bool m1DesaturationFault() const;

    // Limits
    virtual bool m0OutputVoltagePwmLimit() const;
    virtual bool m0MotorCurrentLimit() const;
    virtual bool m0VelocityLimit() const;
    virtual bool m0BusCurrentLimit() const;
    virtual bool m0BusVoltageUpperLimit() const;
    virtual bool m0BusVoltageLowerLimit() const;
    virtual bool m0IpmOrMotorTelemetryLimit() const;
    virtual bool m1OutputVoltagePwmLimit() const;
    virtual bool m1MotorCurrentLimit() const;
    virtual bool m1VelocityLimit() const;
    virtual bool m1BusCurrentLimit() const;
    virtual bool m1BusVoltageUpperLimit() const;
    virtual bool m1BusVoltageLowerLimit() const;
    virtual bool m1IpmOrMotorTelemetryLimit() const;

    /* MotorFaults Sets */
    virtual void setM0ErrorFlags(const unsigned char& m0ErrorFlags;
    virtual void setM1ErrorFlags(const unsigned char& m1ErrorFlags;
    virtual void setM0LimitFlags(const unsigned char& m0LimitFlags;
    virtual void setM1LimitFlags(const unsigned char& m1LimitFlags;
    virtual void setM0CanRxErrorCount(const unsigned char& m0CanRxErrorCount;
    virtual void setM0CanTxErrorCount(const unsigned char& m0CanTxErrorCount;
    virtual void setM1CanRxErrorCount(const unsigned char& m1CanRxErrorCount;
    virtual void setM1CanTxErrorCount(const unsigned char& m1CanTxErrorCount;

signals:
    void m0ErrorFlagsReceived(const unsigned char& m0ErrorFlags);
    void m1ErrorFlagsReceived(const unsigned char& m1ErrorFlags);
    void m0LimitFlagsReceived(const unsigned char& m0LimitFlags);
    void m1LimitFlagsReceived(const unsigned char& m1LimitFlags);
    void m0CanRxErrorCountReceived(const unsigned char& m0CanRxErrorCount);
    void m0CanTxErrorCountReceived(const unsigned char& m0CanTxErrorCount);
    void m1CanRxErrorCountReceived(const unsigned char& m1CanRxErrorCount);
    void m1CanTxErrorCountReceived(const unsigned char& m1CanTxErrorCount);
};
