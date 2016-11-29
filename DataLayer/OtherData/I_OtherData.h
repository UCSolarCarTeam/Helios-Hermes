#pragma once

#include <QObject>

class I_OtherData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_OtherData() {}

    /* OtherData "Gets"*/
    virtual unsigned char getGps() const = 0;

    /*OtherData "Sets"*/
    virtual void setGps(const unsigned char& gps) = 0;

signals:
    void gpsReceived(const unsigned char& gps);
};
