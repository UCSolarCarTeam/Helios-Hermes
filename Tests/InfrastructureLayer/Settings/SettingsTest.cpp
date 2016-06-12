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

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <QScopedPointer>

#include "InfrastructureLayer/Settings/Settings.h"

namespace
{
const QString TEST_FILE_PATH = "testconfig.ini";
}

class SettingsTest : public ::testing::Test
{
protected:
    QScopedPointer<Settings> settings_;

    virtual void SetUp()
    {
        settings_.reset(new Settings(TEST_FILE_PATH));
    }
};

TEST_F(SettingsTest, serialPortName)
{
    EXPECT_EQ(settings_->serialPortName(), "/dev/pts/7");
}

TEST_F(SettingsTest, baudrate)
{
    EXPECT_EQ(settings_->baudrate(), 9600);
}

TEST_F(SettingsTest, ipAddress)
{
    EXPECT_EQ(settings_->ipAddress(), "239.255.43.21");
}

TEST_F(SettingsTest, port)
{
    EXPECT_EQ(settings_->udpPort(), 44550);
}

TEST_F(SettingsTest, forwardPeriod)
{
    EXPECT_EQ(settings_->forwardPeriod(), 500);
}

TEST_F(SettingsTest, packetTitle)
{
    EXPECT_EQ(settings_->packetTitle(), "Gen5");
}
