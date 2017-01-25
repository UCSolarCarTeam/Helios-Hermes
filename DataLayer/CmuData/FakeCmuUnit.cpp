#include "FakeCmuUnit.h"

FakeCmuUnit::FakeCmuUnit()
{
}

FakeCmuUnit::~FakeCmuUnit()
{
}

/* CmuUnit Gets */
unsigned char FakeCmuUnit::getCmuNumber() const
{
    return 1;
}

short FakeCmuUnit::getCellVoltage(const int& index)
{
    return 2 + index;
}

unsigned short FakeCmuUnit::getPcbTemp() const
{
    return 10;
}

unsigned short FakeCmuUnit::getCellTemp(const int& index) const
{
    return 11 + index;
}

/* CmuUnit Sets */
void FakeCmuUnit::setCmuNumber(const unsigned char& cmuNumber) {}
void FakeCmuUnit::setCellVoltage(const short& value) {}
void FakeCmuUnit::setPcbTemp(const unsigned short& pcbTemp) {}
void FakeCmuUnit::setCellTemp(const unsigned short& value) {}
