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
: packageID_(0)
, cmuNumber_(0)

    // Initialize to 0
}
CmuData::~CmuData()
{
}

/* CmuData gets */
unsigned char CmuData::getPackageID() const {
    return packageID_;
}

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

void CmuData::setPackageID(const unsigned char&) {

}

void CmuData::setCmuNumber(const unsigned char&) {

}

void CmuData::setCell0Voltage(const unsigned short&) {

}

void CmuData::setCell1Voltage(const unsigned short&) {

}

void CmuData::setCell2Voltage(const unsigned short&) {

}

void CmuData::setCell3Voltage(const unsigned short&) {

}

void CmuData::setCell4Voltage(const unsigned short&) {

}

void CmuData::setCell5Voltage(const unsigned short&) {

}

void CmuData::setCell6Voltage(const unsigned short&) {

}

void CmuData::setCell7Voltage(const unsigned short&) {

}

void CmuData::setPcbTemp(const unsigned short&) {

}

void CmuData::setCellTemp0(const unsigned short&) {

}

void CmuData::setCellTemp1(const unsigned short&) {

}

void CmuData::setCellTemp2(const unsigned short&) {

}

void CmuData::setCellTemp3(const unsigned short&) {

}

void CmuData::setCellTemp4(const unsigned short&) {

}

void CmuData::setCellTemp5(const unsigned short&) {

}

void CmuData::setCellTemp6(const unsigned short&) {

}

void CmuData::setCellTemp7(const unsigned short&) {

}

void CmuData::setCellTemp8(const unsigned short&) {

}

void CmuData::setCellTemp9(const unsigned short&) {

}

void CmuData::setCellTemp10(const unsigned short&) {

}

void CmuData::setCellTemp11(const unsigned short&) {

}

void CmuData::setCellTemp12(const unsigned short&) {

}

void CmuData::setCellTemp13(const unsigned short&) {

}

void CmuData::setCellTemp14(const unsigned short&) {

}
