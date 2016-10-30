#pragma once

#include "I_BatteryData.h"

class FakeBatteryData : public I_BatteryData
{
public:
    FakeBatteryData();
    virtual ~FakeBatteryData();

    /*Data "Gets"*/
    unsigned char getAlive() const;
    float getPackSocAmpHours() const;
    float getPackSocPercentage() const;
    float getPackBalanceSoc() const;
    float getPackBalanceSocPercentage() const;
    unsigned short getChargingCellVoltageError() const;
    unsigned short getCellTemperatureMargin() const;
    unsigned short getDischargingCellVoltageError() const;
    unsigned short getTotalPackCapacity() const;
    unsigned char getPrechargeContactorDriverStatus() const;
    unsigned char getPrechargeState() const;
    unsigned char getPrechargeTimerElapsed() const;
    unsigned short getPrechargeTimerCount() const;
    unsigned short getLowestCellVoltage() const;
    unsigned char getLowestCellVoltageNumber() const;
    unsigned short getHighestCellVoltage() const;
    unsigned char getHighestCellVoltageNumber() const;
    unsigned short getLowestCellTemperature() const;
    unsigned char getLowestCellTemperatureNumber() const;
    unsigned short getHighestCellTemperature() const;
    unsigned char getHighestCellTemperatureNumber() const;
    unsigned int getVoltage() const;
    unsigned int getCurrent() const;
    unsigned short getFan0Speed() const;
    unsigned short getFan1Speed() const;
    unsigned short getFanContactors12VCurrentConsumption() const;
    unsigned short getCmu12VCurrentConsumption() const;
    unsigned char getBmsCanLockedOut() const;

    /*BatteryData "Sets"*/
    void setAlive(const unsigned char&);
    void setPackSocAmpHours(const float&);
    void setPackSocPercentage(const float&);
    void setPackBalanceSoc(const float&);
    void setPackBalanceSocPercentage(const float&);
    void setChargingCellVoltageError(const unsigned short&);
    void setCellTemperatureMargin(const unsigned short&);
    void setDischargingCellVoltageError(const unsigned short&);
    void setTotalPackCapacity(const unsigned short&);
    void setPrechargeContactorDriverStatus(const unsigned char&);
    void setPrechargeState(const unsigned char&);
    void setPrechargeTimerElapsed(const unsigned char&);
    void setPrechargeTimerCount(const unsigned short&);
    void setLowestCellVoltage(const unsigned short&);
    void setLowestCellVoltageNumber(const unsigned char&);
    void setHighestCellVoltage(const unsigned short&);
    void setHighestCellVoltageNumber(const unsigned char&);
    void setLowestCellTemperature(const unsigned short&);
    void setLowestCellTemperatureNumber(const unsigned char&);
    void setHighestCellTemperature(const unsigned short&);
    void setHighestCellTemperatureNumber(const unsigned char&);
    void setVoltage(const unsigned int&);
    void setCurrent(const unsigned int&);
    void setFan0Speed(const unsigned short&);
    void setFan1Speed(const unsigned short&);
    void setFanContactors12VCurrentConsumption(const unsigned short&);
    void setCmu12VCurrentConsumption(const unsigned short&);
    void setBmsCanLockedOut(const unsigned char&);
};
