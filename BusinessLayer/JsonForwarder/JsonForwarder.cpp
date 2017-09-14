#include <QTimer>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDateTime>

#include "CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"
#include "InfrastructureLayer/Settings/I_Settings.h"
#include "JsonDefines.h"
#include "JsonForwarder.h"

namespace
{
    const QString MYSQL_DATE_FORMAT = "yyyy-MM-dd HH:mm:ss";
}

JsonForwarder::JsonForwarder(
    I_BatteryData& batteryData,
    I_BatteryFaultsData& batteryFaultsData,
    I_DriverControlsData& driverControlsData,
    I_KeyMotorData& keyMotorData,
    I_LightsData& lightsData,
    I_MotorDetailsData& motorDetailsData,
    I_MotorFaultsData& motorFaultsData,
    I_MpptData& mpptData,
    I_MessageForwarder& messageForwarder,
    I_Settings& settings)
    : batteryData_(batteryData)
    , batteryFaultsData_(batteryFaultsData)
    , driverControlsData_(driverControlsData)
    , keyMotorData_(keyMotorData)
    , lightsData_(lightsData)
    , motorDetailsData_(motorDetailsData)
    , motorFaultsData_(motorFaultsData)
    , mpptData_(mpptData)
    , messageForwarder_(messageForwarder)
    , readTimer_(new QTimer())
    , forwardPeriod_(settings.forwardPeriod())
    , PACKET_TITLE_(settings.packetTitle())
{
    connect(readTimer_.data(), SIGNAL(timeout()), this, SLOT(forwardData()));
}

JsonForwarder::~JsonForwarder()
{}

void JsonForwarder::startForwardingData()
{
    readTimer_->setInterval(forwardPeriod_);
    readTimer_->start();
}

void JsonForwarder::forwardData()
{
    QJsonObject baseJson = QJsonObject();
    baseJson[JsonFormat::PACKET_TITLE] = PACKET_TITLE_;
    QString currentTime = QDateTime::currentDateTime().toUTC().toString(MYSQL_DATE_FORMAT);
    baseJson[JsonFormat::TIMESTAMP] = currentTime;

    messageForwarder_.forwardData(QJsonDocument(baseJson).toJson(QJsonDocument::Compact));
}
