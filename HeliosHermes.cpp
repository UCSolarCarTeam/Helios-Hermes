#include "HeliosHermes.h"
#include "SerialReciever/SerialReciever.h"
#include "Config/ConfigManager.h"
#include "StreamProcessor/StreamProcessor.h"
#include "PacketFactory/PacketFactory.h"
#include "MessageTransmitter/MessageTransmitter.h"
#include "MessageAggregator/MessageAggregator.h"
#include "GPIOReader/GPIOReader.h"

#include <QDebug>

HeliosHermes::HeliosHermes(int& argc, char** argv) :
    QCoreApplication(argc, argv)
{
    qDebug() << "Firing 'er up";

    //load in settings and initialize Packet factory
    ConfigManager& config = ConfigManager::instance();
    PacketFactory* packetFactory = new PacketFactory();

    //initialize SerialReciever which will begin to listen to serial port for incoming data
    SerialReciever* serialReciever = new SerialReciever();

    //initialize StreamProcessor which will process incoming data via signal/slot connected to serialReciever
    StreamProcessor* streamProcessor = new StreamProcessor(serialReciever, packetFactory);

    //initialize GPIOReader which will read GPIO data and forward directly to the PiPacket
    GPIOReader* gpioReader = new GPIOReader();

    //initialize MessageTransmitter which will transmit data every period of time deinifed in config.ini
    MessageTransmitter* messageTransmitter = new MessageTransmitter();

    //initialize MessageAggregator which will aggregate all packets into one json message and transmit
    MessageAggregator* messageAggregator = new MessageAggregator(messageTransmitter, packetFactory);
    messageAggregator->startTransmission();
}

HeliosHermes::~HeliosHermes(){}
