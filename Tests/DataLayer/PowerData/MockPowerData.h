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

