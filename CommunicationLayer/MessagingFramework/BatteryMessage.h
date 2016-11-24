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
    bool prechargeContactorDriverStatus() const;
    bool prechargeState() const;
    bool prechargeTimerElapsed() const;
    unsigned short prechargeTimerCount() const;
    unsigned short lowestCellVoltage() const;
    bool lowestCellVoltageNumber() const;
    unsigned short highestCellVoltage() const;
    bool highestCellVoltageNumber() const;
    unsigned short lowestCellTemperature() const;
    bool lowestCellTemperatureNumber() const;
    unsigned short highestCellTemperature() const;
    bool highestCellTemperatureNumber() const;
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
