#pragma once

#include <QByteArray>
#include <QString>

class KeyMotorMessage
{
public:
    KeyMotorMessage(const QByteArray& messageData);

    bool m0Alive() const;
    float m0SetCurrent() const;
    float m0SetVelocity() const;
    float m0BusCurrent() const;
    float m0BusVoltage() const;
    float m0VehicleVelocity() const;
    bool m1Alive() const;
    float m1SetCurrent() const;
    float m1SetVelocity() const;
    float m1BusCurrent() const;
    float m1BusVoltage() const;
    float m1VehicleVelocity() const;

    QString toString() const;

private:
    const QByteArray messageData_;
}