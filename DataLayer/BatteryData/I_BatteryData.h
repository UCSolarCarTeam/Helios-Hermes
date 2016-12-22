#pragma once

#include <QObject>

class I_BatteryData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_BatteryData() {}

    /*Data "Gets"*/
    virtual unsigned char getAlive() const = 0;
    virtual float getPackSocAmpHours() const = 0;
    virtual float getPackSocPercentage() const = 0;
    virtual float getPackBalanceSoc() const = 0;
    virtual float getPackBalanceSocPercentage() const = 0;
    virtual unsigned short getChargingCellVoltageError() const = 0;
    virtual unsigned short getCellTemperatureMargin() const = 0;
    virtual unsigned short getDischargingCellVoltageError() const = 0;
    virtual unsigned short getTotalPackCapacity() const = 0;
    virtual unsigned char getPrechargeContactorDriverStatus() const = 0;
    virtual unsigned char getPrechargeState() const = 0;
    virtual unsigned char getPrechargeTimerElapsed() const = 0;
    virtual unsigned short getPrechargeTimerCount() const = 0;
    virtual QPair<unsigned char, unsigned short>& getLowestCellVoltage() const = 0;
    virtual QPair<unsigned char, unsigned short>& getHighestCellVoltage() const = 0;
    virtual QPair<unsigned char, unsigned short>& getLowestCellTemperature() const = 0;
    virtual QPair<unsigned char, unsigned short>& getHighestCellTemperature() const = 0;
    virtual unsigned int getVoltage() const = 0;
    virtual unsigned int getCurrent() const = 0;
    virtual unsigned short getFan0Speed() const = 0;
    virtual unsigned short getFan1Speed() const = 0;
    virtual unsigned short getFanContactors12VCurrentConsumption() const = 0;
    virtual unsigned short getCmu12VCurrentConsumption() const = 0;
    virtual unsigned char getBmsCanLockedOut() const = 0;

    /*BatteryData "Sets"*/
    virtual void setAlive(const unsigned char&) = 0;
    virtual void setPackSocAmpHours(const float&) = 0;
    virtual void setPackSocPercentage(const float&) = 0;
    virtual void setPackBalanceSoc(const float&) = 0;
    virtual void setPackBalanceSocPercentage(const float&) = 0;
    virtual void setChargingCellVoltageError(const unsigned short&) = 0;
    virtual void setCellTemperatureMargin(const unsigned short&) = 0;
    virtual void setDischargingCellVoltageError(const unsigned short&) = 0;
    virtual void setTotalPackCapacity(const unsigned short&) = 0;
    virtual void setPrechargeContactorDriverStatus(const unsigned char&) = 0;
    virtual void setPrechargeState(const unsigned char&) = 0;
    virtual void setPrechargeTimerElapsed(const unsigned char&) = 0;
    virtual void setPrechargeTimerCount(const unsigned short&) = 0;
    virtual void setLowestCellVoltage(const QPair<unsigned char, unsigned short>&) = 0;
    virtual void setHighestCellVoltage(const QPair<unsigned char, unsigned short>&) = 0;
    virtual void setLowestCellTemperature(const QPair<unsigned char, unsigned short>&) = 0;
    virtual void setHighestCellTemperature(const QPair<unsigned char, unsigned short>&) = 0;
    virtual void setVoltage(const unsigned int&) = 0;
    virtual void setCurrent(const unsigned int&) = 0;
    virtual void setFan0Speed(const unsigned short&) = 0;
    virtual void setFan1Speed(const unsigned short&) = 0;
    virtual void setFanContactors12VCurrentConsumption(const unsigned short&) = 0;
    virtual void setCmu12VCurrentConsumption(const unsigned short&) = 0;
    virtual void setBmsCanLockedOut(const unsigned char&) = 0;

signals:
    void aliveReceived(const unsigned char& alive);
    void packSocAmpHoursReceived(const float& packSocAmpHours);
    void packSocPercentageReceived(const float& packSocPercentage);
    void packBalanceSocReceived(const float& packBalanceSoc);
    void packBalanceSocPercentageReceived(const float& packBalanceSocPercentage);
    void chargingCellVoltageErrorReceived(const unsigned short& chargingCellVoltageError);
    void cellTemperatureMarginReceived(const unsigned short& cellTemperatureMargin);
    void dischargingCellVoltageErrorReceived(const unsigned short& dischargingCellVoltageError);
    void totalPackCapacityReceived(const unsigned short& totalPackCapacity);
    void prechargeContactorDriverStatusReceived(const unsigned char& prechargeContactorDriverStatus);
    void prechargeStateReceived(const unsigned char& prechargeState);
    void prechargeTimerElapsedReceived(const unsigned char& prechargeTimerElapsed);
    void prechargeTimerCountReceived(const unsigned short& prechargeTimerCount);
    void lowestCellVoltageReceived(const QPair<unsigned char, unsigned short>& lowestCellVoltage);
    void highestCellVoltageReceived(const QPair<unsigned char, unsigned short>& highestCellVoltage);
    void lowestCellTemperatureReceived(const QPair<unsigned char, unsigned short>& lowestCellTemperature);
    void highestCellTemperatureReceived(const QPair<unsigned char, unsigned short>& highestCellTemperature);
    void voltageReceived(const unsigned int& voltage);
    void currentReceived(const unsigned int& current);
    void fan0SpeedReceived(const unsigned short& fan0Speed);
    void fan1SpeedReceived(const unsigned short& fan1Speed);
    void fanContactors12VCurrentConsumptionReceived(const unsigned short& fanContactors12VCurrentConsumption);
    void cmu12VCurrentConsumptionReceived(const unsigned short& cmu12VCurrentConsumption);
    void bmsCanLockedOutReceived(const unsigned char& bmsCanLockedOut);
};
