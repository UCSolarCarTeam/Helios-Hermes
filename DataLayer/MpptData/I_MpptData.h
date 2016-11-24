#pragma once

#include <QObject>
#include "I_MpptUnit.h"

class I_MpptData : public QObject
{
    Q_OBJECT
public:
    virtual ~I_MpptData();

    /* MpptData gets */
    virtual I_MpptUnit& getMpptUnit(const unsigned char& index);

signals:
    // TODO Do we need signals here?
}
