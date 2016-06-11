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
 
#include <QDebug>
#include <QTimer>

#include "RadioCommDevice.h"
#include "InfrastructureLayer/Settings/I_Settings.h"

RadioCommDevice::RadioCommDevice(QSerialPort& serialPort, I_Settings& settings)
: serialPort_(serialPort)
{
   setSerialParameters(settings.serialPortName(), settings.baudrate());
   // This makes sure that it is connected after everything is created.
   // Otherwise the error messages won't be sent to the GUI
   QTimer::singleShot(0, this, SLOT(connectToDataSource()));
}

RadioCommDevice::~RadioCommDevice()
{
}

void RadioCommDevice::setSerialParameters(QString serialPortName, int baudRate)
{
   serialPort_.setPortName(serialPortName);
   serialPort_.setBaudRate(baudRate);
}

bool RadioCommDevice::connectToDataSource()
{
   if (serialPort_.open(QIODevice::ReadWrite))
   {
      connect(&serialPort_, SIGNAL(readyRead()),
         this, SLOT(handleSerialDataIncoming()), Qt::UniqueConnection);
      emit connectionSucceeded();
      return true;
   }
   else
   {
      qDebug() << serialPort_.errorString();
      emit connectionFailed(serialPort_.errorString());
      return false;
   }
}

void RadioCommDevice::handleSerialDataIncoming()
{
   qDebug() << "Serial port received data";
   QByteArray incomingData = serialPort_.readAll();
   if (incomingData.isEmpty())
   {
      qWarning() <<"Incoming data empty";
      return;
   }
   emit dataReceived(incomingData);
}
