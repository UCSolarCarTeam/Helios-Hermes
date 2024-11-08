#ifndef B3MESSAGE_H
#define B3MESSAGE_H

#include <QByteArray>

class B3Message {
public:
    B3Message(const QByteArray& message);

    unsigned char lightInputs() const;
    unsigned char driverInputs() const;
    unsigned short acceleration() const;
    unsigned short regenBraking() const;
    unsigned char lightOutputs() const;

private:
    const QByteArray message_;
};

#endif // B3MESSAGE_H
