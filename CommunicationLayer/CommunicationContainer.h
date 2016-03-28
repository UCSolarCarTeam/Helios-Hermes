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

#pragma once

#include <QScopedPointer>

class DataContainer;
class CommunicationContainerPrivate;

class I_DataInjectionService;
class I_PacketChecksumChecker;
class I_PacketDecoder;
class I_PacketSynchronizer;
class I_CommDevice;
class I_MessageForwarder;

class CommunicationContainer
{
public:
   explicit CommunicationContainer(DataContainer& dataContainer);
   ~CommunicationContainer();

   I_PacketSynchronizer& packetSynchronizer();
   I_PacketDecoder& packetDecoder();
   I_PacketChecksumChecker& packetChecksumChecker();
   I_DataInjectionService& dataInjectionService();
   I_CommDevice& commDevice();
   I_MessageForwarder& udpMessageForwarder();

private:
   // This is using the PIMPL design pattern, refer to http://c2.com/cgi/wiki?PimplIdiom
   QScopedPointer<CommunicationContainerPrivate> impl_;
};
