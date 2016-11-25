#pragma once

#include <QObject>

class I_MotorDetailsUnit : public QObject
{
    Q_OBJECT

public:
    virtual ~I_MotorDetailsUnit() {}

    /*MotorDetailsUnit "Gets"*/
    virtual unsigned char getMotorNumber() const = 0;
    virtual float getPhaseCCurrent() const = 0;
    virtual float getPhaseBCurrent() const = 0;
    virtual float getMotorVoltageReal() const = 0;
    virtual float getMotorVoltageImaginary() const = 0;
    virtual float getMotorCurrentReal() const = 0;
    virtual float getMotorCurrentImaginary() const = 0;
    virtual float getBackEmfReal() const = 0;
    virtual float getBackEmfImaginary() const = 0;
    virtual float getVoltageRailSuppply15V() const = 0;
    virtual float getVoltageRailSupply33V() const = 0;
    virtual float getVoltageRailSupply19V() const = 0;
    virtual float getHeatSinkTemperature() const = 0;
    virtual float getMotorTempterature() const = 0;
    virtual float getDspBoardTemperature() const = 0;
    virtual float getDcBusAmpHours() const = 0;
    virtual float getOdometer() const = 0;
    virtual float getSlipSpeed() const = 0;

    /*MotorDetailsUnit "Sets"*/
    virtual void setPhaseCCurrent(float& phaseCCurrent) = 0;
    virtual void setPhaseBCurrent(float& phaseBCurrent) = 0;
    virtual void setMotorVoltageReal(float& motorVoltageReal) = 0;
    virtual void setMotorVoltageImaginary(float& motorVoltageImaginary) = 0;
    virtual void setMotorCurrentReal(float& motorCurrentReal) = 0;
    virtual void setMotorCurrentImaginary(float& motorCurrentImaginary) = 0;
    virtual void setBackEmfReal(float& backEmfReal) = 0;
    virtual void setBackEmfImaginary(float& backEmfImaginary) = 0;
    virtual void setVoltageRailSuppply15V(float& voltageRailSuppply15V) = 0;
    virtual void setVoltageRailSupply33V(float& voltageRailSupply33V) = 0;
    virtual void setVoltageRailSupply19V(float& voltageRailSupply19V) = 0;
    virtual void setHeatSinkTemperature(float& heatSinkTemperature) = 0;
    virtual void setMotorTempterature(float& motorTempterature) = 0;
    virtual void setDspBoardTemperature(float& dspBoardTemperature) = 0;
    virtual void setDcBusAmpHours(float& dcBusAmpHours) = 0;
    virtual void setOdometer(float& odometer) = 0;
    virtual void setSlipSpeed(float& slipSpeed) = 0;

signals:
    void phaseCCurrentReceived(const float& phaseCCurrent);
    void phaseBCurrentReceived(const float& phaseBCurrent);
    void motorVoltageRealReceived(const float& motorVoltageReal);
    void motorVoltageImaginaryReceived(const float& motorVoltageImaginary);
    void motorCurrentRealReceived(const float& motorCurrentReal);
    void motorCurrentImaginaryReceived(const float& motorCurrentImaginary);
    void backEmfRealReceived(const float& backEmfReal);
    void backEmfImaginaryReceived(const float& backEmfImaginary);
    void voltageRailSuppply15VReceived(const float& voltageRailSuppply15V);
    void voltageRailSupply33VReceived(const float& voltageRailSupply33V);
    void voltageRailSupply19VReceived(const float& voltageRailSupply19V);
    void heatSinkTemperatureReceived(const float& heatSinkTemperature);
    void motorTempteratureReceived(const float& motorTempterature);
    void dspBoardTemperatureReceived(const float& dspBoardTemperature);
    void dcBusAmpHoursReceived(const float& dcBusAmpHours);
    void odometerReceived(const float& odometer);
    void slipSpeedReceived(const float& slipSpeed);
};

