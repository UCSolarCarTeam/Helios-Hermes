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

#include "CmuMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
   const int CELL_NUMBER_INDEX = 1;
   const int CELL_VOLTAGE_0_INDEX = 2;
   const int PCB_TEMPERATURE_INDEX = 18;
   const int CELL_TEMPERATURE_0_INDEX = 20;
   const int NUMBER_OF_CELLS = 8;
   const int NUMBER_OF_TEMPERATURES = 15;
   // TODO make sure this is correct
   const int NUMBER_OF_BYTES_IN_UNSIGNED_SHORT = 2;
}

CmuMessage::CmuMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

unsigned char CmuMessage::cellNumber() const
{
   return messageData_.at(CELL_NUMBER_INDEX);
}

QList<unsigned short> CmuMessage::cellVoltages() const
{
   QList<unsigned short> cellVoltagesData;
   for (int i = 0; i < NUMBER_OF_CELLS; i++)
   {
      const int indexOfCell = CELL_VOLTAGE_0_INDEX + i * NUMBER_OF_BYTES_IN_UNSIGNED_SHORT;
      cellVoltagesData << getUnsignedShort(messageData_, indexOfCell);
   }
   return cellVoltagesData;
}

unsigned short CmuMessage::pcbTemperature() const
{
   return getUnsignedShort(messageData_, PCB_TEMPERATURE_INDEX);
}

unsigned short CmuMessage::cellTemperatures() const
{
   QList<unsigned short> cellTemperatureData;
   for (int i = 0; i < NUMBER_OF_TEMPERATURES; i++)
   {
      const int indexOfCell = CELL_TEMPERATURE_0_INDEX + i * NUMBER_OF_BYTES_IN_UNSIGNED_SHORT;
      cellTemperatureData << getUnsignedShort(messageData_, indexOfCell);
   }
   return cellTemperatureData;
}

QString CmuMessage::toString() const
{
   QString messageString;
   messageString += QString::number(SerialDefines::CmuData) + ", ";
   messageString += QString::number(cellNumber()) + ", ";
   foreach(const float& cellVoltage, cellVoltages())
   {
      messageString += QString::number(cellVoltage) + ", ";
   }
   messageString += QString::number(pcbTemperature()) + ", ";
   foreach(const unsigned short& cellTemperature, cellTemperatures())
   {
       messageString += QString::number(cellTemperature) + ", ";
   }
   return messageString;
}
