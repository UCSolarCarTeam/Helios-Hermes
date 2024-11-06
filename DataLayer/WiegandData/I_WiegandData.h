#pragma once

#include <QObject>

class I_WiegandData : public QObject
{
    Q_OBJECT
public:
    virtual ~I_WiegandData() {}
    virtual QByteArray getData() const = 0;
    virtual int getWiegandId() const = 0;
    // Slots for handling data events
public slots:
    virtual void handleNewData() = 0;   // Pure virtual, must be implemented
    virtual void timerExpired() = 0;    // Pure virtual, must be implemented
};
