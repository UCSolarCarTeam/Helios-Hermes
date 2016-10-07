#include "DriverControlDetails.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
   const int MOTOR_VELOCITY_INDEX = 1;
   const int MOTOR_VOLTAGE_INDEX = 5;
   const int MOTOR_CURRENT_REAL_INDEX = 9;
   const int BACK_EMF_INDEX = 13;
   const int DSP_BOARD_TEMPERATURE_INDEX = 17;
   const int DC_BUS_AMP_HOURS_INDEX = 21;
   const int ODOMETER_INDEX = 25;
}

DriverControlDetails::DriverControlDetails(
   const QByteArray& messageData)
: messageData_(messageData)
{
}

float DriverControlDetails::motorVelocity() const
{
   return getFloat(messageData_, MOTOR_VELOCITY_INDEX);
}

float DriverControlDetails::motorVoltage() const
{
   return getFloat(messageData_, MOTOR_VOLTAGE_INDEX);
}

float DriverControlDetails::motorCurrentReal() const
{
   return getFloat(messageData_, MOTOR_CURRENT_REAL_INDEX);
}

float DriverControlDetails::backEmf() const
{
   return getFloat(messageData_, BACK_EMF_INDEX);
}

float DriverControlDetails::dpsBoardTemperature() const
{
   return getFloat(messageData_, DSP_BOARD_TEMPERATURE_INDEX);
}

float DriverControlDetails::dcBusAmpHours() const
{
   return getFloat(messageData_, DC_BUS_AMP_HOURS_INDEX);
}

float DriverControlDetails::odometer() const 
{
   return getFloat(messageData_, ODOMETER_INDEX);
}

QString DriverControlDetails::toString() const
{
   QString messageString;
   messageString += QString::number(MessageDefines::DriverControlDetails) + ", ";
   messageString += QString::number(motorVelocity()) + ", ";
   messageString += QString::number(motorVoltage()) + ", ";
   messageString += QString::number(motorCurrentReal()) + ", ";
   messageString += QString::number(backEmf()) + ", ";
   messageString += QString::number(dpsBoardTemperature()) + ", ";
   messageString += QString::number(dcBusAmpHours()) + ", ";
   return messageString;
}
