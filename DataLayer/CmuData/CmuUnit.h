#pragma once

#include "I_CmuUnit.h"
#include <QList>

class CmuUnit : public I_CmuUnit
{
public:
    CmuUnit();
    virtual ~CmuUnit();

    /* CmuUnit Gets */
    unsigned char getCmuNumber() const;
    short getCellVoltage(const int& index) const;
    unsigned short getPcbTemp() const;
    unsigned short getCellTemp(const int& index) const;

    /* CmuUnit Sets */
    void setCellVoltage(const int& index, const short& value);
    void setPcbTemp(const unsigned short& pcbTemp);
    void setCellTemp(const int& index, const unsigned short& value);


private:
    static unsigned char newCmuNumber_;
    unsigned char cmuNumber_;
    QList<short> cellVoltages_;
    unsigned short pcbTemp_;
    QList<unsigned short> cellTemps_;
};
