#include <QJsonDocument>
#include <QJsonObject>

#include "BusinessLayer/JsonForwarder/JsonDefines.h"
#include "CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"
#include "PowerJsonForwarder.h"

PowerJsonForwarder::PowerJsonForwarder(/*I_PowerData& powerData,*/
                                       I_MessageForwarder& messageForwarder)
    : /*powerData_(powerData)
    , */messageForwarder_(messageForwarder)
{
}

void PowerJsonForwarder::forwardPowerData(const QJsonObject& baseJson)
{
    QJsonObject powerJson = baseJson;
    /*powerJson[JsonFormat::DATA_TYPE] = JsonFormat::POWER;
    powerJson[JsonFormat::BUS_CURRENT_A] = QString::number(powerData_.busCurrentA(), 'f', JsonFormat::DECIMAL_PRECISION);
    powerJson[JsonFormat::BUS_VOLTAGE] = QString::number(powerData_.busVoltage(), 'f', JsonFormat::DECIMAL_PRECISION);
    powerJson[JsonFormat::MOTOR_VOLTAGE_REAL] = QString::number(powerData_.motorVoltageReal(), 'f', JsonFormat::DECIMAL_PRECISION);
    powerJson[JsonFormat::MOTOR_CURRENT_REAL] = QString::number(powerData_.motorCurrentReal(), 'f', JsonFormat::DECIMAL_PRECISION);
    powerJson[JsonFormat::BACK_EMF_IMAGINARY] = QString::number(powerData_.backEmfImaginary(), 'f', JsonFormat::DECIMAL_PRECISION);
    powerJson[JsonFormat::DC_BUS_AMP_HOURS] = QString::number(powerData_.dcBusAmpHours(), 'f', JsonFormat::DECIMAL_PRECISION);
    messageForwarder_.forwardData(QJsonDocument(powerJson).toJson(QJsonDocument::Compact));*/
}
