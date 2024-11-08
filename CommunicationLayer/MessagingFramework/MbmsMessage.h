#ifndef MBMSMESSAGE_H
#define MBMSMESSAGE_H

#include <QByteArray>

class MbmsMessage {
public:
    MbmsMessage(const QByteArray& message);

    unsigned char contactorStatus() const;
    unsigned char contactorErrors() const;
    unsigned char miscellanousStatus() const;

    unsigned short auxillaryBatteryVoltage() const;
    unsigned short motorVoltage() const;
    unsigned short arrayVoltage() const;
    unsigned short lvVoltage() const;
    unsigned short chargeVoltage() const;
    unsigned short commonCurrent() const;
    unsigned short motorCurrent() const;
    unsigned short arrayCurrent() const;
    unsigned short lvCurrent() const;
    unsigned short chargeCurrent() const;

    unsigned short tripStatuses() const;

private:
    const QByteArray message_;
};

#endif // MBMSMESSAGE_H
