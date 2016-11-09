#pragma once

#include <QObject>

class I_JsonForwarder : public QObject
{
    Q_OBJECT
public:
    virtual ~I_JsonForwarder() {}
    virtual void startForwardingData() = 0;
};
