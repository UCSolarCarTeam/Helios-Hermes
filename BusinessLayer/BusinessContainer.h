#pragma once

#include <QScopedPointer>

class CommunicationContainer;
class DataContainer;
class I_CommunicationsMonitoringService;
class I_JsonForwarder;
class InfrastructureContainer;
class LoggerService;
class I_JsonMessageBuilder;

class BusinessContainer
{
public:
    explicit BusinessContainer(InfrastructureContainer& infrastructureContainer,
                               CommunicationContainer& communicationContainer,
                               DataContainer& dataContainer);
    ~BusinessContainer();

    I_CommunicationsMonitoringService& communicationsMonitoringService();

private:
    QScopedPointer<LoggerService> loggerService_;
    QScopedPointer<I_CommunicationsMonitoringService> communicationsMonitoringService_;
    QScopedPointer<I_JsonMessageBuilder> jsonMessageBuilder_;
    QScopedPointer<I_JsonForwarder> jsonForwarder_;
};
