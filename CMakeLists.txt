cmake_minimum_required(VERSION 3.14)

project(HeliosHermes LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(${CMAKE_SOURCE_DIR}/config.ini.example ${CMAKE_BINARY_DIR}/config.ini COPYONLY)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core SerialPort Mqtt)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core SerialPort Mqtt)

add_executable(HeliosHermes
  main.cpp
  HeliosHermes.h HeliosHermes.cpp
  Config/ConfigManager.h Config/ConfigManager.cpp
  Config/JsonDefinitions.h
  SerialReciever/SerialReciever.h SerialReciever/SerialReciever.cpp
  StreamProcessor/StreamProcessor.h StreamProcessor/StreamProcessor.cpp

  MessageAggregator/MessageAggregator.h MessageAggregator/MessageAggregator.cpp
  MessageTransmitter/MessageTransmitter.h MessageTransmitter/MessageTransmitter.cpp
  PacketFactory/PacketFactory.h PacketFactory/PacketFactory.cpp
  PacketFactory/Packets/KeyMotorPacket.h PacketFactory/Packets/KeyMotorPacket.cpp
  PacketFactory/Packets/IPacket.h
  PacketFactory/Packets/MotorDetailsPacket.h PacketFactory/Packets/MotorDetailsPacket.cpp
  PacketFactory/Packets/B3Packet.h PacketFactory/Packets/B3Packet.cpp
  PacketFactory/Packets/TelemetryPacket.h PacketFactory/Packets/TelemetryPacket.cpp
  PacketFactory/Packets/BatteryFaultsPacket.h PacketFactory/Packets/BatteryFaultsPacket.cpp
  PacketFactory/Packets/BatteryPacket.h PacketFactory/Packets/BatteryPacket.cpp
  PacketFactory/Packets/MpptPacket.h PacketFactory/Packets/MpptPacket.cpp
  PacketFactory/Packets/MbmsPacket.h PacketFactory/Packets/MbmsPacket.cpp
  PacketFactory/Packets/ProximitySensorsPacket.h PacketFactory/Packets/ProximitySensorsPacket.cpp
)

target_link_libraries(HeliosHermes Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Mqtt Qt${QT_VERSION_MAJOR}::SerialPort)

include(GNUInstallDirs)
install(TARGETS HeliosHermes
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
