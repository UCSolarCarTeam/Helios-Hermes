#ifndef MESSAGEDECODINGUTILS_H
#define MESSAGEDECODINGUTILS_H

#include <QByteArray>

namespace MessageDecodingUtils
{
    float getFloat(const QByteArray& data, int startIndex);
    unsigned short getUnsignedShort(const QByteArray& data, int startIndex);
    unsigned char getUnsignedChar(const QByteArray& data, int startIndex);
    unsigned int getUnsignedInt(const QByteArray& data, int startIndex);
}

#endif // MESSAGEDECODINGUTILS_H
