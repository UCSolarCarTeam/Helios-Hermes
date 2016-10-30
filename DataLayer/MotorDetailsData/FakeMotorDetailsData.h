#pragma once

#include "I_MotorDetailsData.h"

class FakeMotorDetails : I_MotorDetailsData
{
public:
    FakeMotorDetails();
    virtual ~FakeMotorDetails();

    /*MotorDetailsData "Gets"*/
    float getPhaseCCurrent() const;
    float getPhaseBCurrent() const;
    float getMotorVoltageReal() const;
    float getMotorVoltageImaginary() const;
    float getMotorCurrentReal() const;
    float getMotorCurrentImaginary() const;
    float getBackEmfReal() const;
    float getBackEmfImaginary() const;
    float getVoltageRailSuppply15V() const;
    float getVoltageRailSupply33V() const;
    float getVoltageRailSupply19V() const;
    float getHeatSinkTemperature() const;
    float getMotorTempterature() const;
    float getDspBoardTemperature() const;
    float getDcBusAmpHours() const;
    float getOdometer() const;
    float getSlipSpeed() const;

    /*MotorDetailsData "Sets"*/
    void setPhaseCCurrent(const float& phaseCCurrent);
    void setPhaseBCurrent(const float& phaseBCurrent);
    void setMotorVoltageReal(const float& motorVoltageReal);
    void setMotorVoltageImaginary(const float& motorVoltageImaginary);
    void setMotorCurrentReal(const float& motorCurrentReal);
    void setMotorCurrentImaginary(const float& motorCurrentImaginary);
    void setBackEmfReal(const float& backEmfReal);
    void setBackEmfImaginary(const float& backEmfImaginary);
    void setVoltageRailSuppply15V(const float& voltageRailSuppply15V);
    void setVoltageRailSupply33V(const float& voltageRailSupply33V);
    void setVoltageRailSupply19V(const float& voltageRailSupply19V);
    void setHeatSinkTemperature(const float& heatSinkTemperature);
    void setMotorTempterature(const float& motorTempterature);
    void setDspBoardTemperature(const float& dspBoardTemperature);
    void setDcBusAmpHours(const float& dcBusAmpHours);
    void setOdometer(const float& odometer);
    void setSlipSpeed(const float& slipSpeed);
}