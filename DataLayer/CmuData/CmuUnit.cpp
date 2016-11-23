#include "CmuUnit.h"

CmuUnit::CmuUnit(const unsigned char& cmuNumber)
: cmuNumber_(cmuNumber)
, cellVoltages_(QList<short>())
, pcbTemp_(0)
, cellTemps_(QList<unsigned short>())
{
    // Initialize to 0
}
CmuUnit::~CmuUnit()
{
}

/* CmuUnit gets */
unsigned char CmuUnit::getCmuNumber() const {
    return cmuNumber_;
}

unsigned short CmuUnit::getCellVoltage(const int& index) const {
    return cellVoltage_[index];
}

unsigned short CmuUnit::getPcbTemp() const {
    return pcbTemp_;
}

unsigned short CmuUnit::getCellTemp0(const int& index) const {
    return cellTemps_[index];
}

/* CmuUnit Sets */

void CmuUnit::setCellVoltage(const int& index, const unsigned short& value) {
    if (index < 0 || index > 7) 
    {
        qDebug() << "Cell voltage index out of bounds";
    }
    cellVoltages_[index] = value;
    emit cellVoltageReceived(index, value);
}

void CmuUnit::setPcbTemp(const unsigned short& pcbTemp) {
    pcbTemp_ = pcbTemp;
    emit pcbTempReceived(pcbTemp_);
}

void CmuUnit::setCellTemp(const int& index, const unsigned short& value) {
    if (index < 0 || index > 14)
    {
        qDebug() << "Cell temperature index out of bounds";
    }
    cellTemps_[index] = value;
    emit cellTempReceived(index, value);
}
