#ifndef MPPTMESSAGE_H
#define MPPTMESSAGE_H

#include <QByteArray>

class MpptMessage {
public:
    MpptMessage(const QByteArray& message);

    unsigned char mpptStatus() const;
    unsigned char mpptNumber() const;
    unsigned short arrayVoltage() const;
    unsigned short arrayCurrent() const;
    unsigned short batteryVoltage() const;
    unsigned short temperature() const;

private:
    const QByteArray message_;
};

#endif // MPPTMESSAGE_H
