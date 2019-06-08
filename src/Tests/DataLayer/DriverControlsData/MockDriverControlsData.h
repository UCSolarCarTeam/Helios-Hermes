#pragma once

#include "DataLayer/DriverControlsData/I_DriverControlsData.h"

class MockDriverControlsData : public I_DriverControlsData
{
public:

    /*DriverControlsData "Gets"*/
    MOCK_CONST_METHOD0(getDriverControlsBoardAlive, bool());
    MOCK_CONST_METHOD0(getHeadlightsOff, bool());
    MOCK_CONST_METHOD0(getHeadlightsLow, bool());
    MOCK_CONST_METHOD0(getHeadlightsHigh, bool());
    MOCK_CONST_METHOD0(getSignalRight, bool());
    MOCK_CONST_METHOD0(getSignalLeft, bool());
    MOCK_CONST_METHOD0(getHazard, bool());
    MOCK_CONST_METHOD0(getInterior, bool());
    MOCK_CONST_METHOD0(getAux, bool());
    MOCK_CONST_METHOD0(getVolumeUp, bool());
    MOCK_CONST_METHOD0(getVolumeDown, bool());
    MOCK_CONST_METHOD0(getNextSong, bool());
    MOCK_CONST_METHOD0(getPreviousSong, bool());
    MOCK_CONST_METHOD0(getBrakes, bool());
    MOCK_CONST_METHOD0(getForward, bool());
    MOCK_CONST_METHOD0(getReverse, bool());
    MOCK_CONST_METHOD0(getPushToTalk, bool());
    MOCK_CONST_METHOD0(getHorn, bool());
    MOCK_CONST_METHOD0(getReset, bool());
    MOCK_CONST_METHOD0(getAcceleration, unsigned short());
    MOCK_CONST_METHOD0(getRegenBraking, unsigned short());
    MOCK_CONST_METHOD0(getLapButton, bool());

    /*DriverControlsData "Gets"*/
    MOCK_METHOD1(setDriverControlsBoardAlive, void(const unsigned char&));
    MOCK_METHOD1(setLightsInputs, void(const unsigned char&));
    MOCK_METHOD1(setMusicInputs, void(const unsigned char&));
    MOCK_METHOD1(setAcceleration, void(const unsigned short&));
    MOCK_METHOD1(setRegenBraking, void(const unsigned short&));
    MOCK_METHOD1(setDriverInputs, void(const unsigned char&));
};
