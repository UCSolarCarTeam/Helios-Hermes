#pragma once

#include <QScopedPointer>

class CommunicationContainer;
class DataContainer;
class I_JsonForwarder;
class InfrastructureContainer;
class I_JsonMessageBuilder;

class BusinessContainer
{
public:
    explicit BusinessContainer(InfrastructureContainer& infrastructureContainer,
                               CommunicationContainer& communicationContainer,
                               DataContainer& dataContainer);
    ~BusinessContainer();

private:
    QScopedPointer<I_JsonMessageBuilder> jsonMessageBuilder_;
    QScopedPointer<I_JsonForwarder> jsonForwarder_;
};
