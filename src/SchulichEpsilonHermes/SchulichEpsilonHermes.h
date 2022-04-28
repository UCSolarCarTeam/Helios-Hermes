#pragma once

#include <QApplication>
#include <QScopedPointer>

class InfrastructureContainer;
class CommunicationContainer;
class DataContainer;
class BusinessContainer;

class SchulichEpsilonHermes : public QCoreApplication
{
public:
    SchulichEpsilonHermes(int& argc, char** argv);
    ~SchulichEpsilonHermes();

private:
    QScopedPointer<InfrastructureContainer> infrastructureContainer_;
    QScopedPointer<DataContainer> dataContainer_;
    QScopedPointer<CommunicationContainer> communicationContainer_;
    QScopedPointer<BusinessContainer> businessContainer_;
};
