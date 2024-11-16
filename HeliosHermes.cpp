#include "HeliosHermes.h"
#include "SerialReciever/SerialReciever.h"
#include "Config/ConfigManager.h"
#include "StreamProcessor/StreamProcessor.h"
#include "PacketFactory/PacketFactory.h"
#include "MessageTransmitter/MessageTransmitter.h"

#include <QDebug>

HeliosHermes::HeliosHermes(int& argc, char** argv) :
    QCoreApplication(argc, argv)
{
    qDebug() << "Here We Go Again";

    //load in settings
    ConfigManager& config = ConfigManager::instance();
    PacketFactory* packetFactory = new PacketFactory();

    //start serial port listener which will emit dataRecieved signal and populate packets as required
    SerialReciever* serialReciever = new SerialReciever();
    StreamProcessor* streamProcessor = new StreamProcessor(serialReciever, packetFactory);

    MessageTransmitter* messageTransmitter = new MessageTransmitter();
    //send json message every interval
}

HeliosHermes::~HeliosHermes(){}
