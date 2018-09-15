#include "FakeMotorDetails.h"

FakeMotorDetails::FakeMotorDetails()
{
}

FakeMotorDetails::~FakeMotorDetails()
{
}


/*MotorDetailsUnit "Gets"*/
unsigned char FakeMotorDetailsUnit::getMotorNumber() const
{
    return 0;
}

float FakeMotorDetailsUnit::getPhaseCCurrent() const
{
    return 1;
}

float FakeMotorDetailsUnit::getPhaseBCurrent() const
{
    return 2;
}

float FakeMotorDetailsUnit::getMotorVoltageReal() const
{
    return 3;
}

float FakeMotorDetailsUnit::getMotorVoltageImaginary() const
{
    return 4;
}

float FakeMotorDetailsUnit::getMotorCurrentReal() const
{
    return 5;
}

float FakeMotorDetailsUnit::getMotorCurrentImaginary() const
{
    return 6;
}

float FakeMotorDetailsUnit::getBackEmf() const
{
    return 7;
}

float FakeMotorDetailsUnit::getVoltageRailSuppply15V() const
{
    return 9;
}

float FakeMotorDetailsUnit::getVoltageRailSupply33V() const
{
    return 10;
}

float FakeMotorDetailsUnit::getVoltageRailSupply19V() const
{
    return 11;
}

float FakeMotorDetailsUnit::getHeatSinkTemperature() const
{
    return 12;
}

float FakeMotorDetailsUnit::getMotorTemperature() const
{
    return 13;
}

float FakeMotorDetailsUnit::getDspBoardTemperature() const
{
    return 14;
}

float FakeMotorDetailsUnit::getDcBusAmpHours() const
{
    return 15;
}

float FakeMotorDetailsUnit::getOdometer() const
{
    return 16;
}

float FakeMotorDetailsUnit::getSlipSpeed() const
{
    return 17;
}


/*MotorDetailsUnit "Sets"*/
void FakeMotorDetailsUnit::setPhaseCCurrent(const float& phaseCCurrent) {}
void FakeMotorDetailsUnit::setPhaseBCurrent(const float& phaseBCurrent) {}
void FakeMotorDetailsUnit::setMotorVoltageReal(const float& motorVoltageReal) {}
void FakeMotorDetailsUnit::setMotorVoltageImaginary(const float& motorVoltageImaginary) {}
void FakeMotorDetailsUnit::setMotorCurrentReal(const float& motorCurrentReal) {}
void FakeMotorDetailsUnit::setMotorCurrentImaginary(const float& motorCurrentImaginary) {}
void FakeMotorDetailsUnit::setBackEmf(const float& backEmf) {}
void FakeMotorDetailsUnit::setVoltageRailSuppply15V(const float& voltageRailSuppply15V) {}
void FakeMotorDetailsUnit::setVoltageRailSupply33V(const float& voltageRailSupply33V) {}
void FakeMotorDetailsUnit::setVoltageRailSupply19V(const float& voltageRailSupply19V) {}
void FakeMotorDetailsUnit::setHeatSinkTemperature(const float& heatSinkTemperature) {}
void FakeMotorDetailsUnit::setMotorTemperature(const float& motorTemperature) {}
void FakeMotorDetailsUnit::setDspBoardTemperature(const float& dspBoardTemperature) {}
void FakeMotorDetailsUnit::setDcBusAmpHours(const float& dcBusAmpHours) {}
void FakeMotorDetailsUnit::setOdometer(const float& odometer) {}
void FakeMotorDetailsUnit::setSlipSpeed(const float& slipSpeed) {}
