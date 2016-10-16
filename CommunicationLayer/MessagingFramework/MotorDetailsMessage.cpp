#include "MotorDetailsMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
    const int PHASE_CCURRENT = 1;
    const int PHASE_BCURRENT = 5;
    const int MOTOR_VOLTAGE_REAL = 9;
    const int MOTOR_VOLTAGE_IMAGINARY = 13;
    const int MOTOR_CURRENT_REAL = 17;
    const int MOTOR_CURRENT_IMAGINARY = 21;
    const int BACK_EMF_REAL = 25;
    const int BACK_EMF_IMAGINARY = 29;
    const int VOLTAGE_RAIL_SUPPPLY_15_V = 33;
    const int VOLTAGE_RAIL_SUPPLY_33_V = 37;
    const int VOLTAGE_RAIL_SUPPLY_19_V = 41;
    const int HEAT_SINK_TEMPERATURE = 45;
    const int MOTOR_TEMPTERATURE = 49;
    const int DSP_BOARD_TEMPERATURE = 53;
    const int DC_BUS_AMP_HOURS = 57;
    const int ODOMETER = 61;
    const int SLIP_SPEED = 65;
}

MotorDetailsMessage::MotorDetailsMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

float MotorDetailsMessage::phaseCCurrent() const
{
    return getFloat(messageData_, PHASE_CCURRENT);
}

float MotorDetailsMessage::phaseBCurrent() const
{
    return getFloat(messageData_, PHASE_BCURRENT);
}

float MotorDetailsMessage::motorVoltageReal() const
{
    return getFloat(messageData_, MOTOR_VOLTAGE_REAL);
}

float MotorDetailsMessage::motorVoltageImaginary() const
{
    return getFloat(messageData_, MOTOR_VOLTAGE_IMAGINARY);
}

float MotorDetailsMessage::motorCurrentReal() const
{
    return getFloat(messageData_, MOTOR_CURRENT_REAL);
}

float MotorDetailsMessage::motorCurrentImaginary() const
{
    return getFloat(messageData_, MOTOR_CURRENT_IMAGINARY);
}

float MotorDetailsMessage::backEmfReal() const
{
    return getFloat(messageData_, BACK_EMF_REAL);
}

float MotorDetailsMessage::backEmfImaginary() const
{
    return getFloat(messageData_, BACK_EMF_IMAGINARY);
}

float MotorDetailsMessage::voltageRailSuppply15V() const
{
    return getFloat(messageData_, VOLTAGE_RAIL_SUPPPLY_15_V);
}

float MotorDetailsMessage::voltageRailSupply33V() const
{
    return getFloat(messageData_, VOLTAGE_RAIL_SUPPLY_33_V);
}

float MotorDetailsMessage::voltageRailSupply19V() const
{
    return getFloat(messageData_, VOLTAGE_RAIL_SUPPLY_19_V);
}

float MotorDetailsMessage::heatSinkTemperature() const
{
    return getFloat(messageData_, HEAT_SINK_TEMPERATURE);
}

float MotorDetailsMessage::motorTempterature() const
{
    return getFloat(messageData_, MOTOR_TEMPTERATURE);
}

float MotorDetailsMessage::dspBoardTemperature() const
{
    return getFloat(messageData_, DSP_BOARD_TEMPERATURE);
}

float MotorDetailsMessage::dcBusAmpHours() const
{
    return getFloat(messageData_, DC_BUS_AMP_HOURS);
}

float MotorDetailsMessage::odometer() const
{
    return getFloat(messageData_, ODOMETER);
}

float MotorDetailsMessage::slipSpeed() const
{
    return getFloat(messageData_, SLIP_SPEED);
}

QString MotorDetailsMessage::toString() const
{
    QString messageString;
    messageString += QString::number(phaseCCurrent() + ", "); 
    messageString += QString::number(phaseBCurrent() + ", "); 
    messageString += QString::number(motorVoltageReal() + ", "); 
    messageString += QString::number(motorVoltageImaginary() + ", "); 
    messageString += QString::number(motorCurrentReal() + ", "); 
    messageString += QString::number(motorCurrentImaginary() + ", "); 
    messageString += QString::number(backEmfReal() + ", "); 
    messageString += QString::number(backEmfImaginary() + ", "); 
    messageString += QString::number(voltageRailSuppply15V() + ", "); 
    messageString += QString::number(voltageRailSupply33V() + ", "); 
    messageString += QString::number(voltageRailSupply19V() + ", "); 
    messageString += QString::number(heatSinkTemperature() + ", "); 
    messageString += QString::number(motorTempterature() + ", "); 
    messageString += QString::number(dspBoardTemperature() + ", "); 
    messageString += QString::number(dcBusAmpHours() + ", "); 
    messageString += QString::number(odometer() + ", "); 
    messageString += QString::number(slipSpeed());
    // TODO how is the message going to be terminated?
    return messageString;
}
