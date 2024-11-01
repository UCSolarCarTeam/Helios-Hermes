#ifndef BUSINESSCONTAINER_H
#define BUSINESSCONTAINER_H

#include "JsonMessageBuilder/JsonMessageBuilder.h"
#include "JsonForwarder/JsonForwarder.h"

class InfrastructureContainer;
class CommunicationContainer;
class DataContainer;

class BusinessContainer {

public:
    explicit BusinessContainer(InfrastructureContainer& infrastructureContainer,
                               CommunicationContainer& communicationContainer,
                               DataContainer& dataContainer);
    ~BusinessContainer();

private:
    QScopedPointer<JsonMessageBuilder> builder_;
    QScopedPointer<JsonForwarder> forwarder_;

};

#endif // BUSINESSCONTAINER_H
