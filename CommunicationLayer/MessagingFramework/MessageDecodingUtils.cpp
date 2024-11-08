#include "MessageDecodingUtils.h"

#include <QDebug>
#include <QDataStream>


namespace {
    constexpr int UNION_SIZE = 4;

    enum Type { FLOAT = 1,
                UNSIGNED_SHORT = 2,
                UNSIGNED_CHAR = 3,
                UNSIGNED_INT = 4 };

    int numberOfBytesInData(Type type){
        switch (type){
            case FLOAT: return sizeof(float);
            case UNSIGNED_SHORT: return sizeof(unsigned short);
            case UNSIGNED_CHAR: return sizeof(unsigned char);
            case UNSIGNED_INT: return sizeof(unsigned int);
            default:
                qCritical() << "MessageDecodingHelpers: Invalid type";
                return -1;
        }
    }
}


template <class T>
T readDataStream(QDataStream& dataStream){
    dataStream.setByteOrder(QDataStream::LittleEndian);
    dataStream.setFloatingPointPrecision(QDataStream::SinglePrecision);
    T value;
    dataStream >> value;
    return value;
}

float MessageDecodingUtils::getFloat(const QByteArray& data, int startIndex){
    QDataStream dataStream(data.mid(startIndex, numberOfBytesInData(Type::FLOAT)));
    return readDataStream<float>(dataStream);
}

unsigned short MessageDecodingUtils::getUnsignedShort(const QByteArray& data, int startIndex){
    QDataStream dataStream(data.mid(startIndex, numberOfBytesInData(Type::UNSIGNED_SHORT)));
    return readDataStream<unsigned short>(dataStream);
}

unsigned char MessageDecodingUtils::getUnsignedChar(const QByteArray& data, int startIndex){
    return static_cast<unsigned char>(data.at(startIndex));
}

unsigned int MessageDecodingUtils::getUnsignedInt(const QByteArray& data, int startIndex){
    QDataStream dataStream(data.mid(startIndex, numberOfBytesInData(Type::UNSIGNED_INT)));
    return readDataStream<unsigned int>(dataStream);
}
