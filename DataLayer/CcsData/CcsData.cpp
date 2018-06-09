#include "CcsData.h"

CcsData::CcsData()
    :ccsAlive_(false)
{
}

CcsData::~CcsData()
{
}

bool CcsData::getCcsAlive() const
{
    return ccsAlive_;
}

void CcsData::setCcsAlive(const bool& ccsAlive)
{
    ccsAlive_ = ccsAlive;
    emit ccsAliveReceived(ccsAlive_);
}
