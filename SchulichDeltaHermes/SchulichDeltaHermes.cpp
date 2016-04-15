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

#include "InfrastructureLayer/InfrastructureContainer.h"
#include "DataLayer/DataContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "BusinessLayer/BusinessContainer.h"

#include "SchulichDeltaHermes.h"

SchulichDeltaHermes::SchulichDeltaHermes(int& argc, char** argv)
: QApplication(argc, argv)
, infrastructureContainer_(new InfrastructureContainer())
, dataContainer_(new DataContainer())
, communicationContainer_(new CommunicationContainer(*dataContainer_,
                                                     *infrastructureContainer_))
, businessContainer_(new BusinessContainer(*infrastructureContainer_,
                                           *communicationContainer_,
                                           *dataContainer_))
{
}

SchulichDeltaHermes::~SchulichDeltaHermes()
{
}
