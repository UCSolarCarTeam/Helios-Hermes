#pragma once

#include "DataLayer/LightsData/I_LightsData.h"

class MockLightsData : public I_LightsData
{
public:

    /*LightsData "Gets"*/
    MOCK_CONST_METHOD0(getAlive, bool());
    MOCK_CONST_METHOD0(getLowBeams, bool());
    MOCK_CONST_METHOD0(getHighBeams, bool());
    MOCK_CONST_METHOD0(getBrakes, bool());
    MOCK_CONST_METHOD0(getLeftSignal, bool());
    MOCK_CONST_METHOD0(getRightSignal, bool());
    MOCK_CONST_METHOD0(getBmsStrobeLight, bool());

    /*LightsData "Sets"*/
    MOCK_METHOD1(setAlive, void(const bool&));
    MOCK_METHOD1(setLightStatus, void(const unsigned char&));
};
