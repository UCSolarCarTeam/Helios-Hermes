#pragma once

#include <QObject>

class I_CcsData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_CcsData() {}

    virtual bool getCcsAlive() const = 0;

    virtual void setCcsAlive(const bool&) = 0;

signals:
    void ccsAliveReceived(const bool&);
};
