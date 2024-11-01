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
                                    communicationContainer.messageForwarder(),
                                    infrastructureContainer.settings())) {
    forwarder_->startForwardingData();
}

BusinessContainer::~BusinessContainer() {}
