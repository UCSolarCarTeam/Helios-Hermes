/**
 *  Schulich Delta Hermes
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of Schulich Delta Hermes
 *
 *  Schulich Delta Hermes is free software: 
 *  you can redistribute it and/or modify it under the terms 
 *  of the GNU Affero General Public License as published by 
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  Schulich Delta Hermes is distributed 
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 *  without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero 
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General 
 *  Public License along with Schulich Delta Hermes.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#include "MessageDecodingHelpers.h"

namespace
{
    const int UNION_SIZE = 4;

    union DataFromCharTranslator
    {
        unsigned short unsignedShortData;
        float floatData;
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
        return 4;
        break;
    case UNSIGNED_SHORT:
        return 2;
        break;
    default:
        throw "Unhandled data type!";
    }
}
