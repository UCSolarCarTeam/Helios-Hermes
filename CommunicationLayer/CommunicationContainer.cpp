#include <QtSerialPort/QSerialPort>
#include <QUdpSocket>

#include "InfrastructureLayer/InfrastructureContainer.h"
#include "DataLayer/DataContainer.h"
#include "CommDeviceControl/RadioCommDevice.h"
#include "CommDeviceControl/UdpMessageForwarder.h"
#include "CommunicationContainer.h"
#include "DataPopulators/BatteryPopulator.h"
#include "DataPopulators/CmuPopulator.h"
#include "DataPopulators/DriverDetailsPopulator.h"
#include "DataPopulators/FaultsPopulator.h"
#include "DataPopulators/KeyDriverControlPopulator.h"
#include "PacketChecksumChecker/PacketChecksumChecker.h"
#include "PacketDecoder/PacketDecoder.h"
#include "PacketSynchronizer/PacketSynchronizer.h"
#include "PacketUnstuffer/PacketUnstuffer.h"

class CommunicationContainerPrivate
{
public:
    CommunicationContainerPrivate(DataContainer& dataContainer, InfrastructureContainer& infrastructureContainer)
        : radioCommDevice(serialPort, infrastructureContainer.settings())
        , messageForwarder(infrastructureContainer.settings())
        , packetSynchronizer(radioCommDevice)
        , packetUnstuffer(packetSynchronizer)
        , packetChecksumChecker(packetUnstuffer)
        , packetDecoder(packetChecksumChecker)
        , keyDriverControlPopulator(
              packetDecoder,
              dataContainer.vehicleData(),
              dataContainer.powerData())
        , driverDetailsPopulator(
              packetDecoder,
              dataContainer.vehicleData(),
              dataContainer.powerData())
        , faultsPopulator(
              packetDecoder,
              dataContainer.faultsData())
        , batteryPopulator(
              packetDecoder,
              dataContainer.batteryData())
        , cmuPopulator(
              packetDecoder,
              dataContainer.batteryData())
    {
    }

    QSerialPort serialPort;
    RadioCommDevice radioCommDevice;
    UdpMessageForwarder messageForwarder;
    PacketSynchronizer packetSynchronizer;
    PacketUnstuffer packetUnstuffer;
    PacketChecksumChecker packetChecksumChecker;
    PacketDecoder packetDecoder;
    KeyDriverControlPopulator keyDriverControlPopulator;
    DriverDetailsPopulator driverDetailsPopulator;
    FaultsPopulator faultsPopulator;
    BatteryPopulator batteryPopulator;
    CmuPopulator cmuPopulator;
};

CommunicationContainer::CommunicationContainer(DataContainer& dataContainer, InfrastructureContainer& infrastructureContainer)
    : impl_(new CommunicationContainerPrivate(dataContainer, infrastructureContainer))
{
}

CommunicationContainer::~CommunicationContainer()
{
}

I_CommDevice& CommunicationContainer::commDevice()
{
    return impl_->radioCommDevice;
}

I_PacketSynchronizer& CommunicationContainer::packetSynchronizer()
{
    return impl_->packetSynchronizer;
}

I_DataInjectionService& CommunicationContainer::dataInjectionService()
{
    return impl_->packetUnstuffer;
}

I_PacketDecoder& CommunicationContainer::packetDecoder()
{
    return impl_->packetDecoder;
}

I_PacketChecksumChecker& CommunicationContainer::packetChecksumChecker()
{
    return impl_->packetChecksumChecker;
}

I_MessageForwarder& CommunicationContainer::udpMessageForwarder()
{
    return impl_->messageForwarder;
}
