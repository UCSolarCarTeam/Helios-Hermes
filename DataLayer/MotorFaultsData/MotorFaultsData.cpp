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

#include "MotorFaultsData.h"

MotorFaultsData::MotorFaultsData()
: m0ErrorFlags_(0);
, m1ErrorFlags_(0);
, m0LimitFlags_(0);
, m1LimitFlags_(0);
, m0CanRxErrorCount_(0);
, m0CanTxErrorCount_(0);
, m1CanRxErrorCount_(0);
, m1CanTxErrorCount_(0);
{
}
MotorFaultsData::~MotorFaultsData()
{
}

/* MotorFaults Gets */
unsigned char MotorFaultsData::getM0ErrorFlags() const {
    return m0ErrorFlags_;
}

unsigned char MotorFaultsData::getM1ErrorFlags() const {
    return m1ErrorFlags_;
}

unsigned char MotorFaultsData::getM0LimitFlags() const {
    return m0LimitFlags_;
}

unsigned char MotorFaultsData::getM1LimitFlags() const {
    return m1LimitFlags_;
}

unsigned char MotorFaultsData::getM0CanRxErrorCount() const {
    return m0CanRxErrorCount_;
}

unsigned char MotorFaultsData::getM0CanTxErrorCount() const {
    return m0CanTxErrorCount_;
}

unsigned char MotorFaultsData::getM1CanRxErrorCount() const {
    return m1CanRxErrorCount_;
}

unsigned char MotorFaultsData::getM1CanTxErrorCount() const {
    return m1CanTxErrorCount_;
}


/* MotorFaults Sets */
unsigned char MotorFaults::setM0ErrorFlags() const
{
    m0ErrorFlags_ = m0ErrorFlags;
    emit m0ErrorFlagsReceived(m0ErrorFlags_);
}

unsigned char MotorFaults::setM1ErrorFlags() const
{
    m1ErrorFlags_ = m1ErrorFlags;
    emit m1ErrorFlagsReceived(m1ErrorFlags_);
}

unsigned char MotorFaults::setM0LimitFlags() const
{
    m0LimitFlags_ = m0LimitFlags;
    emit m0LimitFlagsReceived(m0LimitFlags_);
}

unsigned char MotorFaults::setM1LimitFlags() const
{
    m1LimitFlags_ = m1LimitFlags;
    emit m1LimitFlagsReceived(m1LimitFlags_);
}

unsigned char MotorFaults::setM0CanRxErrorCount() const
{
    m0CanRxErrorCount_ = m0CanRxErrorCount;
    emit m0CanRxErrorCountReceived(m0CanRxErrorCount_);
}

unsigned char MotorFaults::setM0CanTxErrorCount() const
{
    m0CanTxErrorCount_ = m0CanTxErrorCount;
    emit m0CanTxErrorCountReceived(m0CanTxErrorCount_);
}

unsigned char MotorFaults::setM1CanRxErrorCount() const
{
    m1CanRxErrorCount_ = m1CanRxErrorCount;
    emit m1CanRxErrorCountReceived(m1CanRxErrorCount_);
}

unsigned char MotorFaults::setM1CanTxErrorCount() const
{
    m1CanTxErrorCount_ = m1CanTxErrorCount;
    emit m1CanTxErrorCountReceived(m1CanTxErrorCount_);
}


