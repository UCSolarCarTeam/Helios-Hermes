#pragma once

#include <QByteArray>

class MessageDecodingHelpers
{
public:
    float getFloat(const QByteArray& data, int startIndex);
    unsigned short getUnsignedShort(const QByteArray& data, int startIndex);
    unsigned char getUnsignedChar(const QByteArray& data, int startIndex);

private:
    enum Type { FLOAT = 1, UNSIGNED_SHORT = 2, UNSIGNED_CHAR = 3 };
    int numberOfBytesInData(Type) const;
    void getData(const QByteArray& data, int startIndex, void* output);
};
