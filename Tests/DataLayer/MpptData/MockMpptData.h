#pragma once

#include "DataLayer/MpptData/I_MpptData.h"

class MockMpptData : public I_MpptData
{
public:

    /*MpptData "Gets"*/
    MOCK_CONST_METHOD0(getNumberOfUnits, unsigned char());
    MOCK_CONST_METHOD1(getMpptUnit, I_MpptUnit&(const unsigned char&));
};
