#ifndef HELIOSHERMES_H
#define HELIOSHERMES_H

#include <QScopedPointer>
#include <QCoreApplication>

class InfrastructureContainer;
class CommunicationContainer;
class DataContainer;
class BusinessContainer;

class HeliosHermes : public QCoreApplication
{
public:
    HeliosHermes(int& argc, char** argv);
    ~HeliosHermes();
private:
    QScopedPointer<InfrastructureContainer> infrastructureContainer_;
    //QScopedPointer<DataContainer> dataContainer_;
    QScopedPointer<CommunicationContainer> communicationContainer_;
    //QScopedPointer<BusinessContainer> businessContainer_;
};

#endif // HELIOSHERMES_H
