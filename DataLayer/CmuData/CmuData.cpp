/**
 *  Schulich Delta Hermes
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of Schulich Delta Hermes
 *
 *  Schulich Delta Hermes is free software:
 *  you can redistribute it and/or modify it under the terms
 *  of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  Schulich Delta Hermes is distributed
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General
 *  Public License along with Schulich Delta Hermes.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#include "CmuData.h"

CmuData::CmuData()
    : cmuNumber_(0)
{

    // Initialize to 0
}
CmuData::~CmuData()
{
}

/* CmuData gets */
unsigned char CmuData::getCmuNumber() const {
    return cmuNumber_;
}

unsigned short CmuData::getCell0Voltage() const {
    return cell0Voltage_;
}

unsigned short CmuData::getCell1Voltage() const {
    return cell1Voltage_;
}

unsigned short CmuData::getCell2Voltage() const {
    return cell2Voltage_;
}

unsigned short CmuData::getCell3Voltage() const {
    return cell3Voltage_;
}

unsigned short CmuData::getCell4Voltage() const {
    return cell4Voltage_;
}

unsigned short CmuData::getCell5Voltage() const {
    return cell5Voltage_;
}

unsigned short CmuData::getCell6Voltage() const {
    return cell6Voltage_;
}

unsigned short CmuData::getCell7Voltage() const {
    return cell7Voltage_;
}

unsigned short CmuData::getPcbTemp() const {
    return pcbTemp_;
}

unsigned short CmuData::getCellTemp0() const {
    return cellTemp0_;
}

unsigned short CmuData::getCellTemp1() const {
    return cellTemp1_;
}

unsigned short CmuData::getCellTemp2() const {
    return cellTemp2_;
}

unsigned short CmuData::getCellTemp3() const {
    return cellTemp4_;
}

unsigned short CmuData::getCellTemp4() const {
    return cellTemp4_;
}

unsigned short CmuData::getCellTemp5() const {
    return cellTemp5_;
}

unsigned short CmuData::getCellTemp6() const {
    return cellTemp6_;
}

unsigned short CmuData::getCellTemp7() const {
    return cellTemp7_;
}

unsigned short CmuData::getCellTemp8() const {
    return cellTemp8_;
}

unsigned short CmuData::getCellTemp9() const {
    return cellTemp9_;
}

unsigned short CmuData::getCellTemp10() const {
    return cellTemp10_;
}

unsigned short CmuData::getCellTemp11() const {
    return cellTemp11_;
}

unsigned short CmuData::getCellTemp12() const {
    return cellTemp12_;
}

unsigned short CmuData::getCellTemp13() const {
    return cellTemp13_;
}

unsigned short CmuData::getCellTemp14() const {
    return cellTemp14_;
}

/* CmuData Sets */

void CmuData::setCmuNumber(const unsigned char&) {
    cmuNumber_ = cmuNumber;
    emit cmuNumberReceived(cmuNumber_);
}

void CmuData::setCell0Voltage(const unsigned short&) {
    cell0Voltage_ = cell0Voltage;
    emit cell0VoltageReceived(cell0Voltage_);
}

void CmuData::setCell1Voltage(const unsigned short&) {
    cell1Voltage_ = cell1Voltage;
    emit cell1VoltageReceived(cell1Voltage_);
}

void CmuData::setCell2Voltage(const unsigned short&) {
    cell2Voltage_ = cell2Voltage;
    emit cell2Voltage_VoltageReceived(cell2Voltage_);
}

void CmuData::setCell3Voltage(const unsigned short&) {
    cell3Voltage_ = cell3Voltage;
    emit cell3VoltageReceived(cell3Voltage_);
}

void CmuData::setCell4Voltage(const unsigned short&) {
    cell4Voltage_ = cell4Voltage;
    emit cell4VoltageReceived(cell4Voltage_);
}

void CmuData::setCell5Voltage(const unsigned short&) {
    cell5Voltage_ = cell5Voltage;
    emit cell5VoltageReceived(cell5Voltage_);
}

void CmuData::setCell6Voltage(const unsigned short&) {
    cell6Voltage_ = cell6Voltage;
    emit cell6VoltageReceived(cell6Voltage_);
}

void CmuData::setCell7Voltage(const unsigned short&) {
    cell7Voltage_ = cell7Voltage;
    emit cell7VoltageReceived(cell7Voltage_);
}

void CmuData::setPcbTemp(const unsigned short&) {
    pcbTemp_ = pcbTemp;
    emit pcbTempReceived(pcbTemp_);
}

void CmuData::setCellTemp0(const unsigned short&) {
    cellTemp0_ = cellTemp0;
    emit cellTemp0Received(cellTemp0_);
}

void CmuData::setCellTemp1(const unsigned short&) {
    cellTemp1_ = cellTemp1;
    emit cellTemp1Received(cellTemp1_);
}

void CmuData::setCellTemp2(const unsigned short&) {
    cellTemp2_ = cellTemp2;
    emit cellTemp2Received(cellTemp2_);
}

void CmuData::setCellTemp3(const unsigned short&) {
    cellTemp3_ = cellTemp3;
    emit cellTemp3Received(cellTemp3_);
}

void CmuData::setCellTemp4(const unsigned short&) {
    cellTemp4_ = cellTemp4;
    emit cellTemp4Received(cellTemp4_);
}

void CmuData::setCellTemp5(const unsigned short&) {
    cellTemp5_ = cellTemp5;
    emit cellTemp5Received(cellTemp5_);
}

void CmuData::setCellTemp6(const unsigned short&) {
    cellTemp6_ = cellTemp6;
    emit cellTemp6Received(cellTemp6_);
}

void CmuData::setCellTemp7(const unsigned short&) {
    cellTemp7_ = cellTemp7;
    emit cellTemp7Received(cellTemp7_);
}

void CmuData::setCellTemp8(const unsigned short&) {
    cellTemp8_ = cellTemp8;
    emit cellTemp8Received(cellTemp8_);
}

void CmuData::setCellTemp9(const unsigned short&) {
    cellTemp9_ = cellTemp9;
    emit cellTemp9Received(cellTemp9_);
}

void CmuData::setCellTemp10(const unsigned short&) {
    cellTemp10_ = cellTemp10;
    emit cellTemp10Received(cellTemp10_);
}

void CmuData::setCellTemp11(const unsigned short&) {
    cellTemp11_ = cellTemp11;
    emit cellTemp11Received(cellTemp11_);
}

void CmuData::setCellTemp12(const unsigned short&) {
    cellTemp12_ = cellTemp12;
    emit cellTemp12Received(cellTemp12_);
}

void CmuData::setCellTemp13(const unsigned short&) {
    cellTemp13_ = cellTemp13;
    emit cellTemp13Received(cellTemp13_);
}

void CmuData::setCellTemp14(const unsigned short&) {
    cellTemp14_ = cellTemp14;
    emit cellTemp14Received(cellTemp14_);
}
