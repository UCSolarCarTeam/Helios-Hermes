#pragma once

#include <QObject>

class I_OtherData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_OtherData() {}

    /* OtherData "Gets"*/
    unsigned char getGps() const;

    /*OtherData "Sets"*/
    virtual void setGps(const unsigned char& gps);

signals:
    void gpsReceived(const unsigned char& gps);
};
