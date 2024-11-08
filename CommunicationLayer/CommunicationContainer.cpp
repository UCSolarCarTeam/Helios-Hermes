#include <QtSerialPort/QSerialPort>

#include "../InfrastructureLayer/InfrastructureContainer.h"
#include "../DataLayer/DataContainer.h"
#include "CommDeviceControl/RadioCommDevice.h"
#include "CommDeviceControl/OutputRadioCommDevice.h"
#include "CommDeviceControl/MqttMessageForwarder.h"
#include "CommunicationContainer.h"

#include "DataPopulators/KeyMotorPopulator.h"
#include "DataPopulators/ProximitySensorsPopulator.h"
#include "DataPopulators/B3Populator.h"
#include "DataPopulators/TelemetryPopulator.h"
#include "DataPopulators/BatteryPopulator.h"
#include "DataPopulators/BatteryFaultsPopulator.h"
#include "DataPopulators/MbmsPopulator.h"
#include "DataPopulators/MpptPopulator.h"
#include "DataPopulators/MotorDetailsPopulator.h"

#include "PacketChecksumChecker/PacketChecksumChecker.h"
#include "PacketDecoder/PacketDecoder.h"
#include "PacketSynchronizer/PacketSynchronizer.h"
#include "PacketUnstuffer/PacketUnstuffer.h"

class CommunicationContainerPrivate
{
public:
    CommunicationContainerPrivate(DataContainer& dataContainer, InfrastructureContainer& infrastructureContainer)
        : radioCommDevice(serialPort, infrastructureContainer.settings())
        , outputRadioCommDevice(radioCommDevice, outputSerialPort, infrastructureContainer.settings())
        , messageForwarder(infrastructureContainer.settings())
        , packetSynchronizer(radioCommDevice)
        , packetUnstuffer(packetSynchronizer)
        , packetChecksumChecker(packetUnstuffer)
        , packetDecoder(packetChecksumChecker)
        , keyMotorPopulator(packetDecoder, dataContainer.keyMotorData())
        , proximitySensorPopulator(packetDecoder, dataContainer.proximitySensorsData())
        , b3Populator(packetDecoder, dataContainer.b3Data())
        , telemetryPopulator(packetDecoder, dataContainer.telemetryData())
        , batteryPopulator(packetDecoder, dataContainer.batteryData())
        , batteryFaultsPopulator(packetDecoder, dataContainer.batteryFaultsData())
        , mbmsPopulator(packetDecoder, dataContainer.mbmsData())
        , mpptPopulator(packetDecoder, dataContainer.mpptData())
        , motorDetailsPopulator(packetDecoder, dataContainer.motorDetailsData())
    {
        qDebug() << "CALLED" ;
    }

    QSerialPort serialPort;
    QSerialPort outputSerialPort;
    RadioCommDevice radioCommDevice;
    OutputRadioCommDevice outputRadioCommDevice;
    MqttMessageForwarder messageForwarder;
    PacketSynchronizer packetSynchronizer;
    PacketUnstuffer packetUnstuffer;
    PacketChecksumChecker packetChecksumChecker;
    PacketDecoder packetDecoder;
    KeyMotorPopulator keyMotorPopulator;
    ProximitySensorsPopulator proximitySensorPopulator;
    B3Populator b3Populator;
    TelemetryPopulator telemetryPopulator;
    BatteryPopulator batteryPopulator;
    BatteryFaultsPopulator batteryFaultsPopulator;
    MbmsPopulator mbmsPopulator;
    MpptPopulator mpptPopulator;
    MotorDetailsPopulator motorDetailsPopulator;
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

I_CommDevice& CommunicationContainer::outputCommDevice()
{
    return impl_->outputRadioCommDevice;
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

I_MessageForwarder& CommunicationContainer::messageForwarder()
{
    return impl_->messageForwarder;
}
