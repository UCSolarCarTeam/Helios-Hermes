#pragma once

#include <QByteArray>
#include <QString>

class BatteryMessage
{
public:
    BatteryMessage(const QByteArray& messageData);

    bool alive() const;
    float packSocAmpHours() const;
    float packSocPercentage() const;
    float packBalanceSoc() const;
    float packBalanceSocPercentage() const;
    unsigned short chargingCellVoltageError() const;
    unsigned short cellTemperatureMargin() const;
    unsigned short dischargingCellVoltageError() const;
    unsigned short totalPackCapacity() const;
    unsigned char prechargeContactorDriverStatus() const;
    unsigned char prechargeState() const;
    unsigned char prechargeTimerElapsed() const;
    unsigned short prechargeTimerCount() const;
    unsigned short lowestCellVoltage() const;
    unsigned char lowestCellVoltageNumber() const;
    unsigned short highestCellVoltage() const;
    unsigned char highestCellVoltageNumber() const;
    unsigned short lowestCellTemperature() const;
    unsigned char lowestCellTemperatureNumber() const;
    unsigned short highestCellTemperature() const;
    unsigned char highestCellTemperatureNumber() const;
    unsigned int voltage() const;
    unsigned int current() const;
    unsigned short fan0Speed() const;
    unsigned short fan1Speed() const;
    unsigned short fanContactors12VCurrentConsumption() const;
    unsigned short cmu12VCurrentConsumption() const;
    bool bmsCanLockedOut() const;

    QString toString() const;

private:
   const QByteArray messageData_;
};
