#include <QtSerialPort/QSerialPort>

#include "../InfrastructureLayer/InfrastructureContainer.h"
#include "../DataLayer/DataContainer.h"
#include "CommDeviceControl/RadioCommDevice.h"
#include "CommDeviceControl/OutputRadioCommDevice.h"
#include "CommDeviceControl/MqttMessageForwarder.h"
#include "CommunicationContainer.h"
//#include "DataPopulators/AuxBmsPopulator.h"
// #include "DataPopulators/CcsPopulator.h"
// #include "DataPopulators/BatteryFaultsPopulator.h"
// #include "DataPopulators/BatteryPopulator.h"
// #include "DataPopulators/DriverControlsPopulator.h"
#include "DataPopulators/KeyMotorPopulator.h"
#include "DataPopulators/ProximitySensorsPopulator.h"
#include "DataPopulators/B3Populator.h"
#include "DataPopulators/TelemetryPopulator.h"
#include "DataPopulators/BatteryPopulator.h"
#include "DataPopulators/BatteryFaultsPopulator.h"
#include "DataPopulators/MbmsPopulator.h"
#include "DataPopulators/MpptPopulator.h"
// #include "DataPopulators/LightsPopulator.h"
// #include "DataPopulators/MotorDetailsPopulator.h"
// #include "DataPopulators/MotorFaultsPopulator.h"
// #include "DataPopulators/MpptPopulator.h"
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
        // , auxBmsPopulator(packetDecoder, dataContainer.auxBmsData())
        // , batteryFaultsPopulator(packetDecoder, dataContainer.batteryFaultsData())
        // , batteryPopulator(packetDecoder, dataContainer.batteryData())
        // , driverControlsPopulator(packetDecoder, dataContainer.driverControlsData())
        , keyMotorPopulator(packetDecoder, dataContainer.keyMotorData())
        , proximitySensorPopulator(packetDecoder, dataContainer.proximitySensorsData())
        , b3Populator(packetDecoder, dataContainer.b3Data())
        , telemetryPopulator(packetDecoder, dataContainer.telemetryData())
        , batteryPopulator(packetDecoder, dataContainer.batteryData())
        , batteryFaultsPopulator(packetDecoder, dataContainer.batteryFaultsData())
        , mbmsPopulator(packetDecoder, dataContainer.mbmsData())
        , mpptPopulator(packetDecoder, dataContainer.mpptData())
        // , lightsPopulator(packetDecoder, dataContainer.lightsData())
        // , motorDetailsPopulator(packetDecoder, dataContainer.motorDetailsData())
        // , motorFaultsPopulator(packetDecoder, dataContainer.motorFaultsData())
        // , mpptPopulator(packetDecoder, dataContainer.mpptData())
        // , ccsPopulator(packetChecksumChecker, dataContainer.ccsData())
    {
        qDebug() << "CALLED" ;
    }

    QSerialPort serialPort;
    QSerialPort outputSerialPort;
    RadioCommDevice radioCommDevice;
    OutputRadioCommDevice outputRadioCommDevice;
    RabbitMqMessageForwarder messageForwarder;
    PacketSynchronizer packetSynchronizer;
    PacketUnstuffer packetUnstuffer;
    PacketChecksumChecker packetChecksumChecker;
    PacketDecoder packetDecoder;
    // AuxBmsPopulator auxBmsPopulator;
    // BatteryFaultsPopulator batteryFaultsPopulator;
    // BatteryPopulator batteryPopulator;
    // DriverControlsPopulator driverControlsPopulator;
    KeyMotorPopulator keyMotorPopulator;
    ProximitySensorsPopulator proximitySensorPopulator;
    B3Populator b3Populator;
    TelemetryPopulator telemetryPopulator;
    BatteryPopulator batteryPopulator;
    BatteryFaultsPopulator batteryFaultsPopulator;
    MbmsPopulator mbmsPopulator;
    MpptPopulator mpptPopulator;
    // LightsPopulator lightsPopulator;
    // MotorDetailsPopulator motorDetailsPopulator;
    // MotorFaultsPopulator motorFaultsPopulator;
    // MpptPopulator mpptPopulator;
    // CcsPopulator ccsPopulator;
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
