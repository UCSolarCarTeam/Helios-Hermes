#pragma once

#include "DataLayer/CcsData/I_CcsData.h"

class MockCcsData : public I_CcsData
{
public:

    /*CcsData "Gets"*/

    MOCK_CONST_METHOD0(getCcsAlive, bool());


    /*CcsData "Sets"*/

    MOCK_METHOD1(setCcsAlive, void(const bool&));

};
