#pragma once

#include <QByteArray>
#include <QString>

class MotorDetailsMessage
{
public:
    MotorDetailsMessage(const QByteArray& messageData);

    unsigned char motorNumber() const;
    float phaseCCurrent() const;
    float phaseBCurrent() const;
    float motorVoltageReal() const;
    float motorVoltageImaginary() const;
    float motorCurrentReal() const;
    float motorCurrentImaginary() const;
    float backEmf() const;
    float voltageRailSuppply15V() const;
    float voltageRailSupply33V() const;
    float voltageRailSupply19V() const;
    float heatSinkTemperature() const;
    float motorTemperature() const;
    float dspBoardTemperature() const;
    float dcBusAmpHours() const;
    float odometer() const;
    float slipSpeed() const;

    QString toString() const;

private:
    const QByteArray messageData_;
};
