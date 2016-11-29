#include "MessageDecodingHelpers.h"

#include <QDebug>

namespace
{
    const int UNION_SIZE = 4;

    enum Type { FLOAT = 1, UNSIGNED_SHORT = 2, UNSIGNED_CHAR = 3, UNSIGNED_INT = 4 };

    int numberOfBytesInData(Type type)
    {
        switch (type)
        {
        case FLOAT:
            return sizeof(float);
            break;
        case UNSIGNED_SHORT:
            return sizeof(unsigned short);
            break;
        case UNSIGNED_CHAR:
            return sizeof(unsigned char);
            break;
        case UNSIGNED_INT:
            return sizeof(unsigned int);
            break;
        default:
            qDebug() << "MessageDecodingHelpers: Invalid type";
            return -1;
        }
    }

    union DataFromCharTranslator
    {
        unsigned short unsignedShortData;
        float floatData;
        unsigned char unsignedCharData;
        unsigned char intData;
        char charData[UNION_SIZE];
    };

    DataFromCharTranslator getData(const QByteArray& data, int startIndex, Type type)
    {
        DataFromCharTranslator dataUnion;
        for (int i = 0; i < numberOfBytesInData(type); i++)
        {
            dataUnion.charData[i] = data.at(i + startIndex);
        }
        return dataUnion;
    }
}

float MessageDecodingHelpers::getFloat(const QByteArray& data, int startIndex)
{
   return getData(data, startIndex, Type::FLOAT).floatData;
}

unsigned short MessageDecodingHelpers::getUnsignedShort(const QByteArray& data, int startIndex)
{
    return getData(data, startIndex, Type::UNSIGNED_SHORT).unsignedShortData;
}

unsigned char MessageDecodingHelpers::getUnsignedChar(const QByteArray& data, int startIndex)
{
    return getData(data, startIndex, Type::UNSIGNED_CHAR).unsignedCharData;
}

unsigned int MessageDecodingHelpers::getUnsignedInt(const QByteArray &data, int startIndex)
{
    return getData(data, startIndex, Type::UNSIGNED_INT).intData;
}


