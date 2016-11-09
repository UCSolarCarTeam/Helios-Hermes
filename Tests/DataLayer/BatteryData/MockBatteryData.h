#pragma once

#include "DataLayer/BatteryData/I_BatteryData.h"

class MockBatteryData : public I_BatteryData
{
public:

    /*BatteryData "Gets"*/
    MOCK_CONST_METHOD0(mod0PcbTemperature, double()); // double mod0PcbTemperature() const;
    MOCK_CONST_METHOD0(mod0CellTemperature, double()); // double mod0CellTemperature() const;
    MOCK_CONST_METHOD0(mod0CellVoltages, QList<double>()); // QList<double> mod0CellVoltages() const;
    MOCK_CONST_METHOD0(mod1PcbTemperature, double()); // double mod1PcbTemperature() const;
    MOCK_CONST_METHOD0(mod1CellTemperature, double()); // double mod1CellTemperature() const;
    MOCK_CONST_METHOD0(mod1CellVoltages, QList<double>()); // QList<double> mod1CellVoltages() const;
    MOCK_CONST_METHOD0(mod2PcbTemperature, double()); // double mod2PcbTemperature() const;
    MOCK_CONST_METHOD0(mod2CellTemperature, double()); // double mod2CellTemperature() const;
    MOCK_CONST_METHOD0(mod2CellVoltages, QList<double>()); // QList<double> mod2CellVoltages() const;
    MOCK_CONST_METHOD0(mod3PcbTemperature, double()); // double mod3PcbTemperature() const;
    MOCK_CONST_METHOD0(mod3CellTemperature, double()); // double mod3CellTemperature() const;
    MOCK_CONST_METHOD0(mod3CellVoltages, QList<double>()); // QList<double> mod3CellVoltages() const;
    MOCK_CONST_METHOD0(batteryVoltage, double()); // double batteryVoltage() const;
    MOCK_CONST_METHOD0(batteryCurrent, double()); // double batteryCurrent() const;

    /*BatteryData "Sets"*/
    MOCK_METHOD1(setMod0PcbTemperature, void(double)); // void setMod0PcbTemperature(double mod0PcbTemperature);
    MOCK_METHOD1(setMod0CellTemperature, void(double)); // void setMod0CellTemperature(double mod0CellTemperature);
    MOCK_METHOD1(setMod0CellVoltages, void(QList<double>)); // void setMod0CellVoltages(QList<double> mod0CellVoltages);
    MOCK_METHOD1(setMod1PcbTemperature, void(double)); // void setMod1PcbTemperature(double mod1PcbTemperature);
    MOCK_METHOD1(setMod1CellTemperature, void(double)); // void setMod1CellTemperature(double mod1CellTemperature);
    MOCK_METHOD1(setMod1CellVoltages, void(QList<double>)); // void setMod1CellVoltages(QList<double> mod1CellVoltages);
    MOCK_METHOD1(setMod2PcbTemperature, void(double)); // void setMod2PcbTemperature(double mod2PcbTemperature);
    MOCK_METHOD1(setMod2CellTemperature, void(double)); // void setMod2CellTemperature(double mod2CellTemperature);
    MOCK_METHOD1(setMod2CellVoltages, void(QList<double>)); // void setMod2CellVoltages(QList<double> mod2CellVoltages);
    MOCK_METHOD1(setMod3PcbTemperature, void(double)); // void setMod3PcbTemperature(double mod3PcbTemperature);
    MOCK_METHOD1(setMod3CellTemperature, void(double)); // void setMod3CellTemperature(double mod3CellTemperature);
    MOCK_METHOD1(setMod3CellVoltages, void(QList<double>)); // void setMod3CellVoltages(QList<double> mod3CellVoltages);
    MOCK_METHOD1(setBatteryVoltage, void(double)); // void setBatteryVoltage(double batteryVoltage);
    MOCK_METHOD1(setBatteryCurrent, void(double)); // void setBatteryCurrent(double batteryCurrent);
};

