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

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "BatteryJsonForwarder.h"
#include "BusinessLayer/JsonForwarder/JsonDefines.h"
#include "CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"
#include "DataLayer/BatteryData/I_BatteryData.h"

BatteryJsonForwarder::BatteryJsonForwarder(I_BatteryData& batteryData,
                                           I_MessageForwarder& messageForwarder)
: batteryData_(batteryData)
, messageForwarder_(messageForwarder)
{
}

void BatteryJsonForwarder::forwardBatteryData(const QJsonObject& baseJson)
{
    QJsonObject batteryJson = baseJson;
    batteryJson[JsonFormat::DATA_TYPE] = JsonFormat::BATTERY;

    QJsonObject mod0 = QJsonObject();
    mod0[JsonFormat::PCB_TEMPERATURE] = QString::number(batteryData_.mod0PcbTemperature(), 'f', JsonFormat::DECIMAL_PRECISION);
    mod0[JsonFormat::CELL_TEMPERATURE] = QString::number(batteryData_.mod0CellTemperature(), 'f', JsonFormat::DECIMAL_PRECISION);
    QJsonArray mod0CellVoltages = { QString::number(batteryData_.mod0CellVoltages()[0], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod0CellVoltages()[1], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod0CellVoltages()[2], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod0CellVoltages()[3], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod0CellVoltages()[4], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod0CellVoltages()[5], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod0CellVoltages()[6], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod0CellVoltages()[7], 'f', JsonFormat::DECIMAL_PRECISION)
                                  };
    mod0[JsonFormat::CELL_VOLTAGES] = mod0CellVoltages;
    batteryJson[JsonFormat::MOD_0] = mod0;

    QJsonObject mod1 = QJsonObject();
    mod1[JsonFormat::PCB_TEMPERATURE] = QString::number(batteryData_.mod1PcbTemperature(), 'f', JsonFormat::DECIMAL_PRECISION);
    mod1[JsonFormat::CELL_TEMPERATURE] = QString::number(batteryData_.mod1CellTemperature(), 'f', JsonFormat::DECIMAL_PRECISION);
    QJsonArray mod1CellVoltages = { QString::number(batteryData_.mod1CellVoltages()[0], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod1CellVoltages()[1], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod1CellVoltages()[2], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod1CellVoltages()[3], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod1CellVoltages()[4], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod1CellVoltages()[5], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod1CellVoltages()[6], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod1CellVoltages()[7], 'f', JsonFormat::DECIMAL_PRECISION)
                                  };
    mod1[JsonFormat::CELL_VOLTAGES] = mod1CellVoltages;
    batteryJson[JsonFormat::MOD_1] = mod1;

    QJsonObject mod2 = QJsonObject();
    mod2[JsonFormat::PCB_TEMPERATURE] = QString::number(batteryData_.mod2PcbTemperature(), 'f', JsonFormat::DECIMAL_PRECISION);
    mod2[JsonFormat::CELL_TEMPERATURE] = QString::number(batteryData_.mod2CellTemperature(), 'f', JsonFormat::DECIMAL_PRECISION);
    QJsonArray mod2CellVoltages = { QString::number(batteryData_.mod2CellVoltages()[0], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod2CellVoltages()[1], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod2CellVoltages()[2], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod2CellVoltages()[3], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod2CellVoltages()[4], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod2CellVoltages()[5], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod2CellVoltages()[6], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod2CellVoltages()[7], 'f', JsonFormat::DECIMAL_PRECISION)
                                  };
    mod2[JsonFormat::CELL_VOLTAGES] = mod2CellVoltages;
    batteryJson[JsonFormat::MOD_2] = mod2;

    QJsonObject mod3 = QJsonObject();
    mod3[JsonFormat::PCB_TEMPERATURE] = QString::number(batteryData_.mod3PcbTemperature(), 'f', JsonFormat::DECIMAL_PRECISION);
    mod3[JsonFormat::CELL_TEMPERATURE] = QString::number(batteryData_.mod3CellTemperature(), 'f', JsonFormat::DECIMAL_PRECISION);
    QJsonArray mod3CellVoltages = { QString::number(batteryData_.mod3CellVoltages()[0], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod3CellVoltages()[1], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod3CellVoltages()[2], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod3CellVoltages()[3], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod3CellVoltages()[4], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod3CellVoltages()[5], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod3CellVoltages()[6], 'f', JsonFormat::DECIMAL_PRECISION),
                                    QString::number(batteryData_.mod3CellVoltages()[7], 'f', JsonFormat::DECIMAL_PRECISION)
                                  };
    mod3[JsonFormat::CELL_VOLTAGES] = mod3CellVoltages;
    batteryJson[JsonFormat::MOD_3] = mod3;

    batteryJson[JsonFormat::BATTERY_VOLTAGE] = QString::number(batteryData_.batteryVoltage(), 'f', JsonFormat::DECIMAL_PRECISION);
    batteryJson[JsonFormat::BATTERY_CURRENT] = QString::number(batteryData_.batteryCurrent(), 'f', JsonFormat::DECIMAL_PRECISION);

    messageForwarder_.forwardData(QJsonDocument(batteryJson).toJson(QJsonDocument::Compact));
}
