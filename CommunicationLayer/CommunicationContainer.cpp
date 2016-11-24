#include <QtSerialPort/QSerialPort>
#include <QUdpSocket>

#include "InfrastructureLayer/InfrastructureContainer.h"
#include "DataLayer/DataContainer.h"
#include "CommDeviceControl/RadioCommDevice.h"
#include "CommDeviceControl/UdpMessageForwarder.h"
#include "CommunicationContainer.h"
#include "DataPopulators/BatteryFaultsPopulator.h"
#include "DataPopulators/BatteryPopulator.h"
#include "DataPopulators/CmuPopulator.h"
#include "DataPopulators/DriverControlsPopulator.h"
#include "DataPopulators/KeyMotorPopulator.h"
#include "DataPopulators/LightsPopulator.h"
#include "DataPopulators/MotorDetailsPopulator.h"
#include "DataPopulators/MotorFaultsPopulator.h"
#include "DataPopulators/MpptPopulator.h"
#include "DataPopulators/OtherPopulator.h"
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
        , BatteryFaultsPopulator(packetDecoder, dataContainer.batteryFaultsData())
        , batteryPopulator(packetDecoder, dataContainer.batteryData())
        , cmuPopulator(packetDecoder, dataContainer.cmuData())
        , driverControlsPopulator(packetDecoder, dataContainer.driverControlsData())
        , keyMotorPopulator(packetDecoder, dataContainer.keyMotorData())
        , lightsPopulator(packetDecoder, dataContainer.lightsData())
        , motorDetailsPopulator(packetDecoder, dataContainer.motorDetailsData())
        , motorFaultsPopulator(packetDecoder, dataContainer.motorFaultsData())
        , mpptPopulator(packetDecoder, dataContainer.mpptData())
        , otherPopulator(packetDecoder, dataContainer.otherData())
    {
    }

    QSerialPort serialPort;
    RadioCommDevice radioCommDevice;
    UdpMessageForwarder messageForwarder;
    PacketSynchronizer packetSynchronizer;
    PacketUnstuffer packetUnstuffer;
    PacketChecksumChecker packetChecksumChecker;
    PacketDecoder packetDecoder;
    BatteryFaultsPopulator batteryFaultsPopulator;
    BatteryPopulator batteryPopulator;
    CmuPopulator cmuPopulator;
    DriverControlsPopulator driverControlsPopulator;
    KeyMotorPopulator keyMotorPopulator;
    LightsPopulator lightsPopulator;
    MotorDetailsPopulator motorDetailsPopulator;
    MotorFaultsPopulator motorFaultsPopulator;
    MpptPopulator mpptPopulator;
    OtherPopulator otherPopulator;
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
