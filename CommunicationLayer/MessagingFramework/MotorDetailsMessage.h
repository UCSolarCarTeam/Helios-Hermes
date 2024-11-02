#ifndef MOTORDETAILSMESSAGE_H
#define MOTORDETAILSMESSAGE_H

#include <QByteArray>

class MotorDetailsMessage {
public:
    MotorDetailsMessage(const QByteArray& message, const int& id);

    unsigned short controlValue() const;
    unsigned char controlBits() const;
    short currentMotorTorque() const;
    short currentRpmValue() const;
    char motorTemperature() const;
    unsigned short inverterPeakCurrent() const;
    unsigned short currentMotorPower() const;
    unsigned short AbsoluteAngle() const;
    unsigned short warningCode1() const;
    unsigned short warningCode2() const;
    unsigned short warningCode3() const;
    unsigned short warningCode4() const;
    unsigned char warningCode5() const;
    unsigned short errorCode1() const;
    unsigned short errorCode2() const;
    unsigned short errorCode3() const;
    unsigned short errorCode4() const;
    unsigned char errorCode5() const;

    int motorId() const;

private:
    const QByteArray message_;
    const int motorId_;
};

#endif // MOTORDETAILSMESSAGE_H
