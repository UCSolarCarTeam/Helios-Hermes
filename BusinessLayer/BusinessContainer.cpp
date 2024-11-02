#include "BusinessContainer.h"
#include "../DataLayer/DataContainer.h"
#include "../CommunicationLayer/CommunicationContainer.h"
#include "../InfrastructureLayer/InfrastructureContainer.h"

BusinessContainer::BusinessContainer(InfrastructureContainer& infrastructureContainer,
                                     CommunicationContainer& communicationContainer,
                                     DataContainer& dataContainer)
    : builder_(new JsonMessageBuilder()),
      forwarder_(new JsonForwarder(*builder_,
                                    dataContainer.keyMotorData(),
                                    dataContainer.b3Data(),
                                    dataContainer.telemetryData(),
                                    dataContainer.batteryFaultsData(),
                                    dataContainer.batteryData(),
                                    dataContainer.mpptData(),
                                    dataContainer.mbmsData(),
                                    dataContainer.proximitySensorsData(),
                                    communicationContainer.messageForwarder(),
                                    infrastructureContainer.settings())) {
    forwarder_->startForwardingData();
}

BusinessContainer::~BusinessContainer() {}
