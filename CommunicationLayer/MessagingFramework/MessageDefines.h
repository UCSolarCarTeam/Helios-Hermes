#pragma once

namespace MessageDefines
{
   enum Type
   {
      KeyMotor = 1,
      Motor0Details = 2,
      Motor1Details = 3,
      DriverControls = 4,
      MotorFaults = 5,
      BatteryFaults = 6,
      Battery = 7,
      Cmu = 8,
      Mppt = 9,
      Lights = 10,
      Other = 11
   };

    int getLengthForMessage(Type type);
}
