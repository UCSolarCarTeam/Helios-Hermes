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

#pragma once

#include <QObject>

class I_MotorFaultsData : public QObject
{
    Q_OBJECT
public:
    virtual ~I_MotorFaultsData() {}

    /* MotorFaults Gets */
    virtual unsigned char getM0ErrorFlags() const;
    virtual unsigned char getM1ErrorFlags() const;
    virtual unsigned char getM0LimitFlags() const;
    virtual unsigned char getM1LimitFlags() const;
    virtual unsigned char getM0CanRxErrorCount() const;
    virtual unsigned char getM0CanTxErrorCount() const;
    virtual unsigned char getM1CanRxErrorCount() const;
    virtual unsigned char getM1CanTxErrorCount() const;

    /* MotorFaults Sets */
    virtual void setM0ErrorFlags(const unsigned char& m0ErrorFlags;
    virtual void setM1ErrorFlags(const unsigned char& m1ErrorFlags;
    virtual void setM0LimitFlags(const unsigned char& m0LimitFlags;
    virtual void setM1LimitFlags(const unsigned char& m1LimitFlags;
    virtual void setM0CanRxErrorCount(const unsigned char& m0CanRxErrorCount;
    virtual void setM0CanTxErrorCount(const unsigned char& m0CanTxErrorCount;
    virtual void setM1CanRxErrorCount(const unsigned char& m1CanRxErrorCount;
    virtual void setM1CanTxErrorCount(const unsigned char& m1CanTxErrorCount;

signals:
    void m0ErrorFlagsReceived(const unsigned char& m0ErrorFlags);
    void m1ErrorFlagsReceived(const unsigned char& m1ErrorFlags);
    void m0LimitFlagsReceived(const unsigned char& m0LimitFlags);
    void m1LimitFlagsReceived(const unsigned char& m1LimitFlags);
    void m0CanRxErrorCountReceived(const unsigned char& m0CanRxErrorCount);
    void m0CanTxErrorCountReceived(const unsigned char& m0CanTxErrorCount);
    void m1CanRxErrorCountReceived(const unsigned char& m1CanRxErrorCount);
    void m1CanTxErrorCountReceived(const unsigned char& m1CanTxErrorCount);
};
