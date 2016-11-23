#include "OtherData.h"

OtherData::OtherData()
    : gps_(0)

{
    // initialize to 0
}

OtherData::~OtherData()
{
}

/* OtherData "Gets"*/
unsigned char OtherData::getGps() const
{
    return gps_;
}

/*OtherData "Sets"*/
void OtherData::setGps(const unsigned char& gps)
{
    gps_ = gps;
}
