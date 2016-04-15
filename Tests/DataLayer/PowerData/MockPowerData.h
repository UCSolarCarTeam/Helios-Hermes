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

#pragma once

#include "DataLayer/PowerData/I_PowerData.h"

class MockPowerData : public I_PowerData
{
public:

    /*PowerData "Gets"*/
    MOCK_CONST_METHOD0(busCurrentA, double()); // double busCurrentA() const;
    MOCK_CONST_METHOD0(busVoltage, double()); // double busVoltage() const;
    MOCK_CONST_METHOD0(motorVoltageReal, double()); // double motorVoltageReal() const;
    MOCK_CONST_METHOD0(motorCurrentReal, double()); // double motorCurrentReal() const;
    MOCK_CONST_METHOD0(backEmfImaginary, double()); // double backEmfImaginary() const;
    MOCK_CONST_METHOD0(dcBusAmpHours, double()); // double dcBusAmpHours() const;

    /*PowerData "Sets"*/
    MOCK_METHOD1(setBusCurrentA, void(double)); // void setBusCurrentA(double busCurrentA);
    MOCK_METHOD1(setBusVoltage, void(double)); // void setBusVoltage(double busVoltage);
    MOCK_METHOD1(setMotorVoltageReal, void(double)); // void setMotorVoltageReal(double motorVoltageReal);
    MOCK_METHOD1(setMotorCurrentReal, void(double)); // void setMotorCurrentReal(double motorCurrentReal);
    MOCK_METHOD1(setBackEmfImaginary, void(double)); // void setBackEmfImaginary(double backEmfImaginary);
    MOCK_METHOD1(setDcBusAmpHours, void(double)); // void setDcBusAmpHours(double dcBusAmpHours);
};

