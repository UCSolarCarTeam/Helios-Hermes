#pragma once

#include "DataLayer/VehicleData/I_VehicleData.h"

class MockVehicleData : public I_VehicleData
{
public:

    /*VehicleData "Gets"*/
    MOCK_CONST_METHOD0(driverSetSpeedMetersPerSecond, double()); // double driverSetSpeedMetersPerSecond() const;
    MOCK_CONST_METHOD0(driverSetCurrent, double()); // double driverSetCurrent() const;
    MOCK_CONST_METHOD0(vehicleVelocityMetersPerSecond, double()); // double vehicleVelocityMetersPerSecond() const;
    MOCK_CONST_METHOD0(motorVelocityRpm, double()); // double motorVelocityRpm() const;
    MOCK_CONST_METHOD0(ipmHeatSinkTemp, double()); // double ipmHeatSinkTemp() const;
    MOCK_CONST_METHOD0(dspBoardTemp, double()); // double dspBoardTemp() const;
    MOCK_CONST_METHOD0(receivedErrorCount, double()); // double receivedErrorCount() const;
    MOCK_CONST_METHOD0(transmittedErrorCount, double()); // double transmittedErrorCount() const;

    /*VehicleData "Sets"*/
    MOCK_METHOD1(setDriverSetSpeedMetersPerSecond, void(double)); // void setDriverSetSpeedMetersPerSecond(double driverSetSpeedMetersPerSecond);
    MOCK_METHOD1(setDriverSetCurrent, void(double)); // void setDriverSetCurrent(double driverSetCurrent);
    MOCK_METHOD1(setVehicleVelocityMetersPerSecond, void(double)); // void setVehicleVelocityMetersPerSecond(double vehicleVelocityMetersPerSecond);
    MOCK_METHOD1(setMotorVelocityRpm, void(double)); // void setMotorVelocityRpm(double motorVelocityRpm);
    MOCK_METHOD1(setIpmHeatSinkTemp, void(double)); // void setIpmHeatSinkTemp(double ipmHeatSinkTemp);
    MOCK_METHOD1(setDspBoardTemp, void(double)); // void setDspBoardTemp(double dspBoardTemp);
    MOCK_METHOD1(setReceivedErrorCount, void(double)); // void setReceivedErrorCount(double receivedErrorCount);
    MOCK_METHOD1(setTransmittedErrorCount, void(double)); // void setTransmittedErrorCount(double transmittedErrorCount);
};

