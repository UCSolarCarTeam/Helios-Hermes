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

/***************************** Solution One *************************************/

 class SerialDefines
 {
public:
    /* Serial Gets */
    unsigned char getKeyMotorID() const;
    unsigned char getMotor0DetailsID() const;
    unsigned char getMotor1DetailsID() const;
    unsigned char getDriverControlsID() const;
    unsigned char getMotorFaultsID() const;
    unsigned char getBatteryFaultsID() const;
    unsigned char getBatteryID() const;
    unsigned char getCmuID() const;
    unsigned char getMpptID() const;
    unsigned char getLightsID() const;
    unsigned char getOtherID() const;

private:
    const unsigned char keyMotorID_;
    const unsigned char motor0DetailsID_;
    const unsigned char motor1DetailsID_;
    const unsigned char driverControlsID_;
    const unsigned char motorFaultsID_;
    const unsigned char batteryFaultsID_;
    const unsigned char batteryID_;
    const unsigned char cmuID_;
    const unsigned char mpptID_;
    const unsigned char lightsID_;
    const unsigned char otherID_;
 }
 // With implementation in cpp file... or

 /***************************** Solution Two *************************************/

const unsigned char kKeyMotorSerialID = 1;
const unsigned char kMotor0DetailsSerialID = 2;
const unsigned char kMotor1DetailsSerialID = 3;
const unsigned char kDriverControlsSerialID = 4;
const unsigned char kMotorFaultsSerialID = 5;
const unsigned char kBatteryFaultsSerialID = 6;
const unsigned char kBatterySerialID = 7;
const unsigned char kCmuSerialID = 8;
const unsigned char kMpptSerialID = 9;
const unsigned char kLightsSerialID = 10;
const unsigned char kOtherSerialID = 11;
