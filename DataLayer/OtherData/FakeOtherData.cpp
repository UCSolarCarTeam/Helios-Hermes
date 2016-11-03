#include "FakeOtherData.h"

FakeOtherData::FakeOtherData()
{
}

FakeOtherData::~FakeOtherData()
{
}


/* OtherData "Gets"*/
unsigned char FakeOtherData::getGps() const
{
    return 1;
}

/*OtherData "Sets"*/
void FakeOtherData::setGps(const unsigned char& gps) {}
