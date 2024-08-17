#pragma once

#include <QJsonObject>
#include <QElapsedTimer>

#include "I_JsonMessageBuilder.h"

class I_PacketChecksumChecker;

class JsonMessageBuilder : public I_JsonMessageBuilder
{
    Q_OBJECT
public:
    virtual ~JsonMessageBuilder() {}
    JsonMessageBuilder();
    JsonMessageBuilder(const I_PacketChecksumChecker& checksumChecker);
    QJsonObject buildAuxBmsMessage(const I_AuxBmsData& data);
    QJsonObject buildCcsMessage(const I_CcsData& data);
    QJsonObject buildBatteryMessage(const I_BatteryData& data);
    QJsonObject buildBatteryFaultsMessage(const I_BatteryFaultsData& data);
    QJsonObject buildDriverControlsMessage(const I_DriverControlsData& data);
    QJsonArray buildKeyMotorMessage(const I_KeyMotorData& data);
    QJsonObject buildLightsMessage(const I_LightsData& data);
    QJsonArray buildMotorDetailsMessage(const I_MotorDetailsData& data);
    QJsonArray buildMotorFaultsMessage(const I_MotorFaultsData& data);
    QJsonArray buildMpptMessage(const I_MpptData& data);

};


