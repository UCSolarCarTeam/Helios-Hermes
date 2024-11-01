#ifndef KEYMOTORMESSAGE_H
#define KEYMOTORMESSAGE_H

#include <QByteArray>

class KeyMotorMessage
{
public:
    KeyMotorMessage(const QByteArray& message);

    unsigned short motorSetpoint() const;
    unsigned char controlBits() const;

    QString toString() const;

private:
    const QByteArray message_;

};

#endif // KEYMOTORMESSAGE_H
