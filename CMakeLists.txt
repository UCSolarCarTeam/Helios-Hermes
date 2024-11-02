cmake_minimum_required(VERSION 3.14)

project(HeliosHermes LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core SerialPort Mqtt)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core SerialPort Mqtt)

add_executable(HeliosHermes
  main.cpp
  CommunicationLayer/CommDeviceControl/I_CommDevice.h CommunicationLayer/CommDeviceControl/I_ConnectionService.h CommunicationLayer/CommDeviceControl/I_MessageForwarder.h CommunicationLayer/CommDeviceControl/MqttMessageForwarder.cpp CommunicationLayer/CommDeviceControl/MqttMessageForwarder.h CommunicationLayer/CommDeviceControl/OutputRadioCommDevice.cpp CommunicationLayer/CommDeviceControl/OutputRadioCommDevice.h CommunicationLayer/CommDeviceControl/RadioCommDevice.cpp CommunicationLayer/CommDeviceControl/RadioCommDevice.h CommunicationLayer/PacketChecksumChecker/I_PacketChecksumChecker.h CommunicationLayer/PacketChecksumChecker/PacketChecksumChecker.cpp CommunicationLayer/PacketChecksumChecker/PacketChecksumChecker.h CommunicationLayer/PacketSynchronizer/I_PacketSynchronizer.h CommunicationLayer/PacketSynchronizer/PacketSynchronizer.cpp CommunicationLayer/PacketSynchronizer/PacketSynchronizer.h CommunicationLayer/PacketUnstuffer/I_DataInjectionService.h CommunicationLayer/PacketUnstuffer/I_PacketUnstuffer.h CommunicationLayer/PacketUnstuffer/PacketUnstuffer.cpp CommunicationLayer/PacketUnstuffer/PacketUnstuffer.h CommunicationLayer/CommunicationContainer.cpp CommunicationLayer/CommunicationContainer.h
  HeliosHermes.h HeliosHermes.cpp
  InfrastructureLayer/Logging/Logging.cpp InfrastructureLayer/Logging/Logging.h InfrastructureLayer/Settings/I_Settings.h InfrastructureLayer/Settings/Settings.cpp InfrastructureLayer/Settings/Settings.h InfrastructureLayer/InfrastructureContainer.cpp InfrastructureLayer/InfrastructureContainer.h
  CommunicationLayer/MessagingFramework/KeyMotorMessage.h CommunicationLayer/MessagingFramework/KeyMotorMessage.cpp
  CommunicationLayer/MessagingFramework/MessageDecodingUtils.h CommunicationLayer/MessagingFramework/MessageDecodingUtils.cpp
  CommunicationLayer/PacketDecoder/PacketDecoder.h CommunicationLayer/PacketDecoder/PacketDecoder.cpp
  CommunicationLayer/PacketDecoder/I_PacketDecoder.h
  CommunicationLayer/DataPopulators/KeyMotorPopulator.h CommunicationLayer/DataPopulators/KeyMotorPopulator.cpp
  DataLayer/DataContainer.h DataLayer/DataContainer.cpp

  DataLayer/KeyMotorData/KeyMotorData.h DataLayer/KeyMotorData/KeyMotorData.cpp

  DataLayer/SerialDefines.h
  BusinessLayer/BusinessContainer.h BusinessLayer/BusinessContainer.cpp
  BusinessLayer/JsonMessageBuilder/JsonMessageBuilder.h BusinessLayer/JsonMessageBuilder/JsonMessageBuilder.cpp
  BusinessLayer/JsonForwarder/JsonForwarder.h BusinessLayer/JsonForwarder/JsonForwarder.cpp
  BusinessLayer/JsonDefines.h
  CommunicationLayer/MessagingFramework/ProximitySensorsMessage.h CommunicationLayer/MessagingFramework/ProximitySensorsMessage.cpp
  CommunicationLayer/DataPopulators/ProximitySensorsPopulator.h CommunicationLayer/DataPopulators/ProximitySensorsPopulator.cpp
  DataLayer/ProximitySensorsData/ProximitySensorsData.h DataLayer/ProximitySensorsData/ProximitySensorsData.cpp

)

target_link_libraries(HeliosHermes Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Mqtt Qt${QT_VERSION_MAJOR}::SerialPort)

include(GNUInstallDirs)
install(TARGETS HeliosHermes
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
