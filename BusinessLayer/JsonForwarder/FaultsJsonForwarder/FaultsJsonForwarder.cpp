/**
 *  Schulich Delta Hermes
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of Schulich Delta Hermes
 *
 *  Schulich Delta Hermes is free software:
 *  you can redistribute it and/or modify it under the terms
 *  of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  Schulich Delta Hermes is distributed
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General
 *  Public License along with Schulich Delta Hermes.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#include <QJsonDocument>
#include <QJsonObject>

#include "BusinessLayer/JsonForwarder/JsonDefines.h"
#include "CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"
#include "DataLayer/FaultsData/I_FaultsData.h"
#include "FaultsJsonForwarder.h"

FaultsJsonForwarder::FaultsJsonForwarder(I_FaultsData& faultsData,
                                         I_MessageForwarder& messageForwarder)
: faultsData_(faultsData)
, messageForwarder_(messageForwarder)
{
}

void FaultsJsonForwarder::forwardFaultsData(const QJsonObject& baseJson)
{
    QJsonObject faultsJson = baseJson;
    faultsJson[JsonFormat::DATA_TYPE] = JsonFormat::FAULTS;

    QJsonObject motorOneFaultsJson = QJsonObject();
    motorOneFaultsJson[JsonFormat::HARDWARE_OVER_CURRENT] = faultsData_.motorOneFaults().hardwareOverCurrent();
    motorOneFaultsJson[JsonFormat::SOFTWARE_OVER_CURRENT] = faultsData_.motorOneFaults().softwareOverCurrent();
    motorOneFaultsJson[JsonFormat::DC_BUS_OVER_VOLTAGE] = faultsData_.motorOneFaults().dcBusOverVoltage();
    motorOneFaultsJson[JsonFormat::BAD_MOTOR_POSITION_HALL_SEQUENCE] = faultsData_.motorOneFaults().badMotorPositionHallSequence();
    motorOneFaultsJson[JsonFormat::WATCHDOG_CAUSED_LAST_RESET] = faultsData_.motorOneFaults().watchdogCausedLastReset();
    motorOneFaultsJson[JsonFormat::CONFIG_READ_ERROR] = faultsData_.motorOneFaults().configReadError();
    motorOneFaultsJson[JsonFormat::RAIL_UNDER_VOLTAGE_LOCK_OUT] = faultsData_.motorOneFaults().railUnderVoltageLockOut();
    motorOneFaultsJson[JsonFormat::DESATURATION_FAULT] = faultsData_.motorOneFaults().desaturationFault();
    faultsJson[JsonFormat::MOTOR_ONE_FAULTS] = motorOneFaultsJson;

    QJsonObject motorTwoFaultsJson = QJsonObject();
    motorTwoFaultsJson[JsonFormat::HARDWARE_OVER_CURRENT] = faultsData_.motorTwoFaults().hardwareOverCurrent();
    motorTwoFaultsJson[JsonFormat::SOFTWARE_OVER_CURRENT] = faultsData_.motorTwoFaults().softwareOverCurrent();
    motorTwoFaultsJson[JsonFormat::DC_BUS_OVER_VOLTAGE] = faultsData_.motorTwoFaults().dcBusOverVoltage();
    motorTwoFaultsJson[JsonFormat::BAD_MOTOR_POSITION_HALL_SEQUENCE] = faultsData_.motorTwoFaults().badMotorPositionHallSequence();
    motorTwoFaultsJson[JsonFormat::WATCHDOG_CAUSED_LAST_RESET] = faultsData_.motorTwoFaults().watchdogCausedLastReset();
    motorTwoFaultsJson[JsonFormat::CONFIG_READ_ERROR] = faultsData_.motorTwoFaults().configReadError();
    motorTwoFaultsJson[JsonFormat::RAIL_UNDER_VOLTAGE_LOCK_OUT] = faultsData_.motorTwoFaults().railUnderVoltageLockOut();
    motorTwoFaultsJson[JsonFormat::DESATURATION_FAULT] = faultsData_.motorTwoFaults().desaturationFault();
    faultsJson[JsonFormat::MOTOR_TWO_FAULTS] = motorTwoFaultsJson;

    QJsonObject motorOneLimitsJson = QJsonObject();
    motorOneLimitsJson[JsonFormat::OUTPUT_VOLTAGE_PWM_LIMIT] = faultsData_.motorOneLimitFlags().outputVoltagePwmLimit();
    motorOneLimitsJson[JsonFormat::MOTOR_CURRENT_LIMIT] = faultsData_.motorOneLimitFlags().motorCurrentLimit();
    motorOneLimitsJson[JsonFormat::VELOCITY_LIMIT] = faultsData_.motorOneLimitFlags().velocityLimit();
    motorOneLimitsJson[JsonFormat::BUS_CURRENT_LIMIT] = faultsData_.motorOneLimitFlags().busCurrentLimit();
    motorOneLimitsJson[JsonFormat::BUS_VOLTAGE_UPPER_LIMIT] = faultsData_.motorOneLimitFlags().busVoltageUpperLimit();
    motorOneLimitsJson[JsonFormat::BUS_VOLTAGE_LOWER_LIMIT] = faultsData_.motorOneLimitFlags().busVoltageLowerLimit();
    motorOneLimitsJson[JsonFormat::IPM_OR_MOTOR_TELEMETRY_LIMIT] = faultsData_.motorOneLimitFlags().ipmOrMotorTelemetryLimit();
    faultsJson[JsonFormat::MOTOR_ONE_LIMIT_FLAGS] = motorOneLimitsJson;

    QJsonObject motorTwoLimitsJson = QJsonObject();
    motorTwoLimitsJson[JsonFormat::OUTPUT_VOLTAGE_PWM_LIMIT] = faultsData_.motorTwoLimitFlags().outputVoltagePwmLimit();
    motorTwoLimitsJson[JsonFormat::MOTOR_CURRENT_LIMIT] = faultsData_.motorTwoLimitFlags().motorCurrentLimit();
    motorTwoLimitsJson[JsonFormat::VELOCITY_LIMIT] = faultsData_.motorTwoLimitFlags().velocityLimit();
    motorTwoLimitsJson[JsonFormat::BUS_CURRENT_LIMIT] = faultsData_.motorTwoLimitFlags().busCurrentLimit();
    motorTwoLimitsJson[JsonFormat::BUS_VOLTAGE_UPPER_LIMIT] = faultsData_.motorTwoLimitFlags().busVoltageUpperLimit();
    motorTwoLimitsJson[JsonFormat::BUS_VOLTAGE_LOWER_LIMIT] = faultsData_.motorTwoLimitFlags().busVoltageLowerLimit();
    motorTwoLimitsJson[JsonFormat::IPM_OR_MOTOR_TELEMETRY_LIMIT] = faultsData_.motorTwoLimitFlags().ipmOrMotorTelemetryLimit();
    faultsJson[JsonFormat::MOTOR_TWO_LIMIT_FLAGS] = motorTwoLimitsJson;

    QJsonObject batteryFaultsJson = QJsonObject();
    batteryFaultsJson[JsonFormat::CELL_OVER_VOLTAGE] = faultsData_.batteryFaults().cellOverVoltage();
    batteryFaultsJson[JsonFormat::CELL_UNDER_VOLTAGE] = faultsData_.batteryFaults().cellUnderVoltage();
    batteryFaultsJson[JsonFormat::CELL_OVER_TEMPERATURE] = faultsData_.batteryFaults().cellOverTemperature();
    batteryFaultsJson[JsonFormat::MEASUREMENT_UNTRUSTED] = faultsData_.batteryFaults().measurementUntrusted();
    batteryFaultsJson[JsonFormat::CMU_COMM_TIMEOUT] = faultsData_.batteryFaults().cmuCommTimeout();
    batteryFaultsJson[JsonFormat::VEHICLE_COMM_TIMEOUT] = faultsData_.batteryFaults().vehicleCommTimeout();
    batteryFaultsJson[JsonFormat::BMU_IS_IN_SETUP_MODE] = faultsData_.batteryFaults().bmuIsInSetupMode();
    batteryFaultsJson[JsonFormat::CMU_CAN_BUS_POWER_STATUS] = faultsData_.batteryFaults().cmuCanBusPowerStatus();
    batteryFaultsJson[JsonFormat::PACK_ISOLATION_TEST_FAILURE] = faultsData_.batteryFaults().packIsolationTestFailure();
    batteryFaultsJson[JsonFormat::SOFTWARE_OVER_CURRENT_MEASURED] = faultsData_.batteryFaults().softwareOverCurrentMeasured();
    batteryFaultsJson[JsonFormat::CAN_SUPPLY_IS_LOW] = faultsData_.batteryFaults().canSupplyIsLow();
    batteryFaultsJson[JsonFormat::CONTACTOR_IS_STUCK] = faultsData_.batteryFaults().contactorIsStuck();
    batteryFaultsJson[JsonFormat::CMU_DETECTED_EXTRA_CELL_PRESENT] = faultsData_.batteryFaults().cmuDetectedExtraCellPresent();
    faultsJson[JsonFormat::BATTERY_FAULTS] = batteryFaultsJson;

    messageForwarder_.forwardData(QJsonDocument(faultsJson).toJson(QJsonDocument::Compact));
}
