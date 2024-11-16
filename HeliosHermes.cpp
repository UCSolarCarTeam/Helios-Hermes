#include "HeliosHermes.h"
#include "SerialReciever/SerialReciever.h"
#include "Config/ConfigManager.h"

#include <QDebug>

HeliosHermes::HeliosHermes(int& argc, char** argv) :
    QCoreApplication(argc, argv)
{
    qDebug() << "Here We Go Again";

    //load in settings
    ConfigManager& config = ConfigManager::instance();

    //start serial port listener which will emit dataRecieved signal and populate packets as required
    SerialReciever* serialReciever = new SerialReciever();

    //send json message every interval
}

HeliosHermes::~HeliosHermes(){}
