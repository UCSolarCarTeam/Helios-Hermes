#include "InfrastructureContainer.h"
#include "Settings/Settings.h"
#include "Logging/Logging.h"
#include <QCoreApplication>

namespace
{
    QString SETTINGS_FILE_NAME = "/config.ini";
}

InfrastructureContainer::InfrastructureContainer()
    : settings_(new Settings(QCoreApplication::applicationDirPath() + SETTINGS_FILE_NAME))
    , logging_(Logging::instance())
{
    if (settings_->loggingEnabled())
    {
        logging_.init(settings_->logLevel());
    }
}

InfrastructureContainer::~InfrastructureContainer()
{
}

I_Settings& InfrastructureContainer::settings()
{
    return *settings_;
}
