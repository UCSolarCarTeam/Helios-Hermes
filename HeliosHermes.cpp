#include "HeliosHermes.h"

#include "CommunicationLayer/CommunicationContainer.h"
//#include "DataLayer/DataContainer.h"
#include "InfrastructureLayer/InfrastructureContainer.h"
//#include "BusinessLayer/BusinessContainer.h"

#include <QDebug>

HeliosHermes::HeliosHermes(int& argc, char** argv) :
    QCoreApplication(argc, argv),
    infrastructureContainer_(new InfrastructureContainer()),
    //dataContainer_(new DataContainer(infrastructureContainer_->settings())),
    communicationContainer_(new CommunicationContainer(*infrastructureContainer_))//*dataContainer_, *infrastructureContainer_))//,
    //businessContainer_(new BusinessContainer(*infrastructureContainer_, *communicationContainer_, *dataContainer_))
{
    qDebug() << "INIT";
}

HeliosHermes::~HeliosHermes(){}
