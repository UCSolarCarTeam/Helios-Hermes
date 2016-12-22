#pragma once

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QDateTime>
#include <QDir>

#include "../../CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
class I_PacketDecoder;
class I_PacketSynchronizer;

class LoggerService : public QObject
{
    Q_OBJECT
public:
    LoggerService(const I_PacketSynchronizer& packetSynchronizer,
                  const I_PacketDecoder& packetDecoder);
    virtual ~LoggerService();

private slots:
    void handleFramedPacket(QByteArray packet);

    void handlePacketDecoded(const KeyMotorMessage message);
    void handlePacketDecoded(const MotorDetailsMessage message);
    void handlePacketDecoded(const DriverControlsMessage message);
    void handlePacketDecoded(const MotorFaultsMessage message);
    void handlePacketDecoded(const BatteryFaultsMessage message);
    void handlePacketDecoded(const BatteryMessage message);
    void handlePacketDecoded(const CmuMessage message);
    void handlePacketDecoded(const MpptMessage message);
    void handlePacketDecoded(const LightsMessage message);

private:
    void connectToPacketDecoder(const I_PacketDecoder& decoder);
    template <class T>
    void printReceivedMessage(const T& message);
    void markStartOfDebugLog() const;
    void markEndOfDebugLog() const;

    QFile logCsvFile_;
    QTextStream csvFileWriter_;

    QFile rawDataFile_;
    QDataStream dataWriter_;
};
