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

namespace JsonFormat
{
const int DECIMAL_PRECISION = 2;
const QString PACKET_TITLE = "packetTitle";
const QString TIMESTAMP = "timestamp";
const QString DATA_TYPE = "datatype";

/* Battery */
const QString BATTERY = "Battery";
const QString MOD_0 = "mod0";
const QString MOD_1 = "mod1";
const QString MOD_2 = "mod2";
const QString MOD_3 = "mod3";
const QString PCB_TEMPERATURE = "pcbTemperature";
const QString CELL_TEMPERATURE = "cellTemperature";
const QString CELL_VOLTAGES = "cellVoltages";
const QString BATTERY_VOLTAGE = "batteryVoltage";
const QString BATTERY_CURRENT = "batteryCurrent";

/* Faults */
const QString FAULTS = "Faults";;
/* Motor Faults */
const QString MOTOR_ONE_FAULTS = "motorOneFaults";
const QString MOTOR_TWO_FAULTS = "motorTwoFaults";
const QString HARDWARE_OVER_CURRENT = "hardwareOverCurrent";
const QString SOFTWARE_OVER_CURRENT = "softwareOverCurrent";
const QString DC_BUS_OVER_VOLTAGE = "dcBusOverVoltage";
const QString BAD_MOTOR_POSITION_HALL_SEQUENCE = "badMotorPositionHallSequence";
const QString WATCHDOG_CAUSED_LAST_RESET = "watchdogCausedLastReset";
const QString CONFIG_READ_ERROR = "configReadError";
const QString RAIL_UNDER_VOLTAGE_LOCK_OUT = "railUnderVoltageLockOut";
const QString DESATURATION_FAULT = "desaturationFault";
/* Motor Limits */
const QString MOTOR_ONE_LIMIT_FLAGS = "motorOneLimitFlags";
const QString MOTOR_TWO_LIMIT_FLAGS = "motorTwoLimitFlags";
const QString OUTPUT_VOLTAGE_PWM_LIMIT = "outputVoltagePwmLimit";
const QString MOTOR_CURRENT_LIMIT = "motorCurrentLimit";
const QString VELOCITY_LIMIT = "velocityLimit";
const QString BUS_CURRENT_LIMIT = "busCurrentLimit";
const QString BUS_VOLTAGE_UPPER_LIMIT = "busVoltageUpperLimit";
const QString BUS_VOLTAGE_LOWER_LIMIT = "busVoltageLowerLimit";
const QString IPM_OR_MOTOR_TELEMETRY_LIMIT = "ipmOrMotorTelemetryLimit";
/* Battery Faults */
const QString BATTERY_FAULTS = "batteryFaults";
const QString CELL_OVER_VOLTAGE = "cellOverVoltage";
const QString CELL_UNDER_VOLTAGE = "cellUnderVoltage";
const QString CELL_OVER_TEMPERATURE = "cellOverTemperature";
const QString MEASUREMENT_UNTRUSTED = "measurementUntrusted";
const QString CMU_COMM_TIMEOUT = "cmuCommTimeout";
const QString VEHICLE_COMM_TIMEOUT = "vehicleCommTimeout";
const QString BMU_IS_IN_SETUP_MODE = "bmuIsInSetupMode";
const QString CMU_CAN_BUS_POWER_STATUS = "cmuCanBusPowerStatus";
const QString PACK_ISOLATION_TEST_FAILURE = "packIsolationTestFailure";
const QString SOFTWARE_OVER_CURRENT_MEASURED = "softwareOverCurrentMeasured";
const QString CAN_SUPPLY_IS_LOW = "canSupplyIsLow";
const QString CONTACTOR_IS_STUCK = "contactorIsStuck";
const QString CMU_DETECTED_EXTRA_CELL_PRESENT = "cmuDetectedExtraCellPresent";

/* Power */
const QString POWER = "Power";
const QString BUS_CURRENT_A = "busCurrentA";
const QString BUS_VOLTAGE = "busVoltage";
const QString MOTOR_VOLTAGE_REAL = "motorVoltageReal";
const QString MOTOR_CURRENT_REAL = "motorCurrentReal";
const QString BACK_EMF_IMAGINARY = "backEmfImaginary";
const QString DC_BUS_AMP_HOURS = "dcBusAmpHours";

/* Vehicle */
const QString VEHICLE = "Vehicle";
const QString DRIVER_SET_SPEED_METERS_PER_SECOND = "driverSetSpeedMetersPerSecond";
const QString DRIVER_SET_CURRENT = "driverSetCurrent";
const QString VEHICLE_VELOCITY_METERS_PER_SECOND = "vehicleVelocityMetersPerSecond";
const QString MOTOR_VELOCITY_RPM = "motorVelocityRpm";
const QString IPM_HEAT_SINK_TEMP = "ipmHeatSinkTemp";
const QString DSP_BOARD_TEMP = "dspBoardTemp";
const QString RECEIVED_ERROR_COUNT = "receivedErrorCount";
const QString TRANSMITTED_ERROR_COUNT = "transmittedErrorCount";
}
