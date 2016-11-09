#pragma once

#include <QString>

class MotorFaults
{
public:
   MotorFaults(unsigned char errorFlags, unsigned char limitFlags);

   // Errors
   bool motorOverSpeed() const;
   bool softwareOverCurrent() const;
   bool dcBusOverVoltage() const;
   bool badMotorPositionHallSequence() const;
   bool watchdogCausedLastReset() const;
   bool configReadError() const;
   bool railUnderVoltageLockOut() const;
   bool desaturationFault() const;

   // Limits
   bool outputVoltagePwmLimit() const;
   bool motorCurrentLimit() const;
   bool velocityLimit() const;
   bool busCurrentLimit() const;
   bool busVoltageUpperLimit() const;
   bool busVoltageLowerLimit() const;
   bool ipmOrMotorTelemetryLimit() const;

   // TODO implement this (look at file history, accidently deleted before implemented)
   bool operator==(const MotorFaults& other) const;
   QString toString() const;

private:
   unsigned char errorFlags_;
   unsigned char limitFlags_;
};
