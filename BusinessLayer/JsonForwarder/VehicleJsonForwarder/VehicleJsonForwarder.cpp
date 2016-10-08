#include <QJsonDocument>
#include <QJsonObject>

#include "BusinessLayer/JsonForwarder/JsonDefines.h"
#include "CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"
#include "DataLayer/VehicleData/I_VehicleData.h"
#include "VehicleJsonForwarder.h"

VehicleJsonForwarder::VehicleJsonForwarder(I_VehicleData& vehicleData,
                                           I_MessageForwarder& messageForwarder)
: vehicleData_(vehicleData)
, messageForwarder_(messageForwarder)
{
}

void VehicleJsonForwarder::forwardVehicleData(const QJsonObject& baseJson)
{
    QJsonObject vehicleJson = baseJson;
    vehicleJson[JsonFormat::DATA_TYPE] = JsonFormat::VEHICLE;

    vehicleJson[JsonFormat::DRIVER_SET_SPEED_METERS_PER_SECOND] = QString::number(vehicleData_.driverSetSpeedMetersPerSecond(), 'f', JsonFormat::DECIMAL_PRECISION);
    vehicleJson[JsonFormat::DRIVER_SET_CURRENT] = QString::number(vehicleData_.driverSetCurrent(), 'f', JsonFormat::DECIMAL_PRECISION);
    vehicleJson[JsonFormat::VEHICLE_VELOCITY_METERS_PER_SECOND] = QString::number(vehicleData_.vehicleVelocityMetersPerSecond(), 'f', JsonFormat::DECIMAL_PRECISION);
    vehicleJson[JsonFormat::MOTOR_VELOCITY_RPM] = QString::number(vehicleData_.motorVelocityRpm(), 'f', JsonFormat::DECIMAL_PRECISION);
    vehicleJson[JsonFormat::IPM_HEAT_SINK_TEMP] = QString::number(vehicleData_.ipmHeatSinkTemp(), 'f', JsonFormat::DECIMAL_PRECISION);
    vehicleJson[JsonFormat::DSP_BOARD_TEMP] = QString::number(vehicleData_.dspBoardTemp(), 'f', JsonFormat::DECIMAL_PRECISION);
    vehicleJson[JsonFormat::RECEIVED_ERROR_COUNT] = QString::number(vehicleData_.receivedErrorCount(), 'f', JsonFormat::DECIMAL_PRECISION);
    vehicleJson[JsonFormat::TRANSMITTED_ERROR_COUNT] = QString::number(vehicleData_.transmittedErrorCount(), 'f', JsonFormat::DECIMAL_PRECISION);

    messageForwarder_.forwardData(QJsonDocument(vehicleJson).toJson(QJsonDocument::Compact));
}
