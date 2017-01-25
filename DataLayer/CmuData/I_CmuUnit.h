#pragma once

#include <QObject>

class I_CmuUnit : public QObject
{
    Q_OBJECT
public:
    virtual ~I_CmuUnit() {}

    /* CmuUnit Gets */
    virtual unsigned char getCmuNumber() const = 0;
    virtual short getCellVoltage(const int&) const = 0;
    virtual unsigned short getPcbTemp() const = 0;
    virtual unsigned short getCellTemp(const int&) const = 0;

    /* CmuUnit Sets */
    virtual void setCellVoltage(const int&, const short&) = 0;
    virtual void setPcbTemp(const unsigned short&) = 0;
    virtual void setCellTemp(const int&, const unsigned short&) = 0;

signals:
    void cmuNumberReceived(const unsigned char& cmuNumber);
    void cellVoltageReceived(const int& index, const short& value);
    void pcbTempReceived(const unsigned short& pcbTemp);
    void cellTempReceived(const int& index, const unsigned short& value);
};
