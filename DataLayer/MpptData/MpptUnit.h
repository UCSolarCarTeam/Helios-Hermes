#pragma once

#include "I_MpptUnit.h"

class MpptUnit : public I_MpptUnit
{
public:
    MpptUnit();
    virtual ~MpptUnit();

    /* MpptUnit Gets */
    unsigned char getMpptNumber() const;
    unsigned char getMpptStatus() const;
    unsigned short getArrayVoltage() const;
    unsigned short getArrayCurrent() const;
    unsigned short getBatteryVoltage() const;
    unsigned short getTemperature() const;

    /* MpptUnit Sets */
    void setMpptStatus(const unsigned char& mpptStatus);
    void setArrayVoltage(const unsigned short& arrayVoltage);
    void setArrayCurrent(const unsigned short& arrayCurrent);
    void setBatteryVoltage(const unsigned short& batteryVoltage);
    void setTemperature(const unsigned short& temperature);


private:
    unsigned char mpptNumber_;
    unsigned char mpptStatus_;
    unsigned short arrayVoltage_;
    unsigned short arrayCurrent_;
    unsigned short batteryVoltage_;
    unsigned short temperature_;
};
