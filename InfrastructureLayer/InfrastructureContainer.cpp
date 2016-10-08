#include "InfrastructureContainer.h"
#include "Settings/Settings.h"

namespace
{
QString SETTINGS_FILE_NAME = "config.ini";
}

InfrastructureContainer::InfrastructureContainer()
: settings_(new Settings(SETTINGS_FILE_NAME))
{
}

InfrastructureContainer::~InfrastructureContainer()
{   
}

I_Settings& InfrastructureContainer::settings()
{
    return *settings_;
}
