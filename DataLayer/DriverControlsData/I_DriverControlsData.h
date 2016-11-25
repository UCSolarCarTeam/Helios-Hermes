#pragma once

#include <QObject>

class I_DriverControlsData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_DriverControlsData() {}

    /*Data "Gets"*/
    virtual unsigned char getDriverControlsBoardAlive() const = 0;
    virtual unsigned char getLightsInputs() const = 0;
    virtual unsigned char getMusicInputs() const = 0;
    virtual unsigned short getAcceleration() const = 0;
    virtual unsigned short getRegenBraking() const = 0;
    virtual unsigned char getDriverInputs() const = 0;

    /*DriverControlsData "Sets"*/
    virtual void setDriverControlsBoardAlive(const unsigned char& getDriverControlsBoardAlive) = 0;
    virtual void setLightsInputs(const unsigned char& getLightsInputs) = 0;
    virtual void setMusicInputs(const unsigned char& getMusicInputs) = 0;
    virtual void setAcceleration(const unsigned short& getAcceleration) = 0;
    virtual void setRegenBraking(const unsigned short& getRegenBraking) = 0;
    virtual void setDriverInputs(const unsigned char& getDriverInputs) = 0;

signals:
    void driverControlsBoardAliveReceived(unsigned char getDriverControlsBoardAlive);
    void lightsInputsReceived(unsigned char getLightsInputs);
    void musicInputsReceived(unsigned char getMusicInputs);
    void accelerationReceived(unsigned short getAcceleration);
    void regenBrakingReceived(unsigned short getRegenBraking);
    void driverInputsReceived(unsigned char getDriverInputs);
};
