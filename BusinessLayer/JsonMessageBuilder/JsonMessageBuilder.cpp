#include "JsonMessageBuilder.h"

JsonMessageBuilder::JsonMessageBuilder()
{
}


QJsonObject JsonMessageBuilder::buildBatteryMessage(const I_BatteryData& data)
{
	Q_UNUSED(data);
	return QJsonObject();
}

QJsonObject JsonMessageBuilder::buildBatteryFaultsMessage(const I_BatteryFaultsData& data)
{
	Q_UNUSED(data);
	return QJsonObject();
}

QJsonObject JsonMessageBuilder::buildDriverControlsMessage(const I_DriverControlsData& data)
{
	Q_UNUSED(data);
	return QJsonObject();
}

QJsonArray JsonMessageBuilder::buildKeyMotorMessage(const I_KeyMotorData& data)
{
	Q_UNUSED(data);
	return QJsonArray();
}

QJsonObject JsonMessageBuilder::buildLightsMessage(const I_LightsData& data)
{
	Q_UNUSED(data);
	return QJsonObject();
}

QJsonArray JsonMessageBuilder::buildMotorDetailsMessage(const I_MotorDetailsData& data)
{
	Q_UNUSED(data);
	return QJsonArray();
}

QJsonArray JsonMessageBuilder::buildMotorFaultsMessage(const I_MotorFaultsData& data)
{
	Q_UNUSED(data);
	return QJsonArray();
}

QJsonArray JsonMessageBuilder::buildMpptMessage(const I_MpptData& data)
{
	Q_UNUSED(data);
	return QJsonArray();
}