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

#include <QtSerialPort/QSerialPort>
#include <QUdpSocket>

#include "DataLayer/DataContainer.h"
#include "CommDeviceControl/RadioCommDevice.h"
#include "CommDeviceControl/UdpMessageForwarder.h"
#include "CommunicationContainer.h"
#include "DataPopulators/BatteryPopulator.h"
#include "DataPopulators/CmuPopulator.h"
#include "DataPopulators/DriverDetailsPopulator.h"
#include "DataPopulators/FaultsPopulator.h"
#include "DataPopulators/KeyDriverControlPopulator.h"
#include "PacketChecksumChecker/PacketChecksumChecker.h"
#include "PacketDecoder/PacketDecoder.h"
#include "PacketSynchronizer/PacketSynchronizer.h"
#include "PacketUnstuffer/PacketUnstuffer.h"

class CommunicationContainerPrivate
{
public:
   CommunicationContainerPrivate(DataContainer& dataContainer)
   : radioCommDevice(serialPort)
   , messageForwarder()
   , packetSynchronizer(radioCommDevice)
   , packetUnstuffer(packetSynchronizer)
   , packetChecksumChecker(packetUnstuffer)
   , packetDecoder(packetChecksumChecker)
   , keyDriverControlPopulator(
      packetDecoder,
      dataContainer.vehicleData(),
      dataContainer.powerData())
   , driverDetailsPopulator(
      packetDecoder,
      dataContainer.vehicleData(),
      dataContainer.powerData())
   , faultsPopulator(
      packetDecoder,
      dataContainer.faultsData())
   , batteryPopulator(
      packetDecoder,
      dataContainer.batteryData())
   , cmuPopulator(
      packetDecoder,
      dataContainer.batteryData())
   {
   }

   QSerialPort serialPort;
   RadioCommDevice radioCommDevice;
   UdpMessageForwarder messageForwarder;
   PacketSynchronizer packetSynchronizer;
   PacketUnstuffer packetUnstuffer;
   PacketChecksumChecker packetChecksumChecker;
   PacketDecoder packetDecoder;
   KeyDriverControlPopulator keyDriverControlPopulator;
   DriverDetailsPopulator driverDetailsPopulator;
   FaultsPopulator faultsPopulator;
   BatteryPopulator batteryPopulator;
   CmuPopulator cmuPopulator;
};

CommunicationContainer::CommunicationContainer(DataContainer& dataContainer)
: impl_(new CommunicationContainerPrivate(dataContainer))
{
}

CommunicationContainer::~CommunicationContainer()
{
}

I_CommDevice& CommunicationContainer::commDevice()
{
   return impl_->radioCommDevice;
}

I_PacketSynchronizer& CommunicationContainer::packetSynchronizer()
{
   return impl_->packetSynchronizer;
}

I_DataInjectionService& CommunicationContainer::dataInjectionService()
{
   return impl_->packetUnstuffer;
}

I_PacketDecoder& CommunicationContainer::packetDecoder()
{
   return impl_->packetDecoder;
}

I_PacketChecksumChecker& CommunicationContainer::packetChecksumChecker()
{
   return impl_->packetChecksumChecker;
}

I_MessageForwarder& CommunicationContainer::udpMessageForwarder()
{
   return impl_->messageForwarder;
}
