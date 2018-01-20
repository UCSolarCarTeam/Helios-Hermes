#pragma once

#include "I_MotorDetailsUnit.h"

class FakeMotorDetails : I_MotorDetailsUnit
{
public:
    FakeMotorDetails();
    virtual ~FakeMotorDetails();

    /*MotorDetailsUnit "Gets"*/
    unsigned char getMotorNumber() const;
    float getPhaseCCurrent() const;
    float getPhaseBCurrent() const;
    float getMotorVoltageReal() const;
    float getMotorVoltageImaginary() const;
    float getMotorCurrentReal() const;
    float getMotorCurrentImaginary() const;
    float getBackEmf() const;
    float getVoltageRailSuppply15V() const;
    float getVoltageRailSupply33V() const;
    float getVoltageRailSupply19V() const;
    float getHeatSinkTemperature() const;
    float getMotorTemperature() const;
    float getDspBoardTemperature() const;
    float getDcBusAmpHours() const;
    float getOdometer() const;
    float getSlipSpeed() const;

    /*MotorDetailsUnit "Sets"*/
    void setPhaseCCurrent(const float& phaseCCurrent);
    void setPhaseBCurrent(const float& phaseBCurrent);
    void setMotorVoltageReal(const float& motorVoltageReal);
    void setMotorVoltageImaginary(const float& motorVoltageImaginary);
    void setMotorCurrentReal(const float& motorCurrentReal);
    void setMotorCurrentImaginary(const float& motorCurrentImaginary);
    void setBackEmfR(const float& backEmf);
    void setVoltageRailSuppply15V(const float& voltageRailSuppply15V);
    void setVoltageRailSupply33V(const float& voltageRailSupply33V);
    void setVoltageRailSupply19V(const float& voltageRailSupply19V);
    void setHeatSinkTemperature(const float& heatSinkTemperature);
    void setMotorTemperature(const float& motorTemperature);
    void setDspBoardTemperature(const float& dspBoardTemperature);
    void setDcBusAmpHours(const float& dcBusAmpHours);
    void setOdometer(const float& odometer);
    void setSlipSpeed(const float& slipSpeed);
}