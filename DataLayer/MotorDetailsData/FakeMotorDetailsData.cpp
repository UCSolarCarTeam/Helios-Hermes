#include "FakeMotorDetails.h"

FakeMotorDetails::FakeMotorDetails()
{
}

FakeMotorDetails::~FakeMotorDetails()
{
}


/*MotorDetailsData "Gets"*/
float FakeMotorDetailsData::getPhaseCCurrent() const
{
    return 1;
}

float FakeMotorDetailsData::getPhaseBCurrent() const
{
    return 2;
}

float FakeMotorDetailsData::getMotorVoltageReal() const
{
    return 3;
}

float FakeMotorDetailsData::getMotorVoltageImaginary() const
{
    return 4;
}

float FakeMotorDetailsData::getMotorCurrentReal() const
{
    return 5;
}

float FakeMotorDetailsData::getMotorCurrentImaginary() const
{
    return 6;
}

float FakeMotorDetailsData::getBackEmfReal() const
{
    return 7;
}

float FakeMotorDetailsData::getBackEmfImaginary() const
{
    return 8;
}

float FakeMotorDetailsData::getVoltageRailSuppply15V() const
{
    return 9;
}

float FakeMotorDetailsData::getVoltageRailSupply33V() const
{
    return 10;
}

float FakeMotorDetailsData::getVoltageRailSupply19V() const
{
    return 11;
}

float FakeMotorDetailsData::getHeatSinkTemperature() const
{
    return 12;
}

float FakeMotorDetailsData::getMotorTempterature() const
{
    return 13;
}

float FakeMotorDetailsData::getDspBoardTemperature() const
{
    return 14;
}

float FakeMotorDetailsData::getDcBusAmpHours() const
{
    return 15;
}

float FakeMotorDetailsData::getOdometer() const
{
    return 16;
}

float FakeMotorDetailsData::getSlipSpeed() const
{
    return 17;
}


/*MotorDetailsData "Sets"*/
void FakeMotorDetailsData::setPhaseCCurrent(const float& phaseCCurrent) {}
void FakeMotorDetailsData::setPhaseBCurrent(const float& phaseBCurrent) {}
void FakeMotorDetailsData::setMotorVoltageReal(const float& motorVoltageReal) {}
void FakeMotorDetailsData::setMotorVoltageImaginary(const float& motorVoltageImaginary) {}
void FakeMotorDetailsData::setMotorCurrentReal(const float& motorCurrentReal) {}
void FakeMotorDetailsData::setMotorCurrentImaginary(const float& motorCurrentImaginary) {}
void FakeMotorDetailsData::setBackEmfReal(const float& backEmfReal) {}
void FakeMotorDetailsData::setBackEmfImaginary(const float& backEmfImaginary) {}
void FakeMotorDetailsData::setVoltageRailSuppply15V(const float& voltageRailSuppply15V) {}
void FakeMotorDetailsData::setVoltageRailSupply33V(const float& voltageRailSupply33V) {}
void FakeMotorDetailsData::setVoltageRailSupply19V(const float& voltageRailSupply19V) {}
void FakeMotorDetailsData::setHeatSinkTemperature(const float& heatSinkTemperature) {}
void FakeMotorDetailsData::setMotorTempterature(const float& motorTempterature) {}
void FakeMotorDetailsData::setDspBoardTemperature(const float& dspBoardTemperature) {}
void FakeMotorDetailsData::setDcBusAmpHours(const float& dcBusAmpHours) {}
void FakeMotorDetailsData::setOdometer(const float& odometer) {}
void FakeMotorDetailsData::setSlipSpeed(const float& slipSpeed) {}
