#pragma once

#include <QByteArray>
#include <QString>

class MotorDetailsMessage
{
public:
    float phaseCCurrent() const;
    float phaseBCurrent() const;
    float motorVoltageReal() const;
    float motorVoltageImaginary() const;
    float motorCurrentReal() const;
    float motorCurrentImaginary() const;
    float backEmfReal() const;
    float backEmfImaginary() const;
    float voltageRailSuppply15V() const;
    float voltageRailSupply33V() const;
    float voltageRailSupply19V() const;
    float heatSinkTemperature() const;
    float motorTempterature() const;
    float dspBoardTemperature() const;
    float dcBusAmpHours() const;
    float odometer() const;
    float slipSpeed() const;

    QString toString() const;

private:
    const QByteArray messageData_;
    const unsigned char motorNumber_;
}