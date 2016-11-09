#pragma once

#include "I_BatteryFaultsData.h"

class BatteryFaultsData : public I_BatteryFaultsData
{
public:
    BatteryFaultsData();
    virtual ~BatteryFaultsData();

    /* BatteryFaults Gets */
    unsigned short getErrorFlag() const;

    /* BatteryFaults Sets */
    void setErrorFlag(const unsigned short&);


private:
    unsigned short errorFlag_;
};
