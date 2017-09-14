#pragma once

#include <QJsonObject>

#include "I_JsonMessageBuilder.h"

class JsonMessageBuilder : public I_JsonMessageBuilder
{
public:
    virtual ~JsonMessageBuilder() {}
    JsonMessageBuilder();
    QJsonObject buildBatteryMessage(const I_BatteryData& data);
    QJsonObject buildBatteryFaultsMessage(const I_BatteryFaultsData& data);
    QJsonObject buildDriverControlsMessage(const I_DriverControlsData& data);
    QJsonObject buildKeyMotorMessage(const I_KeyMotorData& data);
    QJsonObject buildLightsMessage(const I_LightsData& data);
    QJsonObject buildMotorDetailsMessage(const I_MotorDetailsData& data);
    QJsonObject buildMotorFaultsMessage(const I_MotorFaultsData& data);
    QJsonObject buildMpptMessage(const I_MpptData& data);
};