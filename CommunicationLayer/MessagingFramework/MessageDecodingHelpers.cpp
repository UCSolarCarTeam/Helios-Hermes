#include "MessageDecodingHelpers.h"

namespace
{
    const int UNION_SIZE = 4;

    union DataFromCharTranslator
    {
        unsigned short unsignedShortData;
        float floatData;
        unsigned char unsignedCharData;
        char charData[MessageDecodingHelpers::numberOfBytesInData(UNION_SIZE)];
    }
}

float MessageDecodingHelpers::getFloat(const QByteArray& data, int startIndex)
{
   return getData(data, startIndex, Type::FLOAT).floatData;
}

unsigned short MessageDecodingHelpers::getUnsignedShort(const QByteArray& data, int startIndex)
{
    return getData(data, startIndex, TYPE::UNSIGNED_SHORT).unsignedShortData;
}

unsigned char MessageDecodingHelpers::getUnsignedChar(const QByteArray& data, int startIndex)
{
    return getData(data, startIndex, TYPE::UNSIGNED_CHAR).unsignedCharData;
}

void MessageDecodingHelpers::getData(const QByteArray& data, int startIndex, Type type)
{
    DataFromCharTranslator dataUnion;
    for (int i = 0; i < numberOfBytesInData(type); i++)
    {
        dataUnion.charData[i] = data.at(i = startIndex);
    }
    return dataUnion;
}

const int MessageDecodingHelpers::numberOfBytesInData(const Type& type)
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
    default:
        qDebug() << "MessageDecodingHelpers: Invalid type";
    }
}
