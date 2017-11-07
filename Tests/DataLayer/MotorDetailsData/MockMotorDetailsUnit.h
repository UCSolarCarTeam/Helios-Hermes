#pragma once

#include "DataLayer/MotorDetailsData/I_MotorDetailsUnit.h"

class MockMotorDetailsUnit : public I_MotorDetailsUnit
{
public:

    /*MotorDetailsUnit "Gets"*/
    MOCK_CONST_METHOD0(getMotorNumber, unsigned char());
    MOCK_CONST_METHOD0(getPhaseCCurrent, float());
    MOCK_CONST_METHOD0(getPhaseBCurrent, float());
    MOCK_CONST_METHOD0(getMotorVoltageReal, float());
    MOCK_CONST_METHOD0(getMotorVoltageImaginary, float());
    MOCK_CONST_METHOD0(getMotorCurrentReal, float());
    MOCK_CONST_METHOD0(getMotorCurrentImaginary, float());
    MOCK_CONST_METHOD0(getBackEmfReal, float());
    MOCK_CONST_METHOD0(getBackEmfImaginary, float());
    MOCK_CONST_METHOD0(getVoltageRailSuppply15V, float());
    MOCK_CONST_METHOD0(getVoltageRailSupply33V, float());
    MOCK_CONST_METHOD0(getVoltageRailSupply19V, float());
    MOCK_CONST_METHOD0(getHeatSinkTemperature, float());
    MOCK_CONST_METHOD0(getMotorTempterature, float());
    MOCK_CONST_METHOD0(getDspBoardTemperature, float());
    MOCK_CONST_METHOD0(getDcBusAmpHours, float());
    MOCK_CONST_METHOD0(getOdometer, float());
    MOCK_CONST_METHOD0(getSlipSpeed, float());

    /*MotorDetailsUnit "Gets"*/
    MOCK_METHOD1(setPhaseCCurrent, void(const float&));
    MOCK_METHOD1(setPhaseBCurrent, void(const float&));
    MOCK_METHOD1(setMotorVoltageReal, void(const float&));
    MOCK_METHOD1(setMotorVoltageImaginary, void(const float&));
    MOCK_METHOD1(setMotorCurrentReal, void(const float&));
    MOCK_METHOD1(setMotorCurrentImaginary, void(const float&));
    MOCK_METHOD1(setBackEmfReal, void(const float&));
    MOCK_METHOD1(setBackEmfImaginary, void(const float&));
    MOCK_METHOD1(setVoltageRailSuppply15V, void(const float&));
    MOCK_METHOD1(setVoltageRailSupply33V, void(const float&));
    MOCK_METHOD1(setVoltageRailSupply19V, void(const float&));
    MOCK_METHOD1(setHeatSinkTemperature, void(const float&));
    MOCK_METHOD1(setMotorTempterature, void(const float&));
    MOCK_METHOD1(setDspBoardTemperature, void(const float&));
    MOCK_METHOD1(setDcBusAmpHours, void(const float&));
    MOCK_METHOD1(setOdometer, void(const float&));
    MOCK_METHOD1(setSlipSpeed, void(const float&));
};
