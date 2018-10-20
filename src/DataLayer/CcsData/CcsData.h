#pragma once

#include "I_CcsData.h"


class CcsData : public I_CcsData
{
public:

    CcsData();
    virtual ~CcsData();

    bool getCcsAlive() const;

    void setCcsAlive(const bool&);

private:

    bool ccsAlive_;
};


