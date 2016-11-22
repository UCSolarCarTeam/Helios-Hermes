#include "CmuUnit.h"

CmuUnit::CmuUnit(const unsigned char& cmuNumber)
: cmuNumber_(cmuNumber)
, cell0Voltage_(0)
, cell1Voltage_(0)
, cell2Voltage_(0)
, cell3Voltage_(0)
, cell4Voltage_(0)
, cell5Voltage_(0)
, cell6Voltage_(0)
, cell7Voltage_(0)
, pcbTemp_(0)
, cellTemp0_(0)
, cellTemp1_(0)
, cellTemp2_(0)
, cellTemp3_(0)
, cellTemp4_(0)
, cellTemp5_(0)
, cellTemp6_(0)
, cellTemp7_(0)
, cellTemp8_(0)
, cellTemp9_(0)
, cellTemp10_(0)
, cellTemp11_(0)
, cellTemp12_(0)
, cellTemp13_(0)
, cellTemp14_(0)
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

unsigned short CmuUnit::getCell0Voltage() const {
    return cell0Voltage_;
}

unsigned short CmuUnit::getCell1Voltage() const {
    return cell1Voltage_;
}

unsigned short CmuUnit::getCell2Voltage() const {
    return cell2Voltage_;
}

unsigned short CmuUnit::getCell3Voltage() const {
    return cell3Voltage_;
}

unsigned short CmuUnit::getCell4Voltage() const {
    return cell4Voltage_;
}

unsigned short CmuUnit::getCell5Voltage() const {
    return cell5Voltage_;
}

unsigned short CmuUnit::getCell6Voltage() const {
    return cell6Voltage_;
}

unsigned short CmuUnit::getCell7Voltage() const {
    return cell7Voltage_;
}

unsigned short CmuUnit::getPcbTemp() const {
    return pcbTemp_;
}

unsigned short CmuUnit::getCellTemp0() const {
    return cellTemp0_;
}

unsigned short CmuUnit::getCellTemp1() const {
    return cellTemp1_;
}

unsigned short CmuUnit::getCellTemp2() const {
    return cellTemp2_;
}

unsigned short CmuUnit::getCellTemp3() const {
    return cellTemp4_;
}

unsigned short CmuUnit::getCellTemp4() const {
    return cellTemp4_;
}

unsigned short CmuUnit::getCellTemp5() const {
    return cellTemp5_;
}

unsigned short CmuUnit::getCellTemp6() const {
    return cellTemp6_;
}

unsigned short CmuUnit::getCellTemp7() const {
    return cellTemp7_;
}

unsigned short CmuUnit::getCellTemp8() const {
    return cellTemp8_;
}

unsigned short CmuUnit::getCellTemp9() const {
    return cellTemp9_;
}

unsigned short CmuUnit::getCellTemp10() const {
    return cellTemp10_;
}

unsigned short CmuUnit::getCellTemp11() const {
    return cellTemp11_;
}

unsigned short CmuUnit::getCellTemp12() const {
    return cellTemp12_;
}

unsigned short CmuUnit::getCellTemp13() const {
    return cellTemp13_;
}

unsigned short CmuUnit::getCellTemp14() const {
    return cellTemp14_;
}

/* CmuUnit Sets */

void CmuUnit::setCell0Voltage(const unsigned short&) {
    cell0Voltage_ = cell0Voltage;
    emit cell0VoltageReceived(cell0Voltage_);
}

void CmuUnit::setCell1Voltage(const unsigned short&) {
    cell1Voltage_ = cell1Voltage;
    emit cell1VoltageReceived(cell1Voltage_);
}

void CmuUnit::setCell2Voltage(const unsigned short&) {
    cell2Voltage_ = cell2Voltage;
    emit cell2Voltage_VoltageReceived(cell2Voltage_);
}

void CmuUnit::setCell3Voltage(const unsigned short&) {
    cell3Voltage_ = cell3Voltage;
    emit cell3VoltageReceived(cell3Voltage_);
}

void CmuUnit::setCell4Voltage(const unsigned short&) {
    cell4Voltage_ = cell4Voltage;
    emit cell4VoltageReceived(cell4Voltage_);
}

void CmuUnit::setCell5Voltage(const unsigned short&) {
    cell5Voltage_ = cell5Voltage;
    emit cell5VoltageReceived(cell5Voltage_);
}

void CmuUnit::setCell6Voltage(const unsigned short&) {
    cell6Voltage_ = cell6Voltage;
    emit cell6VoltageReceived(cell6Voltage_);
}

void CmuUnit::setCell7Voltage(const unsigned short&) {
    cell7Voltage_ = cell7Voltage;
    emit cell7VoltageReceived(cell7Voltage_);
}

void CmuUnit::setPcbTemp(const unsigned short&) {
    pcbTemp_ = pcbTemp;
    emit pcbTempReceived(pcbTemp_);
}

void CmuUnit::setCellTemp0(const unsigned short&) {
    cellTemp0_ = cellTemp0;
    emit cellTemp0Received(cellTemp0_);
}

void CmuUnit::setCellTemp1(const unsigned short&) {
    cellTemp1_ = cellTemp1;
    emit cellTemp1Received(cellTemp1_);
}

void CmuUnit::setCellTemp2(const unsigned short&) {
    cellTemp2_ = cellTemp2;
    emit cellTemp2Received(cellTemp2_);
}

void CmuUnit::setCellTemp3(const unsigned short&) {
    cellTemp3_ = cellTemp3;
    emit cellTemp3Received(cellTemp3_);
}

void CmuUnit::setCellTemp4(const unsigned short&) {
    cellTemp4_ = cellTemp4;
    emit cellTemp4Received(cellTemp4_);
}

void CmuUnit::setCellTemp5(const unsigned short&) {
    cellTemp5_ = cellTemp5;
    emit cellTemp5Received(cellTemp5_);
}

void CmuUnit::setCellTemp6(const unsigned short&) {
    cellTemp6_ = cellTemp6;
    emit cellTemp6Received(cellTemp6_);
}

void CmuUnit::setCellTemp7(const unsigned short&) {
    cellTemp7_ = cellTemp7;
    emit cellTemp7Received(cellTemp7_);
}

void CmuUnit::setCellTemp8(const unsigned short&) {
    cellTemp8_ = cellTemp8;
    emit cellTemp8Received(cellTemp8_);
}

void CmuUnit::setCellTemp9(const unsigned short&) {
    cellTemp9_ = cellTemp9;
    emit cellTemp9Received(cellTemp9_);
}

void CmuUnit::setCellTemp10(const unsigned short&) {
    cellTemp10_ = cellTemp10;
    emit cellTemp10Received(cellTemp10_);
}

void CmuUnit::setCellTemp11(const unsigned short&) {
    cellTemp11_ = cellTemp11;
    emit cellTemp11Received(cellTemp11_);
}

void CmuUnit::setCellTemp12(const unsigned short&) {
    cellTemp12_ = cellTemp12;
    emit cellTemp12Received(cellTemp12_);
}

void CmuUnit::setCellTemp13(const unsigned short&) {
    cellTemp13_ = cellTemp13;
    emit cellTemp13Received(cellTemp13_);
}

void CmuUnit::setCellTemp14(const unsigned short&) {
    cellTemp14_ = cellTemp14;
    emit cellTemp14Received(cellTemp14_);
}
