#pragma once

#include <QObject>

class I_LightsData : public QObject
{
    Q_OBJECT
public:
    virtual ~I_LightsData() {}

    /* LightsData Gets */
    virtual unsigned char getLightStatus() const = 0;

    /* LightsData Sets */
    virtual void setLightStatus(const unsigned char&) = 0;

signals:
    void lightStatusReceived(const unsigned char lightStatus);
};
