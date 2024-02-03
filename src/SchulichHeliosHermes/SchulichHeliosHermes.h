#pragma once

#include <QApplication>
#include <QScopedPointer>

class InfrastructureContainer;
class CommunicationContainer;
class DataContainer;
class BusinessContainer;

class SchulichHeliosHermes : public QCoreApplication
{
public:
    SchulichHeliosHermes(int& argc, char** argv);
    ~SchulichHeliosHermes();

private:
    QScopedPointer<InfrastructureContainer> infrastructureContainer_;
    QScopedPointer<DataContainer> dataContainer_;
    QScopedPointer<CommunicationContainer> communicationContainer_;
    QScopedPointer<BusinessContainer> businessContainer_;
};
