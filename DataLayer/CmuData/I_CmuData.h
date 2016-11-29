#pragma once

#include <QObject>
#include "I_CmuUnit.h"

class I_CmuData : public QObject
{
    Q_OBJECT
public:
    virtual ~I_CmuData();

    /* CmuData get */
    virtual I_CmuUnit& getCmuUnit(const unsigned char& index) = 0;
};
