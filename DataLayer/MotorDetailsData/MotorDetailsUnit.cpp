#include "MotorDetailsUnit.h"

unsigned char MotorDetailsUnit::newMotorNumber_ = 0;

MotorDetailsUnit::MotorDetailsUnit()
    : phaseCCurrent_(0)
    , phaseBCurrent_(0)
    , motorVoltageReal_(0)
    , motorVoltageImaginary_(0)
    , motorCurrentReal_(0)
    , motorCurrentImaginary_(0)
    , backEmf_(0)
    , voltageRailSuppply15V_(0)
    , voltageRailSupply33V_(0)
    , voltageRailSupply19V_(0)
    , heatSinkTemperature_(0)
    , motorTemperature_(0)
    , dspBoardTemperature_(0)
    , dcBusAmpHours_(0)
    , odometer_(0)
    , slipSpeed_(0)
{
    motorNumber_ = newMotorNumber_++;
}

MotorDetailsUnit::~MotorDetailsUnit()
{
}

/* MotorDetailsUnit Gets*/
unsigned char MotorDetailsUnit::getMotorNumber() const
{
    return motorNumber_;
}

float MotorDetailsUnit::getPhaseCCurrent() const
{
    return phaseCCurrent_;
}

float MotorDetailsUnit::getPhaseBCurrent() const
{
    return phaseBCurrent_;
}

float MotorDetailsUnit::getMotorVoltageReal() const
{
    return motorVoltageReal_;
}

float MotorDetailsUnit::getMotorVoltageImaginary() const
{
    return motorVoltageImaginary_;
}

float MotorDetailsUnit::getMotorCurrentReal() const
{
    return motorCurrentReal_;
}

float MotorDetailsUnit::getMotorCurrentImaginary() const
{
    return motorCurrentImaginary_;
}

float MotorDetailsUnit::getBackEmf() const
{
    return backEmf_;
}

float MotorDetailsUnit::getVoltageRailSuppply15V() const
{
    return voltageRailSuppply15V_;
}

float MotorDetailsUnit::getVoltageRailSupply33V() const
{
    return voltageRailSupply33V_;
}

float MotorDetailsUnit::getVoltageRailSupply19V() const
{
    return voltageRailSupply19V_;
}

float MotorDetailsUnit::getHeatSinkTemperature() const
{
    return heatSinkTemperature_;
}

float MotorDetailsUnit::getMotorTemperature() const
{
    return motorTemperature_;
}

float MotorDetailsUnit::getDspBoardTemperature() const
{
    return dspBoardTemperature_;
}

float MotorDetailsUnit::getDcBusAmpHours() const
{
    return dcBusAmpHours_;
}

float MotorDetailsUnit::getOdometer() const
{
    return odometer_;
}

float MotorDetailsUnit::getSlipSpeed() const
{
    return slipSpeed_;
}


/* MotorDetailsUnit Sets*/
void MotorDetailsUnit::setPhaseCCurrent(const float& phaseCCurrent)
{
    phaseCCurrent_ = phaseCCurrent;
    emit phaseCCurrentReceived(phaseCCurrent_);
}

void MotorDetailsUnit::setPhaseBCurrent(const float& phaseBCurrent)
{
    phaseBCurrent_ = phaseBCurrent;
    emit phaseBCurrentReceived(phaseBCurrent_);
}

void MotorDetailsUnit::setMotorVoltageReal(const float& motorVoltageReal)
{
    motorVoltageReal_ = motorVoltageReal;
    emit motorVoltageRealReceived(motorVoltageReal_);
}

void MotorDetailsUnit::setMotorVoltageImaginary(const float& motorVoltageImaginary)
{
    motorVoltageImaginary_ = motorVoltageImaginary;
    emit motorVoltageImaginaryReceived(motorVoltageImaginary_);
}

void MotorDetailsUnit::setMotorCurrentReal(const float& motorCurrentReal)
{
    motorCurrentReal_ = motorCurrentReal;
    emit motorCurrentRealReceived(motorCurrentReal_);
}

void MotorDetailsUnit::setMotorCurrentImaginary(const float& motorCurrentImaginary)
{
    motorCurrentImaginary_ = motorCurrentImaginary;
    emit motorCurrentImaginaryReceived(motorCurrentImaginary_);
}

void MotorDetailsUnit::setBackEmf(const float& backEmf)
{
    backEmf_ = backEmf;
    emit backEmfReceived(backEmf_);
}

void MotorDetailsUnit::setVoltageRailSuppply15V(const float& voltageRailSuppply15V)
{
    voltageRailSuppply15V_ = voltageRailSuppply15V;
    emit voltageRailSuppply15VReceived(voltageRailSuppply15V_);
}

void MotorDetailsUnit::setVoltageRailSupply33V(const float& voltageRailSupply33V)
{
    voltageRailSupply33V_ = voltageRailSupply33V;
    emit voltageRailSupply33VReceived(voltageRailSupply33V_);
}

void MotorDetailsUnit::setVoltageRailSupply19V(const float& voltageRailSupply19V)
{
    voltageRailSupply19V_ = voltageRailSupply19V;
    emit voltageRailSupply19VReceived(voltageRailSupply19V_);
}

void MotorDetailsUnit::setHeatSinkTemperature(const float& heatSinkTemperature)
{
    heatSinkTemperature_ = heatSinkTemperature;
    emit heatSinkTemperatureReceived(heatSinkTemperature_);
}

void MotorDetailsUnit::setMotorTemperature(const float& motorTemperature)
{
    motorTemperature_ = motorTemperature;
    emit motorTemperatureReceived(motorTemperature_);
}

void MotorDetailsUnit::setDspBoardTemperature(const float& dspBoardTemperature)
{
    dspBoardTemperature_ = dspBoardTemperature;
    emit dspBoardTemperatureReceived(dspBoardTemperature_);
}

void MotorDetailsUnit::setDcBusAmpHours(const float& dcBusAmpHours)
{
    dcBusAmpHours_ = dcBusAmpHours;
    emit dcBusAmpHoursReceived(dcBusAmpHours_);
}

void MotorDetailsUnit::setOdometer(const float& odometer)
{
    odometer_ = odometer;
    emit odometerReceived(odometer_);
}

void MotorDetailsUnit::setSlipSpeed(const float& slipSpeed)
{
    slipSpeed_ = slipSpeed;
    emit slipSpeedReceived(slipSpeed_);
}
