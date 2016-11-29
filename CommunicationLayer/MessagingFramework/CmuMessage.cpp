#include "CmuMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

namespace
{
   const int CELL_NUMBER_INDEX = 1;
   const int CELL_VOLTAGE_0_INDEX = 2;
   const int PCB_TEMPERATURE_INDEX = 18;
   const int CELL_TEMPERATURE_0_INDEX = 20;
   const int NUMBER_OF_VOLTAGES = 8;
   const int NUMBER_OF_TEMPERATURES = 15;
   const int NUMBER_OF_BYTES_IN_UNSIGNED_SHORT = 2;
}

CmuMessage::CmuMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

unsigned char CmuMessage::cmuNumber() const
{
    return messageData_.at(CELL_NUMBER_INDEX);
}

QList<short> CmuMessage::cellVoltages() const
{
   QList<short> cellVoltagesData;
   for (int i = 0; i < NUMBER_OF_VOLTAGES; i++)
   {
      const int indexOfCell = CELL_VOLTAGE_0_INDEX + i * NUMBER_OF_BYTES_IN_UNSIGNED_SHORT;
      cellVoltagesData << MessageDecodingHelpers::getUnsignedShort(messageData_, indexOfCell);
   }
   return cellVoltagesData;
}

unsigned short CmuMessage::pcbTemperature() const
{
   return MessageDecodingHelpers::getUnsignedShort(messageData_, PCB_TEMPERATURE_INDEX);
}

QList<unsigned short> CmuMessage::cellTemperatures() const
{
   QList<unsigned short> cellTemperatureData;
   for (int i = 0; i < NUMBER_OF_TEMPERATURES; i++)
   {
      const int indexOfCell = CELL_TEMPERATURE_0_INDEX + i * NUMBER_OF_BYTES_IN_UNSIGNED_SHORT;
      cellTemperatureData << MessageDecodingHelpers::getUnsignedShort(messageData_, indexOfCell);
   }
   return cellTemperatureData;
}

QString CmuMessage::toString() const
{
   QString messageString;
   messageString += QString::number(MessageDefines::Cmu) + ", ";
   messageString += QString::number(cmuNumber()) + ", ";
   foreach(const short& cellVoltage, cellVoltages())
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
